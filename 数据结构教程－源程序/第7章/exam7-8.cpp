#include "btree.cpp"
void DispLeaf(BTNode *b)
{
	if (b!=NULL) 
	{
		if (b->lchild==NULL && b->rchild==NULL) 
			printf("%c ",b->data);	//����Ҷ�ӽ��
		DispLeaf(b->lchild);	//����������е�Ҷ�ӽ��
		DispLeaf(b->rchild);	//����������е�Ҷ�ӽ��
	}
}
void DispLeaf1(BTNode *b)
{
	if (b!=NULL) 
	{
		if (b->lchild==NULL && b->rchild==NULL) 
			printf("%c ",b->data);	//����Ҷ�ӽ��
		DispLeaf1(b->rchild);		//����������е�Ҷ�ӽ��
		DispLeaf1(b->lchild);		//����������е�Ҷ�ӽ��
	}
}
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("�������������Ҷ�ӽ��:");DispLeaf(b);printf("\n");
	printf("���ҵ����������Ҷ�ӽ��:");DispLeaf1(b);printf("\n");
}
