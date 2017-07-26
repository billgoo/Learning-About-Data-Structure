#include "exam8-2.cpp"
void BFS(ALGraph *G,int v)  
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			//����ѭ�����в���ʼ��
	int visited[MAXV];            			//�����Ž��ķ��ʱ�־������
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%2d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				//v����
	while (front!=rear)       				//�����в���ʱѭ��
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				//���Ӳ�����w
		p=G->adjlist[w].firstarc; 			//���붥��w�ڽӵĵ�һ������
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		//����ǰ�ڽӶ���δ������
			{
				printf("%2d",p->adjvex);  	//�������ڶ���
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				queue[rear]=p->adjvex;
           	}
           	p=p->nextarc;              		//����һ���ڽӶ���
		}
	}
	printf("\n");
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
	printf("�����������:");BFS(G,2);printf("\n");
}
