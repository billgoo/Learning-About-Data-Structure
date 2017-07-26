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
} Box;
typedef struct
{
	Box data[MaxSize];
    int length;			//·������
} PathType;				//����·������
int count=0;			//����Թ�·��������
void mgpath(int xi,int yi,int xe,int ye,PathType path)
//���·��Ϊ:(xi,yi)->(xe,ye)
{
	int di,k,i,j;
	if (xi==xe && yi==ye)		//�ҵ��˳���,���·��
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("�Թ�·��%d����:\n",++count);
		for (k=0;k<path.length;k++)
		{
			printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
			if ((k+1)%5==0)		//ÿ���ÿ5�������һ��
				printf("\n");  
		}
		printf("\n");
	}
	else						//(xi,yi)���ǳ���
	{
		if (mg[xi][yi]==0)		//(xi,yi)��һ�����߷���
		{
			di=0;
			while (di<4)		//��(xi,yi)��һ�����ڷ���(i,j)
			{
				path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;
				switch(di)
				{
				case 0:i=xi-1; j=yi;   break;
				case 1:i=xi;   j=yi+1; break;
				case 2:i=xi+1; j=yi;   break;
				case 3:i=xi;   j=yi-1; break;
				}
				mg[xi][yi]=-1;			//�����ظ���·��
				mgpath(i,j,xe,ye,path);
				mg[xi][yi]=0;			//�ָ�(xi,yi)Ϊ����
				path.length--;			//����һ������
				di++;
			}
		}
	}
}
void main()
{
	PathType path;
	path.length=0;				//��ʼ��·������
	mgpath(1,1,M,N,path);
}
