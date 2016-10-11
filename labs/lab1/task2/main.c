#include <stdio.h>
#include <math.h>
#include <progbase.h>

int main(void) {

	int a = 0;
	int b = 0; 
	int c = 0; 
	int min = 0; 
	int max = 0;
	int sum = 0;
	int sum2 = 0;
	int result = 0;
	int modmin = 0;
	
	puts("Enter int a:");
	a = getInt();
	printf("You entered: a = %i\n", a);

	puts("Enter int b:");
	b = getInt();
	printf("You entered: b = %i\n", b);

	puts("Enter int c:");
	c = getInt();
	printf("You entered: c = %i\n", c);
	
	sum = a + b + c; 
	min = fmin( a, fmin(b, c));
	max = fmax( a, fmax(b, c));

	
	if( a < 0 && b < 0 && c < 0){
		modmin = fabs(min);
		printf("modmin = %i\n", modmin);
		sum2 = sum - min;
		printf("sum of two other values = %i\n", sum2);
		if( sum2 > -256 && fmod(log2(modmin), 1) == 0){
			result = 1;
			}  else if ( fabs(sum2) - modmin < 16 || fabs(sum2) < 16) {
				result = 1;
				} 
	
		if(result == 0)	{
			printf("Result is false\n"); 
			} else {
			printf("Result is true\n");
			}
		}
	
	else if(fabs(sum) > sum) {
		if((a + b + c - min) == fabs(a + b + c - min))/* если два числа положительные */{
			if(min > - 256) {
				result = 1;				
			} else {
				if((sum - max)*8 > -256) {
					result = 1;
					}
				}				
			}
		if(result == 0)	{
			printf("Result is false\n"); 
			} else {
			printf("Result is true\n");
			}
		}
		
	else {
		if( max*min < 256){
			result = 1;
			}
			
		if(result == 0)	{
			printf("Result is false\n"); 
		} else {
			printf("Result is true\n");
		}
	}
				
	return 0;
}
