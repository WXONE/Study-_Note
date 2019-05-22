#include "Game.h"
#include "string.h"
#include <time.h>
#include<iostream>
using namespace std;
Ghost::Ghost(int life) {
	this->life = life;
}
void Ghost::Hurt(int life) {
	this->life -= life;
}
bool Ghost::IsDead() {
	return (life <= 0);
}
string Power::GetPowerName(int which) {
	string name;
	if (which == 1)
	{
		name = "木剑";
	}
	else if (which == 2)
	{
		name = "铁剑";
	}
	else if (which == 3)
	{
		name = "魔剑";
	}

	return name;
}
int Power::GetPowerHurt(int which) {
	int hurt = 0;
	if (which  == 1)
	{
		hurt = 20;
	}
	else if (which == 2)
	{
		hurt = 50;
	}
	else  if (which == 3)
	{
		hurt = 100;
	}
	return hurt;
}
Li::Li() {
	srand((unsigned int)time(0));
}
int Li::ChoosePower() {
	power = rand() % 3 + 1;
	return power;
}
bool Li::IsBig() {
	return (rand() % 2 == 1);
}
void Game::Play() {
	Li xiaoli;
	Ghost ghost(1000);
	int hurt, which;
	cout << "游戏开始！" << endl;
	while (!ghost.IsDead())
	{
		which = xiaoli.ChoosePower();
		hurt = Power::GetPowerHurt(which);
		if (xiaoli.IsBig())
		{
			cout << "李哥打出致命一击,效果拔群！！" << endl;
			hurt = hurt * 2;
		}
		ghost.Hurt(hurt);
		cout << Power::GetPowerName(which) << "," << hurt << "!" << endl;
	}
	cout << "小李把妖怪打死啦！" << endl;
}
int main() {
	Game g;
	g.Play();
	getchar();
	return 0;
}