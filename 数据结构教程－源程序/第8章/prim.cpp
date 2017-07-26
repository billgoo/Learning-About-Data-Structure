#include <stdio.h>
#define MAXV 20			//��ඥ����
#define INF 32767       //INF��ʾ��
typedef char InfoType;
typedef struct 
{  	
	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct  				//ͼ�Ķ���
{  	
	int edges[MAXV][MAXV]; 		//�ڽӾ���
   	int n,e;   					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//ͼ���ڽӾ�������

void Prim(MGraph g,int v)
{
	int lowcost[MAXV];			//����i�Ƿ���U��
	int min;
	int closest[MAXV],i,j,k;
	for (i=0;i<g.n;i++)          	//��lowcost[]��closest[]�ó�ֵ
	{	
		lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)          	//�ҳ�n-1������
	{
		min=INF;
		for (j=0;j<g.n;j++)       //��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j]!=0 && lowcost[j]<min) 
			{
				min=lowcost[j];
				k=j;			//k��¼�������ı��
			}
		printf(" ��(%d,%d)ȨΪ:%d\n",closest[k],k,min);
		lowcost[k]=0;         	//���k�Ѿ�����U
		for (j=0;j<g.n;j++)   	//�޸�����lowcost��closest
			if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j]) 
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k; 
			}
	}
}
void main()
{
	int i,j;
	MGraph g;
	g.n=6;g.e=20;
	int a[6][MAXV]={
		{0,6,1,5,INF,INF},
		{6,0,5,INF,3,INF},
		{1,5,0,5,6,4},
		{5,INF,5,0,INF,2},
		{INF,3,6,INF,0,6},
		{INF,INF,4,2,6,0}};
	for (i=0;i<g.n;i++)		//����ͼ9.13(a)��ʾ��ͼ���ڽӾ���
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	printf("��С����������:\n");
	Prim(g,0);
	printf("\n");
}