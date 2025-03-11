#define ESC 27

void TPmove(void);

//class monsters TBlinky;

//TBlinky.monster_image_init();
//TBlinky.location_init(1, 1);
//TBlinky.color = RED;	
//TBlinky.spawn_sec = 0;
//TBlinky.TBlinky_path_finder();

void skill_training(void)
{
	px = 1;
	py = 14;
	pcx = 1;
	pcy = 14;
	x = px;
	y = py;
	s1_DNA = 99;
	s2_DNA = 99;
	s3_DNA = 99;
	int msec = 0;
	int count_tmp_sec = start_sec;
	
	TBlinky.monster_image_init();	
	TBlinky.location_init(50, 14);
	TBlinky.color = RED;	
	TBlinky.spawn_sec = 0;
	
	Tdrawing_skill_guide_in_game();
	
	for(y=0;y<TMapSize_y;y++)
	{
        for(x=0;x<TMapSize_x;x++)
		{
			TMprint(x, y); //맵 프린트 
			Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
        }
    } 
    
    while(1)
    {
    	struct tm *t; time_t timer; 
		timer = time(NULL); 
		t = localtime(&timer);
		
		second = ((t->tm_sec) + (t->tm_min*60) + (t->tm_hour*3600)) - start_sec;
		
    	Tdrawing_skill_in_game();
    	
		if(px == TBlinky.mx && py == TBlinky.my)
		{
			Sleep(1500);
			printf("\a");
			return skill_training();	
		}

    	if(msec % 15 == 0)
    	{
	    	x = px, y = py;
	    	
	    	if(msec==0)
				key = RIGHT;
						
			getkey(msec);
			if(key == ESC)
			{
				s1_DNA = 3;
				s2_DNA = 3;
				s3_DNA = 3;
				main();
				return ;
			}
			
			skill(2);
			TPmove();
		
		    for(y=0;y<TMapSize_y;y++)
			{
	            for(x=0;x<TMapSize_x;x++)
				{
//	                TMprint(x, y); //맵 프린트 
					Pprint(x, y, px, py, pcx, pcy); //플레이어 프린트 
	            }   
	        } 	//화면출력 
	    	TBlinky.TBlinky_path_finder();    
	    	
	    	if(s2_active > 0)
    		{ 
	            if(s2_x == TBlinky.mx && s2_y == TBlinky.my)
	            {
	                TBlinky.location_init(50, 14);
	                TBlinky.spawn_sec = 0;
	                TBlinky.iscaught = 1;
	            }
      		}
	    	
			Sleep(50);
		}
		if(second - count_tmp_sec != 0)
		{
			count_tmp_sec = second;
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

		msec++;
	}
}

void TPmove(void)
{
	switch(lkey)
	{
		case LEFT:
			if(Tmap[y][x-1] != 1)
			{ // 좌
				key = lkey; 
		        pcx = px;
		        pcy = py;
				px--;
            	return ;
			}
          	else
			{
				key = pkey;
			}
            break;
	
	    case RIGHT:
            if(Tmap[y][x+1] != 1)
            { //우 
        		key = lkey; 
                pcx = px;
                pcy = py;
				px++;
                
                return ;
			}
        	else
			{
				key = pkey;
			}

            break;  
        break;
    }

	switch(key)
	{
    	case LEFT:
			if(Tmap[y][x-1] != 1)
			{ // 좌 
	            pcx = px;
	            pcy = py;
				px--;
	        	
	        	return ;
	        }
	        
            break;

        case RIGHT:
            if(Tmap[y][x+1] != 1)
            { //우 
                pcx = px;
                pcy = py;
				px++;
				
				return ;
            } 
            break;    
        break;
	}
}
