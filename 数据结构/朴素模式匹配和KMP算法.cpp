#include"stdio.h"
#include"string.h"
//朴素模式匹配算法 
int Index(String S,String T,int pos)
{
	int i = pos;//i用于存储当前主串S中的下标，若pos不为1，则从pos位置开始匹配
	int j = 1;  //j用于存储字串T当前位置下标值
	while(i <= s[0]&&j <= T[0])//若i小于S长度且j小于T的长度时循环
	{
		if(S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+2;
			j = 1;
		}
	 } 
	 if(j > T[0])
	 	return i-T[0];
	 else
	 	return 0;
	 	
}
//KMP模式匹配算法实现
//计算当前要匹配的串T的next数组 
void get_next(String T , int *next)
{
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while( i < T[0])//此处T[0]表示T的长度
	{
		if( j == 0 || T[i] == T[j] )
		//T[i]表示后缀的单个字符
		//T[j]表示前缀的单个字符
		{
			++i;
			++j;
			next[i] = j;
		 } 
		 else
		 j = next[j];//若字符不相同，则j值回溯 
	 } 
 } 
 /*
 返回字串T在字串S中第pos个字符后的位置，若不存在，则函数返回值为0 
 T非空，1<=pos<=StrLength(S) 
 */ 
 int Index_KMP(String S,String T,int pos)
 {
 	int i = pos;//i用于主串当前位置下标值，若pos不为1，则从pos位置开始匹配
	int j = 1;//j用于字串T中当前位置下标值
	int next[255];//定义一next数组
	get_next(T,next);//求T串的next数组
	while( i <= S[0] && j <= T[0] )//若i小于S的长度且j小于T的长度时循环
	{
	if (j == 0 || S[i] == T[j])//两字母相等则继续，相对于朴素算法增加了j=0判断
	{
		++i;
		++j;
	 } 
	else//指针后退开始重新匹配 
	{
		j = next[j];//j退回合适的位置，i不变
		 
	}
	
 }
 if( j > T[0] )
 	return i-T[0];
 else
 	return 0;
}
