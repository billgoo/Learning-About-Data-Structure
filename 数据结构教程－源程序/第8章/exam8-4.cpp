#include <stdio.h>
#include <malloc.h>
#include "exam8-2.cpp"
#define INF 32767       //INF��ʾ��
int visited[MAXV];
void PathAll(ALGraph *G,int u,int v,int l,int path[],int d)
//d�ǵ���ǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
{
	int m,i;
	ArcNode *p;
	visited[u]=1;
	d++;						//·��������1
	path[d]=u;					//����ǰ������ӵ�·����
	if (u==v && d==l)			//���һ��·��
	{	
		printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;  	//pָ�򶥵�u�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL)
	{	m=p->adjvex;			//mΪu���ڽӶ���
		if (visited[m]==0)		//���ö���δ��Ƿ���,��ݹ����֮
			PathAll(G,m,v,l,path,d);
		p=p->nextarc;			//��u����һ���ڽӶ���
	}
	visited[u]=0;				//�ָ�������ʹ�ö��������ʹ��
}
void main()
{ 
	int path[MAXV],u=1,v=4,d=3,i,j;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=8;
	int A[MAXV][MAXV]={
		{0,1,0,1,1},
		{1,0,1,1,0},
		{0,1,0,1,1},
		{1,1,1,0,1},
		{1,0,1,1,0}};	
	for (i=0;i<g.n;i++)		
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	printf("��%d��%d�����г���Ϊ%d·��:\n",u,v,d);
	PathAll(G,u,v,d,path,-1);
	printf("\n");
}
