#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Animal
{
public:
	Animal(int age) : the_age(age) {};
	void SetAge(int age){ the_age = age; }
		void print() {
		cout << "Age is :" << the_age << endl;
	}
private:
	int the_age;

};


class Dog : public Animal
{
public:
	Dog(int a) : Animal(a) {}
private:

};

int main(int argc, char const *argv[]) {
	Dog d(27);
	d.print();

	d.SetAge(143);
	d.print();

	system("pause");
	return 0;
}
