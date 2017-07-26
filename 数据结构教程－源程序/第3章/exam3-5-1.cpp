#include "sqstack.cpp"
#include <string.h>
bool Match(char exp[],int n)
{
	int i=0; char e;
	bool match=true;
	SqStack *st;
	InitStack(st);						//��ʼ��ջ
	while (i<n && match)				//ɨ��exp�������ַ�
	{	
		if (exp[i]=='(')				//��ǰ�ַ�Ϊ������,�����ջ
			Push(st,exp[i]);
		else if (exp[i]==')')			//��ǰ�ַ�Ϊ������
		{
			if (GetTop(st,e)==true)
			{
				if (e!='(')				//ջ��Ԫ�ز�Ϊ'('ʱ��ʾ��ƥ��
					match=false;
				else
					Pop(st,e);			//��ջ��Ԫ�س�ջ
			}
			else  match=false;			//�޷�ȡջ��Ԫ��ʱ��ʾ��ƥ��
		}
		i++;							//�������������ַ�
	}
	if (!StackEmpty(st))				//ջ����ʱ��ʾ��ƥ��
		match=false;
	DestroyStack(st);					//����ջ
	return match;
}
void main()
{
	char exp[]="(1+2*(5+3)/2)";
	if (Match(exp,strlen(exp)))
		printf("���ʽ%s�������\n",exp);
	else
		printf("���ʽ%s���Ų����\n",exp);
}