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
void DisMinTree(int path[],int s[],int n,int v) 
//��path����С��������
{
	int i,pre,j,k;
	int edges[MAXV][2],edgenum=0;	//edges�������ڴ����С�����������б�,
	//edges[i][0]��ŵ�i���ߵ����,edges[i][1]��ŵ�i���ߵ��յ�
	printf(" ��С�����������б�:\n\t");
	for (i=0;i<n;i++)
		if (s[i]==1 && i!=v) 
		{	
			j=i;
			pre=path[i];
			do						//�������·��������С�����������б�
			{	if (edgenum==0)		//��(pre,j)�߼��뵽edges��
				{	edges[edgenum][0]=pre;
					edges[edgenum][1]=j;
					edgenum++;
				}
				else
				{
					k=0;
					while (k<edgenum&&(edges[k][0]!=pre||edges[k][1]!=j))
						k++;
					if (k>=edgenum)		//(pre,j)��δ��edges��ʱ����
					{
						edges[edgenum][0]=pre;
						edges[edgenum][1]=j;
						edgenum++;
					}
				}
				j=pre;
				pre=path[pre];
			} while (pre!=v);
		}
		for (k=0;k<edgenum;k++)
			printf("(%d,%d) ",edges[k][0],edges[k][1]);
		printf("\n");
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
	DisMinTree(path,s,g.n,v);  	//�����С������
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
	for (i=0;i<g.n;i++)		//����ͼ���ڽӾ���
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	Dijkstra(g,0);
	printf("\n");
}