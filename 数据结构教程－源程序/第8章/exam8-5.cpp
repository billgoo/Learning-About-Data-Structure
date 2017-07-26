#include <stdio.h>
#include <malloc.h>
#include "exam8-2.cpp"
#define INF 32767       //INF��ʾ��
int visited[MAXV],path[MAXV];  //path[]���ڴ�Ż�··��,��Ϊȫ�ֱ���
void DFSPath(ALGraph *g ,int i,int j,int d)
{
	int v,k;
	ArcNode *p;
	visited[i]=1;
	d++;path[d]=i;
	if (i==j && d>2)         	//�ҵ�һ����·,�����
	{	
		printf("  ");
		for (k=1;k<=d;k++)
			printf("%d ",path[k]);
		printf("\n");
	}
	p=g->adjlist[i].firstarc;  //�Ҷ���i�ĵ�һ���ڽӶ���
	while (p!=NULL) 
	{	
		v=p->adjvex;          	//vΪ����i���ڽӶ���
		if (visited[v]==0 || v==j) 
			DFSPath(g,v,j,d); 	//���ö���δ��Ƿ���,��Ϊvj,��ݹ����֮
		p=p->nextarc;           //�Ҷ���i����һ���ڽӶ���
	}
	visited[i]=0;              //ȡ�����ʱ��,��ʹ�ö��������ʹ��
}
void FindCyclePath(ALGraph *G,int k)	//�����������k�����л�·
{
	printf("��������%d�����л�·\n",k);
    DFSPath(G,k,k,0);
}

void main()
{ 
	int i,j;
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
	FindCyclePath(G,0);
	printf("\n");
}
