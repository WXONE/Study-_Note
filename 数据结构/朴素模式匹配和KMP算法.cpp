#include"stdio.h"
#include"string.h"
//����ģʽƥ���㷨 
int Index(String S,String T,int pos)
{
	int i = pos;//i���ڴ洢��ǰ����S�е��±꣬��pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int j = 1;  //j���ڴ洢�ִ�T��ǰλ���±�ֵ
	while(i <= s[0]&&j <= T[0])//��iС��S������jС��T�ĳ���ʱѭ��
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
//KMPģʽƥ���㷨ʵ��
//���㵱ǰҪƥ��Ĵ�T��next���� 
void get_next(String T , int *next)
{
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while( i < T[0])//�˴�T[0]��ʾT�ĳ���
	{
		if( j == 0 || T[i] == T[j] )
		//T[i]��ʾ��׺�ĵ����ַ�
		//T[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j;
			next[i] = j;
		 } 
		 else
		 j = next[j];//���ַ�����ͬ����jֵ���� 
	 } 
 } 
 /*
 �����ִ�T���ִ�S�е�pos���ַ����λ�ã��������ڣ���������ֵΪ0 
 T�ǿգ�1<=pos<=StrLength(S) 
 */ 
 int Index_KMP(String S,String T,int pos)
 {
 	int i = pos;//i����������ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int j = 1;//j�����ִ�T�е�ǰλ���±�ֵ
	int next[255];//����һnext����
	get_next(T,next);//��T����next����
	while( i <= S[0] && j <= T[0] )//��iС��S�ĳ�����jС��T�ĳ���ʱѭ��
	{
	if (j == 0 || S[i] == T[j])//����ĸ��������������������㷨������j=0�ж�
	{
		++i;
		++j;
	 } 
	else//ָ����˿�ʼ����ƥ�� 
	{
		j = next[j];//j�˻غ��ʵ�λ�ã�i����
		 
	}
	
 }
 if( j > T[0] )
 	return i-T[0];
 else
 	return 0;
}
