#include "exam8-2.cpp"
int visited[MAXV];
void DFS(ALGraph *G,int v)  
{
	ArcNode *p;
	visited[v]=1;                   //���ѷ��ʱ��
	printf("%d  ",v); 				//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              	//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}

void main()
{
	int i,j;
	MGraph g;
	ALGraph *G;
	int A[MAXV][5]={ 
		{0,1,0,1,1},
		{1,0,1,1,0},
		{0,1,0,1,1},
		{1,1,1,0,1},
		{1,0,1,1,0}};
	g.n=5;g.e=16;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	G=(ALGraph *)malloc(sizeof(ALGraph));	
	MatToList(g,G);
	printf(" �ڽӱ�:\n");DispAdj(G);
	for (i=0;i<MAXV;i++)
		visited[i]=0;
	printf("�����������:");DFS(G,2);printf("\n");
}
