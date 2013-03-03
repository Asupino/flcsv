#include <stdlib.h>
#include <stdio.h>



//this is a change
FILE *ptr;  

int flCSV(int lsize, char *filename)
{
	int n;
	int i = 0;
	char line[lsize];
	ptr = fopen(filename,"rw");
	while(fgets(line,80,ptr))
	{
		if(line[i] == ',')
		{
			putc('\n',ptr);
		}
		i++;
	}
	close(ptr);
	ptr = fopen(filename,"rw");
	int size = i;
	int array[size];
	i = 0;
	while(fgets(line,80,ptr))
	{
		
		array[i] = (int)strtol(line, (char **)NULL, 10);
		i++;
		
	}
	 
	for(i = 0; i < size; i++)
	{
		if(i == 0)
		{
			n = array[i];
		}
		else
		{
			if(array[i] > n)
			{
				n = array[i];
			}
		}
		printf("%d\n", array[i] );
	}
	printf("%d\n",n );
	
	

	fclose(ptr);
	return n;
}



