#include <stdio.h>
#include <malloc.h>
#include "graph.h"
void MatToList(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex=j;
				p->nextarc=G->adjlist[i].firstarc;		//����ͷ�巨����*p
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	g.edges[i][p->adjvex]=1;
			p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}
void DispMat(MGraph g)
//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
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
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
/*������������������
void main()
{
	int i,j;
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,0,7,0,0},
		{0,0,4,0,0,0},
		{8,0,0,0,0,9},
		{0,0,5,0,0,6},
		{0,0,0,5,0,0},
		{3,0,0,0,1,0}};
	g.n=6;g.e=10;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf(" ����ͼG���ڽӾ���:\n");
	DispMat(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf(" ͼG���ڽӾ���ת�����ڽӱ�:\n");
	MatToList(g,G);
	DispAdj(G);
	printf(" ͼG���ڽӱ�ת�����ڽ�����:\n");
	for (i=0;i<g.n;i++)
	   	for (j=0;j<g.n;j++)
			g1.edges[i][j]=0;
	ListToMat(G,g1);
	DispMat(g1);
	printf("\n");
}
*/
int visited[MAXV];						//ȫ�ֱ���
void DFSTrav(MGraph g,int parent,int child,int &len)
{	int clen,v=0,maxlen;
	clen=len;
	maxlen=len;
	while (v<g.n && g.edges[child][v]==0)	//��child�ĵ�һ���ڽӵ�v
		v++;
    	while (v<g.n)							//�����ڽӵ�ʱѭ��
	{	if (v!=parent)
		{	len=len+g.edges[child][v];
		    	DFSTrav(g,child,v,len);
		    	if (len>maxlen)  maxlen=len;
		}
		v++;
	    	while (v<g.n && g.edges[child][v]==0)//��child����һ���ڽӵ�
		    v++;
	    	len=clen;
	}
	len=maxlen;
}
int Diameter(MGraph g,int v)
{	int maxlen1=0;     	//��ŵ�Ŀǰ�ҵ���v��Ҷ�ڵ�����ֵ
	int maxlen2=0;     	//��ŵ�Ŀǰ�ҵ���v��Ҷ�ڵ�Ĵδ�ֵ
	int len=0;         	//��¼������ȱ����е�ĳ��Ҷ�ڵ�ľ���
	int w=0;           	//���v���ڽӶ���
	while (w<g.n && g.edges[v][w]==0) //����v���ڵĵ�һ������w
		w++;
    	while (w<g.n)						//�����ڽӵ�ʱѭ��
	{	len=g.edges[v][w];
		DFSTrav(g,v,w,len);
		if (len>maxlen1)
		{	maxlen2=maxlen1;
			maxlen1=len;
		}
		else if (len>maxlen2)
			maxlen2=len;
		w++;
	    	while (w<g.n && g.edges[v][w]==0)  //��v����һ���ڽӵ�w
			w++;
	}
	return maxlen1+maxlen2;
}

void PathAll(ALGraph *G,int u,int v,int path[],int d)
{
	ArcNode *p;
	int j,w;
	visited[u]=1;
	p=G->adjlist[u].firstarc;			//pָ�򶥵�u�ĵ�һ���ߵı�ͷ�ڵ�
	while (p!=NULL)
	{	w=p->adjvex;					//wΪu���ڽӶ���
		if (w==v)
		{	path[d+1]=w;
			for (j=0;j<=d+1;j++)
				printf("%2d",path[j]);
			printf("\n");
		}
		else if (visited[w]==0)			//���ö���δ��Ƿ���,��ݹ����֮
		{	path[d+1]=w;
			PathAll(G,w,v,path,d+1);
		}
		p=p->nextarc;					//��u����һ���ڽӶ���
	}
	visited[u]=0;
}

void main()
{	int i,j;
	int u=0,v=3,path[MAXV];
	MGraph g;
	ALGraph *G;
	int A[MAXV][5]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	g.n=5;g.e=8;
	for (i=0;i<g.n;i++)			//�������̡̳���ͼ8.1(a)���ڽӾ���
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList(g,G);				//���ɡ��̡̳���ͼ8.1(a)���ڽӱ�G
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);
	for (i=0;i<g.n;i++)			//���ʱ�ʶ�����ó�ֵ0
		visited[i]=0;
	printf("��%d��%d�����м�·��:\n",u,v);
	path[0]=u;visited[u]=1;
	PathAll(G,u,v,path,0);
}
