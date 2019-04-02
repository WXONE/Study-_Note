#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s1 = "c++",s2 = "NB";
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	s1 = s1+s2;
	cout<<"the new string is "<<s1<<endl;
	return 0;
}
