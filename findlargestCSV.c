#include <stdlib.h>
#include <stdio.h>

//for debbugging purposes -> FDP

FILE *ptr;
FILE *ptr1;
FILE *TEMP;  

int flCSV(int lsize, char *filename)
{
	int n,j;
	int i = 0;
	
	char line[lsize],line1[lsize];
	ptr = fopen(filename,"r");
	TEMP = fopen("newfile.txt","w");

	/*this is somewhat clunky but it allows for 
	* a dynamic array declaration while also 
	* converting csv to the more easily read
	* (in c) carrige return format*/
	while(fgets(line,80,ptr))
	{
		j = 0;
		while(j < 80)
		{
			if(line[j] == ',')
			{
				line[j] = '\n';
				/
				i++;
			}
			
			j++;
		}
		fprintf(TEMP, "%s", line);
		
	}
	fflush(ptr);
	fflush(TEMP);
	close(ptr);
	close(TEMP);

	ptr = fopen("newfile.txt","rw");
	int size = i;

	printf("%d\n",size ); //FDP

	int array[size];

	i = 0;

	printf("above while\n"); //FDP
	

	while(fgets(line,lsize,ptr))
	{

		//!!!!!!Data is not stored correctly here causing seg fault!!!!!!!

		array[i] = (int)strtol(line, (char **)NULL, 10);
		i++;
	}


	printf("%d",array[1]); //FDP -> SEG FAULT HERE


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
	}


	fflush(ptr)
	feof(ptr);
	fclose(ptr);
	return n;
}