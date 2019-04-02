#include<iostream>
using namespace std;
class Shangpin{
	public:
		Shangpin(int n,int q,float p):num(n),quantity(q),price(p){};
		void total();
		static float ave();
		static void display();
	private:
		int num;
		int quantity;
		float price;
		static float discount;
		static float sum;
		static int n;
};
void Shangpin::total()
{
	float rate = 1.0;
	if (quantity > 10) rate = 0.98*rate;
	sum = sum+quantity*price*(discount);
	n = n + quantity;
	
}
void Shangpin::display()
{
	cout<<sum<<endl;
	cout<<ave()<<endl;
}
float Shangpin::ave()
{
	return (sum/n);
}
float Shangpin::discount = 0.95;
float Shangpin::sum = 0;
int Shangpin::n = 0;
int main()
{
	Shangpin sha[3] = {Shangpin(101,5,23.5),Shangpin(102,12,24.56),Shangpin(103,100,21.5)};
	for(int i = 0;i < 3;i++)
	{
		sha[i].total();
		Shangpin::display();
		return 0;
	}
}
