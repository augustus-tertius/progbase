#include <stdio.h>
#include <math.h>
#include <progbase.h>

int main(void) {

	int a = 0;
	int b = 0;
	int op = 0;
	int temp = 0;
	double result = 0;
	const double pi = 3.1415926535;
	
	printf("List of possible operations:\
	\n 0\ta + b \n 1\ta - b \n 2\ta * b \n 3\ta / b \n 4\tabs(a) \n 5\tmin(a, b) \n 6\tmax(a, b) \n 7, 13\tpow(a, b)\
	\n 8\tvar(a, b) \n other\tdef(a, b)\n"); 
	
	puts("\nEnter operation code:");
	op = getInt();
	printf("You entered operation code %i\n", op);
	
	puts("\nEnter int a:");
	a = getInt();
	printf("You entered: a = %i\n", a);

	puts("Enter int b:");
	b = getInt();
	printf("You entered: b = %i\n", b);


	if(op < 0){
		op = abs(op);
		
		temp = a;
		a = b;
		b = temp;
		
		printf("\nOperation code was changed to %i.\na = %i, b = %i \n", op, a, b);
		}
		 
	switch (op) {
	    case 0:
	    	result = a + b;
		printf("\nResult: a + b = %.0f\n", result);
		break;
	    case 1:
	    	result = a - b;
		printf("\nResult: a - b = %.0f\n", result);
		break;
	    case 2:
		result = a * b;
		printf("\nResult: a * b = %.0f\n", result);
		break;
	    case 3:
	    	if(b != 0) {
	    		result = a / b;
			printf("\nResult: a / b = %f\n", result);
			} else {
			printf("b = 0, a / b can't be computed. \n");
			}
		break;
	    case 4:
	    	result = abs(a);
	    	printf("\nResult: |a| = %.0f\n", result);
	    	break;
	    case 5:
	    	result = fmin(a, b);
	    	printf("\nResult: minimal value is %.0f\n", result);	    	
	    	break;
	    case 6:
		result = fmax(a, b);
	    	printf("\nResult: maximal value is %.0f\n", result);	    	
	    	break;
	    case 7:
	    case 13:
		if( a != 0 && b > 0) { 
			result = pow(a, b);
		    	printf("\nResult: a^b = %f\n", result);
		    	} else{
		    	printf("Division by zero, result can't be computed \n");
		    	} 
	    	break;
	    case 8:
	    	result = tan(a*pi) / (7 - 2*b);
	    	if(isnan(result) || isinf(result)) {
			printf("Result can't be computed \n");
		    	} else {
		    	printf("\nResult: var(a, b) = %f\n", result);
		    	} /*всегда получаем 0, см. график */
	    	break;
	    default:
	    	if (abs(a+1) != 0 && abs(b+1) != 0) {
		    	result = (op % abs(a+1)) + (op % abs(b+1));
			printf("\nResult: def( a, b) = %.0f\n", result);
			} else {
			printf("Division by zero, result can't be computed \n");
			}	
		break;
	    }
	    
    return 0;
}
