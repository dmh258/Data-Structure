int Factorial_main() {

	int factorial_num;
	int result;

	printf("Enter factorial number : ");
	scanf_s("%d", &factorial_num);
	
	result = Exec_Factorial(factorial_num);

	printf("result = %d\n", result);

	return 0;
}

int Exec_Factorial(int factorial_num) {
	int fun_factorial_num;
	int semi_result;

	fun_factorial_num = factorial_num;

	if (fun_factorial_num == 0) {
		return 1;
	}
	else {
		semi_result = fun_factorial_num * Exec_Factorial(fun_factorial_num - 1);
		
		return semi_result;
	}
}