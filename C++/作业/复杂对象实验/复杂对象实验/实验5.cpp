#include<iostream>
#include<string.>
#include"TDate.h"
using namespace std;
class Pepple {
public:
	Pepple(const char*pName, char*pAddress, int Height, int y, int m, int d) :birthday(y, m, d) {
		height = Height;
		name = new char[strlen(pName) + 1];
		strcpy(name, pName);
		name[strlen(pName)] = '\0';
		address = new char[strlen(pAddress) + 1];
		strcpy(address, pAddress);
		address[strlen(pAddress)] = '\0';
	}
	~Pepple()
	{
		delete[]name;
		delete[]address;
	}
	void SetAddress(const char * pAddress) {
		delete[]address;
		address = new char[strlen(pAddress) + 1];
		strcpy(address, pAddress);
		address[strlen(pAddress)] = '\0';
	}
	void print() {
		cout << "����:" << endl;
		cout << "���:" << endl;
		cout << "��������:" << endl;
		birthday.Show();

	}
private :
	char* name;
	char* address;
	int height;
	TDate birthday;
};

int main() {
	Pepple ren("����", "�б���ѧ10��¥", 20, 1999, 4, 8);

	ren.SetAddress("�б���ѧ20��¥");

	ren.print();

	return 0;

}

