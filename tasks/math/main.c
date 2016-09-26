#include <math.h>
#include <stdio.h>

int main(void) 
{
	double x = - 10.0;
	double F1 = 0.0;
	double F2 = 0.0;
	double sum = 0.0;
	double product = 0.0;
	double fraction12 = 0.0;
	double fraction21 = 0.0;

	for(x = -10; x <= 10; x = x + 0.5) {
		
		printf("x = %.1f\n", x);
		
		F1 = cos(pow(x, 2)) + sin(pow((2 * x), 2)) + 1;	
		F2 = - pow(x, 2) + 3;
		
		sum = F1 + F2;
		product = F1 * F2;
		fraction12 = F1 / F2;
		fraction21 = F2 / F1;
		
		printf("F1(x) = %f\n", F1);
		printf("F2(x) = %f\n", F2);
		printf("F1(x) + F2(x) = %f\n", sum);
		printf("F1(x) * F2(x) = %f\n", product);

		if(F2 != 0) {
			printf("F1(x) / F2(x) = %f\n", fraction12);
			} else {
			printf("F1(x) / F2(x) = Division by zero\n");
			}
		
		if(F1 != 0) {
			printf("F2(x) / F1(x) = %f\n", fraction21);
		} else {
			printf("F2(x) / F1(x) = Division by zero");
		}
		
		printf("\n");
		}
		
	return 0;
}
