//ʵ��1
#include <iostream>
using namespace std;
const float pi = 3.14159;
int main()
{
	int i;
	float radius,a,b,area;
	cout<<"ͼ�����ʹ������£�1.Բ��2.�����Σ�3.������";
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
			cout<<"���ڿ�ѡ��Χ�ڣ�����������"<<endl;
			
		
	 } 
	 return 0;
}
