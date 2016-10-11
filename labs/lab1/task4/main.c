#include <stdio.h>
#include <math.h>
#include <progbase.h>

int main(void) {

	const double pi = 3.1415926535;
	unsigned int n = 0;
	unsigned int m = 0;
	int i = 1;
	int j = 1;
	double x = 0;
	double sumj = 0;
	
	
	puts("Enter unsigned int n:");
	n = getInt();
	printf("You entered: n = %i\n", n);

	puts("Enter unsigned int m:");
	m = getInt();
	printf("You entered: m = %i\n", m);
	
	for(; j <= m; j++){
		sumj += cos((pi*j)/2);
		}
	for(; i <= n; i++) {
		x +=(i+1) + sumj;
		}
			
	printf("x = %f\n", x);	

	return 0;
}
