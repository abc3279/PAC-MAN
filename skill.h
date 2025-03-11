
void skill(int mod)
{
	switch(key){
		case S1:
			if(s1_cd <= 0 && s1_DNA > 0)
			{
			s1_active = 5;
			s1_cd = 15;
			s1_DNA--;
			}
			break;
			
		case S2:
			if(s2_active == -1 && s2_DNA > 0)
			{
				s2_active = 2;
	//			s2_cd = 0;
				s2_x = px;
				s2_y = py;
				s2_dir = pkey;
				s2_DNA--;
			}
			break;
			
		case S3:
			if(s3_cd <= 0 && s3_DNA > 0)
			{
			s3_active = 1;
			s3_cd = 3;
			s3_DNA--;
			}
			break;
	}
	
	key = pkey;
	
	s1(mod);
	s2(mod);
	s3(mod);
}

void s1(int mod){
	if(s1_active != 0)
	{
		//시간에따라 빼기 
	}	
}

void s2(int mod){
	
	int a = s2_x;
	int b = s2_y;
	int type = 0;
	switch(mod)
	{
		case 1: // 일반게임 
		{
			switch(s2_active)
			{
				case 2:
					switch(s2_dir)
					{
						case LEFT:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b][a-2] != 1 && map[b][a-1] != 1)
							{
								s2_cx = s2_x;
								s2_cy = s2_y;
								
								s2_x--;	
								s2_x--;	
							}
							
							else if(s2_x-2 < MapMin_x && map[b][a-1] != 1)
							{
					            gotoxy(s2_x*2,s2_y);
				                printf("  ");
							    s2_x = MapSize_x-1;
				      	    }
				          	
							else
							{
								s2_DNA++;
								s2_active = 0;
							}
							break;
						
						case RIGHT:	
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b][a+2] != 1 && map[b][a+1] != 1)
							{
								s2_cx = s2_x;
								s2_cy = s2_y;
								
								s2_x++;
								s2_x++;	
							}
								
							else if(s2_x+2 > MapSize_x-1 && map[b][a+1] != 1)
							{
					            gotoxy(s2_x*2,s2_y);
								printf("  ");
								s2_x = MapMin_x;
				        	}
				        	
							else
							{
								s2_DNA++;
								s2_active = 0;
							}
							break;
						
						case UP:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b-2][a] != 1 && map[b-1][a] != 1)
							{
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_y--;
								s2_y--;	
							}
							else
							{
								s2_DNA++;
								s2_active = 0;
							}
							break;
						
						case DOWN:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b+2][a] != 1 && map[b+1][a] != 1)
							{
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_y++;
								s2_y++;	
							}
							else
							{
								s2_DNA++;
								s2_active = 0;
							}
							break;
					}
					
					for(b=0;b<MapSize_y;b++){
						for(a=0;a<MapSize_x;a++){
							s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
						}
					}
					
					if(s2_x == Blinky.mx && s2_y == Blinky.my)
						{
							Blinky.location_init(12, 13);
							Blinky.spawn_sec = 0;
							Blinky.iscaught = 1;
						}
					else if(s2_x == Pinky.mx && s2_y == Pinky.my)
						{
							Pinky.location_init(12, 15);
							Pinky.spawn_sec = 0;
							Pinky.iscaught = 1;
						}
					else if(s2_x == Inky.mx && s2_y == Inky.my)
						{
							Inky.location_init(16, 13);
							Inky.spawn_sec = 0;
							Inky.iscaught = 1;
						}
					else if(s2_x == Clyde.mx && s2_y == Clyde.my)
						{
							Clyde.location_init(16, 15);
							Clyde.spawn_sec = 0;
							Clyde.iscaught = 1;
						}
					
					s2_active = 1;
					
					break;
				
				case 1:
				{
					switch(s2_dir)
					{
						case LEFT:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b][a-1] != 1){
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_x--;	
							}
							
							else if(s2_x-1 < MapMin_x)
							{
					            gotoxy(s2_x*2,s2_y);
				                printf("  ");
							    s2_x = MapSize_x-1;
				      	    }
				      	    
							else
							{
								s2_active = 0;
							}
							break;
						
						case RIGHT:	
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b][a+1] != 1){
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_x++;	
							}
							else if(s2_x+1 > MapSize_x-1)
							{
					            gotoxy(s2_x*2,s2_y);
								printf("  ");
								s2_x = MapMin_x;
				        	}	
							else
							{
								s2_active = 0;
							}
							break;
						
						case UP:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b-1][a] != 1){
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_y--;	
							}
							else
							{
								s2_active = 0;
							}
							break;
						
						case DOWN:
							if(map[b][a] == 3)
					    	{
					    		type=1; //코인
							}
					    	else if(map[b][a] == 4)
					    	{
						        type=2; // 아이템 
							}
							
							if(map[b+1][a] != 1){
								s2_cx = s2_x;
								s2_cy = s2_y;
							
								s2_y++;	
							}
							else
							{
								s2_active = 0;
							}
							break;
					}
					
					for(b=0;b<MapSize_y;b++){
						for(a=0;a<MapSize_x;a++){
							s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
						}
					}
					
					if(s2_x == Blinky.mx && s2_y == Blinky.my)
						{
							Blinky.location_init(12, 13);
							Blinky.spawn_sec = 0;
							Blinky.iscaught = 1;
						}
					else if(s2_x == Pinky.mx && s2_y == Pinky.my)
						{
							Pinky.location_init(12, 15);
							Pinky.spawn_sec = 0;
							Pinky.iscaught = 1;
						}
					else if(s2_x == Inky.mx && s2_y == Inky.my)
						{
							Inky.location_init(16, 13);
							Inky.spawn_sec = 0;
							Inky.iscaught = 1;
						}
					else if(s2_x == Clyde.mx && s2_y == Clyde.my)
						{
							Clyde.location_init(16, 15);
							Clyde.spawn_sec = 0;
							Clyde.iscaught = 1;
						}
				}break;
				
				case 0:
				{
					if(map[b][a] == 3)
				   	{
						type=1; //코인
					}
					else if(map[b][a] == 4)
					{
				        type=2; // 아이템 
					}
					
					s2_cx = s2_x;
					s2_cy = s2_y;
					
					for(b=0;b<MapSize_y;b++){
						for(a=0;a<MapSize_x;a++){
							s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
						}
					}
					s2_active = -1;
				}break;
			}break;
		}
			
		
		
		case 2: // 연습모드 
		{
			switch(s2_active)
			{	
			case 2:
				switch(s2_dir)
				{
					case LEFT:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b][a-2] != 1 && Tmap[b][a-1] != 1)
						{
							s2_cx = s2_x;
							s2_cy = s2_y;
							
							s2_x--;	
							s2_x--;	
						}
			          	
						else
						{
							s2_active = 0;
						}
						break;
					
					case RIGHT:	
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b][a+2] != 1 && Tmap[b][a+1] != 1)
						{
							s2_cx = s2_x;
							s2_cy = s2_y;
							
							s2_x++;
							s2_x++;	
						}
			        	
						else
						{
							s2_active = 0;
						}
						break;
					
					case UP:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b-2][a] != 1 && Tmap[b-1][a] != 1)
						{
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_y--;
							s2_y--;	
						}
						else
						{
							s2_active = 0;
						}
						break;
					
					case DOWN:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b+2][a] != 1 && Tmap[b+1][a] != 1)
						{
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_y++;
							s2_y++;	
						}
						else
						{
							s2_active = 0;
						}
						break;
				}
				
				for(b=0;b<TMapSize_y;b++){
					for(a=0;a<TMapSize_x;a++){
						s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
					}
				}
				
				if(s2_x == TBlinky.mx && s2_y == TBlinky.my)
					{
						TBlinky.location_init(50, 14);
						TBlinky.spawn_sec = 0;
						TBlinky.iscaught = 1;
					}
				
				s2_active = 1;
				
				break;
			
			case 1:
			{
				switch(s2_dir)
				{
					case LEFT:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b][a-1] != 1){
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_x--;	
						}
			      	    
						else
						{
							s2_active = 0;
						}
						break;
					
					case RIGHT:	
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b][a+1] != 1){
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_x++;	
						}
	
						else
						{
							s2_active = 0;
						}
						break;
					
					case UP:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b-1][a] != 1){
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_y--;	
						}
						else
						{
							s2_active = 0;
						}
						break;
					
					case DOWN:
						if(Tmap[b][a] == 3)
				    	{
				    		type=1; //코인
						}
				    	else if(Tmap[b][a] == 4)
				    	{
					        type=2; // 아이템 
						}
						
						if(Tmap[b+1][a] != 1){
							s2_cx = s2_x;
							s2_cy = s2_y;
						
							s2_y++;	
						}
						else
						{
							s2_active = 0;
						}
						break;
				}
				
				for(b=0;b<TMapSize_y;b++){
					for(a=0;a<TMapSize_x;a++){
						s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
					}
				}
				
				if(s2_x == TBlinky.mx && s2_y == TBlinky.my)
					{
						TBlinky.location_init(50, 14);
						TBlinky.spawn_sec = 0;
						TBlinky.iscaught = 1;
					}
			}break;
			
			case 0:
			{
				if(Tmap[b][a] == 3)
			   	{
					type=1; //코인
				}
				else if(Tmap[b][a] == 4)
				{
			        type=2; // 아이템 
				}
				
				s2_cx = s2_x;
				s2_cy = s2_y;
				
				for(b=0;b<TMapSize_y;b++){
					for(a=0;a<TMapSize_x;a++){
						s2_print(a,b,s2_x,s2_y,s2_cx,s2_cy,type,s2_dir);
					}
				}
				s2_active = -1;
				}break;
			}break;
		}
	}
}

void s2_print(int x, int y, int s_x, int s_y, int s_cx, int s_cy, int type,int s_dir){
	if(y==s_y && x==s_x)
	{

		gotoxy(s_x*2,s_y);
		
		switch(s_dir)
		{
			case LEFT:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),4);
				printf("←");
				break;
			case RIGHT:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),13);
				printf("→");
				break;
			case UP:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
				printf("↑");
				break;
			case DOWN:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),12);
				printf("↓");
				break;
		}
		
		switch(type)
		{
			case 1: //코인 
			
				gotoxy(s_cx*2, s_cy);
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
		        printf("ㆍ"); //코인으로 표시 
		        break;
			
			case 2: // 아이템 
			
				gotoxy(s_cx*2, s_cy);
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
				printf("⊙");//아이템으로 표시 
				break;
			
			case 0://type = 0 이전모습지우기. 
			
				gotoxy(s_cx*2, s_cy);
				printf("  "); //이전 모습 지우기 
				break;	
		}
	}
}

void s3(int mod){
	
	switch(mod)
	{
		case 1:
		{
			if(s3_active != 0)
			{ 
				if(-py+26>0)
				{
					if(map[-py+28][-px+27] != 1) // 원래 이동위치 
						{
							pcx = px;
							pcy = py;
							px = -px+27;
							py = -py+28;
						}
					else if(map[-py+28][-px+26] != 1) //좌 
						{
							pcx = px;
							pcy = py;
							px = -px+26;
							py = -py+28;
						}
					else if(map[-py+28][-px+28] != 1) //우 
						{
							pcx = px;
							pcy = py;
							px = -px+28;
							py = -py+28;
						}
					else if(map[-py+27][-px+27] != 1) //상 
						{
							pcx = px;
							pcy = py;
							px = -px+27;
							py = -py+27;
						}
					else if(map[-py+29][-px+27] != 1) //하 
						{
							pcx = px;
							pcy = py;
							px = -px+27;
							py = -py+29;
						}
					
					s3_active = 0;
					
					for(y=0;y<MapSize_y;y++)
					{
			            for(x=0;x<MapSize_x;x++)
						{
			                Mprint(x, y); //맵 프린트 
							Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
			            }   
			        } 	//화면출력 
			        x = px;
					y = py;
				}
				
				else
				{
					s3_cd = 0;
					s3_DNA++;
					s3_active = 0;
				}
			}
		}break;
		
		case 2:
		{
			if(s3_active != 0)
			{ 
				pcx = px;
				pcy = py;
				px = -px+59;
					
				s3_active = 0;
				
				for(y=0;y<TMapSize_y;y++)
				{
			        for(x=0;x<TMapSize_x;x++)
					{
			            TMprint(x, y); //맵 프린트 
						Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
			        }   
			    } 	//화면출력 
			    x = px;
				y = py;
			}
		}break;
	}
}
