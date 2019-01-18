// Week10_Pow.c
// Compute the nth power of x, where
// n is a non-negative integer.
#include <stdio.h>

double mypow(double, int);

int main(void) {
	double x;
	int n;

	printf("Enter x and n: ");
	scanf("%lf %d", &x, &n);

	printf("mypow(%f, %d) = %f\n", x, n, mypow(x, n));
	return 0;
}

// Compute the nth power of x.
// Precond: n >= 0
double mypow(double x, int n) {
	// to be completed
	int i;
	double mul=1;

	if (n==0){
		return 1;
	}

	for(i=0;i<n-1;i++){
		mul=mul*x;
	}
	return mul + mypow(x,n-1);
}

