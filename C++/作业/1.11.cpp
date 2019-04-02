#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1;
	int i,n;
	char temp;
	cout<<"please cout a string";
	cin>>s1;
	n = s1.size();
	for(i = 0;i<n/2;i++)
	{
		temp = s1[i];
		s1[i] = s1[n-i-1];
		s1[n-i-1] = temp;
	} 
	cout<<s1<<endl;
	return 0;
}
