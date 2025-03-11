#define REAL_START_POINT_X 14
#define REAL_START_POINT_Y 11

enum {RED, PINK, BLUISH_GREEN, ORANGE, GRAY};

void monster_print(int, int, int, int, int, int, int, int);
void Inky_path_finder(int mode=0); // �̰��ϰ� 

class monsters
{
	public:
		int mx, my; //���� x,y ��ǥ px, py ��ü�� 
		int mcx, mcy; //���� ���� ��ǥ pcx, pcy ��ü�� 
		int target_x, target_y;
		int a, b; // x, y ��ü�� 
		int color; // ���� �� 
		int iscaught;
		int spawn_sec;
		char stuck; // ���Ͱ� �����ڸ��� �ݺ��ؼ� �� Ƚ�� 
		char stuck_move;  // stuck �����϶� �۵��ϴ� �ڵ� ����Ƚ�� 
	
	void monster_image_init(void)
	{
		gotoxy(mx*2, my);
		
		if(map[my][mx] == 3)
		{
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	        printf("��"); //�������� ǥ�� 
		}
		else if(map[my][mx] == 4)
		{
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
			printf("��");//���������� ǥ�� 
		}
		else 
			printf("  "); //���� ��� ����� 
	}
	
	void location_init(int x, int y)
	{
		mx = x;
		my = y;
		
		mcx = x;
		mcy = y;
	}
	
	void Blinky_path_finder(int mode=0) //mode�� ���� ���¿� �߰ݻ��¸� ������. 0 : �߰�, 1 : ���� | �߰ݻ��¸� ǥ���Ҷ��� ���ڸ� ���൵ �ǰ�, ���ɻ��¸� ǥ���Ҷ��� �����. 
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
				  	type=1; //����
				}
			else if(map[my][mx] == 4)
				{
					type=2; // ������ 
				}
		}
		else
		{
			switch(stuck == 3)
			{	
				case 1:			//3�� ���ڸ�����  
				if(map[b][a-1] != 1 && ((mx-1) != mcx)) // �� 
				{
					compare_pathx[0] = (mx-1) - target_x;
					compare_pathy[0] = my - target_y;
				}
				else
				{
					compare_pathx[0] = 50;
					compare_pathy[0] = 50;
				}
				if(map[b][a+1] != 1 && ((mx+1) != mcx)) // �� 
				{
					compare_pathx[1] = (mx+1) - target_x;
					compare_pathy[1] = my - target_y;
				}
				else
				{
					compare_pathx[1] = 50;
					compare_pathy[1] = 50;
				}
				if(map[b-1][a] != 1 && ((my-1) != mcy)) // �� 
				{
					compare_pathx[2] = mx - target_x;
					compare_pathy[2] = (my-1) - target_y;
				}
				else
				{
					compare_pathx[2] = 50;
					compare_pathy[2] = 50;
				}
				if(map[b+1][a] != 1 && ((my+1) != mcy)) // �� 
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
				
				default : 		//�Ϲݻ���				
				if(map[b][a-1] != 1) // �� 
				{
					compare_pathx[0] = (mx-1) - target_x;
					compare_pathy[0] = my - target_y;
				}
				else
				{
					compare_pathx[0] = 50;
					compare_pathy[0] = 50;
				}
				if(map[b][a+1] != 1) // �� 
				{
					compare_pathx[1] = (mx+1) - target_x;
					compare_pathy[1] = my - target_y;
				}
				else
				{
					compare_pathx[1] = 50;
					compare_pathy[1] = 50;
				}
				if(map[b-1][a] != 1) // �� 
				{
					compare_pathx[2] = mx - target_x;
					compare_pathy[2] = (my-1) - target_y;
				}
				else
				{
					compare_pathx[2] = 50;
					compare_pathy[2] = 50;
				}
				if(map[b+1][a] != 1) // �� 
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
				
				for(i=1;i<4;i++) //�� 3���� ������ �ʱ�ȭ�� ���־��⶧����. 
				{
					if(compare_result > (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]))
					{
						compare_result = (compare_pathy[i] * compare_pathy[i] + compare_pathx[i] * compare_pathx[i]);
						compare_resulti = i;
					}
				}
				
			if(map[my][mx] == 3)
			{
			  	type=1; //����
			}
			else if(map[my][mx] == 4)
			{
				type=2; // ������ 
			}
			
			switch(compare_resulti)
			{
			    case 0: // �� 	
					if(mcx == mx - 1)
						stuck++;

	    			mcx = mx;
				   	mcy = my;
					mx--;
			    	break;   	
		    	case 1: // �� 
					if(mcx == mx + 1)
						stuck++;
				
	    			mcx = mx;
			 	    mcy = my;
					mx++;
		    		break;
		    	case 2: //�� 
					if(mcy == my - 1)
						stuck++;
					
					mcx = mx;
	          	  	mcy = my;
					my--;
		    		break;
		    	case 3: // �� 						
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
	//		    Mprint(a, b); //�� ����Ʈ 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //�÷��̾� ����Ʈ
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
			  	type=1; //����
			}
			else if(map[my][mx] == 4)
			{
				type=2; // ������ 
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
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy)) // �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // �� 
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
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy) )// �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // �� 
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
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx) ) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy) )// �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // �� 
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
					if(map[b][a-1] != 1 && (mx-1 != mcx)) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1 && (mx+1 != mcx)) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1 && (my-1 != mcy)) // �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1 && (my+1 != mcy)) // �� 
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
					if(map[b][a-1] != 1) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // �� 
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
					if(map[b][a-1] != 1) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // �� 
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
					if(map[b][a-1] != 1) // �� 
					{
						compare_pathx[0] = (mx-1) - target_x;
						compare_pathy[0] = my - target_y;
					}
					else
					{
						compare_pathx[0] = 50;
						compare_pathy[0] = 50;
					}
					if(map[b][a+1] != 1) // �� 
					{
						compare_pathx[1] = (mx+1) - target_x;
						compare_pathy[1] = my - target_y;
					}
					else
					{
						compare_pathx[1] = 50;
						compare_pathy[1] = 50;
					}
					if(map[b-1][a] != 1) // �� 
					{
						compare_pathx[2] = mx - target_x;
						compare_pathy[2] = (my-1) - target_y;
					}
					else
					{
						compare_pathx[2] = 50;
						compare_pathy[2] = 50;
					}
					if(map[b+1][a] != 1) // �� 
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
						if(map[b][a-1] != 1) // �� 
						{
							compare_pathx[0] = (mx-1) - target_x;
							compare_pathy[0] = my - target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[b][a+1] != 1) // �� 
						{
							compare_pathx[1] = (mx+1) - target_x;
							compare_pathy[1] = my - target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[b-1][a] != 1) // �� 
						{
							compare_pathx[2] = mx - target_x;
							compare_pathy[2] = (my-1) - target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[b+1][a] != 1) // �� 
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
				
				for(i=1;i<4;i++) //�� 3���� ������ �ʱ�ȭ�� ���־��⶧����. 
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
		    		type=1; //����
				}
		    	else if(map[my][mx] == 4)
		    	{
			        type=2; // ������ 
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
		    	
		    	case 1: // �� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
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
		    	case 2: //�� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
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
		    	case 3: // �� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
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
	//		    Mprint(a, b); //�� ����Ʈ 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //�÷��̾� ����Ʈ
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
			  	type=1; //����
			}
			else if(map[my][mx] == 4)
			{
				type=2; // ������ 
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
            case 1:            //3�� ���ڸ�����
                if(map[b][a-1] != 1 && ((mx-1) != mcx)) // �� 
                {
                    isgo[0]  = 1;
                }
                else
                {
                    isgo[0]  = 0;
                }
                if(map[b][a+1] != 1 && ((mx+1) != mcx)) // �� 
                {
                    isgo[1]  = 1;
                }
                else
                {
                    isgo[1]  = 0;
                }
                if(map[b-1][a] != 1 && ((my-1) != mcy)) // �� 
                {
                    isgo[2]  = 1;
                }
                else
                {
                    isgo[2]  = 0;
                }
                if(map[b+1][a] != 1 && ((my+1) != mcy)) // �� 
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
                
				default:        //�Ϲݻ���
                if(map[b][a-1] != 1) // �� 
                {
                    isgo[0]  = 1;
                }
                else
                {
                    isgo[0] = 0;
                }
                if(map[b][a+1] != 1) // �� 
                {
                    isgo[1]  = 1;
                }
                else
                {
                    isgo[1] = 0;
                }
                if(map[b-1][a] != 1) // �� 
                {
                    isgo[2]  = 1;
                }
                else
                {
                    isgo[2] = 0;
                }
                if(map[b+1][a] != 1) // �� 
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
				for(i=0;i<4;i++) //�� 3���� ������ �ʱ�ȭ�� ���־��⶧����. 
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
				for(i=0;i<4;i++) //�� 3���� ������ �ʱ�ȭ�� ���־��⶧����. 
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
		    case 0: // �� 
		    	if(map[my][mx] == 3)
		    	{
		    		type=1; //����
				}
		    	else if(map[my][mx] == 4)
		    	{
			        type=2; // ������ 
				}
									//if(map[b][a-1] != 1) �̺κ� �տ��� �˻��ϱ� ������ �ʿ���ٰ� �����ؼ� �����߽��ϴ�. ���߿� �������� �ٽ� ������. 
				if(mcx == mx - 1)
				stuck++;
				
    			mcx = mx;
			   	mcy = my;
				mx--;
									// ����� ��	
				if(mx-1 < MapMin_x) // ����� else if 
				{
			        gotoxy(mx*2, my);
					printf("  ");
					mx = MapSize_x-1;
		        }
		    	break;
		    	
		    	case 1: // �� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
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
		    	case 2: //�� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
					}
					if(mcy == my - 1)
						stuck++;
					
					mcx = mx;
	          	  	mcy = my;
					my--;
		    		break;
		    	case 3: // �� 
		    		if(map[b][a] == 3)
		    		{
		    			type=1; //����
					}
		    		else if(map[b][a] == 4)
		    		{
			            type=2; // ������ 
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
		//	    Mprint(a, b); //�� ����Ʈ 
				monster_print(a, b, mx, my, mcx, mcy, type, color); //�÷��̾� ����Ʈ
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
			if(Tmap[b][a-1] != 1) // �� 
			{
				compare_pathx[0] = (mx-1) - target_x;
			}
			else
			{
				compare_pathx[0] = 50;
			}
			if(Tmap[b][a+1] != 1) // �� 
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
			    case 0: // �� 
	    			mcx = mx;
				   	mcy = my;
					mx--;
			    	break;
		    	case 1: // �� 
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
			 //   TMprint(a, b); //�� ����Ʈ 
				monster_print(a, b, mx, my, mcx, mcy, 0, color); //�÷��̾� ����Ʈ
			}
		}
	}

	void real_start()
	{
		mx = REAL_START_POINT_X;
		my = REAL_START_POINT_Y; 
	}	
};
