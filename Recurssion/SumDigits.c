// Week10_SumDigits.c
// Sum up all digits in an integer.

#include <stdio.h>

int sum_digits(int);

int sumArray(int [], int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);

	printf("Sum of its digits = %d\n", sum_digits(num));

	return 0;
}

// Return sum of digits in integer n
// Pre-cond: n >= 0
int sum_digits(int n) {

	int i,N;
	int count = 0;

	N=n;

	while(N!=0){
		N=N/10;
		count += 1;
	}
	int array[count];

	for(i=0;n!=0;i++){
		array[i] = n%10;
		n= n/10;
	}

	return sumArray(array,count);
}

//summing the digits in the number
int sumArray(int array[], int count){

	if(count == 0){
		return array[0];
	}

	return array[count] + sumArray(array,count-1);
}

