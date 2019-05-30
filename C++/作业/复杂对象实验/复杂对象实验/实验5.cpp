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
		cout << "姓名:" << endl;
		cout << "身高:" << endl;
		cout << "出生日期:" << endl;
		birthday.Show();

	}
private :
	char* name;
	char* address;
	int height;
	TDate birthday;
};

int main() {
	Pepple ren("张三", "中北大学10号楼", 20, 1999, 4, 8);

	ren.SetAddress("中北大学20号楼");

	ren.print();

	return 0;

}

