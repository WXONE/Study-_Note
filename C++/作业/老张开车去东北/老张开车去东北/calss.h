#include<iostream>
#include<string>
using namespace std;
class  Place
{
public:
	Place(string n) :placeName(n) {}
	void Destination() {
		cout << placeName;
	}
private:
	string placeName;
};
class  Vehicle
{
public:
	virtual void tools(Place p) {}
};


class Car :public Vehicle {
public:
	void tools(Place p) {
		cout << "С�������ȥ" << endl;
		p.Destination();
	}
};

class Train :public Vehicle {
public:
	void tools(Place p) {
		cout << "С�𳵹�Թ����ȥ" << endl;
		p.Destination();
	}
};
class Plane :public Vehicle {
public:
	void tools(Place p) {
		cout << "С�ɻ���¡¡��ȥ" << endl;
		p.Destination();
	}
};
class Broom : public Vehicle {
public:
	void tools(Place p) {
		cout << "ɨ�������ط�ȥ";
		p.Destination();
	}
};
class Person {
public:
	Person(string n) :name(n) {}
	void Drive(Vehicle *v, Place p) {
		cout << name << "��";
		v->tools(p);
	}
private:
	string name;
};
