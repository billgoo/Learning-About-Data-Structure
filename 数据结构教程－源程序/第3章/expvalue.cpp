#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define MaxOp 7
struct 
{
	char ch;   //�����
	int pri;   //���ȼ�
} 
 lpri[]={{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
 rpri[]={{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};
int leftpri(char op)    //���������op�����ȼ�
{
	int i;
	for (i=0;i<MaxOp;i++)
		if (lpri[i].ch==op) return lpri[i].pri;
}
int rightpri(char op)  //���������op�����ȼ�
{
	int i;
	for (i=0;i<MaxOp;i++)
		if (rpri[i].ch==op) return rpri[i].pri;
}
int InOp(char ch)       //�ж�ch�Ƿ�Ϊ�����
{
	if (ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return 1;
	else
		return 0;
}
int Precede(char op1,char op2)  //op1��op2��������ȼ��ıȽϽ��
{
	if (leftpri(op1)==rightpri(op2))
		return 0;
	else if (leftpri(op1)<rightpri(op2))
		return -1;
	else
		return 1;
}
void trans(char *exp,char postexp[])     
//���������ʽexpת���ɺ�׺���ʽpostexp
{

	struct
	{	
		char data[MaxSize];		//��������
		int top;				//ջָ��
	} op;						//���������ջ
	int i=0;					//i��Ϊpostexp���±�
	op.top=-1;
	op.top++;                   //��'='��ջ
	op.data[op.top]='='; 
	while (*exp!='\0')			//exp���ʽδɨ����ʱѭ��
	{	
		if (!InOp(*exp))		//Ϊ�����ַ������
		{
			while (*exp>='0' && *exp<='9') //�ж�Ϊ����
			{	
				postexp[i++]=*exp;
				exp++;
			}
			postexp[i++]='#';	//��#��ʶһ����ֵ������
		}
		else					//Ϊ����������
			switch(Precede(op.data[op.top],*exp))
			{	
	        case -1:			//ջ������������ȼ���
				op.top++;op.data[op.top]=*exp;
				exp++;			//����ɨ�������ַ�
				break;
			case 0:				//ֻ�����������������
				op.top--;		//��(��ջ
				exp++;			//����ɨ�������ַ�
				break;
			case 1:             //��ջ�������postexp��
				postexp[i++]=op.data[op.top];
				op.top--;
				break;
		}
	}
	while (op.data[op.top]!='=') //��ʱexpɨ�����,��ջ��'='Ϊֹ
	{	
		postexp[i++]=op.data[op.top];
		op.top--;  
	}
	postexp[i]='\0';			//��postexp���ʽ��ӽ�����ʶ
}
float compvalue(char *postexp )	//�����׺���ʽ��ֵ
{
	struct 
	{	
		float data[MaxSize];	//�����ֵ
		int top;				//ջָ��
	} st;						//������ֵջ
	float d,a,b,c;
	st.top=-1;
	while (*postexp!='\0')		//postexp�ַ���δɨ����ʱѭ��
	{	
		switch (*postexp)
		{
		case '+':				//�ж�Ϊ'+'��
			a=st.data[st.top];
			st.top--;			//��ջȡ��ֵa
			b=st.data[st.top];
			st.top--;			//��ջȡ��ֵb
			c=a+b;				//����c
			st.top++;
			st.data[st.top]=c;	//����������ջ
			break;
		case '-':				//�ж�Ϊ'-'��
			a=st.data[st.top];
			st.top--;			//��ջȡ��ֵa
			b=st.data[st.top];
			st.top--;			//��ջȡ��ֵb
			c=b-a;				//����c
			st.top++;
			st.data[st.top]=c;	//����������ջ
			break;
		case '*':				//�ж�Ϊ'*'��
			a=st.data[st.top];
			st.top--;			//��ջȡ��ֵa
			b=st.data[st.top];
			st.top--;			//��ջȡ��ֵb
			c=a*b;				//����c
			st.top++;
			st.data[st.top]=c;	//����������ջ
			break;
		case '/':				//�ж�Ϊ'/'��
			a=st.data[st.top];
			st.top--;			//��ջȡ��ֵa
			b=st.data[st.top];
			st.top--;			//��ջȡ��ֵb
			if (a!=0)
			{
				c=b/a;			//����c
				st.top++;
				st.data[st.top]=c;	//����������ջ
			}
			else
		    {	
				printf("\n\t�������!\n");
				exit(0);		//�쳣�˳�
			}
			break;
		default:				//���������ַ�
			d=0;				//�������������ַ�ת���ɶ�Ӧ����ֵ��ŵ�d��
			while (*postexp>='0' && *postexp<='9')   //�ж�Ϊ�����ַ�
			{	
				d=10*d+*postexp-'0';  
				postexp++;
			}
			st.top++;
			st.data[st.top]=d;
			break;
		}
		postexp++;				//�������������ַ�
	}
	return(st.data[st.top]);
}
void main()
{
	char exp[]="(56-20)/(4+2)";
	//char exp[]="1+2*3+6/2";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("��׺���ʽ:%s\n",exp);
	printf("��׺���ʽ:%s\n",postexp);
	printf("���ʽ��ֵ:%g\n",compvalue(postexp));
}