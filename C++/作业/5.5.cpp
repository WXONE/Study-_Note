#include<iostream>
using namespace std;
class A{			//A Ϊ����

	public :
		void f1();
		int i;
	protected:
		void f2();
		int j;
	private:
		int k;	
}; 
class B :public A		//B Ϊ A �Ĺ���������
{
	public:
		void f3();
	private:
		int m;
	protected:
		int n;
		
};
class C:public B			//C Ϊ B�Ĺ��������� 
{
	public:
		void f4();
	private:
		int p;
			
};
int main()
{
	A a1;		//a1 �ǻ��� A �Ķ��� 
	B b1;		//b1 �������� B �Ķ��� 
	C c1;	
	cout<<b1.i<<;
	
}
/*
��1��������b1.i,������b1.j  b1.k��ΪjΪ������Ա��
     kΪ˽�г�Ա����Ȼ���̳��ˣ������ܹ�����. 
 (2) �����ԣ���B�����棬A���˽�г�Ա�����Ը�B�ĳ�Ա����ʹ�ã���Ϊ�����̳��˹���
 (3) ��˽�еĿ������ã����Կ������� i ��j 
 (4) c1.i���ԣ����������У��ο�(1) 
 (5) ���Ե������й��г�Ա������c1.f2()������ 
 (6) ��˽�еĶ����� 
*/

