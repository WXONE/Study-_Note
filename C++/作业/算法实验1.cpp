#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>

#define FILENAME "data.txt"

using namespace std;

const int INF = 1<<30;
const int MAXN = 2100;
const int MAXC = 2010;
int ans;//����ֵ

int ansv[MAXN];//������
int ansvt[MAXN];//��ʱ������

/**
*   ������
*   @parm   n interger ����ĸ���
*/
void output(int n)  //���
{
    printf("%d\n",ans);
    for(int i=0; i<n; i++)
    {
        printf("%d %d\n",i+1,ansv[i]);
    }
}

/**
*   ʮ����ת������
*   @parm   n interger ʮ������
*           ansvt int[] �洢����������ÿһλΪ0��1
*/
void deci2bin(int n,int ansvt[])
{
    for(int i=0; i<MAXN; i++)
    {
        ansvt[i] = n%2;
        n = n/2;
        if(n==0) break;
    }
}
/**
*   �������0-1��������
*   @parm   n   interger ��������ݸ���
*           c   interger ����ı���������
*           w   int[]    ��Ʒ������
*           v   int[]    ��Ʒ�ļ�ֵ
*/
void manli(int n,int c,int w[],int v[])
{
    int i,j;
    int vt,wt;//��ʱ����
    ans = 0;

    memset(ansv,0,sizeof(ans));

    int maxcnt = pow(2,n);//2��n�η�
    //�ֱ�������е��Ӽ�����Ҫ��Ѱ�������Ӽ�
    for (i=0; i<maxcnt; i++)
    {
        vt = wt = 0;
        memset(ansvt,0,sizeof(int)*(n + 1));

        deci2bin(i,ansvt);//��iʮ����ת�����ƣ���ʾÿһ����Ʒ�Ƿ���뱳��

        for (j=0; j<n; j++)
        {
            if (ansvt[j]==1)//�������ٵļ��ϵ���
            {
                wt += w[j];
                vt += v[j];
            }
        }
        if ( (wt <= c) && (vt >= ans) )//�ж��Ƿ��֮ǰ��Ľ���Ƿ���ţ��������滻
        {
            ans = vt;
            for(j=0; j<n; j++)
            {
                ansv[j]=ansvt[j];
            }
        }
    }
}

int main()
{
    int C;//��������
    int n;//��Ʒ����
    int v[MAXN];//��Ʒ��ֵ
    int w[MAXN];//��Ʒ����

    freopen(FILENAME,"r",stdin);

    clock_t start, finish;
    double duration; /* ����һ���¼�������ʱ��*/
    start = clock();

    while(scanf("%d%d",&C,&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&v[i]);//��������
        }
        manli(n,C,w,v);
    }

    output(n);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    return 0;
}
