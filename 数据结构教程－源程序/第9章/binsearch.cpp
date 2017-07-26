#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                //KeyTypeΪ�ؼ��ֵ���������
	InfoType data;              //��������
} NodeType;
typedef NodeType SeqList[MAXL];	//˳�������
int BinSearch(SeqList R,int n,KeyType k)
{
	int low=0,high=n-1,mid;
	while (low<=high) 
	{
		mid=(low+high)/2;
		if (R[mid].key==k)   	//���ҳɹ�����
			return mid;
		if (R[mid].key>k)     	//������R[low..mid-1]�в���
			high=mid-1;
		else
			low=mid+1;       	//������R[mid+1..high]�в���
	}
	return -1;
}

void main()
{
	int i,n=10;
	SeqList R;
	KeyType a[]={0,1,2,3,4,5,6,7,8,9},x=9;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("R[%d]=%d\n",BinSearch(R,n,x),x);
}
