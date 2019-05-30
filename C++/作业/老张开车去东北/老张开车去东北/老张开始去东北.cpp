#include <iostream>
#include<string>
#include"calss.h"
using namespace std;

int main()
{

	Person LZ("老张");
	Place p("东北");
	Vehicle *v;
	
	v = (new Car());
	LZ.Drive(v, p);
	v = new Train();
	LZ.Drive(v, p);
	v = (new Plane());
	LZ.Drive(v, p);
	v = (new Broom());
	LZ.Drive(v, p);
	getchar();

	return 0;
}

	