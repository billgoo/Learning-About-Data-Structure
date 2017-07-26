#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
int visited[MAXV];
int Maxdist(ALGraph *G,int v)
{
	ArcNode *p;
	int Qu[MAXV];					//���ζ���
	int front=0,rear=0;				//���е�ͷ��βָ��
	int visited[MAXV];				//���ʱ������
	int i,j,k;
	for (i=0;i<G->n;i++)			//��ʼ�����ʱ�־����
		visited[i]=0;
	rear++;Qu[rear]=v;				//����v����
	visited[v]=1;					//���v�ѷ���
	while (rear!=front) 
	{
		front=(front+1)%MAXV;
		k=Qu[front];				//����k����
		p=G->adjlist[k].firstarc;	//�ҵ�һ���ڽӵ�
		while (p!=NULL)				//����δ���ʹ������ڵ����
		{
			j=p->adjvex;			//�ڽӵ�Ϊ����j
			if (visited[j]==0)		//��jδ���ʹ�
			{
				visited[j]=1;
				rear=(rear+1)%MAXV;Qu[rear]=j; //����
			}
			p=p->nextarc;			//����һ���ڽӵ�
		}
	}
	return k;
}
void MatToList(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j,n=g.n;						//nΪ������
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)					//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (g.edges[i][j]!=0)				//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����*p
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=n;G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,n=G->n;
	ArcNode *p;
	for (i=0;i<n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.n=n;g.e=G->e;
}
void DispMat(MGraph g)
//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","��");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		if (p!=NULL) printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void main()
{ 
	int i,j,v=0;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0}};	
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	printf("�붥��%d��Զ�Ķ���:%d",v,Maxdist(G,v));
	printf("\n");
}
