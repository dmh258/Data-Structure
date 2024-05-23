int Fibo_main() {
	int Fibo_num;
	int result;

	printf("Enter Fibonacci num : ");
	scanf_s("%d", &Fibo_num);

	result = Exec_Fibo(Fibo_num);

	printf("Fibo %d = %d", Fibo_num, result+1);

	return 0;
}

int Exec_Fibo(Fibo_num) {
	int fun_fibo_num;
	int fun_result;

	fun_fibo_num = Fibo_num;
	
	if ((fun_fibo_num == 1) || (fun_fibo_num == 2))
		return 1;
	else 
		fun_result = Exec_Fibo(fun_fibo_num - 1) + Exec_Fibo(fun_fibo_num - 2);

	return fun_result;
}