typedef int InfoType;
#define	MAXV 100				//��󶥵����
//���¶����ڽӾ�������
typedef struct 
{  	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct  				//ͼ�Ķ���
{  	int edges[MAXV][MAXV]; 		//�ڽӾ���
   	int n,e;   					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//ͼ���ڽӾ�������
//���¶����ڽӱ�����
typedef struct ANode           	//���Ľ��ṹ����
{	int adjvex;              	//�û����յ�λ��
   	struct ANode *nextarc; 		//ָ����һ������ָ��
   	InfoType info;           	//�û��������Ϣ,�������ڴ��Ȩֵ
} ArcNode;
typedef int Vertex;
typedef struct Vnode      		//�ڽӱ�ͷ��������
{	Vertex data;            	//������Ϣ
	int count;             		//��Ŷ������,ֻ��������������
    ArcNode *firstarc;     		//ָ���һ����
} VNode;
typedef VNode AdjList[MAXV];	//AdjList���ڽӱ�����
typedef struct 
{	AdjList adjlist;         	//�ڽӱ�
    int n,e;                 	//ͼ�ж�����n�ͱ���e
} ALGraph;                   	//ͼ���ڽӱ�����
