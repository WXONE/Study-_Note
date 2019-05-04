#include<iostream>
#include <graphics.h>
using namespace std;
int m[1000][1100];
int x[1000];
int maxn(int x, int y)
{
	return x > y ? x : y;
}
int minn(int x, int y)
{
	return x < y ? x : y;
}
void Knapsack(int w[], int v[], int c, int n)
{
	int jMax = minn(w[n] - 1, c);
	for (int j = 0; j <= jMax; j++)
		m[n][j] = 0;

	for (int j = w[n]; j <= c; j++)
		m[n][j] = v[n];
	for (int i = n - 1; i >= 1; i--)
	{
		jMax = minn(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++)
		{
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j <= c; j++)
			m[i][j] = maxn(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				printf("%3d", m[i][j]);
			}
			printf("\n");
		}

	}
}

void Traceback(int w[], int c, int n)
{
	for (int i = 1; i < n; i++)
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else
		{
			x[i] = 1;
			c = c - w[i];
		}
	x[n] = (m[n][c]) ? 1 : 0;
}
int main()
{
	int n, c;
	int w[1000], v[1000];
	cin >> n; cin >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i]; cin >> v[i];
	}
	Knapsack(w, v, c, n);
	Traceback(w, c, n);
	initgraph(1000, 800);
	int y = 10;
	for (int i = 1; i <= n; i++)
	{
		int x = 10;
		for (int j = 0; j <= c; j++)
		{
			TCHAR s[5];
			swprintf_s(s, _T("%3d"), m[i][j]);        // 高版本 VC 推荐使用 _stprintf_s 函数
			outtextxy(x, y, s);
			x = x + 30;
		}
		y = y + 40;
	}
	for (int i = n; i > 1; i--)
	{
		for (int j = 0; j <= c; j++)
		{
			if (j >= 0 && j < w[i - 1])
			{
				line(10 + 30 * j + 10, 10 + (i - 1) * 40 - 2, 10 + 30 * j + 10, 10 + (i - 2) * 40 + 15);
				Sleep(500);
			}
			if (j >= w[i - 1])
			{
				if (m[i - 1][j] == m[i][j - w[i - 1]] + v[i - 1])
				{
					line(10 + 30 * (j - w[i - 1]) + 10, 10 + (i - 1) * 40 - 2, 10 + 30 * j + 10, 10 + (i - 2) * 40 + 15);
					Sleep(500);
				}
				if (m[i - 1][j] == m[i][j])
				{
					line(10 + 30 * j + 10, 10 + (i - 1) * 40 - 2, 10 + 30 * j + 10, 10 + (i - 2) * 40 + 15);
					Sleep(500);
				}
			}

		}
		Sleep(1000);
	}

	for (int i = 1; i <= n; i++)
	{
		fillrectangle((i + 1) * 100 - 60, 50, (i + 1) * 100 + 30, 150);
		TCHAR s[10];
		swprintf_s(s, _T("%d"), x[i]);
		outtextxy((i + 1) * 100, 80, s);
		Sleep(500);
	}
	Sleep(500);
	system("pause");
	return 0;
}

