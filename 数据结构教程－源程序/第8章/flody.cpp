#include <stdio.h>
#define MaxSize 100
#define INF 32767	//INF��ʾ��
#define	MAXV 100	//��󶥵����
typedef int InfoType;

typedef struct 
{  	
	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct  				//ͼ�Ķ���
{  	
	int edges[MAXV][MAXV]; 		//�ڽӾ���
   	int n,e;   					//������,����
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//ͼ���ڽӾ�������
void Ppath(int path[][MAXV],int i,int j)  //ǰ��ݹ����·���ϵĶ���
{
	int k;
	k=path[i][j];
	if (k==-1) return;	//�ҵ�������򷵻�
	Ppath(path,i,k);	//�Ҷ���i��ǰһ������k
	printf("%d,",k);
	Ppath(path,k,j);	//�Ҷ���k��ǰһ������j
}
void Dispath(int A[][MAXV],int path[][MAXV],int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) 
		{
			if (A[i][j]==INF) 
			{
				if (i!=j) 
					printf("��%d��%dû��·��\n",i,j);
			}
			else 
			{
				printf("  ��%d��%d=>·������:%d ·��:",i,j,A[i][j]);
				printf("%d,",i);	//���·���ϵ����
				Ppath(path,i,j);	//���·���ϵ��м��
				printf("%d\n",j);	//���·���ϵ��յ�
			}
		}
} 
void Floyd(MGraph g)
{
	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{
			A[i][j]=g.edges[i][j];
			path[i][j]=-1;
		}
	for (k=0;k<g.n;k++)
	{
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j]) 
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
	}
	Dispath(A,path,g.n);   //������·��
}

void main()
{
	int i,j;
	MGraph g;
	g.n=4;g.e=8;
	int a[4][MAXV]={
		{0,  5,INF,7},
		{INF,0,  4,2},
		{3,  3,  0,2},
		{INF,INF,1,0}};
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	printf("����������·��:\n");
	Floyd(g);
	printf("\n");
}