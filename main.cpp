#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include "based_func.h"
#include "map.h"
#include "player_data.h"
#include "skill_data.h"
#include "UI.h"
#include "monster_data.h"
#include "monster.h"
#include "skill.h"
#include "player.h" 

void skill_training(void); // skill training.h 를 밑에 둬서 놨어용 

int main(void)
{
	if(start_drawingUI() == 1)
		TF = Player();
	else
	skill_training();
	end_drawingUI();
	exit(1); // 재귀함수 하고 돌아갈때 문제생겨서 재귀함수에서 호출한 main 에서 프로그램 자체를 끝낼 수 있도록 해놨습니다. 
	return 0;
}

#include "skill_training.h"

