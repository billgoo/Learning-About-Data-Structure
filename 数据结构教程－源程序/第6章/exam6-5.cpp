#include "glist.cpp"
int atomnum(GLNode *g)	//������g�е�ԭ�Ӹ���
{
	if (g!=NULL)
	{
		if (g->tag==0)
			return 1+atomnum(g->link);
		else
			return atomnum(g->val.sublist)+atomnum(g->link);
	}
	else
		return 0;
}
void main()
{
	GLNode *g;
	char *s="((#),(a,b),a,(((a),b)))";
	g=CreateGL(s);
	printf("g:");DispGL(g);printf("\n");
	printf("ԭ�Ӹ���=%d\n",atomnum(g));
}
