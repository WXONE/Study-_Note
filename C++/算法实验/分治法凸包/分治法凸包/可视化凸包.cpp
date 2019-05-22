#include <graphics.h> 
#include<conio.h>
#include<iostream>
using namespace std;
#define M 10000
struct Convex_Hull
{
	int x;
	int y;
	int flag = 0;
}point[M];

int m[1000];
int p[1000];


void ConvexHull(int n, Convex_Hull point[M])
{
	int count = 0;
	int tag = 0;
	int i = 0, j = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			int a = point[j].y - point[i].y;
			int b = point[i].x - point[j].x;
			int c = (point[i].x*point[j].y) - (point[i].y*point[j].x);
			int sign1 = 0;
			int sign2 = 0;  // sign1和sign2记录直线两边点的数量
			for (int k = 0; k < n; k++)
			{
				if ((k == j) || (k == i))
					continue;
				if ((a*point[k].x + b * point[k].y) == c)
				{
					++sign1;
					++sign2;
				}
				if ((a*point[k].x + b * point[k].y) > c)
					++sign1;
				if ((a*point[k].x + b * point[k].y) < c)
					++sign2;
			}
			if ((sign1 == (n - 2)) || (sign2 == (n - 2)))
			{
				point[i].flag = 1;   //point[i].flag为1表示极点
				point[j].flag = 1;
				m[count++] = i;
				p[tag++] = j;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (point[i].flag == 1)
		{
			cout << "(" << point[i].x << "," << point[i].y << ")" << endl;
		}
	}

	initgraph(640, 480);
	setorigin(320, 240);
	for (int i = 0; i < n; i++)
	{
		circle(point[i].x, point[i].y, 4);
		Sleep(1000);
	}
	//polygon((POINT*)a, count / 2);
	for (int i = 0; i < count; i++)
	{
		line(point[m[i]].x, point[m[i]].y, point[p[i]].x, point[p[i]].y);
		Sleep(1000);
	}
	_getch();
}
int main()
{
	Convex_Hull h[M];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i].x;
		cin >> h[i].y;
	}
	ConvexHull(n, h);
	system("pause");
	return 0;
}
/*
8
-80
80
0
50
80
80
-50
0
50
0
0
-50
-80
-80
80
-80
*/




