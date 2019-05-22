#include<iostream>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<sstream>
#include <graphics.h> 
int k = 0;

using namespace std;
 struct Point
{
	double x;
	double y;
};
int arr = 0;
inline bool Compx(const Point &p1, const Point &p2)
{
	return p1.x < p2.x;
}
inline double Line(const Point &p1, const Point &p2, const Point &p)
{
	return (p1.y - p2.y)*p.x + (p2.x - p1.x) * p.y + (p1.x * p2.y - p1.y * p2.x);
}
//求p点在p1p2上还是下，上>0,下<0 。在p1p2上 =0
double Dist(const Point &p1, const Point &p2, const Point &p)
{
	double A = p1.y - p2.y;
	double B = p2.x - p2.x;
	double C = p1.x * p2.y - p1.y * p2.x;
	return abs(A * p.x + B * p.y) / sqrt(A * A + B * B);
}
//求解上包
void UpHull(const vector<Point> &v, vector <Point>&v0, const Point &p1, const Point &p2)
{
	if (v.size() == 0) {
		return;
	}
	if (v.size() == 1) {
		v0.push_back(v[0]);
		return;
	}
	double d = 0;
	//int k = 0;
	for (int i =0;i  < v.size(); ++ i)
	{
		double t = Dist(p1, p2, v[i]);
		if (t > d) {
			d = t;
			k = i;
		}
	}
	v0.push_back(v[k]);
	vector<Point> vl;
	vector<Point> vr;
	for (int   i = 0; i < v.size(); ++i)
	{
		if (Line(p1, v[k], v[i]) > 0) 
			vl.push_back(v[i]);
		else if (Line(v[k],p2,v[i]) > 0)
		
			vr.push_back(v[i]);
		
	}
	UpHull(vl, v0, p1, v[k]);
	UpHull(vr, v0, v[k], p2);
}
//求下包
void DownHull(const vector<Point> &v, vector <Point>&v0, const Point &p1, const Point &p2)
{
	if (v.size() == 0)
	{
		return;
	}
	if (v.size() == 1)
	{
		v0.push_back(v[0]);
		return;
	}
	double d = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		double t = Dist(p1, p2, v[i]);
		if (t > d) {
			d = t;
			k = i;
		}
	}
	v0.push_back(v[k]);
	vector<Point> vl;
	vector<Point> vr;
	for (int i = 0; i < v.size(); ++i)
	{
		if (Line(p1, v[k], v[i]) < 0)
			vl.push_back(v[i]);
		else if (Line(v[k], p2, v[i]) < 0)

			vr.push_back(v[i]);

	}
	DownHull(vl, v0, p1, v[k]);
	DownHull(vr, v0, v[k], p2);

}
//合并求凸包
void ConvexHull(vector<Point> & v, vector<Point> & v0)
{
	sort(v.begin(), v.end(), Compx);
	v0.push_back(v[0]);
	v0.push_back(v[v.size() - 1]);
	vector<Point> vu;
	vector<Point> vd;
	initgraph(640, 480);
	setorigin(320, 240);
	Point p[1000];
	for (int i = 1; i < v.size() - 1; ++i)
	{
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (Line(v[0], v[v.size() - 1], v[i]) > 0)
			{
				vu.push_back(v[i]);
				p[j] = v[i];
				continue;
			}
			else if (Line(v[0], v[v.size() - 1], v[i]) < 0)
			{
				vu.push_back(v[i]);
				p[j] = v[i];
				continue;
			}
			
			
		}

	}

	UpHull(vu, v0, v[0], v[v.size() - 1]);
	DownHull(vd, v0, v[0], v[v.size() - 1]);
/*	for (int i = 0; i < sizeof(p); i++)
	{
		line(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
	}*/

}
int main()
{
	vector <Point> v;
	ifstream setfs("D:\\Study-_Note\\C++\\算法实验\\分治法凸包\\Point.txt",ifstream :: in);
	string line;
	Point p;
	while (getline(setfs, line)) {
		stringstream liness(line);
		liness >> p.x >> p.y;
		v.push_back(p);
	}
	vector<Point>v0;
	ConvexHull(v, v0);
	for (auto p : v0)
		cout << " < " << p.x << "," << p.y << ">" << endl;


	//polygon((const Point*)v, v.size());

	
	getchar();

	return 0;
}
