# include <stdio.h>

int main(){

	int c;
	int n;


	printf("which is the number of units : ");
	while(scanf("%d" ,&n) != 1)
	{
		printf("which is the number of units : ");
		while(getchar() != '\n');

	}

	if(n>0){
	    if(n<=60){

		if(n<=30){
		    c=30+(n*2.50);
		}else{
		    c=60+(30*2.50);
		    c = c + (n-30)*4.85;
		}

	    }else if(n<=90){
		c=90 + 7.85*60;
		c= c + (n-60)*10;

	    }else if(n<=120){
		c=480 + (7.85*60) + (10*30);
		c=c + (n-90)*27.75;

	    }else if(n<=180){
		c=480 + (7.85*60) + (10*30) + (27.75*30);
		c=c + (n-120)*32;

	    }else{
		c=540 + (7.85*60) + (10*30);
		c=c + (27.75*30) + (32*60);
		c=c + (n-180)*45;
		}

	    printf("The bill is Rs.%d\n",c);


	}else{

		printf("-1\n");

	}
	return 0;
}
