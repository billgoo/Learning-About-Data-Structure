#include "sqqueue.cpp"
void number(int n)
{
	int i;  ElemType e;
	SqQueue q;		//����SqQueueΪ˳������ͣ��轫ElemType��Ϊint����
	q.front=q.rear=0;
	for (i=1;i<=n;i++)			//������ʼ����
	{	
		q.rear=(q.rear+1)%MaxSize;
		q.data[q.rear]=i;
	}
	printf("��������˳��:");
	while (q.front!=q.rear)		//���в���ѭ��
	{
		q.front=(q.front+1)%MaxSize;
		e=q.data[q.front];		//����һ��Ԫ��
		printf("%d ",e);		//���Ԫ�ر��
		if (q.front!=q.rear)	//���в���
		{
			q.front=(q.front+1)%MaxSize;
			e=q.data[q.front];	//����һ��Ԫ��
			q.rear=(q.rear+1)%MaxSize;
			q.data[q.rear]=e;	//���ճ��е�Ԫ�ؽ���
		}
	}
	printf("\n");
}
void main()
{
	int i,n=8;
	printf("��ʼ����:");
	for (i=1;i<=n;i++)
		printf("%d ",i);
	printf("\n");
	number(n);
}
