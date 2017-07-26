#include "exam8-2.cpp"
void TopSort(ALGraph *G)
{
	int i,j;
	int St[MAXV],top=-1;  			//ջSt��ָ��Ϊtop
	ArcNode *p;
	for (i=0;i<G->n;i++)			//����ó�ֵ0
		G->adjlist[i].count=0;
	for (i=0;i<G->n;i++)			//�����ж�������
	{
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			G->adjlist[p->adjvex].count++;
			p=p->nextarc;
		}
	}
	for (i=0;i<G->n;i++)
		if (G->adjlist[i].count==0)  //���Ϊ0�Ķ����ջ
		{
			top++; 
			St[top]=i;  
		}
	while (top>-1)             		//ջ��Ϊ��ʱѭ��
	{
		i=St[top];top--;  			//��ջ
		printf("%d ",i);      		//�������
		p=G->adjlist[i].firstarc;	//�ҵ�һ�����ڶ���
		while (p!=NULL) 
		{
			j=p->adjvex;
			G->adjlist[j].count--; 
			if (G->adjlist[j].count==0)//���Ϊ0�����ڶ����ջ
			{
				top++;
				St[top]=j;
			}
			p=p->nextarc;       //����һ�����ڶ���
		}
	}
}

void main()
{
	int i,j;
	MGraph g;
	ALGraph *G;
	int A[MAXV][6]={
		{0,1,0,0,0,0},
		{0,0,1,0,0,0},
		{0,0,0,1,0,0},
		{0,0,0,0,0,0},
		{0,1,0,0,0,1},
		{0,0,0,1,0,0}};
	g.n=6;g.e=6;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList(g,G);
	DispAdj(G);
	printf("\n");
	printf("��������:");TopSort(G);printf("\n");
}
