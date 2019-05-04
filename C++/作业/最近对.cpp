#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define MAX 10000
typedef struct {
	float x;
	float y;
}point;

double ClosestPoints(point p[], int n, int* ind1, int* ind2) {
	double mind = MAX;
	double dis = 0;
	*ind1 = 0;
	*ind2 = 0;
	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			dis = (p[j].x - p[i].x)*(p[j].x - p[i].x)
				+ (p[j].y - p[i].y)*(p[j].y - p[i].y);
			if (dis < mind) {
				mind = dis;
				*ind1 = i;
				*ind2 = j;
			}
		}
	}
	return mind;
}

int main()
{

	initgraph(1000, 600);
	int x, y, i = 0;
	point points[100];
	MOUSEMSG m;// 定义鼠标消息
	char strRes[10];
	
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			circle(m.x, m.y, 1);
			points[i].x = m.x;
			points[i++].y = m.y;
			break;
		case WM_RBUTTONUP:
			sprintf_s(strRes, "%f", sqrt(ClosestPoints(points, i, &x, &y)));
			line(points[x].x, points[x].y, points[y].x, points[y].y);
			int ax = (points[x].x + points[y].x) / 2;
			int ay = (points[x].y + points[y].y) / 2;
			outtextxy(ax, ay, strRes);
		}
	}
	return 0;
}

