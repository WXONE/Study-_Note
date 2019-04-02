#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[5] = {1,5,7,4,8};
	float b[5] = {3.14,5.32,2.5,6.3,9.0};
	long c[5] = {10120,-101023,118947,9034};
	void sort(int []);
	void sort(float []);
	void sort(long []);
	sort(a);
	sort(b);
	sort(c);
	return 0;		
}
void sort(int  a[])
{
	int i,j,min;
	int t;
	for(i = 0;i < 5;i++)
	{
		min = i;
		for(j = i+1;j<5;j++)
			if(a[min]>a[j]) min = j;
			{
				t = a[i];
				a[i] = a[min];
				a[min] = t;
			}
			
			
	}
	cout<<"sorted:"<<endl;
	for (i = 0;i < 5;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}
void sort(float a[])
{
	int i,j,min;
	float t;
	for(i = 0;i < 5;i++)
	{
		min = i;
		for(j = i+1;j<5;j++)
			if(a[min]>a[j]) min = j;
			{
				t = a[i];
				a[i] = a[min];
				a[min] = t;
			}
			
			
	}
	cout<<"sorted:"<<endl;
	for (i = 0;i < 5;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}
void sort(long a[])
{
	int i,j,min;
	long t;
	for(i = 0;i < 5;i++)
	{
		min = i;
		for(j = i+1;j<5;j++)
			if(a[min]>a[j]) min = j;
			{
				t = a[i];
				a[i] = a[min];
				a[min] = t;
			}
			
	}
	cout<<"sorted:"<<endl;

	for (i = 0;i < 5;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
}
