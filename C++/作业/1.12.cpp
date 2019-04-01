#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i;
	string s1[5] = {"c++ teacher is so handsome","Pxxxhub","c++","artist","deep dark fantastic"};
	void sort(string []);
	sort(s1);
	for(i = 0;i < 5;i++)
	{
		cout<<s[i]<<""<<endl;
		
	}
	return 0;
	
	
}
void sort(string s[])
{
	int i,j;
	string t;
	for (i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			if(s[i]>s[i+1])
			{
				t = s[i];
				s[i] = s[i+1];
				s[i+1] = t; 
			}
}
