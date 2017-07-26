#include <stdio.h>
#define MaxSize 100
typedef struct
{	
	char data[MaxSize];
	int len;			//����
} SqString;
void StrAssign(SqString &str,char cstr[])	//strΪ�����Ͳ���
{
    int i;
    for (i=0;cstr[i]!='\0';i++)
		str.data[i]=cstr[i];
    str.len=i;
}
void StrCopy(SqString &s,SqString t)		//sΪ�����Ͳ���
{
    int i;
    for (i=0;i<t.len;i++)
        s.data[i]=t.data[i];
    s.len=t.len;
}
int StrLength(SqString s)
{
    return s.len;
}
SqString Concat(SqString s,SqString t)
{
    SqString str;
    int i;
    str.len=s.len+t.len;
    for (i=0;i<s.len;i++)   	//��s.data[0]��s.data[s.len-1]���Ƶ�str
        str.data[i]=s.data[i]; 
    for (i=0;i<t.len;i++)   	//��t.data[0]��t.data[t.len-1]���Ƶ�str
        str.data[s.len+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)
{
	SqString str;
	int k;
	str.len=0;
	if (i<=0 || i>s.len || j<0 || i+j-1>s.len)
		return str;          		//��������ȷʱ���ؿմ�
	for (k=i-1;k<i+j-1;k++)  		//��s.data[i]��s.data[i+j]���Ƶ�str
		str.data[k-i+1]=s.data[k];
	str.len=j;
	return str;
} 
void DispStr(SqString s)
{
	int i;
	if (s.len>0)
	{	
		for (i=0;i<s.len;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}
SqString invert(SqString &s)	//��6-2���㷨
{
    SqString s1,s2;
    if (StrLength(s)>0) 
	{	
		s1=invert(SubStr(s,2,StrLength(s)-1));
		s2=Concat(s1,SubStr(s,1,1));
	}
	else 
		StrCopy(s2,s);
	return s2;
}
void main()
{
	SqString s,t;
	StrAssign(s,"abcd1234");
	printf("s:");DispStr(s);
	printf("s->t\n");
	t=invert(s);
	printf("t:");DispStr(t);
}