#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
#define ll long long
#define llu unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
#define Max 1000

#pragma warning(disable : 4996)

char zuxian[100], chengyuan[100], fubei[100];

struct Tree
{
	string name;
	string sex;
	string fed;			  //配偶
	string thing;		  //个人简介
	string birth;		  //生日
	int level;			  //辈分
	struct Tree *child;   //孩子指针
	struct Tree *brother; //兄弟指针
	struct Tree *parent;  //父亲指针
	int length;
};

Tree *array[100];
int i = 0;

Tree *Create(Tree *t, string s)
{
	Tree *p;
	p = new Tree;
	p->name = s;
	p->brother = NULL; //规定祖先只有一个人，即指向兄弟的指针为空，指向父亲节点的指针为空
	p->child = NULL;   //暂且将孩子指针赋值为空
	p->parent = NULL;
	p->level = 1; //记录辈分，为第一代
	cout << "请输入性别：" << endl;
	cin >> p->sex;
	cout << "请输入配偶名称：" << endl;
	cin >> p->fed;
	cout << "请输入生日：" << endl;
	cin >> p->birth;
	cout << "请输入个人简介：" << endl;
	cin >> p->thing;

	t = p;
	return t; //创建祖先成功；
}

Tree *fCreat(Tree *t, string name, string sex, string fed, string birth, string thing) //文件输入专用；
{
	Tree *p;
	p = new Tree;
	p->name = name;
	p->brother = NULL; //规定祖先只有一个人，即指向兄弟的指针为空，指向父亲节点的指针为空
	p->child = NULL;   //暂且将孩子指针赋值为空
	p->parent = NULL;
	p->level = 1;
	p->sex = sex;
	p->fed = fed;
	p->birth = birth;
	p->thing = thing;

	t = p;
	return t;
}

Tree *Find(Tree *b, string cname) //查询
{
	Tree *p;
	if (b == NULL)
		return NULL;
	else if (b->name == cname)
	{
		return b;
	}
	else
	{
		p = Find(b->child, cname);
		{
			if (p != NULL)
				return p;
			else
				return Find(b->brother, cname);
		}
	}
}

//模糊查询
void MohuFind(Tree *b, string mname)
{
	int i, j, k = 0, l; //,l = 0,m = 0;
	int f = 0;			//f = 1 为符合条件
	int N1 = 0, N2 = 0; //N1记录子串长度，N2记录连续字串个数
	Tree *p;
	if (b == NULL)
		printf("族谱为空");
	else if (b->name == mname)
		cout << b->name;
	else
	{
		for (l = 0; l < b->length; l++)
		{
			i = b->name.length(); //i记录每一个结点的姓名
			j = mname.length();   //j记录被查询结点
			int flag = 0;		  //flag的功能一是计数，二是作为被查询字符串的字符元素编号
			for (k = 0; k < i; k++)
			{ /*flag初始值为0，可以从mname的第一个字符开始
			逐一扫描并且与结点的每一个字符比较，如果相同，
			flag自加1，使mname做好比较下一个字符的准备 */
				if (b->name[k] == mname[flag])
					flag++;
			}
			if (flag == j)
				cout << b->name << endl;
			else
				printf("查询失败\n");
		}
	}
}

void coutxinxi(Tree *b, string cname) //查询个人信息；
{
	Tree *p;
	p = Find(b, cname);
	cout << "名字:\t" << p->name;
	cout << "第" << p->level << "代";
	cout << "父辈:\t" << p->parent->name;
	cout << "性别:\t" << p->sex;
	cout << "配偶:\t" << p->fed;
	cout << "生日:\t" << p->birth;
	cout << "个人简介:\t" << p->thing;
}

// 查询上三代

int chaxunbeifen(Tree *b, string chaxunmingzi) //查询辈分
{
	Tree *p;
	p = Find(b, chaxunmingzi);
	if (p == NULL)
		return 0;
	else
		return p->level;
}

void Add(Tree *b, string parent, string erzi) //添加新成员
{
	int zuigaomax = 1;
	string chengyuan;
	Tree *p, *q;
	p = Find(b, parent);
	if (p == NULL)
	{
		cout << "双亲不存在" << endl;
		return;
	}
	q = new Tree;
	q->name = erzi;
	q->level = p->level + 1;
	cout << "请输入性别:" << endl;
	cin >> chengyuan;
	q->sex = chengyuan;
	cout << "请输入配偶名称:" << endl;
	cin >> chengyuan;
	q->fed = chengyuan;
	cout << "请输入生日:" << endl;
	cin >> chengyuan;
	q->birth = chengyuan;
	cout << "请输入个人简介:" << endl;
	cin >> chengyuan;
	q->thing = chengyuan;
	if (p->level + 1 > zuigaomax)
	{
		zuigaomax = p->level + 1;
	}
	q->child = NULL;
	q->brother = NULL;
	q->parent = p;
	if (p->child == NULL)
		p->child = q;
	else
	{
		p = p->child;
		while (p->brother != NULL)
		{
			p = p->brother;
		}
		p->brother = q;
	}
}

void fAdd(Tree *b, string name, string parent, string sex, string fed, string thing, string birth)
{
	int zuigaomax = 1;
	string chengyuan;
	Tree *p, *q;
	p = Find(b, parent);
	if (p == NULL)
	{
		cout << "双亲不存在" << endl;
		return;
	}
	q = new Tree;
	q->name = name;
	q->level = p->level + 1;
	q->sex = sex;
	q->fed = fed;
	q->birth = birth;
	q->thing = thing;
	if (p->level + 1 > zuigaomax)
	{
		zuigaomax = p->level + 1;
	}
	q->child = NULL;
	q->brother = NULL;
	q->parent = p;
	if (p->child == NULL)
		p->child = q;
	else
	{
		p = p->child;
		while (p->brother != NULL)
		{
			p = p->brother;
		}
		p->brother = q;
	}
}

void modify(Tree *b, string chaxunmingzi) //修改
{
	string chengyuan;
	Tree *p;
	p = Find(b, chaxunmingzi);
	if (p == NULL)
	{
		cout << "查无此人";
		return;
	}
	cout << "请输入修改信息" << endl; //查到之后进行逐项修改
	cout << "新姓名:";
	cin >> chengyuan;
	p->name = chengyuan;
	cout << "请输入性别:" << endl;
	cin >> chengyuan;
	p->sex == chengyuan;
	cout << "请输入配偶名称:" << endl;
	cin >> chengyuan;
	p->fed = chengyuan;
	cout << "请输入生日----(格式：****--**--**)" << endl;
	cin >> chengyuan;
	p->birth = chengyuan;
	cout << "请输入个人简介:" << endl;
	cin >> chengyuan;
	p->thing = chengyuan;
}

void Traversal(Tree *b) //遍历；
{
	if (b != NULL)
	{
		for (int i = 0; i < b->level; i++)
			cout << " ";
		cout << "第" << b->level << "代";
		cout << b->name << "---";
		cout << "配偶:" << b->fed << "---";
		cout << "出生日期：" << b->birth << endl;
		if (b->child != NULL || b->brother != NULL)
		{
			Traversal(b->child);
			Traversal(b->brother);
		}
	}
}

void fTraversal(Tree *b) //文件遍历
{
	if (b != NULL)
	{
		array[i] = b;
		i++;

		if (b->child != NULL || b->brother != NULL)
		{
			fTraversal(b->child);
			fTraversal(b->brother);
		}
	}
}

void creat(Tree *&u)
{
	string zuxian;
	cout << "开始创建族谱！" << endl;
	cout << "祖先名字" << endl;
	cin >> zuxian;
	u = Create(u, zuxian);
	cout << "恭喜下面都是我儿子" << endl;
}

void fcreat(Tree *&u, string name, string sex, string fed, string birth, string thing) //文件专用；
{
	u = fCreat(u, name, sex, fed, birth, thing);
}

void Rfile(Tree *a) //文件写入；
{
	ofstream out;
	out.open("e://ssmd.txt", ios::trunc);

	fTraversal(a);

	if (!out.is_open())
	{
		cout << "打开文件失败" << endl;
		exit(0);
	}
	for (int j = 0; j < i; j++)
	{
		if (j == 0)
			out << array[j]->name << "\t" << array[j]->parent << "\t" << array[j]->sex << "\t" << array[j]->fed << "\t" << array[j]->birth << "\t" << array[j]->thing << endl;
		else
			out << array[j]->name << "\t" << array[j]->parent->name << "\t" << array[j]->sex << "\t" << array[j]->fed << "\t" << array[j]->birth << "\t" << array[j]->thing << endl;
	}
	cout << "1" << endl;
	out.close();
}

void Wfile(Tree *&b)
{
	ifstream in;
	in.open("e://ssmd.txt", ios::in);
	if (!in.is_open())
	{
		cout << "文件打开失败\n";
		exit(0);
	}
	while (!in.eof())
	{
		string name;
		string parent;
		string sex;
		string fed;
		string thing;
		string birth;
		in >> name >> parent >> sex >> fed >> birth >> thing;
		if (parent == "0")
		{
			fcreat(b, name, sex, fed, birth, thing);
		}
		else
		{
			fAdd(b, name, parent, sex, fed, thing, birth);
		}
		in.get();
		if (in.peek() == '\n')
			break;
	}
	in.close();
}

void exit()
{
	exit(0);
}

int menu_select() //菜单函数定义
{
	char c;
	printf("===============================================================\n");
	printf("|--------------------家族成员信息管理系统 v1.0----------------|\n");
	printf("|                                                             |\n");
	printf("|                         1.添加成员                          |\n");
	printf("|                         2.查询个人信息                      |\n");
	printf("|                         3.查看族谱                          |\n");
	printf("|                         4.查询辈分                          |\n");
	printf("|                         5.人物修改                          |\n");
	printf("|                         6.创建族谱                          |\n");
	printf("|                         7.文件读取                          |");
	printf("|                         8.文件保存                          |\n");

	printf("***************************************************************\n");
	printf("                    请输入（1-8）进行操作：\n");
	do
	{
		scanf("%c", &c);
	} while (c < '1' || c > '9');
	return c - 48;
}

int main()
{
	Tree *u;
	u = NULL;
	int n;

	while (1)
	{
		n = menu_select();

		if (n == 1)
		{
			if (u == NULL)
			{
				cout << "暂未创建族谱，请输入功能键8创建族谱！" << endl;
				continue;
			}
			cout << "请输入添加成员名称:" << endl;
			cin >> chengyuan;
			cout << "请输入添加成员的长辈名称:" << endl;
			cin >> fubei;
			Add(u, fubei, chengyuan);
		}
		else if (n == 2)
		{
			if (u == NULL)
			{
				cout << "暂未创建族谱，请输入功能键8创建族谱！" << endl;
				continue;
			}
			cout << "请输入查询名称:";
			cin >> chengyuan;

			Tree *o = Find(u, chengyuan);

			if (o)
			{
				cout << "名字:\t" << o->name << endl;
				cout << "辈分:\t" << o->level << endl;
				cout << "性别:\t" << o->sex << endl;
				cout << "配偶:\t" << o->fed << endl;
				cout << "生日:\t" << o->birth << endl;
				cout << "个人简介:\t" << o->thing << endl;
				if (o->parent == NULL)
				{
				}
				else
					cout << "爸爸为" << o->parent->name << endl;
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (n == 3)
		{
			if (u == NULL)
			{
				cout << "暂未创建族谱，请输入功能键8创建族谱！" << endl;
				continue;
			}
			Traversal(u);
		}
		else if (n == 4)
		{
			if (u == NULL)
			{
				cout << "暂未创建族谱，请输入功能键8创建族谱！" << endl;
				continue;
			}
			cout << "请输入查询名称:";
			cin >> chengyuan;
			int y = chaxunbeifen(u, chengyuan);
			if (y)
			{
				cout << "辈分为:第" << y << "代" << endl;
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (n == 5)
		{
			if (u == NULL)
			{
				cout << "暂未创建族谱，请输入功能键8创建族谱！" << endl;
				continue;
			}
			cout << "请输入要修改的成员名称" << endl;
			cin >> chengyuan;
			modify(u, chengyuan);
		}
		else if (n == 7)
		{
			Rfile(u);
		}
		else if (n == 6)
		{
			creat(u);
		}
		else if (n == 8)
		{
			Wfile(u);
		}
	}
	return 0;
}
