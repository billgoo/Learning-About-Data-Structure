#include "btree.cpp"
#define MaxSize 100
void LevelOrder(BTNode *b)
{
	BTNode *p;
	BTNode *qu[MaxSize];			//���廷�ζ���,��Ž��ָ��
	int front,rear;					//�����ͷ�Ͷ�βָ��
	front=rear=-1;					//�ö���Ϊ�ն���
	rear++;
	qu[rear]=b;						//�����ָ��������
	while (front!=rear)				//���в�Ϊ��
	{
		front=(front+1)%MaxSize;
		p=qu[front];				//��ͷ������
		printf("%c ",p->data);		//���ʽ��
		if (p->lchild!=NULL)		//������ʱ�������
		{	
			rear=(rear+1)%MaxSize;
			qu[rear]=p->lchild;
		}
		if (p->rchild!=NULL)		//���Һ���ʱ�������
		{	
			rear=(rear+1)%MaxSize;
			qu[rear]=p->rchild;
		}
	} 
}
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("��α�������:");LevelOrder(b);printf("\n");
}
