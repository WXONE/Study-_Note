#include<iostream>
using namespace std;
float swap(float F)
{
	float C;
	C = (F - 32) * 5 / 9.0;
	return C;
}
int main()
{
	float f,c;
	cin>>f;
	c = swap(f);
	cout<<c;
	return 0;
 } 
