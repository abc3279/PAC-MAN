#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPEED 100

int px = 12, py = 22; //�÷��̾� x,y ��ǥ
int key, pkey, lkey; // key, pkey : ������ ���� ���� , lkey : ������ ����� �Է� ���� 
int pcx = px, pcy = py; //�÷��̾� ���� ��ǥ  
int x = px, y = py; // �� x,y ��ǥ
int iscoin=0; // 1 ���� ����, 0 ���� �ȸ���. 

int sec_tmp = 0; //�� �ӽ� ���� 


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
