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
		cout << "Ð¡Æû³µà½à½à½È¥" << endl;
		p.Destination();
	}
};

class Train :public Vehicle {
public:
	void tools(Place p) {
		cout << "Ð¡»ð³µ¹ä³Ô¹ä³ÔÅÜÈ¥" << endl;
		p.Destination();
	}
};
class Plane :public Vehicle {
public:
	void tools(Place p) {
		cout << "Ð¡·É»úºäÂ¡Â¡·ÉÈ¥" << endl;
		p.Destination();
	}
};
class Broom : public Vehicle {
public:
	void tools(Place p) {
		cout << "É¨ÖãÎØÎØÎØ·ÉÈ¥";
		p.Destination();
	}
};
class Person {
public:
	Person(string n) :name(n) {}
	void Drive(Vehicle *v, Place p) {
		cout << name << "³Ë";
		v->tools(p);
	}
private:
	string name;
};
