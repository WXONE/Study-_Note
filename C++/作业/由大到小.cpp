#include <iostream>
using namespace std;
int main()
{
	void main(int &,int &);
	int a,b;
	cin>>a>>b;
	if(a<b) change(a,b);
	cout<<a<<b<<endl;
	return 0;
}
void change(int &x,int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
