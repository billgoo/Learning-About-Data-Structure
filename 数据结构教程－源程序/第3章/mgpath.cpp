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
{
	int i;				//��ǰ������к�
	int j;				//��ǰ������к�
	int di;				//di����һ�������ڷ�λ�ķ�λ��
} Box;
typedef struct
{
	Box data[MaxSize];
    int top;			//ջ��ָ��
} StType;				//����ջ����
int mgpath(int xi,int yi,int xe,int ye)	//���·��Ϊ:(xi,yi)->(xe,ye)
{
	int i,j,k,di,find;
	StType st;					//����ջst
	st.top=-1;					//��ʼ��ջ��ָ��
	st.top++;      				//��ʼ�����ջ
	st.data[st.top].i=xi; st.data[st.top].j=yi;	st.data[st.top].di=-1;
	mg[xi][yi]=-1; 
	while (st.top>-1)			//ջ����ʱѭ��
	{
		i=st.data[st.top].i;j=st.data[st.top].j;di=st.data[st.top].di;  //ȡջ������
		if (i==xe && j==ye)		//�ҵ��˳���,���·��
		{ 
			printf("�Թ�·������:\n");
			for (k=0;k<=st.top;k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if ((k+1)%5==0)	//ÿ���ÿ5�������һ��
					printf("\n");  
			}
			printf("\n");
			return(1);		//�ҵ�һ��·���󷵻�1
		}
		find=0;
		while (di<4 && find==0)		//����һ�����߷���
		{	
			di++;
			switch(di)
			{
			case 0:i=st.data[st.top].i-1;j=st.data[st.top].j;break;
			case 1:i=st.data[st.top].i;j=st.data[st.top].j+1;break;
			case 2:i=st.data[st.top].i+1;j=st.data[st.top].j;break;
			case 3:i=st.data[st.top].i,j=st.data[st.top].j-1;break;
			}
			if (mg[i][j]==0) find=1;	//�ҵ���һ���������ڷ���
		}
		if (find==1)					//�ҵ�����һ�����߷���
		{	
			st.data[st.top].di=di;		//�޸�ԭջ��Ԫ�ص�diֵ
			st.top++;					//��һ�����߷����ջ
			st.data[st.top].i=i; st.data[st.top].j=j; st.data[st.top].di=-1;
			mg[i][j]=-1;				//�����ظ��ߵ��÷���
		}
		else							//û��·������,����ջ
		{	
			mg[st.data[st.top].i][st.data[st.top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
			st.top--;					//���÷�����ջ
		}
	}
	return(0);							//��ʾû�п���·��,����0
}
void main()
{
	mgpath(1,1,M,N);
}