#include <stdio.h>
#define MAXL 100	//���ݱ����󳤶�
#define MAXI 20		//���������󳤶�
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                //KeyTypeΪ�ؼ��ֵ���������
	InfoType data;              //��������
} NodeType;
typedef NodeType SeqList[MAXL];	//˳�������

typedef struct 
{	
	KeyType key;			//KeyTypeΪ�ؼ��ֵ�����
	int link;				//ָ���Ӧ�����ʼ�±�
} IdxType;
typedef IdxType IDX[MAXI];	//����������

int IdxSearch(IDX I,int m,SeqList R,int n,KeyType k)
{
	int low=0,high=m-1,mid,i;
	int b=n/m;            	//bΪÿ��ļ�¼����
	while (low<=high)    	//���������н��ж��ֲ���,�ҵ���λ�ô����low��
	{
		mid=(low+high)/2;
		if (I[mid].key>=k)	
			high=mid-1;
		else 
			low=mid+1;
	}
	//Ӧ���������high+1����,�������Ա��н���˳�����
	i=I[high+1].link;
	while (i<=I[high+1].link+b-1 && R[i].key!=k) i++;
	if (i<=I[high+1].link+b-1) 
		return i;
	else 
		return -1;
}

void main()
{
	int i,n=25,m=5,j;
	SeqList R;
	IDX I={{14,0},{34,5},{66,10},{85,15},{100,20}};
	KeyType a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
	KeyType x=85;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	j=IdxSearch(I,m,R,n,x);
	if (j!=-1)
		printf("R[%d]=%d\n",j,x);
	else
		printf("δ�ҵ�%d\n",x);
}
