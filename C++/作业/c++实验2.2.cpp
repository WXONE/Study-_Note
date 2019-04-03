#include<iostream>
using namespace std;
int max1(int a = 0,int b = 0)
{
	return a>b?a:b;
 } 
int max1(int a,int b,int c)
{
	int tmp = max1(a,b);
	return tmp>c?tmp:c;
}
double max1(double a = 0,double b = 0)
{
	return a>b?a:b;
 } 
double max1(double a,double b,double c)
{
	int tmp = max1(a,b);
	return tmp>c?tmp:c;
}
int main()
{
	int n1,n2,n3;
	cout<<"please enter two :";
	cin>>n1>>n2;
	cout<<"the max is"<<max1(n1,n2)<<endl;
	cout<<"please enter three :";
	cin>>n1>>n2>>n3;
	cout<<"the max is"<<max1(n1,n2,n3)<<endl;
	double b1,b2,b3;
	cout<<"please enter two :";
	cin>>b1>>b2;
	cout<<"the max is"<<max1(b1,b2)<<endl;
	cout<<"please enter three :";
	cin>>b1>>b2>>b3;
	cout<<"the max is"<<max1(b1,b2,b3)<<endl;
	return 0;
	
}

