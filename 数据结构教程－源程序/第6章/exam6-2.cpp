#include <stdio.h>
#define MaxSize 100
void josephus(int n,int m)
{
	int p[MaxSize];
	int i,j,t;
	for (i=0;i<n;i++)			//������ʼ����
		p[i]=i+1;
	t=0;						//�״α�������ʼλ��
	printf("����˳��:");
	for (i=n;i>=1;i--)			//iΪ����p�е�����
	{
		t=(t+m-1)%i;			//tΪ�����ߵı��
		printf("%d ",p[t]);		//���Ϊt��Ԫ�س���
		for (j=t+1;j<=i-1;j++)	//�����Ԫ��ǰ��һ��λ��
			p[j-1]=p[j];
	}
	printf("\n");
}
void main()
{
	josephus(8,4);
}