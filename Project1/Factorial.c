#include <stdio.h>

int Factorial(int factorial_num);

int main() {

	int factorial_num;
	int result;

	printf("Enter factorial number : ");
	scanf_s("%d", &factorial_num);
	
	result = Factorial(factorial_num);

	printf("result = %d\n", result);

	return 0;
}

int Factorial(int factorial_num) {
	int fun_factorial_num;
	int semi_result;

	fun_factorial_num = factorial_num;

	if (fun_factorial_num == 0) {
		return 1;
	}
	else {
		semi_result = fun_factorial_num * Factorial(fun_factorial_num - 1);
		
		return semi_result;
	}
}