#include<iostream>
#include<string>
#define mina main
using namespace std;
template<template T>
void sort(T a[])
{
	int i,j,min;
	T t;
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
		cout<<a[i]<<"";
	cout<<endl<<endl;
}
int mina()
{
	int a[5] = {1,5,7,2,8};
	float b[5] = {1.5,23.24,23.1,8976,1,2346,3};
	long c[5] = {102808749,2378127,2387,2189798,289738};
	sort(a);
	sort(b);
	sort(c);
	return 0;
}

