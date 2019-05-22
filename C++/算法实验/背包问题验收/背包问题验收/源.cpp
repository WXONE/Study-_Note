#include <iostream>
#include<memory>
#include<algorithm>
#include<graphics.h>
using namespace std;
const int M = 1000;
int n, key, b[1000] = { 0 };
float total;
struct node {
	int w;
	int v;
	float s;
}thing[M];
typedef struct
{
	int numerator;	//����
	int denominator;
} F;
F f1;
float Knapsack(float x[], int C)
{
	int i; int l = C, d = 0;
	float tota;
	i = 1; tota = 0;
	while (thing[i].w <= C)
	{
		x[i] = 1;
		tota += thing[i].v;
		C = C - thing[i].w;
		d = d + thing[i].w;
		b[i] = 2;
		i++;
	}
	if (d < l)
	{
		b[i] = 1;
		x[i] = C / thing[i].w;
		tota += thing[i].v*C / thing[i].w;
		f1.numerator = C;
		f1.denominator = thing[i].w;
	}
	return tota;
}
int gcd(int a, int b)
{
	int i, temp_gcd;
	for (i = a; i >= 1; i--)
	{
		if (a%i == 0)
		{
			if (b%i == 0)
			{
				temp_gcd = i;
				return temp_gcd;
			}
		}
	}
}
float comp(const node &a, const node &b)
{
	return a.s > b.s;
}
void drawbg()
{
	int j = 1;
	rectangle(0, 1, 80, 21);
	TCHAR p1[] = _T("��Ʒ");
	outtextxy(5, 4, p1);
	rectangle(0, 21, 80, 41);
	TCHAR p2[] = _T("��ֵ");
	outtextxy(5, 24, p2);
	rectangle(0, 41, 80, 61);
	TCHAR p3[] = _T("����");
	outtextxy(5, 44, p3);
	rectangle(0, 61, 80, 81);
	TCHAR p4[] = _T("��ֵ/����");
	outtextxy(5, 64, p4);
	for (int i = 2; i <= n + 1; i++)
	{
		rectangle(80 * (i - 1), 1, 80 * i, 21);
		TCHAR p5[5];
		_stprintf(p5, _T("%d"), i - 1);
		outtextxy(80 * (i - 1) + 30, 5, p5);
		rectangle(80 * (i - 1), 21, 80 * i, 41);
		TCHAR p6[5];
		_stprintf(p6, _T("%d"), thing[i - 1].v);
		outtextxy(80 * (i - 1) + 30, 25, p6);
		rectangle(80 * (i - 1), 41, 80 * i, 61);
		TCHAR p7[5];
		_stprintf(p7, _T("%d"), thing[i - 1].w);
		outtextxy(80 * (i - 1) + 30, 45, p7);
		rectangle(80 * (i - 1), 61, 80 * i, 81);
		TCHAR p8[5];
		_stprintf(p8, _T("%d"), thing[i - 1].v / gcd(thing[i - 1].v, thing[i - 1].w));
		outtextxy(80 * (i - 1) + 15, 65, p8);
		if (thing[i - 1].w / gcd(thing[i - 1].v, thing[i - 1].w) != 1)
		{
			TCHAR p10[] = _T("/");
			outtextxy(80 * (i - 1) + 30, 65, p10);
			TCHAR p9[5];
			_stprintf(p9, _T("%d"), thing[i - 1].w / gcd(thing[i - 1].v, thing[i - 1].w));
			outtextxy(80 * (i - 1) + 40, 65, p9);
		}
		Sleep(500);
	}
}
void draw(float C, float x[])
{
	initgraph(890, 640);
	drawbg();
	roundrect(1, 90, 500, 600, 50, 50);
	settextstyle(20, 16, _T("Courier"));
	settextcolor(GREEN);
	TCHAR p11[] = _T("��         ��");
	outtextxy(20, 91, p11);
	Sleep(1000);
	settextstyle(15, 10, 0);
	rectangle(2, 140, 82, 160);
	TCHAR p12[] = _T("��Ʒ");
	outtextxy(7, 143, p12);
	rectangle(2, 160, 82, 180);
	TCHAR p13[] = _T("�������");
	outtextxy(5, 163, p13);
	int j = 140, m = 1;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 2)//ȫ��
		{
			clearrectangle(80 * i + 2, 1, 80 * (i + 1) - 2, 80);
			Sleep(1000);
			rectangle(82 * m, j, 82 * (m + 1), j + 20);
			TCHAR p14[5];
			_stprintf(p14, _T("%d"), i);
			outtextxy(82 * m + 30, j + 3, p14);
			rectangle(82 * m, j + 20, 82 * m + 80, j + 40);
			TCHAR p15[] = _T("ȫ������");
			outtextxy(82 * m + 5, j + 23, p15);
			Sleep(1000);
		}
		if (b[i] == 1)//����
		{
			clearrectangle(80 * i + 2, 62, 80 * (i + 1) - 2, 80);
			Sleep(1000);
			rectangle(82 * m, j, 82 * (m + 1), j + 20);
			TCHAR p123[5];
			_stprintf(p123, _T("%d"), i);
			outtextxy(82 * m + 30, j + 3, p123);
			rectangle(82 * m, j + 20, 82 * m + 80, j + 40);
			TCHAR p15[] = _T("��");
			outtextxy(82 * m + 2, j + 23, p15);
			TCHAR p16[5];
			_stprintf(p16, _T("%d"), f1.numerator / gcd(f1.numerator, f1.denominator));
			outtextxy(82 * m + 23, j + 23, p16);
			TCHAR p17[] = _T("/");
			outtextxy(82 * m + 42, j + 23, p17);
			TCHAR p18[5];
			_stprintf(p18, _T("%d"), f1.denominator / gcd(f1.numerator, f1.denominator));
			outtextxy(82 * m + 53, j + 23, p18);
			TCHAR p19[] = _T("ʣ");
			outtextxy(80 * i + 2, 64, p19);
			TCHAR p20[5];
			_stprintf(p20, _T("%d"), (f1.denominator - f1.numerator) / gcd(f1.numerator, f1.denominator));
			outtextxy(80 * i + 23, 64, p20);
			TCHAR p21[] = _T("/");
			outtextxy(80 * i + 42, 64, p21);
			TCHAR p22[5];
			_stprintf(p22, _T("%d"), f1.denominator / gcd(f1.numerator, f1.denominator));
			outtextxy(80 * i + 53, 64, p22);
			Sleep(1000);
		}
		if (b[i] == 0)
		{
			clearrectangle(80 * i + 2, 62, 80 * (i + 1) - 2, 80);
			TCHAR p120[] = _T("������");
			outtextxy(80 * i + 5, 64, p120);
			Sleep(1000);
		}
		if (i % 5 == 0 && i < key)
		{
			j = j + 60;
			rectangle(2, j, 82, j + 20);
			TCHAR p121[] = _T("��Ʒ");
			outtextxy(7, j + 3, p121);
			rectangle(2, j + 20, 82, j + 40);
			TCHAR p122[] = _T("�������");
			outtextxy(5, j + 23, p122);
			m = 0;
		}
		m++;
	}
	settextstyle(40, 40, _T("Courier"));
	settextcolor(RED);
	TCHAR p26[] = _T("������ֵ:");
	outtextxy(520, 100, p26);
	TCHAR p30[50];
	_stprintf(p30, _T("%.2f"), total);
	outtextxy(600, 180, p30);
	system("pause");
}
int main()
{

	int C;
	float x[M];
	memset(x, 0, sizeof(x));
	cout << "��������Ʒ����:";
	cin >> n;
	cout << "�����뱳������:";
	cin >> C;
	for (int j = 1; j <= n; j++)
	{
		cout << "�������" << j << "����Ʒ�ļ�ֵ������" << endl;
		cin >> thing[j].v;
		cin >> thing[j].w;
		thing[j].s = thing[j].v / thing[j].w;
	}
	sort(thing + 1, thing + 1 + n, comp);
	for (int j = 1; j <= n; j++)
	{
		cout << "����Ʒ��ţ�" << j << "����Ʒ�ļ�ֵ����������ֵ/����Ϊ��" << endl;
		cout << thing[j].v << "  " << thing[j].w << "  ";
		if (thing[j].w / gcd(thing[j].v, thing[j].w) != 1)
		{
			cout << thing[j].v / gcd(thing[j].v, thing[j].w)
				<< "/" << thing[j].w / gcd(thing[j].v, thing[j].w) << endl;
		}
		else {
			cout << thing[j].s << endl;
		}
	}
	total = Knapsack(x, C);
	cout << "�ܼ�ֵΪ��" << total << endl;
	for (int k = 1; k <= n; k++)
	{
		if (b[k] == 2)
		{
			cout << k << "����Ʒȫ������" << endl;
		}
		if (b[k] == 1)
		{
			key = k;
			cout << k << "����Ʒ����ȫ����" << f1.numerator / gcd(f1.numerator, f1.denominator)
				<< "/" << f1.denominator / gcd(f1.numerator, f1.denominator) << endl;
		}
		if (b[k] == 0)
		{
			cout << k << "����Ʒ������" << endl;
		}
	}

	draw(C, x);
	return 0;
}