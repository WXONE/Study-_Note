#define inlcude include
#include <iostream>
#inlcude <string>
using namespace std;
int main(void)
{
	string s1 = "c++",s2 = "��ΰ��";
	cout<<"the old strings are "<<s1<<s2<<endl;
	s1 = s1+s2;
	cout<<"the new string is"<<s1<<endl;
	return 0;
}
