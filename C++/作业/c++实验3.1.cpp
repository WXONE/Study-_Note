#include<iostream>
using namespace std;
class TDate{
	public:
		TDate()
		{
			year = 2018;month = 1;day = 1;
			cout<<"调用缺省的构造函数"<<endl;
			 
		}
		TDate(int y,int m = 1,int d = 1)
		{
			year = y;month = m;day = d;
			cout<<"调用带参数的构造函数"<<endl;
			
		}
		
		void SetDate(int y,int m,int d);
		void AddOneDay();
		void Show();
		~TDate(){cout<<"调用析构函数"<<endl; }
	private:
		int year;
		int month;
		int day;
}; 
int MonthMaxDay(int year,int month)
{
	int days;
	switch(month)
	{
		case 1:
		case 3:
		case 7:
		case 8:
		case 10:
		case 12:days = 31;break;
		case 2:if(year % 4 == 0 && year % 100 != 0||year % 400 == 0) days = 29;else days = 28;break;
		default:days = 30;break;
	}
	return days;
}
void TDate::Show()
{
	cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
	
}
void TDate::SetDate(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}
void TDate::AddOneDay()
{
	day = day + 1;
	if(day > MonthMaxDay(year,month))
	{
		month = month + 1;
		day = 1;
	}
	if(month > 12)
	{
		year = year + 1;
		month = 1;
	}
}
int main()
{
	TDate d;
	cout<<"不带参数的对象: ";
	d.Show();
	TDate d1(2019);
	cout<<"构造函数重载";
	d1.Show();
	TDate d2(2019,2,28);
	cout<<"带两个参数";
	d2.Show();
	TDate d3(2019,4,02);
	cout<<"三个参数";
	d3.Show();
	
	d3.SetDate(2019,2,28);
	cout<<"重新设置日期";
	d3.Show();
	cout<<"增加一天后";
	d3.AddOneDay();
	d3.Show();
	return 0;
}
