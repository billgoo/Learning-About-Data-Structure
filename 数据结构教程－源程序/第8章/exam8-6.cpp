#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
typedef struct
{
	int data;					//������
	int parent;					//ǰһ�������λ��
} QUERE;						//�ǻ��ζ�������
int visited[MAXV];
void ShortPath(ALGraph *G,int u,int v)
{	//����Ӷ���u������v�������·��
	ArcNode *p;
	int w,i;
	QUERE qu[MAXV];				//�ǻ��ζ���
	int front=-1,rear=-1;		//���е�ͷ��βָ��
	int visited[MAXV];
	for (i=0;i<G->n;i++)		//���ʱ���ó�ֵ0
		visited[i]=0;
	rear++;						//����u����
	qu[rear].data=u;
	qu[rear].parent=-1;
	visited[u]=1;
	while (front!=rear)			//�Ӳ���ѭ��
	{
		front++;				//���Ӷ���w
		w=qu[front].data;
		if (w==v)				//�ҵ�vʱ���·��֮�沢�˳�
		{
			i=front;			//ͨ�����������·��
			while (qu[i].parent!=-1)
			{
				printf("%2d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%2d\n",qu[i].data);
			break; 
		}
		p=G->adjlist[w].firstarc;	//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				visited[p->adjvex]=1;
				rear++;				//��w��δ���ʹ����ڽӵ����
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;
			}
			p=p->nextarc;			//��w����һ���ڽӵ�
		}
	}
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
	int i,j,u=0,v=4;
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
	printf("����%d������%d�������·��:",u,v);
	ShortPath(G,u,v);
	printf("\n");
}
