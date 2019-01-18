#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}





int main(int argc, char **argv){

	int i,j,h;
	int k,l,m;
	int s=8;
	int sq1,sq2;
	char *colors[8]={"black","red","green","yellow","blue","magenta","cyan","white"};
	char *figure[2]={"checker","donut"};
	int fig=-1;
	int Fc=-1;
	int Bc=-1;

	if (argc==4)				
	{
		for(k=0;k<8;k++)		//Checking if the  foreground color is available
		{
			if(strcmp(argv[2],colors[k])==0)
			{
				Bc=k;
				break;
			}
		}


		for(l=0;l<8;l++)		//Checking if the  background color is available			
		{
			if(strcmp(argv[3],colors[l])==0)
			{
				Fc=l;
				break;
			}
		}
		for(m=0;m<2;m++)			//Checking no. of arguments
		{
			if(strcmp(argv[1],figure[m])==0)
			{
				fig=1;
				break;
			}
		}
		if(fig==-1)		//error messages
		{
			printf("Request figure is not available\n");
		}
		else if(Bc==-1)		//error messages
		{
			printf("Background color is not available\n");

		}
		else if(Fc==-1)			//error messages
		{
			printf("Foreground color is not available\n");
		}
		else
		{
			if(strcmp(argv[1],"checker")==0)		//if the diagram is checker
			{
				for (i=0;i<s;i++)			// y axis to change the square
				{
					sq1=i%2;
					for(h=0;h<s;h++)		//y axis for coloring the same square
					{
						for(j=0;j<s;j++)	//x axis
						{
							sq2=j%2;
							if(sq1+sq2==1)
							{
								textcolor(BRIGHT, BLACK, Bc);
								printf("        ");
							}
							else
							{
								textcolor(BRIGHT, BLACK, Fc);
								printf("        ");
							}
						}
						textcolor(RESET, WHITE, Bc);	
						printf("\n");
					}
				}
			}
			else if (strcmp(argv[1],"donut")==0)		//if the digram is donut
			{
				double dia;
				float r1,r2;
				float z1;
				float q1,q2;

				scanf("%lf",&dia);		//getting the diameter

				r1=dia/2;
				r2=r1/2;

				for(i=0;i<dia;i++)		//drawing y axis
				{
					for(j=0;j<dia;j++)	//drawing x axis
					{
						z1=((i-r1)*(i-r1))+((j-r1)*(j-r1));		//circle equation
						q1=r1*r1;

						q2=r2*r2;

						if(z1<q1)		//outer circle
						{
							if(z1<=q2)	//inner circle
							{
								textcolor(BRIGHT, BLACK, Bc);				
								printf(" ");
							}
							else
							{
								textcolor(BRIGHT, BLACK, Fc);			
								printf(" ");
							}
						}
						else
						{
							textcolor(BRIGHT, BLACK, Bc);			
							printf(" ");
						}
					}
					textcolor(RESET, WHITE, Bc);
					printf("\n");
				}				
			}
		}
	}
	else			//error messages
	{
		printf("Not enough arguments\n");		
	}
	
	return 0;	
}
