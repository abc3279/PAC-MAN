int Player(void)
{
//	PlaySound(TEXT("ppm.wav"), NULL, SND_ASYNC | SND_LOOP);  
	monster_init();
	drawing_guide_in_game();
    px = 12, py = 22; //플레이어 x,y 좌표
	x = px, y = py;
	  
    int msec = 0; 
    int count_tmp_sec = start_sec;
	drawing_life();
	int realstartsec = 0;

	
    for(y=0;y<MapSize_y;y++)
	{
        for(x=0;x<MapSize_x;x++)
		{
            Mprint(x, y); //맵 프린트 
			Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
        }
    } 	
		
	while(1)
	{	
		struct tm *t; time_t timer; 
		timer = time(NULL); 
		t = localtime(&timer);
		
		second = ((t->tm_sec) + (t->tm_min*60) + (t->tm_hour*3600)) - start_sec;
		
		x = px, y = py; //플레이어 위치와 맵상태 비교하기 위함(아래에서 쓰임)
			
		if(msec % 15 == 0)
		{
			drawing_skill_in_game();
			if(second - sec_tmp > 2)
			{
				if(px == Blinky.mx && py == Blinky.my)
				{
					Sleep(1500);
					ifcollider++;
					if(life <= 0)
					{
						return 0;
					}
					printf("\a");
					return Player();
					
				}
				else if(px == Pinky.mx && py == Pinky.my)
				{
					Sleep(1500);
					ifcollider++;
					if(life <= 0)
					{
						return 0;
					}
					printf("\a");
					return Player();
				
				}
				else if(px == Inky.mx && py == Inky.my)
				{
					Sleep(1500);
					ifcollider++;
					if(life <= 0)
					{
						return 0;
					}
					printf("\a");
					return Player();
					
				}
				else if(px == Clyde.mx && py == Clyde.my)
				{
					Sleep(1500);
					ifcollider++;
					if(life <= 0)
					{
						return 0;
					}
					printf("\a");
					return Player();
				}
			}
			else
			{
				if(px == Blinky.mx && py == Blinky.my)
				{
					Blinky.location_init(12, 13);
					Blinky.spawn_sec = 0;
					Blinky.iscaught = 1;
				}
				else if(px == Pinky.mx && py == Pinky.my)
				{
					Pinky.location_init(12, 15);
					Pinky.spawn_sec = 0;
					Pinky.iscaught = 1;
				}
				else if(px == Inky.mx && py == Inky.my)
				{
					Inky.location_init(16, 13);
					Inky.spawn_sec = 0;
					Inky.iscaught = 1;
				}
				else if(px == Clyde.mx && py == Clyde.my)
				{
					Clyde.location_init(16, 15);
					Clyde.spawn_sec = 0;
					Clyde.iscaught = 1;
				}
			} 
			
			if(msec == 0){
				key = RIGHT;
				pkey = key;
			}
			else	
				getkey(msec);
			
			skill(1);
			Pmove();
			
    	    for(y=0;y<MapSize_y;y++)
			{
	            for(x=0;x<MapSize_x;x++)
				{
	                Mprint(x, y); //맵 프린트 
					Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
	            }   
	        } 	//화면출력 
	        
		    monster_move(iscoin);
    		
    	if(s2_active > 0)
        { 
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
       	}
       	Sleep(SPEED);

	}
		if(second - count_tmp_sec != 0)
		{
			count_tmp_sec = second;
			realstartsec++;
			Blinky.spawn_sec++;
			Pinky.spawn_sec++;
			Inky.spawn_sec++;
			Clyde.spawn_sec++;
			s1_cd--;
			s3_cd--;
			if(s1_active > 0)
			{
				s1_active--;
			}
			if(s3_active > 0)
			{
				s3_active--;
			}
		}
		if(second % 60 == 0 && second != 0)
		{
			start_sec += 60;
			minute++;
		}
		if(minute != 0 && minute % 60 == 0)
		{
			minute -= 60;
			hour++;
		}
		
		if(second - sec_tmp == 2)
		{
			sec_tmp = 0;
			iscoin = 0;
			monster_color_init();
		}
		
		if(Blinky.iscaught == 1 && Blinky.spawn_sec == 2)
		{
			Blinky.monster_image_init();
			Blinky.real_start();
			Blinky.monster_image_init();
		}
		if(Pinky.iscaught == 1 && Pinky.spawn_sec == 2)
		{
			Pinky.monster_image_init();
			Pinky.real_start();	
			Pinky.monster_image_init();
		}
		if(Inky.iscaught == 1 && Inky.spawn_sec == 2)
		{
			Inky.monster_image_init();
			Inky.real_start();	
			Inky.monster_image_init();
		}
		if(Clyde.iscaught == 1 && Clyde.spawn_sec == 2)
		{
			Clyde.monster_image_init();
			Clyde.real_start();	
			Clyde.monster_image_init();
		}
		
		drawing_play_time();   //플레이 타임 표시 
		
		
		if(realstartsec == 2)
		{
			Blinky.monster_image_init();
			Blinky.real_start();
			Blinky.monster_image_init();
		}
		else if(realstartsec == 4)
		{
			Pinky.monster_image_init();
			Pinky.real_start();	
			Pinky.monster_image_init();
		}
		else if(realstartsec == 6)
		{
			Inky.monster_image_init();
			Inky.real_start();
			Inky.monster_image_init();
		}
		else if(realstartsec == 8)
		{
			Clyde.monster_image_init();
			Clyde.real_start();
			Clyde.monster_image_init();
		}

        msec++;
        
   		if(player_count_coin == count_coin)
   		{
   	     	return 1; //게임 승리 
		}
	}
}

void Pmove(void)
{
	x = px;
	y = py;
	
	switch(lkey)
	{
		case LEFT:
			if(map[y][x-1] != 1)
			{ // 좌
				key = lkey; 
		        pcx = px;
		        pcy = py;
				px--;
				
            	if(map[y][x-1] == 3)
				{
            		map[y][x-1] = 0;
            		player_count_coin++;
          		  	drawing_score();
            	}
            	else if(map[y][x-1] == 4)
            	{
            		iscoin = 1;
            		sec_tmp = second;
            		map[y][x-1] = 0;
            	}
            	return ;
			}
            else if(px-1 < MapMin_x)
			{
	            gotoxy(px*2,py);
                printf("  ");
			    px = MapSize_x-1;
      	    }
          	else
			{
				key = pkey;
			}
            break;
	
	    case RIGHT:
            if(map[y][x+1] != 1)
            { //우 
        		key = lkey; 
                pcx = px;
                pcy = py;
				px++;
            	if(map[y][x+1] == 3)
				{
                	map[y][x+1] = 0;
                	player_count_coin++;
                    drawing_score();	
            	}
            	else if(map[y][x+1] == 4)
            	{
            		iscoin = 1;
            		sec_tmp = second;
            		map[y][x+1] = 0;
                }
                
                return ;
			}
            else if(px+1 > MapSize_x-1)
			{
	            gotoxy(px*2,py);
				printf("  ");
				px = MapMin_x;
        	}
        	else
			{
				key = pkey;
			}

            break;
	
        case UP:
            if(map[y-1][x] != 1)
			{ //상 
	    		key = lkey; 
	            pcx = px;
	            pcy = py;
				py--;
            	if(map[y-1][x] == 3)
				{
	            	map[y-1][x] = 0;
	            	player_count_coin++;
	            	drawing_score();                	
            	}
            	else if(map[y-1][x] == 4)
            	{
            		iscoin = 1;
            		sec_tmp = second;
            		map[y-1][x] = 0;
           		}
	            return;
    		}
	            else
				{
					key = pkey;
				}
	            break;

        case DOWN:
			if(map[y+1][x] != 1)
			{ //하 
	    		key = lkey; 
	            pcx = px;
	            pcy = py;
				py++;
	        	if(map[y+1][x] == 3)
				{
	        		map[y+1][x] = 0;
	  	   	  		player_count_coin++;
	   	    	 	drawing_score();
	        	}
	        	else if(map[y+1][x] == 4)
	        	{
	        		map[y+1][x] = 0;
	        		sec_tmp = second;
	        		iscoin = 1;
	      	 	}
	      	 	
	      	 	return ;
	        }
	        else
			{
				key = pkey;
			}
        
        break;
    }

	switch(key)
	{
    	case LEFT:
			if(map[y][x-1] != 1)
			{ // 좌 
	            pcx = px;
	            pcy = py;
				px--;
	        	if(map[y][x-1] == 3)
				{
	        		map[y][x-1] = 0;
	        		player_count_coin++;
	      		  	drawing_score();
	        	}
	        	else if(map[y][x-1] == 4)
	        	{
	        		iscoin = 1;
	        		sec_tmp = second;
	        		map[y][x-1] = 0;
	        	}
	        	
	        	return ;
	        }
	        else if(px-1 < MapMin_x)
			{
	            gotoxy(px*2,py);
				printf("  ");
				px = MapSize_x-1;
	    	}

            break;

        case RIGHT:
            if(map[y][x+1] != 1)
            { //우 
                pcx = px;
                pcy = py;
				px++;
            	if(map[y][x+1] == 3)
				{
	            	map[y][x+1] = 0;
	            	player_count_coin++;
	                drawing_score();	
            	}
            	else if(map[y][x+1] == 4)
            	{
            		map[y][x+1] = 0;
            		sec_tmp = second;
        	    	iscoin = 1;
				}
				
				return ;
            } 
            else if(px+1 > MapSize_x-1)
			{
                gotoxy(px*2,py);
				printf("  ");
				px = MapMin_x;
        	}
            break;

        case UP:
            if(map[y-1][x] != 1)
			{ //상 
                pcx = px;
                pcy = py;
				py--;
            	if(map[y-1][x] == 3){
	            	map[y-1][x] = 0;
	            	player_count_coin++;
	            	drawing_score();                	
            	}
            	else if(map[y-1][x] == 4)
            	{
            		map[y-1][x] = 0;
            		sec_tmp = second;
            		iscoin = 1;
				}	
				
				return ;
			} 

                break;

        case DOWN:
            if(map[y+1][x] != 1)
            { //하 
                pcx = px;
                pcy = py;
				py++;
            	if(map[y+1][x] == 3)
				{
	            	map[y+1][x] = 0;
	            	player_count_coin++;
	            	drawing_score();
            	}
            	else if(map[y+1][x] == 4)
            	{
            		map[y+1][x] = 0;
            		sec_tmp = second;
        			iscoin = 1;
			    }
			    
			    return ;
            }
                
            break;
	    }
}

void Pprint(int x, int y, int px, int py, int pcx, int pcy)
{
 	if(y==py && x==px)
	{
		gotoxy(pcx*2,pcy);
		printf("  "); //이전 모습 지우기 
		
		gotoxy(px*2,py);	
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
		printf("●");
	}
}

