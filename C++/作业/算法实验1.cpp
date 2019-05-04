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
int ans;//最大价值

int ansv[MAXN];//解向量
int ansvt[MAXN];//临时解向量

/**
*   输出结果
*   @parm   n interger 输出的个数
*/
void output(int n)  //输出
{
    printf("%d\n",ans);
    for(int i=0; i<n; i++)
    {
        printf("%d %d\n",i+1,ansv[i]);
    }
}

/**
*   十进制转二进制
*   @parm   n interger 十进制数
*           ansvt int[] 存储二进制数，每一位为0或1
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
*   蛮力求解0-1背包问题
*   @parm   n   interger 输入的数据个数
*           c   interger 输入的背包总容量
*           w   int[]    物品的重量
*           v   int[]    物品的价值
*/
void manli(int n,int c,int w[],int v[])
{
    int i,j;
    int vt,wt;//临时变量
    ans = 0;

    memset(ansv,0,sizeof(ans));

    int maxcnt = pow(2,n);//2的n次方
    //分别求出所有的子集，按要求寻找最大的子集
    for (i=0; i<maxcnt; i++)
    {
        vt = wt = 0;
        memset(ansvt,0,sizeof(int)*(n + 1));

        deci2bin(i,ansvt);//将i十进制转二进制，表示每一件物品是否放入背包

        for (j=0; j<n; j++)
        {
            if (ansvt[j]==1)//如果在穷举的集合当中
            {
                wt += w[j];
                vt += v[j];
            }
        }
        if ( (wt <= c) && (vt >= ans) )//判断是否比之前算的结果是否更优，若是则替换
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
    int C;//背包容量
    int n;//物品个数
    int v[MAXN];//物品价值
    int w[MAXN];//物品重量

    freopen(FILENAME,"r",stdin);

    clock_t start, finish;
    double duration; /* 测量一个事件持续的时间*/
    start = clock();

    while(scanf("%d%d",&C,&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&v[i]);//输入数据
        }
        manli(n,C,w,v);
    }

    output(n);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    return 0;
}
