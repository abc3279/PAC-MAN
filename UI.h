#define SST 0.5 //Origin 15
#define LST 0.5 //Origin 30

int count_coin = 239;
int player_count_coin = 0;
int TF;   
int ifcollider=0;
int life = 3;
unsigned int hour=0, minute=0, second=0;
unsigned int start_sec=0;

void set_console_title(void)
{
	SetConsoleTitle("PAC-MAN");
}

void end_start_UI(void) //�����Ҷ� UI ���� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
	system("cls");
	return ;
}

void drawing_square(void) // �簢�� �����. 
{
	    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
		int i;
		gotoxy(0, 0);
		printf("��") ;
		Sleep(SST);
		for(i=0;i<117;i++)
		{
			printf("��");
			Sleep(SST);
		}
		printf("�� "); 
		Sleep(SST);
		for(i=0;i<28;i++)
		{
			printf("��\n");
			Sleep(LST);
		}
		printf("��");
		Sleep(SST);
		for(i=0;i<117;i++)
		{
			printf("��");
			Sleep(LST);
		}
		printf("��") ;
		Sleep(SST);
		gotoxy(117, 1);
		for(i=0;i<28;i++)
		{
			gotoxy(118, i+1);
			printf("��");
			Sleep(LST);
		}
}

void drawing_pacman(void) //�Ѹ�. ���� �׸��� �� �� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6); //����� ���� 
	gotoxy(6, 3);
	printf(" �����        ��           �����                 ���          ���         ��        ���          ��");
	gotoxy(6, 4);
	printf("��       ��    ��  ��        ��                        �� ��        �� ��       ��  ��      �� ��         ��");
	gotoxy(6, 5);
	printf("��       ��   ��    ��      ��                         �� ��        �� ��      ��    ��     ��  ��        ��");
	gotoxy(6, 6);
	printf("��      ��    ��    ��     ��                          ��  ��      ��  ��      ��    ��     ��   ��       ��");
	gotoxy(6, 7);
	printf("��     ��     ��    ��    ��                           ��   ��    ��   ��      ��    ��     ��    ��      ��");
	gotoxy(6, 8);
	printf("�����      �����    ��            ������     ��   ��    ��   ��      �����     ��     ��     ��"); 
	gotoxy(6, 9);
	printf("��           ��      ��   ��                           ��    ��  ��    ��     ��      ��    ��      ��    ��");
	gotoxy(6, 10);
	printf("��          ��        ��   ��                          ��     ���     ��    ��        ��   ��       ��   ��");
	gotoxy(6, 11);
	printf("��          ��        ��    ��                         ��      ��      ��    ��        ��   ��        ��  ��");
	gotoxy(6, 12);
	printf("��         ��          ��    ��                        ��              ��   ��          ��  ��         �� ��");
	gotoxy(6, 13);
	printf("��         ��          ��     �����                 ��              ��   ��          ��  ��          ���");
} 

int select_choice(void) // ���ӽ���, �ҷ�����, ���� ���� �˰��� �Լ� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	gotoxy(48, 18);
	int select = 1;
	int i=1;
	while(i)
	{
		char c = getch();
		if(c==32) //�����̽�
		{
			i=0;
			
		}
		else if(c==72) // ������Ű
		{
			if(select == 1)
			{
				;
			}
			else if(select>1 && select<=3)
			{
				printf("\b\b  ");
				select--;
				if(select == 1)
				{
					gotoxy(46, 18);
					printf("��");
				}
				else if(select == 2)
				{
					gotoxy(46, 20);
					printf("��");
				}
			}
		}
		else if(c==80) //�Ʒ� ����Ű
		{
			if(select == 3)
			{
				;
			}
			else if(select<3 && select>=1)
			{
				printf("\b\b  ");
				select++;
				if(select == 2)
				{
					gotoxy(46, 20);
					printf("��");
				}
				else if(select == 3)
				{
					gotoxy(46, 22);
					printf("��");
				}
			}	
		} 
	}
	switch(select)
	{
		case 1: // ���ӽ����� �����Ͽ����� 
			return 1;
			break;
		case 2: // skill training�� �����Ͽ����� 
			return 2;
			break;
		case 3: // ���� ���Ḧ �����Ͽ����� 
			end_start_UI();
			exit(1);
			break;
	}
}

void drawing_select(void) // ���ӽ���, �ҷ�����, ���� �׸��� �Լ� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	gotoxy(48, 18);
	printf("1. ���ӽ���");
	gotoxy(48, 20);
	printf("2. ��ų �׽�Ʈ");
	gotoxy(48, 22);
	printf("3. ���� ����");
	gotoxy(46, 18);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("��");
}

void drawing_guide(void) // ���۹� �׸��� �Լ� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
	gotoxy(88, 17);
	printf("���۹�");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
	gotoxy(80, 19);
	printf("��: ���� �������� �̵�");
	gotoxy(80, 21);
	printf("��: ���� �������� �̵�");
	gotoxy(80, 23);
	printf("SPACE : ���� ");
}

void drawing_guide_square(void) //���۹� �׵θ� �׸��� �Լ� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	int i;
	gotoxy(78, 17);
	printf("��");
	Sleep(SST);
	for(i=0;i<10;i++) //�� ���� �� 
	{
		printf("��");
		Sleep(SST);
	}
	gotoxy(92, 17);
	for(i=0;i<10;i++) //�� ���� �� 
	{
		printf("��");
		Sleep(SST);
	}
	printf("�� ");
	gotoxy(78, 24);
	printf("�� ");
	for(i=0;i<22;i++) //�Ʒ� ���� 
	{
		printf("��");
		Sleep(SST);
	}
	printf("�� ");
	gotoxy(78, 18);
	for(i=0;i<7;i++) // ��  �� 
	{
		printf("�� ");
		gotoxy(78, 18+i);
		Sleep(LST);
	}
	gotoxy(102, 18);
	for(i=0;i<7;i++) // ��  �� 
	{
		printf("�� ");
		gotoxy(102, 18+i);	
		Sleep(LST);
	}
}

void drawing_loading_pacman(void) //�ε�â�� pacman ������ �׸��� 
{
	system("cls");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	gotoxy(45, 5);
	printf("    ����������");
	gotoxy(45, 6);	
	printf("  ������������");	
	gotoxy(45, 7);	
	printf("�������  �����");	
	gotoxy(45, 8);
	printf("�����������");
	gotoxy(45, 9);	
	printf("����������");
	gotoxy(45, 10);	
	printf("���������");
	gotoxy(45, 11);	
	printf("��������");
	gotoxy(45, 12);	
	printf("���������");
	gotoxy(45, 13);		
	printf("����������");
	gotoxy(45, 14);	
	printf("�����������");
	gotoxy(45, 15);	
	printf("������������");		
	gotoxy(45, 16);	
	printf("  ������������");
	gotoxy(45, 17);	
	printf("    ����������");					
} 

void drawing_loading() // �ε� ǥ �� 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	srand(time(NULL));
	int i;
	gotoxy(38, 20);
	printf("Loading.."); 
	gotoxy(38, 21);
	for(i=0;i<20;i++)
	printf("��");
	i=0;
	while(i<40)
	{
		Sleep(rand() % 300);
		if(i==0)
		{
			gotoxy(38, 21);
			printf("��");
		}
		gotoxy(38+(i=i+2), 21);
		printf("��");
	} 
}

void drawing_life()
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	gotoxy(60, 16);
	
	if(ifcollider > 0)
	{
		int i;
		life = 2;
		for(i=0;i<ifcollider;i++)
		{
			printf("��"); 
			life--;
		}
	}
	else
	{
		printf("������");	
	}
}

void drawing_play_time(void)
{	 	
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	gotoxy(60, 15);
	printf("%02d�ð� : %02d�� : %02d��", hour, minute, second);
} 

void drawing_score(void)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	gotoxy(60, 14);
	int i;
	printf("%d ��/ %d ��", player_count_coin*100, count_coin*100); 
}

int colori=9;

void drawing_skill_in_game(void)
{	
	if(s1_cd > 0)
		colori = 8;
	else if(s1_cd <= 0)
		colori = 15; // white	
	
	if(s1_DNA == 0)
		colori = 8;
			
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(76, 1);
	printf("������������������");
	gotoxy(76, 2);
	printf("�� ���᦭") ;
	gotoxy(76, 3);
	printf("��   ��  ��") ;
	gotoxy(76, 4);
	printf("��   ��  ��") ;
	gotoxy(76, 5);
	printf("������������������");
	gotoxy(78, 4);
	printf("%d", s1_DNA);
	gotoxy(79, 6);
	printf("Time!");
	
	
	if(s2_active > -1)
		colori = 8;
	else if(s2_active == -1)
		colori = 15; // white
		
	if(s2_DNA == 0)
		colori = 8;
			
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(87, 1);
	printf("������������������");
	gotoxy(87, 2);
	printf("��   ��   ��") ;
	gotoxy(87, 3);
	printf("�� �� ���� ��") ; 
	gotoxy(87, 4);
	printf("��   ��   ��") ;
	gotoxy(87, 5);
	printf("������������������");
	gotoxy(89, 4);
	printf("%d", s2_DNA);
	gotoxy(89, 6);
	printf("Arrow");
	
	
	if(s3_cd > 0)
		colori = 8;
	else if(s3_cd <= 0)
		colori = 15; // white
		
	if(s3_DNA == 0)
		colori = 8;
		
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(98, 1);
	printf("������������������");
	gotoxy(98, 2);
	printf("�� ��    ��");
	gotoxy(98, 3);
	printf("��   ��  ��");
	gotoxy(98, 4);
	printf("��     �ܦ�");
	gotoxy(98, 5);
	printf("������������������");
	gotoxy(100, 4);
	printf("%d", s3_DNA);
	gotoxy(97, 6);
	printf("Teleportation"); 
}

void Tdrawing_skill_in_game(void)
{
	if(s1_cd > 0)
		colori = 8;
	else if(s1_cd <= 0)
		colori = 15; // white	
		
	if(s1_DNA == 0)
		colori = 8;
			
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(35, 3);
	printf("������������������");
	gotoxy(35, 4);
	printf("�� ���᦭") ;
	gotoxy(35, 5);
	printf("��   ��  ��") ;
	gotoxy(35, 6);
	printf("��   ��  ��") ;
	gotoxy(35, 7);
	printf("������������������") ;
	gotoxy(37, 6);
	printf("%d", s1_DNA);
	gotoxy(38, 8);
	printf("Time!");
	
	
	if(s2_active > -1)
		colori = 8;
	else if(s2_active == -1)
		colori = 15; // white	
		
	if(s2_DNA == 0)
		colori = 8;
		
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(55, 3);
	printf("������������������");
	gotoxy(55, 4);
	printf("��   ��   ��") ;
	gotoxy(55, 5);
	printf("�� �� ���� ��") ; 
	gotoxy(55, 6);
	printf("��   ��   ��") ;
	gotoxy(55, 7);
	printf("������������������") ;
	gotoxy(57, 6);
	printf("%d", s2_DNA);
	gotoxy(57, 8);
	printf("Arrow");
	
	
	if(s3_cd > 0)
		colori = 8;
	else if(s3_cd <= 0)
		colori = 15; // white
		
	if(s3_DNA == 0)
		colori = 8;
		
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colori);
	gotoxy(75, 3);
	printf("������������������");
	gotoxy(75, 4);
	printf("�� ��    ��");
	gotoxy(75, 5);
	printf("��   ��  ��");
	gotoxy(75, 6);
	printf("��     �ܦ�");
	gotoxy(75, 7);
	printf("������������������");
	gotoxy(77, 6);
	printf("%d", s3_DNA);
	gotoxy(74, 8);
	printf("Teleportation"); 
}

void Tdrawing_skill_guide_in_game(void)
{	
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
	gotoxy(35, 2);
	printf("Skill");

	gotoxy(35, 18);
	printf("��ų ����");
	
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	gotoxy(35, 19);
	printf("Time!(a) : ������ �ൿ�� 2�ʰ� ����ϴ�.");
	gotoxy(35, 21);
	printf("Arrow(s) : �÷��̾��� ����������� ��ô���� �߻��մϴ�.");
	gotoxy(46, 22);
	printf("��ô���� ���� ���� ������ҷ� ���ư��ϴ�.");
	gotoxy(35, 24);
	printf("Teleportation(d) : ���� �߽��� �߽������� �÷��̾ ��Ī��ŵ�ϴ�.");
}

void drawing_guide_in_game(void)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	gotoxy(60, 0);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
	printf("Object Guide");
	gotoxy(90, 0); 
	printf("Skill"); 
	gotoxy(60, 1);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	printf("��");
	printf(" : �÷��̾�"); 
	gotoxy(60, 2);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9);
	printf("��");
	printf(" : ��");	
	gotoxy(60, 3);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("��"); 
	printf(" : ����");
	gotoxy(60, 4);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	printf("��");
	printf(" : ������");
	gotoxy(60, 5);
	printf("��");
	printf(" : ����");
	gotoxy(60, 7);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
	printf("Player Control");
	gotoxy(60, 8);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	printf("��");
	printf(" : ��");
	gotoxy(60, 9); 
	printf("��");
	printf(" : �Ʒ�");
	gotoxy(60, 10);
	printf("��");
	printf(" : ������");
	gotoxy(60, 11);
	printf("��");
	printf(" : ����");
	gotoxy(60, 13);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
	printf("Playing State");
	gotoxy(60, 18);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),10);
	printf("Tip.");
	gotoxy(60, 19);
	printf("1. ������ ���� ���Ͱ� �����ð����� �־�����");
	gotoxy(60, 20);
	printf("   �̶� ���Ϳ� ���˽� ���� ������ ��ҷ� �̵���Ŵ.");
	gotoxy(60, 22);
	printf("2. �ո� ���� ����ϸ� �ݴ��� �ո� ������ �̵�����.");
	gotoxy(60, 24);
	printf("3. ����Object �ϳ��� 100���� ���� �� ������");
	gotoxy(60, 25);
	printf("   23900���� ������ ������ �����.");
	gotoxy(60, 27);
	printf("4. �����ϰ� ������ ������ �ϳ� �������");
	gotoxy(60, 28);	
	printf("   3���� ������ ������� ������ �����.");
}

int start_drawingUI(void) // ���α׷��� �����Ͽ����� �׸��� UI �Լ����� ����./ �ѹ��� �Լ��������� ���� UI ǥ �� 
{
	system("cls");
	cursor_view();
	set_console_title();
	drawing_square();
	drawing_pacman();
	drawing_select();
	drawing_guide_square();
	drawing_guide();
	int choice = select_choice();
	drawing_loading_pacman();
	drawing_loading();
	end_start_UI();
	
	struct tm *t; time_t timer; 
	timer = time(NULL); 
	t = localtime(&timer);
	
	start_sec = (t->tm_sec) + (t->tm_min*60) + (t->tm_hour*3600);
	
	return choice;
}

void end_drawingUI(void)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	system("cls");
	gotoxy(50, 10);
	if(TF == 0) // ���� ����
	{
		printf("GAMEOVER \n "); //���ӿ��� ��Ʈ��� ������. 
		system("pause");	
	} 
	else if(TF == 1)// ���� �¸�
	{
		printf("VICTORY \n"); //���ӽ¸� ��Ʈ��� ������. 
		system("pause");
	} 
}
