////1.9
//#include<iostream>
//using namespace std;
//int main()
//{
//	void sort(int &,int &,int &);
//	int a,b,c,a1,b1,c1;
//	cin>>a>>b>>c;
//	a1 = a;
//	b1 = b;
//	c1 = c;
//	sort(a1,b1,c1);
//	cout<<a<<" "<<b<<" "<<c<<" ";
//	cout<<a1<<" "<<b1<<" "<<c1<<endl;
//	return 0;
//	
//	
// }
//void sort(int &x,int &y,int &z )
//{
//	void change(int &,int &);
//	if(x>y)change(x,y);
//	if(x>z)change(x,z);
//	if(y>z)change(y,z);
//	
// } 
//void change(int &i,int &j)
//{
//	
//	int temp;
//	temp = i;
//	i = j;
//	i = temp;
//}
#include <iostream> 
using namespace std; 
int main() 
{
	void sort(int &,int &,int &); 
	int a,b,c,a1,b1,c1; 
	cout<<"Please enter 3 integers:"; 
	cin>>a>>b>>c; 
	a1=a;b1=b;c1=c; 
	sort(a1,b1,c1); 
	cout<<a<<" "<<b<<" "<<c<<" in sorted order is "; 
	cout<<a1<<" "<<b1<<" "<<c1<<endl; 
	return 0; 
} 
void sort(int &i,int &j,int &k) 
{ 	void change(int &,int &); 
	if (i>j) change(i,j); 
	if (i>k) change(i,k); 
	if (j>k) change(j,k); 
} 
void change(int &x,int &y) 
{	int temp; 
	temp=x; 
	x=y; 
	y=temp; 
}
