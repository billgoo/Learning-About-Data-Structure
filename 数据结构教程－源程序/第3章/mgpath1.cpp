#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
typedef struct 
{	int i,j;			//�����λ��
	int pre;			//��·������һ�����ڶ����е��±�
} Box;					//��������
typedef struct
{
	Box data[MaxSize];
	int front,rear;		//��ͷָ��Ͷ�βָ��
} QuType;				//����˳�������
void print(QuType qu,int front)	//�Ӷ���qu�����·��
{
	int k=front,j,ns=0;
	printf("\n");
	do				//�����ҵ����·��,����·���ϵķ����pre��Ա���ó�-1
	{	j=k;
		k=qu.data[k].pre;
		qu.data[j].pre=-1;
	} while (k!=0);
	printf("�Թ�·������:\n");
	k=0;
	while (k<MaxSize)  //����������preΪ-1�ķ���,�����������·��
	{	if (qu.data[k].pre==-1)
		{	ns++;
			printf("\t(%d,%d)",qu.data[k].i,qu.data[k].j);
			if (ns%5==0) printf("\n");	//ÿ���ÿ5�������һ��
		}
		k++;
	}
	printf("\n");
}
int mgpath(int xi,int yi,int xe,int ye)					//����·��Ϊ:(xi,yi)->(xe,ye)
{
	int i,j,find=0,di;
	QuType qu;						//����˳���
	qu.front=qu.rear=-1;
	qu.rear++;
	qu.data[qu.rear].i=xi; qu.data[qu.rear].j=yi;	//(xi,yi)����
	qu.data[qu.rear].pre=-1;	
	mg[xi][yi]=-1;					//���丳ֵ-1,�Ա���ع����ظ�����
	while (qu.front!=qu.rear && !find)	//���в�Ϊ����δ�ҵ�·��ʱѭ��
	{	
		qu.front++;					//����,���ڲ��ǻ��ζ��У��ó���Ԫ�����ڶ�����
		i=qu.data[qu.front].i; j=qu.data[qu.front].j;
		if (i==xe && j==ye)			//�ҵ��˳���,���·��
		{	
			find=1;				
			print(qu,qu.front);			//����print�������·��
			return(1);				//�ҵ�һ��·��ʱ����1
		}
		for (di=0;di<4;di++)		//ѭ��ɨ��ÿ����λ,��ÿ�����ߵķ�����������
		{	
			switch(di)
			{
			case 0:i=qu.data[qu.front].i-1; j=qu.data[qu.front].j;break;
			case 1:i=qu.data[qu.front].i; j=qu.data[qu.front].j+1;break;
			case 2:i=qu.data[qu.front].i+1; j=qu.data[qu.front].j;break;
			case 3:i=qu.data[qu.front].i, j=qu.data[qu.front].j-1;break;
			}
			if (mg[i][j]==0)
			{	qu.rear++;				//�������ڷ�����뵽������
				qu.data[qu.rear].i=i; qu.data[qu.rear].j=j;
				qu.data[qu.rear].pre=qu.front; //ָ��·������һ��������±�
				mg[i][j]=-1;		//���丳ֵ-1,�Ա���ع����ظ�����
			}
		}
     }
     return(0);						//δ�ҵ�һ��·��ʱ����1
}
void main()
{
	mgpath(1,1,M,N);
}