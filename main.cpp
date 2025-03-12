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

void skill_training(void); // skill training.h �� �ؿ� �ּ� ����� 

int main(void)
{
	if(start_drawingUI() == 1)
		TF = Player();
	else
	skill_training();
	end_drawingUI();
	exit(1); // ����Լ� �ϰ� ���ư��� �������ܼ� ����Լ����� ȣ���� main ���� ���α׷� ��ü�� ���� �� �ֵ��� �س����ϴ�. 
	return 0;
}

#include "skill_training.h"