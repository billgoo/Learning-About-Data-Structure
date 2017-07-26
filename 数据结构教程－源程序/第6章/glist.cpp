#include <stdio.h>
#include <malloc.h>
#include "glnode.h"
int GLLength(GLNode *g)		//������g�ĳ���
{
	int n=0;
	GLNode *g1;
	g1=g->val.sublist;		//gָ������ĵ�һ��Ԫ��
	while (g1!=NULL)
	{	
		n++;				//�ۼ�Ԫ�ظ���
		g1=g1->link;
	}
	return n;
}
int GLDepth(GLNode *g)		//������g�����
{
	GLNode *g1;
	int max=0,dep;
	if (g->tag==0)			//Ϊԭ��ʱ����0
		return 0;
	g1=g->val.sublist;		//g1ָ���һ��Ԫ��
	if (g1==NULL)			//Ϊ�ձ�ʱ����1
		return 1;
	while (g1!=NULL)		//�������е�ÿһ��Ԫ��
	{	
		if (g1->tag==1)		//Ԫ��Ϊ�ӱ�����
		{
			dep=GLDepth(g1);	//�ݹ��������ӱ�����
			if (dep>max)	//maxΪͬһ����������ӱ�����ȵ����ֵ
				max=dep;
		}
		g1=g1->link;			//ʹg1ָ����һ��Ԫ��
	}
	return(max+1);			//���ر�����
}
GLNode *CreateGL(char *&s)		//���������ű�ʾ����ʾs�Ĺ������ʽ�洢�ṹ
{
	GLNode *g;
	char ch=*s++;                     	//ȡһ���ַ�
	if (ch!='\0')                      //��δ�����ж�
	{
		g=(GLNode *)malloc(sizeof(GLNode));//����һ���½ڵ�
		if (ch=='(')                 	//��ǰ�ַ�Ϊ������ʱ
		{
			g->tag=1;                	//�½ڵ���Ϊ��ͷ�ڵ�
			g->val.sublist=CreateGL(s); //�ݹ鹹���ӱ�������ͷ�ڵ�
		}
		else if (ch==')') 
			g=NULL;           			//����')'�ַ�,g��Ϊ��
		else if (ch=='#')				//����'#'�ַ�����ʾΪ�ձ�
			g=NULL;
		else							//Ϊԭ���ַ�
		{
			g->tag=0;              		//�½ڵ���Ϊԭ�ӽڵ�
			g->val.data=ch;
		}
	}
	else                                 //������,g��Ϊ��
		g=NULL;
	ch=*s++;                           	//ȡ��һ���ַ�
	if (g!=NULL)                      	//��δ���������������ֵݽڵ�
		if (ch==',')                  	//��ǰ�ַ�Ϊ','
			g->link=CreateGL(s);   		//�ݹ鹹���ֵݽڵ�
		else                            //û���ֵ���,���ֵ�ָ����ΪNULL
			g->link=NULL;
	return g;                     		//���ع����g
}
void DispGL(GLNode *g)					//��������g
{
	if (g!=NULL)                 		//��Ϊ���ж�
	{									//�ȴ���g��Ԫ��
		if (g->tag==0)               	//g��Ԫ��Ϊԭ��ʱ
			printf("%c", g->val.data);  //���ԭ��ֵ
		else							//g��Ԫ��Ϊ�ӱ�ʱ
		{
			printf("(");                //���'('
			if (g->val.sublist==NULL)  	//Ϊ�ձ�ʱ
				printf("#");
			else						//Ϊ�ǿ��ӱ�ʱ
				DispGL(g->val.sublist); //�ݹ�����ӱ�
			printf(")");               	//���')'
		}
		if (g->link!=NULL) 
		{
			printf(",");
			DispGL(g->link);            //�ݹ���������������
		}
	}
}
