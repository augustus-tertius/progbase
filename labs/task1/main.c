#include <stdio.h>
#include <progbase.h>
#include <math.h>
 

int main(void) 
{ 
	double a = 0.0;
	double a0 = 0.0;
	double a1 = 0.0;
	double a2 = 0.0;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0; 
	
	puts("Enter double x:");
	x = getDouble();
	printf("You entered: x = %.10f\n", x);

	puts("Enter double y:");
	y = getDouble();
	printf("You entered: y = %.10f\n", y);

	puts("Enter double z:");
	z = getDouble();
	printf("You entered: z = %.10f\n", z);

	printf("\n Results: \n");
	
	if( x - y != 0, z!= 0, (x - y) > 0) {
		a0 = (pow(x, y + 1)) / sqrt(x - y);
		printf("a0 = %.10f\n", a0);
		} else {
		printf("Answer can't be computed, a0 is not a number.\n");
		}
	
	if((x + y)!= 0){
		a1 = y / (8 * fabs(x + y));
		printf("a1 = %.10f\n", a1);
		} else {
		printf("Answer can't be computed, a1 is not a number.\n");
		}
		
	if(sin(x) != 0){
		a2 = sqrt(fabs((cos(y) / sin(x)) + 1));
		printf("a2 = %.10f\n", a2);
		} else {
		printf("Answer can't be computed, a2 is not a number.\n");
		}
		
	/*дописать условия*/
		
	a = a0 + a1 + a2;
	printf("a = %.10f\n", a);


	return 0;
}
