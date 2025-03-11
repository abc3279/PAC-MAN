//monster.h
class monsters Blinky;
class monsters Pinky;	
class monsters Inky;
class monsters Clyde;
class monsters TBlinky; //training Blinky.

void monster_image_init(void)
{
	Blinky.monster_image_init();
	Pinky.monster_image_init();
	Inky.monster_image_init();
	Clyde.monster_image_init();
} 

void monster_location_init(void)
{
	Blinky.location_init(12, 13);
	Pinky.location_init(12, 15);
	Inky.location_init(16, 13);
	Clyde.location_init(16, 15);
}
	
void monster_color_init(void)
{
	Blinky.color = RED; //0
	Pinky.color = PINK; // 1
	Inky.color = BLUISH_GREEN; // 2
	Clyde.color = ORANGE; // 3 
}

void monster_stuck_init(void)
{
	Blinky.stuck = 0;
	Blinky.stuck_move = 0;
	
	Pinky.stuck = 0;
	Pinky.stuck_move = 0;
	
	Inky.stuck = 0;
	Inky.stuck_move = 0;
	
	Clyde.stuck = 0;
	Clyde.stuck_move = 0;
}

void monster_iscaught_init(void)
{
	Blinky.iscaught = 0;
	Pinky.iscaught = 0;
	Inky.iscaught = 0;
	Clyde.iscaught = 0;
}

void monster_spawn_sec_init(void)
{
	Blinky.spawn_sec = 0;
	Pinky.spawn_sec = 0;
	Inky.spawn_sec = 0;
	Clyde.spawn_sec = 0;
}

void monster_init(void)
{
	monster_image_init();
	monster_location_init();
	monster_color_init();
	monster_stuck_init();
	monster_iscaught_init();
	monster_spawn_sec_init();
}

void monster_move(int mode=0) //mode : moster class blinky 참고 
{		
	Blinky.Blinky_path_finder(mode);
	Pinky.Pinky_path_finder(mode);
	Inky_path_finder(mode);
	Clyde.Clyde_path_finder(mode);
}

void monster_print(int x, int y, int mx, int my, int mcx, int mcy, int type, int color)
{	
	if(y==my && x==mx)
	{
		if(type == 1) //코인 
		{
			gotoxy(mcx*2, mcy);
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	        printf("ㆍ"); //코인으로 표시 
		}
		else if(type == 2) // 아이템 
		{
			gotoxy(mcx*2, mcy);
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
			printf("⊙");//아이템으로 표시 
		}
		else if(type == 0)//type = 0 이전모습지우기. 
		{
			gotoxy(mcx*2, mcy);
			printf("  "); //이전 모습 지우기 
		}
		gotoxy(mx*2,my);
		switch(color)
		{
			case RED:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),4);
				break;
			case PINK:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),13);
				break;
			case BLUISH_GREEN:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
				break;
			case ORANGE:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),12);
				break;
			case GRAY:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
				break;
		}	
		printf("Ω");
	}
}

void Inky_path_finder(int mode)
{		
		int i, type = 0;
		int compare_pathx[4] = {1};
		int compare_pathy[4] = {0};
		int compare_result;
		int compare_resulti;
		
		Inky.a=Inky.mx, Inky.b=Inky.my;
		
		if((px == Inky.mx && py == Inky.my) || s1_active != 0)
		{
			Inky.mcx = Inky.mx;
	 	    Inky.mcy = Inky.my;
	 	    
			if(map[Inky.my][Inky.mx] == 3)
			{
				type=1; //코인
			}
			else if(map[Inky.my][Inky.mx] == 4)
			{
				type=2; // 아이템 
			}
				
			if(mode == 1)
			{
				Inky.color = GRAY;
			}
		}
		
		else
		{
		switch(Inky.stuck == 3)
		{	
			case 1:			//3번 제자리걸음  
				switch(key){
					case LEFT:
						if(mode == 0)
						{
						    Inky.target_x = (px-2)*2 - Blinky.mx;
						    Inky.target_y = py*2 - Blinky.my;
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						
						if(map[Inky.b][Inky.a-1] != 1 && ((Inky.mx-1) != Inky.mcx)) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[Inky.b][Inky.a+1] != 1 && ((Inky.mx+1) != Inky.mcx)) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[Inky.b-1][Inky.a] != 1 && ((Inky.my-1) != Inky.mcy)) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[Inky.b+1][Inky.a] != 1 && ((Inky.my+1) != Inky.mcy)) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;					
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
						    Inky.target_x = (px+2)*2 - Blinky.mx;
						    Inky.target_y = py*2 - Blinky.my;
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						
						if(map[Inky.b][Inky.a-1] != 1 && ((Inky.mx-1) != Inky.mcx)) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[Inky.b][Inky.a+1] != 1 && ((Inky.mx+1) != Inky.mcx)) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[Inky.b-1][Inky.a] != 1 && ((Inky.my-1) != Inky.mcy)) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[Inky.b+1][Inky.a] != 1 && ((Inky.my+1) != Inky.mcy)) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;					
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
						    Inky.target_x = px*2 - Blinky.mx;
						    Inky.target_y = (py-2)*2 - Blinky.my;
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						
						if(map[Inky.b][Inky.a-1] != 1 && ((Inky.mx-1) != Inky.mcx)) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[Inky.b][Inky.a+1] != 1 && ((Inky.mx+1) != Inky.mcx)) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[Inky.b-1][Inky.a] != 1 && ((Inky.my-1) != Inky.mcy)) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[Inky.b+1][Inky.a] != 1 && ((Inky.my+1) != Inky.mcy)) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;					
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
						    Inky.target_x = px*2 - Blinky.mx;
						    Inky.target_y = (py+2)*2 - Blinky.my;
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						
						if(map[Inky.b][Inky.a-1] != 1 && ((Inky.mx-1) != Inky.mcx)) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
						if(map[Inky.b][Inky.a+1] != 1 && ((Inky.mx+1) != Inky.mcx)) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
						if(map[Inky.b-1][Inky.a] != 1 && ((Inky.my-1) != Inky.mcy)) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
						if(map[Inky.b+1][Inky.a] != 1 && ((Inky.my+1) != Inky.mcy)) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;					
						}
						else
						{
							compare_pathx[3] = 50;
							compare_pathy[3] = 50;
						}
						break;
						
						Inky.stuck_move++;
						
						if(Inky.stuck_move>20){
							Inky.stuck_move = 0;
							Inky.stuck = 0;
						}
				}break;
			
			//////////////////////////////////////////////
			
			default : 
				switch(key){		//일반상태		
					case LEFT:
						if(mode == 0)
						{
						    Inky.target_x = ((px-2)*2 - Blinky.mx);
						    Inky.target_y = (py*2 - Blinky.my);
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						if(map[Inky.b][Inky.a-1] != 1) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;		// px+2 + -(blinky.mx - (px+2))		== -blinky.mx + 2(px + 2)
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
	
						if(map[Inky.b][Inky.a+1] != 1) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
	
						if(map[Inky.b-1][Inky.a] != 1) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
	
						if(map[Inky.b+1][Inky.a] != 1) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;		
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
						    Inky.target_x = ((px+2)*2 - Blinky.mx);
						    Inky.target_y = (py*2 - Blinky.my);
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						if(map[Inky.b][Inky.a-1] != 1) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;		// px+2 + -(blinky.mx - (px+2))		== -blinky.mx + 2(px + 2)
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
	
						if(map[Inky.b][Inky.a+1] != 1) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
	
						if(map[Inky.b-1][Inky.a] != 1) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
	
						if(map[Inky.b+1][Inky.a] != 1) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;		
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
						    Inky.target_x = (px*2 - Blinky.mx);
						    Inky.target_y = ((py-2)*2 - Blinky.my);
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						if(map[Inky.b][Inky.a-1] != 1) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;		// px+2 + -(blinky.mx - (px+2))		== -blinky.mx + 2(px + 2)
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
	
						if(map[Inky.b][Inky.a+1] != 1) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
	
						if(map[Inky.b-1][Inky.a] != 1) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
	
						if(map[Inky.b+1][Inky.a] != 1) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;		
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
						    Inky.target_x = (px*2 - Blinky.mx);
						    Inky.target_y = ((py+2)*2 - Blinky.my);
						}
						else if(mode == 1)
						{
							Inky.color = GRAY;
							Inky.target_x = REAL_START_POINT_X;
							Inky.target_y = REAL_START_POINT_Y;
						}
						if(map[Inky.b][Inky.a-1] != 1) // 좌 
						{
							compare_pathx[0] = (Inky.mx-1) - Inky.target_x;		// px+2 + -(blinky.mx - (px+2))		== -blinky.mx + 2(px + 2)
							compare_pathy[0] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[0] = 50;
							compare_pathy[0] = 50;
						}
	
						if(map[Inky.b][Inky.a+1] != 1) // 우 
						{
							compare_pathx[1] = (Inky.mx+1) - Inky.target_x;
							compare_pathy[1] = Inky.my - Inky.target_y;
						}
						else
						{
							compare_pathx[1] = 50;
							compare_pathy[1] = 50;
						}
	
						if(map[Inky.b-1][Inky.a] != 1) // 상 
						{
							compare_pathx[2] = Inky.mx - Inky.target_x;
							compare_pathy[2] = (Inky.my-1) - Inky.target_y;
						}
						else
						{
							compare_pathx[2] = 50;
							compare_pathy[2] = 50;
						}
	
						if(map[Inky.b+1][Inky.a] != 1) // 하 
						{	
							compare_pathx[3] = Inky.mx - Inky.target_x;
							compare_pathy[3] = (Inky.my+1) - Inky.target_y;		
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
		    case 0: // 좌 
		    	if(map[Inky.my][Inky.mx] == 3)
		    	{
		    		type=1; //코인
				}
		    	else if(map[Inky.my][Inky.mx] == 4)
		    	{
			        type=2; // 아이템 
				}
					
		    	if(map[Inky.b][Inky.a-1] != 1)
				{
						if(Inky.mcx == Inky.mx - 1)
						Inky.stuck++;
						
		    			Inky.mcx = Inky.mx;
					   	Inky.mcy = Inky.my;
						Inky.mx--;
				}
				else if(Inky.mx-1 < MapMin_x)
				{
			        gotoxy(Inky.mx*2, Inky.my);
					printf("  ");
					Inky.mx = MapSize_x-1;
		        }
		    	break;
		    	
		    	case 1: // 우 
		    		if(map[Inky.b][Inky.a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[Inky.b][Inky.a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
		    		if(map[Inky.b][Inky.a+1] != 1)
					{
						if(Inky.mcx == Inky.mx + 1)
						Inky.stuck++;
						
		    			Inky.mcx = Inky.mx;
				 	    Inky.mcy = Inky.my;
						Inky.mx++;
					}
					else if(Inky.mx+1 > MapSize_x-1)
					{
		                gotoxy(Inky.mx*2, Inky.my);
						printf("  ");
						Inky.mx = MapMin_x;
		            }
		    		break;
		    	case 2: //상 
		    		if(map[Inky.b][Inky.a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[Inky.b][Inky.a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
		    		if(map[Inky.b-1][Inky.a] != 1)
					{
						if(Inky.mcy == Inky.my - 1)
						Inky.stuck++;
						
						Inky.mcx = Inky.mx;
		          	  	Inky.mcy = Inky.my;
						Inky.my--;
					}
		    		break;
		    	case 3: // 하 
		    		if(map[Inky.b][Inky.a] == 3)
		    		{
		    			type=1; //코인
					}
		    		else if(map[Inky.b][Inky.a] == 4)
		    		{
			            type=2; // 아이템 
					}
					
		    		if(map[Inky.b+1][Inky.a] != 1)
					{					
						if(Inky.mcy == Inky.my + 1)
						Inky.stuck++;
						
		    			Inky.mcx = Inky.mx;
		          	 	Inky.mcy = Inky.my;
						Inky.my++;	
					}
		    		break;
		    	}
	}
		
		for(Inky.b=0;Inky.b<MapSize_y;Inky.b++)
		{
			for(Inky.a=0;Inky.a<MapSize_x;Inky.a++)
			{
			//    Mprint(Inky.a, Inky.b); //맵 프린트 
				monster_print(Inky.a, Inky.b, Inky.mx, Inky.my, Inky.mcx, Inky.mcy, type, Inky.color); //플레이어 프린트
			}
		}
	}


