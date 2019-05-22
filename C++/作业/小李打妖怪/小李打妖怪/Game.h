#include<string>
using namespace std;
class Ghost {
public :
	Ghost(int);
	void Hurt(int);
	bool IsDead();
private:
	int life;
};
class  Power
{
public:
	static string GetPowerName(int);
	static int GetPowerHurt(int);
};
class Li {
public:
	Li();
	int ChoosePower();
	bool IsBig();
private:
	int power;//level
};
class Game
{
public:
	static void Play();
};
