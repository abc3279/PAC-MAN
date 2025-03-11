#define REAL_START_POINT_X 14
#define REAL_START_POINT_Y 11

enum {RED, PINK, BLUISH_GREEN, ORANGE, GRAY};

void monster_print(int, int, int, int, int, int, int, int);
void Inky_path_finder(int mode=0); // 이거하고 

class monsters
{
	public:
		int mx, my; //몬스터 x,y 좌표 px, py 대체용 
		int mcx, mcy; //몬스터 이전 좌표 pcx, pcy 대체용 
		int target_x, target_y;
		int a, b; // x, y 대체용 
		int color; // 유령 색 
		int iscaught;
		int spawn_sec;
		char stuck; // 몬스터가 같은자리를 반복해서 간 횟수 
		char stuck_move;  // stuck 상태일때 작동하는 코드 실행횟수 
	
	void monster_image_init(void)
	{
		gotoxy(mx*2, my);
		
		if(map[my][mx] == 3)
		{
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	        printf("ㆍ"); //코인으로 표시 
		}
		else if(map[my][mx] == 4)
		{
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
			printf("⊙");//아이템으로 표시 
		}
		else 
			printf("  "); //이전 모습 지우기 
	}
	
	void location_init(int x, int y)
	{
		mx = x;
		my = y;
		
		mcx = x;
		mcy = y;
	}
	
	void Blinky_path_finder(int mode=0) //mode는 유령 상태와 추격상태를 구분함. 0 : 추격, 1 : 유령 | 추격상태를 표현할때는 인자를 안줘도 되고, 유령상태를 표현할때는 줘야함. 
	{
		int i, type = 0;
		int compare_pathx[4] = {1};
		int compare_pathy[4] = {0};
		int compare_result;
		int compare_resulti;
		
		a=mx, b=my;
		
		if(mode == 0)
		{
			target_x = px;
			target_y = py;
		}
		else if(mode == 1)
		{
			target_x = REAL_START_POINT_X;
			target_y = REAL_START_POINT_Y;
			color = GRAY; 
		}
		
		if((px == mx && py == my) || s1_active != 0)
		{
			mcx = mx;
		  	mcy = my;
					   	
			if(map[my][mx] == 3)
				{
				  	type=1; //코인
				}
			else if(map[my][mx] == 4)
				{
					type=2; // 아이템 
				}
		}
		else
		{
			switch(stuck == 3)
			{	
				case 1:			//3번 제자리걸음  
				if(map[b][a-1] != 1 && ((mx-1) != mcx)) // 좌 
				{
					compare_pathx[0] = (mx-1) - target_x;
					compare_pathy[0] = my - target_y;
				}
				else
				{
					compare_pathx[0] = 50;
					compare_pathy[0] = 50;
				}
				if(map[b][a+1] != 1 && ((mx+1) != mcx)) // 우 
				{
					compare_pathx[1] = (mx+1) - target_x;
					compare_pathy[1] = my - target_y;
				}
				else
				{
					compare_pathx[1] = 50;
					compare_pathy[1] = 50;
				}
				if(map[b-1][a] != 1 && ((my-1) != mcy)) // 상 
				{
					compare_pathx[2] = mx - target_x;
					compare_pathy[2] = (my-1) - target_y;
				}
				else
				{
					compare_pathx[2] = 50;
					compare_pathy[2] = 50;
				}
				if(map[b+1][a] != 1 && ((my+1) != mcy)) // 하 
				{	
					compare_pathx[3] = mx - target_x;
					compare_pathy[3] = (my+1) - target_y;					
				}
				else
				{
					compare_pathx[3] = 50;
					compare_pathy[3] = 50;
				}
				stuck_move++;
				
				if(stuck_move>20){
					stuck_move = 0;
					stuck = 0;
				}
				break;
				
				//////////////////////////////////////////////
				
				default : 		//일반상태				
				if(map[b][a-1] != 1) // 좌 
				{
					compare_pathx[0] = (mx-1) - target_x;
					compare_pathy[0] = my - target_y;
				}
				else
				{
					compare_pathx[0] = 50;
					compare_pathy[0] = 50;
				}
				if(map[b][a+1] != 1) // 우 
				{
					compare_pathx[1] = (mx+1) - target_x;
					compare_pathy[1] = my - target_y;
				}
				else
				{
					compare_pathx[1] = 50;
					compare_pathy[1] = 50;
				}
				if(map[b-1][a] != 1) // 상 
				{
					compare_pathx[2] = mx - target_x;
					compare_pathy[2] = (my-1) - target_y;
				}
				else
				{
					compare_pathx[2] = 50;
					compare_pathy[2] = 50;
				}
				if(map[b+1][a] != 1) // 하 
				{	
					compare_pathx[3] = mx - target_x;
					compare_pathy[3] = (my+1) - target_y;					
				}
				else
				{
					compare_pathx[3] = 50;
					compare_pathy[3] = 50;
				}
		}
			   
				compare_result = (compare_pathy[0] * compare_pathy[0] + compare_pathx[0] * compare_pathx[0]);
				compare_resulti = 0;
				
				for(i=1;i<4;i++) //총 3번만 위에서 초기화를 해주었기때문에. 
				{
					if(compare_result > (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]))
					{
						compare_result = (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]);
						compare_resulti = i;
					}
				}
				
			if(map[my][mx] == 3)
			{
			  	type=1; //코인
			}
			else if(map[my][mx] == 4)
			{
				type=2; // 아이템 
			}
			
			switch(compare_resulti)
			{
			    case 0: // 좌 	
					if(mcx == mx - 1)
						stuck++;

	    			mcx = mx;
				   	mcy = my;
					mx--;
			    	break;   	
		    	case 1: // 우 
					if(mcx == mx + 1)
						stuck++;
				
	    			mcx = mx;
			 	    mcy = my;
					mx++;
		    		break;
		    	case 2: //상 
					if(mcy == my - 1)
						stuck++;
					
					mcx = mx;
	          	  	mcy = my;
					my--;
		    		break;
		    	case 3: // 하 						
					if(mcy == my + 1)
						stuck++;	
								
	    			mcx = mx;
	          	 	mcy = my;
					my++;	
		    		break;
		    }
		}
		
		for(b=0;b<MapSize_y;b++)
		{
			for(a=0;a<MapSize_x;a++)
			{
	//		    Mprint(a, b); //맵 프린트 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //플레이어 프린트
			}
		}
	}
	
	void Pinky_path_finder(int mode=0)   
	{
		int i, type = 0;
		int compare_pathx[4] = {0};
		int compare_pathy[4] = {0};
		int compare_result;
		int compare_resulti;
		
		a=mx, b=my;
		
		if((px == mx && py == my) || s1_active != 0)
		{ 
			mcx = mx;
			mcy = my;
			
			if(map[my][mx] == 3)
			{
			  	type=1; //코인
			}
			else if(map[my][mx] == 4)
			{
				type=2; // 아이템 
			}
			
			if(mode == 1)
			{
				color = GRAY;
			}
		}
		else
		{
		if(stuck == 3)
		{
			switch(key)
			{
				case LEFT:
					if(mode == 0)
					{
						target_x = px-3;
						target_y = py;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy)) // 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				case RIGHT:
					if(mode == 0)
					{
						target_x = px+3;
						target_y = py;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy) )// 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				case UP:
					if(mode == 0)
					{
						target_x = px;
						target_y = px-3;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx) ) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy) )// 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				case DOWN:
					if(mode == 0)
					{
						target_x = px;
						target_y = py+3;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy)) // 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				}
				stuck_move++;
			
				if(stuck_move > 20)
				{
					stuck_move = 0;
					stuck = 0;
				}
			}
			else
			{
				switch(key)
				{
				case LEFT:
					if(mode == 0)
					{
						target_x = px-3;
						target_y =  py;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				case RIGHT:
					if(mode == 0)
					{
						target_x = px+3;
						target_y = py;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) -target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
				case UP:
					if(mode == 0)
					{
						target_x = px;
						target_y = py-3;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
					if(map[b][a-1] != 1) // 좌 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // 우 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // 상 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // 하 
					{	
						compare_pathx[3] = mx - target_x;
						compare_pathy[3] = (my+1) - target_y;					
					}
					else
					{
						compare_pathx[3] = 50;
						compare_pathy[3] = 50;
					}
					break;
					case DOWN:
						if(mode == 0)
					{
						target_x = px;
						target_y = py+3;
					}
					else if(mode == 1)
					{
						target_x = REAL_START_POINT_X;
						target_y = REAL_START_POINT_Y;
						color = GRAY;
					}
						if(map[b][a-1] != 1) // 좌 
						{
							compare_pathx[0] = (mx-1) - target_x;
							compare_pathy[0] = my - target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[b][a+1] != 1) // 우 
						{
							compare_pathx[1] = (mx+1) - target_x;
							compare_pathy[1] = my - target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[b-1][a] != 1) // 상 
						{
							compare_pathx[2] = mx - target_x;
							compare_pathy[2] = (my-1) - target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[b+1][a] != 1) // 하 
						{	
							compare_pathx[3] = mx - target_x;
							compare_pathy[3] = (my+1) - target_y;					
						}
						else
						{
							compare_pathx[3] = 50;
							compare_pathy[3] = 50;
						}
						break;
					}
				}
			
				compare_result = (compare_pathy[0] * compare_pathy[0] + compare_pathx[0] * compare_pathx[0]);
				compare_resulti = 0;
				
				for(i=1;i<4;i++) //총 3번만 위에서 초기화를 해주었기때문에. 
				{
					if(compare_result > (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]))
					{
						compare_result = (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]);
						compare_resulti = i;
					}
				}
	
		
		switch(compare_resulti)
		{
		    case 0: //left
		    	if(map[my][mx] == 3)
		    	{
		    		type=1; //코인
				}
		    	else if(map[my][mx] == 4)
		    	{
			        type=2; // 아이템 
				}
					
//		    	if(map[b][a-1] != 1)
//				{
						if(mcx == mx - 1)
						stuck++;
						
		    			mcx = mx;
					   	mcy = my;
						mx--;
//				}
				if(mx-1 < MapMin_x) //es
				{
			        gotoxy(mx*2, my);
					printf("  ");
					mx = MapSize_x-1;
		        }
		    	break;
		    	
		    	case 1: // 우 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
//		    		if(map[b][a+1] != 1)
//					{
						if(mcx == mx + 1)
						stuck++;
						
		    			mcx = mx;
				 	    mcy = my;
						mx++;
//					}
					if(mx+1 > MapSize_x-1) //esl
					{
		                gotoxy(mx*2, my);
						printf("  ");
						mx = MapMin_x;
		            }
		    		break;
		    	case 2: //상 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
//		    		if(map[b-1][a] != 1)
//					{
						if(mcy == my - 1)
						stuck++;
						
						mcx = mx;
		          	  	mcy = my;
						my--;
//					}
		    		break;
		    	case 3: // 하 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
//		    		if(map[b+1][a] != 1)
//					{	
						if(mcy == my + 1)
						stuck++;
										
		    			mcx = mx;
		          	 	mcy = my;
						my++;	
//					}
		    		break;
		    	}
	}
		
		for(b=0;b<MapSize_y;b++)
		{
			for(a=0;a<MapSize_x;a++)
			{
	//		    Mprint(a, b); //맵 프린트 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //플레이어 프린트
			}
		}
	}

	void Clyde_path_finder(int mode=0)
	{
		int i, type = 0;
		int compare_pathx[4] = {0};
		int compare_pathy[4] = {0};
		int isgo[4] = {0};
		int compare_result;
		int compare_resulti;
		
		a=mx, b=my;
		
		if(mode == 0)
		{
		    target_x = px;
		    target_y = py;
		}
		else if(mode == 1)
		{
			target_x = REAL_START_POINT_X;
			target_y = REAL_START_POINT_Y;
			color = GRAY;
		}		
		
		if((px == mx && py == my) || s1_active != 0)
		{
			mcx = mx;
			mcy = my;
			
			if(map[my][mx] == 3)
			{
			  	type=1; //코인
			}
			else if(map[my][mx] == 4)
			{
				type=2; // 아이템 
			}
		}
		
		else
		{
		a=mx, b=my;
		compare_pathx[0] = (mx-1) - target_x;
		compare_pathy[0] = my - target_y;
		
		compare_pathx[1] = (mx+1) - target_x;
		compare_pathy[1] = my - target_y;
		
		compare_pathx[2] = mx - target_x;
		compare_pathy[2] = (my-1) - target_y;
		
		compare_pathx[3] = mx - target_x;
		compare_pathy[3] = (my+1) - target_y;
		
		switch(stuck == 3)
        {
            case 1:            //3번 제자리걸음
                if(map[b][a-1] != 1 && ((mx-1) != mcx)) // 좌 
                {
                    isgo[0]  = 1;
                }
                else
                {
                    isgo[0]  = 0;
                }
                if(map[b][a+1] != 1 && ((mx+1) != mcx)) // 우 
                {
                    isgo[1]  = 1;
                }
                else
                {
                    isgo[1]  = 0;
                }
                if(map[b-1][a] != 1 && ((my-1) != mcy)) // 상 
                {
                    isgo[2]  = 1;
                }
                else
                {
                    isgo[2]  = 0;
                }
                if(map[b+1][a] != 1 && ((my+1) != mcy)) // 하 
                {
                    isgo[3]  = 1;
                }
                else
                {
                    isgo[3]  = 0;
                }
                stuck_move++;

                if(stuck_move>20){
                    stuck_move = 0;
                    stuck = 0;
                }
                break;
                
				default:        //일반상태
                if(map[b][a-1] != 1) // 좌 
                {
                    isgo[0]  = 1;
                }
                else
                {
                    isgo[0] = 0;
                }
                if(map[b][a+1] != 1) // 우 
                {
                    isgo[1]  = 1;
                }
                else
                {
                    isgo[1] = 0;
                }
                if(map[b-1][a] != 1) // 상 
                {
                    isgo[2]  = 1;
                }
                else
                {
                    isgo[2] = 0;
                }
                if(map[b+1][a] != 1) // 하 
                {
                    isgo[3]  = 1;
                }
                else
                {
                    isgo[3] = 0;
                }

        }
		   
			compare_resulti = 0;
		
			if( (mx-px)*(mx-px) + (my-py)*(my-py) > 64)
			{
				compare_result = 2500;
				for(i=0;i<4;i++) //총 3번만 위에서 초기화를 해주었기때문에. 
				{
					if(isgo[i] == 1)
					{
						if(compare_result > (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]))
						{
							compare_result = (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]);
							compare_resulti = i;
						}	
					}
				}
			}
			else
			{
				compare_result = 0;
				for(i=0;i<4;i++) //총 3번만 위에서 초기화를 해주었기때문에. 
				{
					if(isgo[i] == 1)
					{
						if(compare_result < (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]))
						{
							compare_result = (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]);
							compare_resulti = i;
						}
					}
				}
			}
	
		
		switch(compare_resulti)
		{
		    case 0: // 좌 
		    	if(map[my][mx] == 3)
		    	{
		    		type=1; //코인
				}
		    	else if(map[my][mx] == 4)
		    	{
			        type=2; // 아이템 
				}
									//if(map[b][a-1] != 1) 이부분 앞에서 검사하기 때문에 필요없다고 생각해서 삭제했습니다. 나중에 오류나면 다시 쓰세요. 
				if(mcx == mx - 1)
				stuck++;
				
    			mcx = mx;
			   	mcy = my;
				mx--;
									// 여기까 지	
				if(mx-1 < MapMin_x) // 여기는 else if 
				{
			        gotoxy(mx*2, my);
					printf("  ");
					mx = MapSize_x-1;
		        }
		    	break;
		    	
		    	case 1: // 우 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}
					if(mcx == mx + 1)
						stuck++;
	    			mcx = mx;
			 	    mcy = my;
					mx++;
				
					if(mx+1 > MapSize_x-1)
					{
		                gotoxy(mx*2, my);
						printf("  ");
						mx = MapMin_x;
		            }
		    		break;
		    	case 2: //상 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}
					if(mcy == my - 1)
						stuck++;
					
					mcx = mx;
	          	  	mcy = my;
					my--;
		    		break;
		    	case 3: // 하 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // 아이템 
					}				
					if(mcy == my + 1)
						stuck++;
					
	    			mcx = mx;
	          	 	mcy = my;
					my++;	
		    		break;
		    	}
		}
		
		for(b=0;b<MapSize_y;b++)
		{
			for(a=0;a<MapSize_x;a++)
			{
		//	    Mprint(a, b); //맵 프린트 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //플레이어 프린트
			}
		}
	}
	
	void TBlinky_path_finder(void)
	{
		int i, type = 0;
		int compare_pathx[4] = {0};
		int compare_resulti;
		
		a=mx, b=my;
		
		target_x = px;
		target_y = py;
		
		if((px == mx && py == my) || s1_active != 0)
		{
			;
		}
		else
		{			
			if(Tmap[b][a-1] != 1) // 좌 
			{
				compare_pathx[0] = (mx-1) - target_x;
			}
			else
			{
				compare_pathx[0] = 50;
			}
			if(Tmap[b][a+1] != 1) // 우 
			{
				compare_pathx[1] = (mx+1) - target_x;
			}
			else
			{
				compare_pathx[1] = 50;
			}
		
		   
			compare_pathx[0];
			compare_resulti = 0;
			
			if(compare_pathx[1]*compare_pathx[1] < compare_pathx[0]*compare_pathx[0])
			{
				compare_resulti = 1;
			}
	
			switch(compare_resulti)
			{
			    case 0: // 좌 
	    			mcx = mx;
				   	mcy = my;
					mx--;
			    	break;
		    	case 1: // 우 
	    			mcx = mx;
			 	    mcy = my;
					mx++;		
		    		break;
	    	}
	}
		
		for(b=0;b<TMapSize_y;b++)
		{
			for(a=0;a<TMapSize_x;a++)
			{
			 //   TMprint(a, b); //맵 프린트 
				monster_print(a, b, mx, my, mcx, mcy, 0, color); //플레이어 프린트
			}
		}
	}

	void real_start()
	{
		mx = REAL_START_POINT_X;
		my = REAL_START_POINT_Y; 
	}	
};
