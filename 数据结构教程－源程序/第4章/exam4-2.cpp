#include "sqstring.cpp"
void LongestString(SqString s,int &index,int &max)
{
	int length=1,i=0,start=0;	//length����ƽ̨�ĳ���
	index=0,max=0;				//index�����ƽ̨��s�еĿ�ʼλ��,max�����䳤��
	while (i<s.length-1)
		if (s.data[i]==s.data[i+1])
		{	
			i++;
			length++;
		}
		else				//��һ��ƽ̨����
		{	
			if (max<length)	//��ǰƽ̨���ȴ�,�����max
			{	
				max=length;
				index=start;
			}
			i++;start=i;	//��ʼ����һ��ƽ̨����ʼλ�úͳ���
			length=1;
		}
}
void main()
{
	SqString s;
	int i,j,k;
	StrAssign(s,"aabcsaaaabcdeab");
	printf("s:");DispStr(s);
	LongestString(s,i,j);
	printf("�ƽ̨:");
	for (k=i;k<i+j;k++)
		printf("%c",s.data[k]);
	printf("\n");
}