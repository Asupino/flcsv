#include "findlargestCSV.c"

int main()
{
	int lnum;
	char *str;
	printf("please enter a filename\n");
	scanf("%s",str);
	lnum = flCSV(80,str);
	printf("\n\n%d\n",lnum );
}