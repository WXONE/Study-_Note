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
	string fed;			  //��ż
	string thing;		  //���˼��
	string birth;		  //����
	int level;			  //����
	struct Tree *child;   //����ָ��
	struct Tree *brother; //�ֵ�ָ��
	struct Tree *parent;  //����ָ��
	int length;
};

Tree *array[100];
int i = 0;

Tree *Create(Tree *t, string s)
{
	Tree *p;
	p = new Tree;
	p->name = s;
	p->brother = NULL; //�涨����ֻ��һ���ˣ���ָ���ֵܵ�ָ��Ϊ�գ�ָ���׽ڵ��ָ��Ϊ��
	p->child = NULL;   //���ҽ�����ָ�븳ֵΪ��
	p->parent = NULL;
	p->level = 1; //��¼���֣�Ϊ��һ��
	cout << "�������Ա�" << endl;
	cin >> p->sex;
	cout << "��������ż���ƣ�" << endl;
	cin >> p->fed;
	cout << "���������գ�" << endl;
	cin >> p->birth;
	cout << "��������˼�飺" << endl;
	cin >> p->thing;

	t = p;
	return t; //�������ȳɹ���
}

Tree *fCreat(Tree *t, string name, string sex, string fed, string birth, string thing) //�ļ�����ר�ã�
{
	Tree *p;
	p = new Tree;
	p->name = name;
	p->brother = NULL; //�涨����ֻ��һ���ˣ���ָ���ֵܵ�ָ��Ϊ�գ�ָ���׽ڵ��ָ��Ϊ��
	p->child = NULL;   //���ҽ�����ָ�븳ֵΪ��
	p->parent = NULL;
	p->level = 1;
	p->sex = sex;
	p->fed = fed;
	p->birth = birth;
	p->thing = thing;

	t = p;
	return t;
}

Tree *Find(Tree *b, string cname) //��ѯ
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

//ģ����ѯ
void MohuFind(Tree *b, string mname)
{
	int i, j, k = 0, l; //,l = 0,m = 0;
	int f = 0;			//f = 1 Ϊ��������
	int N1 = 0, N2 = 0; //N1��¼�Ӵ����ȣ�N2��¼�����ִ�����
	Tree *p;
	if (b == NULL)
		printf("����Ϊ��");
	else if (b->name == mname)
		cout << b->name;
	else
	{
		for (l = 0; l < b->length; l++)
		{
			i = b->name.length(); //i��¼ÿһ����������
			j = mname.length();   //j��¼����ѯ���
			int flag = 0;		  //flag�Ĺ���һ�Ǽ�����������Ϊ����ѯ�ַ������ַ�Ԫ�ر��
			for (k = 0; k < i; k++)
			{ /*flag��ʼֵΪ0�����Դ�mname�ĵ�һ���ַ���ʼ
			��һɨ�貢�������ÿһ���ַ��Ƚϣ������ͬ��
			flag�Լ�1��ʹmname���ñȽ���һ���ַ���׼�� */
				if (b->name[k] == mname[flag])
					flag++;
			}
			if (flag == j)
				cout << b->name << endl;
			else
				printf("��ѯʧ��\n");
		}
	}
}

void coutxinxi(Tree *b, string cname) //��ѯ������Ϣ��
{
	Tree *p;
	p = Find(b, cname);
	cout << "����:\t" << p->name;
	cout << "��" << p->level << "��";
	cout << "����:\t" << p->parent->name;
	cout << "�Ա�:\t" << p->sex;
	cout << "��ż:\t" << p->fed;
	cout << "����:\t" << p->birth;
	cout << "���˼��:\t" << p->thing;
}

// ��ѯ������

int chaxunbeifen(Tree *b, string chaxunmingzi) //��ѯ����
{
	Tree *p;
	p = Find(b, chaxunmingzi);
	if (p == NULL)
		return 0;
	else
		return p->level;
}

void Add(Tree *b, string parent, string erzi) //����³�Ա
{
	int zuigaomax = 1;
	string chengyuan;
	Tree *p, *q;
	p = Find(b, parent);
	if (p == NULL)
	{
		cout << "˫�ײ�����" << endl;
		return;
	}
	q = new Tree;
	q->name = erzi;
	q->level = p->level + 1;
	cout << "�������Ա�:" << endl;
	cin >> chengyuan;
	q->sex = chengyuan;
	cout << "��������ż����:" << endl;
	cin >> chengyuan;
	q->fed = chengyuan;
	cout << "����������:" << endl;
	cin >> chengyuan;
	q->birth = chengyuan;
	cout << "��������˼��:" << endl;
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
		cout << "˫�ײ�����" << endl;
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

void modify(Tree *b, string chaxunmingzi) //�޸�
{
	string chengyuan;
	Tree *p;
	p = Find(b, chaxunmingzi);
	if (p == NULL)
	{
		cout << "���޴���";
		return;
	}
	cout << "�������޸���Ϣ" << endl; //�鵽֮����������޸�
	cout << "������:";
	cin >> chengyuan;
	p->name = chengyuan;
	cout << "�������Ա�:" << endl;
	cin >> chengyuan;
	p->sex == chengyuan;
	cout << "��������ż����:" << endl;
	cin >> chengyuan;
	p->fed = chengyuan;
	cout << "����������----(��ʽ��****--**--**)" << endl;
	cin >> chengyuan;
	p->birth = chengyuan;
	cout << "��������˼��:" << endl;
	cin >> chengyuan;
	p->thing = chengyuan;
}

void Traversal(Tree *b) //������
{
	if (b != NULL)
	{
		for (int i = 0; i < b->level; i++)
			cout << " ";
		cout << "��" << b->level << "��";
		cout << b->name << "---";
		cout << "��ż:" << b->fed << "---";
		cout << "�������ڣ�" << b->birth << endl;
		if (b->child != NULL || b->brother != NULL)
		{
			Traversal(b->child);
			Traversal(b->brother);
		}
	}
}

void fTraversal(Tree *b) //�ļ�����
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
	cout << "��ʼ�������ף�" << endl;
	cout << "��������" << endl;
	cin >> zuxian;
	u = Create(u, zuxian);
	cout << "��ϲ���涼���Ҷ���" << endl;
}

void fcreat(Tree *&u, string name, string sex, string fed, string birth, string thing) //�ļ�ר�ã�
{
	u = fCreat(u, name, sex, fed, birth, thing);
}

void Rfile(Tree *a) //�ļ�д�룻
{
	ofstream out;
	out.open("e://ssmd.txt", ios::trunc);

	fTraversal(a);

	if (!out.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
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
		cout << "�ļ���ʧ��\n";
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

int menu_select() //�˵���������
{
	char c;
	printf("===============================================================\n");
	printf("|--------------------�����Ա��Ϣ����ϵͳ v1.0----------------|\n");
	printf("|                                                             |\n");
	printf("|                         1.��ӳ�Ա                          |\n");
	printf("|                         2.��ѯ������Ϣ                      |\n");
	printf("|                         3.�鿴����                          |\n");
	printf("|                         4.��ѯ����                          |\n");
	printf("|                         5.�����޸�                          |\n");
	printf("|                         6.��������                          |\n");
	printf("|                         7.�ļ���ȡ                          |");
	printf("|                         8.�ļ�����                          |\n");

	printf("***************************************************************\n");
	printf("                    �����루1-8�����в�����\n");
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
				cout << "��δ�������ף������빦�ܼ�8�������ף�" << endl;
				continue;
			}
			cout << "��������ӳ�Ա����:" << endl;
			cin >> chengyuan;
			cout << "��������ӳ�Ա�ĳ�������:" << endl;
			cin >> fubei;
			Add(u, fubei, chengyuan);
		}
		else if (n == 2)
		{
			if (u == NULL)
			{
				cout << "��δ�������ף������빦�ܼ�8�������ף�" << endl;
				continue;
			}
			cout << "�������ѯ����:";
			cin >> chengyuan;

			Tree *o = Find(u, chengyuan);

			if (o)
			{
				cout << "����:\t" << o->name << endl;
				cout << "����:\t" << o->level << endl;
				cout << "�Ա�:\t" << o->sex << endl;
				cout << "��ż:\t" << o->fed << endl;
				cout << "����:\t" << o->birth << endl;
				cout << "���˼��:\t" << o->thing << endl;
				if (o->parent == NULL)
				{
				}
				else
					cout << "�ְ�Ϊ" << o->parent->name << endl;
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (n == 3)
		{
			if (u == NULL)
			{
				cout << "��δ�������ף������빦�ܼ�8�������ף�" << endl;
				continue;
			}
			Traversal(u);
		}
		else if (n == 4)
		{
			if (u == NULL)
			{
				cout << "��δ�������ף������빦�ܼ�8�������ף�" << endl;
				continue;
			}
			cout << "�������ѯ����:";
			cin >> chengyuan;
			int y = chaxunbeifen(u, chengyuan);
			if (y)
			{
				cout << "����Ϊ:��" << y << "��" << endl;
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (n == 5)
		{
			if (u == NULL)
			{
				cout << "��δ�������ף������빦�ܼ�8�������ף�" << endl;
				continue;
			}
			cout << "������Ҫ�޸ĵĳ�Ա����" << endl;
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
