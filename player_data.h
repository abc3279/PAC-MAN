#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPEED 100

int px = 12, py = 22; //플레이어 x,y 좌표
int key, pkey, lkey; // key, pkey : 마지막 진행 방향 , lkey : 마지막 사용자 입력 방향 
int pcx = px, pcy = py; //플레이어 이전 좌표  
int x = px, y = py; // 맵 x,y 좌표
int iscoin=0; // 1 코인 먹음, 0 코인 안먹음. 

int sec_tmp = 0; //초 임시 저장 


void Pprint(int, int, int, int, int, int);
void Pmove(void);

void getkey(int msec)
{
	pkey = key;

    if(kbhit() == 1)
	{
        key = getch();
        
		if(key == 224)
		{
            key = getch();
            lkey = key;
        }
        
        else
        {
        	if(msec < 136)
			{
				if(kbhit() == 1)
					key = getch();
				
				key = pkey;
			}
		} 
        
		return;

    }
    else
	{
		key = pkey;
		return ;
	}
}
