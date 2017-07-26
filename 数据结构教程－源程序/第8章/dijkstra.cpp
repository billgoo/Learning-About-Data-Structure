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

void Ppath(int path[],int i,int v)  //ǰ��ݹ����·���ϵĶ���
{
	int k;
	k=path[i];
	if (k==v)  return;			//�ҵ�������򷵻�
	Ppath(path,k,v);			//�Ҷ���k��ǰһ������
	printf("%d,",k);			//�������k
}
void Dispath(int dist[],int path[],int s[],int n,int v)
{
	int i;
	for (i=0;i<n;i++)
		if (s[i]==1) 
		{	
			printf("  ��%d��%d�����·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
			printf("%d,",v);	//���·���ϵ����
			Ppath(path,i,v);	//���·���ϵ��м��
			printf("%d\n",i);	//���·���ϵ��յ�
		}
		else  printf("��%d��%d������·��\n",v,i);
}
void Dijkstra(MGraph g,int v)
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];
	int mindis,i,j,u;
	for (i=0;i<g.n;i++) 
	{	
		dist[i]=g.edges[v][i];   	//�����ʼ��
		s[i]=0;                		//s[]�ÿ�
		if (g.edges[v][i]<INF)		//·����ʼ��
			path[i]=v;
		else
		    path[i]=-1;
	}
	s[v]=1;path[v]=0;        		//Դ����v����s��
	for (i=0;i<g.n;i++)    			//ѭ��ֱ�����ж�������·�������
	{	
		mindis=INF;					//mindis����С���ȳ�ֵ
		for (j=0;j<g.n;j++)     	//ѡȡ����s���Ҿ�����С����Ķ���u
			if (s[j]==0 && dist[j]<mindis) 
			{ 	
				u=j;
				mindis=dist[j];	
			}
		s[u]=1;               		//����u����s��
		for (j=0;j<g.n;j++)     	//�޸Ĳ���s�еĶ���ľ���
			if (s[j]==0) 
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j]) 
				{	
					dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}  
	}
	Dispath(dist,path,s,g.n,v);  	//������·��
}

void main()
{
	int i,j;
	MGraph g;
	g.n=7;g.e=12;
	int a[7][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	for (i=0;i<g.n;i++)		//����ͼ9.16��ʾ��ͼ���ڽӾ���
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	printf("��С����������:\n");
	Dijkstra(g,0);
	printf("\n");
}