//实验1
#include <iostream>
using namespace std;
const float pi = 3.14159;
int main()
{
	int i;
	float radius,a,b,area;
	cout<<"图形类型代码如下：1.圆，2.长方形，3.正方形";
	cin>>i;
	switch(i)
	{
		case 1:
			cout<<"enter the radius";
			cin>>radius;
			area = pi * radius * radius;
			cout<<"S = "<<area<<endl;
			break;
		case 2:
			cout<<"Enter the length of the rectangle";
			cin>>a;
			cout<<"Enter the width of the rectangle";
			cin>>b;
			area = a * b;
			cout<<"S = "<<area<<endl;
			break;
		case 3:
			cout<<"Enter the side length of the square";
			cin>>a;
			area = a * a;
			cout<<"S = "<<area<<endl;
			break;
		default:
			cout<<"不在可选择范围内，请重新输入"<<endl;
			
		
	 } 
	 return 0;
}
