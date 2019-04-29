#include<iostream>
using namespace std;
class A{			//A 为基类

	public :
		void f1();
		int i;
	protected:
		void f2();
		int j;
	private:
		int k;	
}; 
class B :public A		//B 为 A 的公用派生类
{
	public:
		void f3();
	private:
		int m;
	protected:
		int n;
		
};
class C:public B			//C 为 B的公用派生类 
{
	public:
		void f4();
	private:
		int p;
			
};
int main()
{
	A a1;		//a1 是基类 A 的对象 
	B b1;		//b1 是派生类 B 的对象 
	C c1;	
	cout<<b1.i<<;
	
}
/*
（1）可以用b1.i,不可用b1.j  b1.k因为j为保护成员，
     k为私有成员，虽然被继承了，但不能够访问. 
 (2) 都可以，在B类里面，A类非私有成员都可以给B的成员函数使用，因为都被继承了过来
 (3) 非私有的可以引用，所以可以引用 i ，j 
 (4) c1.i可以，其他都不行，参考(1) 
 (5) 可以调用所有公有成员函数，c1.f2()不可以 
 (6) 非私有的都可以 
*/

