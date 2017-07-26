#include "btree.cpp"
#define MaxSize 100
void AllPath2(BTNode *b)
{
	struct snode
	{
		BTNode *node;			//��ŵ�ǰ���ָ��
		int parent;				//���˫�׽���ڶ����е�λ��
	} qu[MaxSize];				//����ǻ��ζ���
	BTNode *q;
	int front,rear,p;			//�����ͷ�Ͷ�βָ��
	front=rear=-1;				//�ö���Ϊ�ն���
	rear++;
	qu[rear].node=b;			//�����ָ��������
	qu[rear].parent=-1;			//�����û��˫�׽��
	while (front!=rear)			//���в�Ϊ��
	{
		front++;
		q=qu[front].node;		//��ͷ������,�ý��ָ������qu��
		if (q->lchild==NULL && q->rchild==NULL)	//*qΪҶ�ӽ��
		{
			p=front;
			while (qu[p].parent!=-1)
			{	
				printf("%c->",qu[p].node->data);
				p=qu[p].parent;
			}
			printf("%c\n",qu[p].node->data);
		}
		if (q->lchild!=NULL)		//*q���������ʱ�������
		{	
			rear++;
			qu[rear].node=q->lchild;
			qu[rear].parent=front;
		}
		if (q->rchild!=NULL)		//*q������Һ���ʱ�������
		{	
			rear++;
			qu[rear].node=q->rchild;
			qu[rear].parent=front;
		}
	}
}
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("������д�Ҷ�ӽ�㵽����������:\n");
	AllPath2(b);
}
