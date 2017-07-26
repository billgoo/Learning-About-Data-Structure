#include <stdio.h>
#define MaxSize 100			//��������ϣ����
#define NULLKEY -1			//����չؼ���ֵ
#define DELKEY	-2			//���屻ɾ�ؼ���ֵ
typedef int KeyType;		//�ؼ�������
typedef char * InfoType;	//������������
typedef struct
{
	KeyType key;			//�ؼ�����
	InfoType data;			//����������
	int count;				//̽�������
} HashTable[MaxSize];		//��ϣ������
void InsertHT(HashTable ha,int &n,KeyType k,int p)  //���ؼ���k���뵽��ϣ����
{
	int i,adr;
	adr=k % p;
	if (ha[adr].key==NULLKEY || ha[adr].key==DELKEY)	//x[j]����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else					//������ͻʱ��������̽�鷨�����ͻ
	{
		i=1;				//i��¼x[j]������ͻ�Ĵ���
		do 
		{
			adr=(adr+1) % p;
			i++;
		} while (ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
		ha[adr].key=k;
		ha[adr].count=i;
	}
	n++;
}
void CreateHT(HashTable ha,KeyType x[],int n,int m,int p)  //������ϣ��
{
	int i,n1=0;
	for (i=0;i<m;i++)			//��ϣ���ó�ֵ
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	for (i=0;i<n;i++)
		InsertHT(ha,n1,x[i],p);
}
int SearchHT(HashTable ha,int p,KeyType k)		//�ڹ�ϣ���в��ҹؼ���k
{
	int i=0,adr;
	adr=k % p;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		i++;				//��������̽�鷨����һ����ַ
		adr=(adr+1) % p;
	}
	if (ha[adr].key==k)		//���ҳɹ�
		return adr;
	else					//����ʧ��
		return -1;
}
int DeleteHT(HashTable ha,int p,int k,int &n)	//ɾ����ϣ���йؼ���k
{
	int adr;
	adr=SearchHT(ha,p,k);
	if (adr!=-1)		//�ڹ�ϣ�����ҵ��ùؼ���
	{
		ha[adr].key=DELKEY;
		n--;			//��ϣ���ȼ�1
		return 1;
	}
	else				//�ڹ�ϣ����δ�ҵ��ùؼ���
		return 0;
}
void DispHT(HashTable ha,int n,int m)    //�����ϣ��
{
	float avg=0;
	int i;
	printf(" ��ϣ���ַ:\t");
	for (i=0;i<m;i++) 
		printf(" %3d",i);
	printf(" \n");
    printf(" ��ϣ��ؼ���:\t");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY || ha[i].key==DELKEY)
			printf("    ");			//���3���ո�
		else
			printf(" %3d",ha[i].key);
	printf(" \n");
	printf(" ��������:\t");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY || ha[i].key==DELKEY)
			printf("    ");			//���3���ո�
		else
			printf(" %3d",ha[i].count);
	printf(" \n");
    for (i=0;i<m;i++)
		if (ha[i].key!=NULLKEY && ha[i].key!=DELKEY)
			avg=avg+ha[i].count;
	avg=avg/n;
	printf(" ƽ����������ASL(%d)=%g\n",n,avg);
}
void main()
{
	int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;
	HashTable ha;
	CreateHT(ha,x,n,m,p);
	printf("\n");DispHT(ha,n,m);
	i=SearchHT(ha,p,k);
	if (i!=-1)
		printf(" ha[%d].key=%d\n",i,k);
	else
		printf(" δ�ҵ�%d\n",k);
	k=77;
	printf(" ɾ���ؼ���%d\n",k);
	DeleteHT(ha,p,k,n);
	DispHT(ha,n,m);
	i=SearchHT(ha,p,k);
	if (i!=-1)
		printf(" ha[%d].key=%d\n",i,k);
	else
		printf(" δ�ҵ�%d\n",k);
	printf(" ����ؼ���%d\n",k);
	InsertHT(ha,n,k,p);
	DispHT(ha,n,m);
	printf("\n");
}