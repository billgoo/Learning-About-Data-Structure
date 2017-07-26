#include <stdio.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���
void QuickSort(RecType R[],int s,int t) //��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i=s,j=t;
	RecType tmp;
	if (s<t) 				//���������ٴ�������Ԫ�ص����
	{	
		tmp=R[s];     		//������ĵ�1����¼��Ϊ��׼
		while (i!=j)  		//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	
			while (j>i && R[j].key>=tmp.key) 
				j--;  		//��������ɨ��,�ҵ�1��С��tmp.key��R[j]
			R[i]=R[j];		//�ҵ�������R[j],R[i]"R[j]����
			while (i<j && R[i].key<=tmp.key) 
				i++;		//��������ɨ��,�ҵ�1������tmp.key�ļ�¼R[i]
			R[j]=R[i];		//�ҵ�������R[i],R[i]"R[j]����
		}
		R[i]=tmp;
		QuickSort(R,s,i-1);    	//��������ݹ�����
		QuickSort(R,i+1,t);    	//��������ݹ�����
	}
}
void main()
{
	int i,n=10;
	RecType R[MaxSize];
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("����ǰ:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	QuickSort(R,0,n-1);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


