#include <stdio.h>
#define MaxSize 20
typedef int KeyType;  	//����ؼ�������
typedef char InfoType[10];
typedef struct       	//��¼����
{
	KeyType key;   		//�ؼ�����
	InfoType data; 		//����������,����ΪInfoType
} RecType;				//����ļ�¼���Ͷ���
void sift(RecType R[],int low,int high)
{
    	int i=low,j=2*i;     					//R[j]��R[i]������
    	RecType temp=R[i];
    	while (j<=high) 
		{
			if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
				j++;    							//��Ϊ2i+1
			if (temp.key<R[j].key) 
			{
				R[i]=R[j];              			//��R[j]������˫�׽��λ����
				i=j;                    			//�޸�i��jֵ,�Ա��������ɸѡ
				j=2*i;
			}
			else break;                 			//ɸѡ����
    	}
    	R[i]=temp;                      			//��ɸѡ����ֵ��������λ��
}

void InsertSort(RecType R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
	int i,j,k;
	RecType temp;
	for (i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1;            //����������������R[0..i-1]����R[i]�Ĳ���λ��
		while (j>=0 && temp.key<R[j].key) 
		{
			R[j+1]=R[j]; //���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
		R[j+1]=temp;      //��j+1������R[i]
		printf("i=%d: ",i);
		for (k=0;k<n;k++)
			printf("%d ",R[k].key);
		printf("\n");
	}
}
void main()
{
	int i,n=10;
	RecType R[MaxSize];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("����ǰ:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	InsertSort(R,n);
	printf("�����:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}


