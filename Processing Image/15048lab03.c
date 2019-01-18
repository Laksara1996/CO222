/* Lab 03

Photo inverter*/


#include <stdio.h>

int main (){

	int cols,rows;
	int i,j=0;
	int R,G,B;
	int colsA;
	int padding;

	scanf("%d %d",&cols ,&rows);                //scaning inputs from reader
	printf("%d %d\n",cols ,rows);

	colsA=cols*3;
	while (colsA%4!=0)                          //check whether number of columns are divisible by 4
	{
		colsA=colsA + 1;

	}
	for (i=0;i<rows;i++)                        //inverting process
	{
		for(j=0;j<colsA;j++)
		{
			if(j<cols*3)
			{
				scanf("%d %d %d",&R ,&G ,&B);
				printf("%d %d %d\n",255-R,255-G,255-B);
				j=j+2;
			}
			else
			{
				scanf("%d",&padding);
				printf("%d\n",padding);

			}
		}
	}

	return 0;
}
