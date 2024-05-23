#include<math.h>
#include<stdio.h>

int Fibo_main() {
	int Fibo_num;
	int result;

	printf("Enter Fibonacci num : ");
	scanf_s("%d", &Fibo_num);

	result = Exec_Fibo(Fibo_num);

	printf("Fibo %d = %d\n\n", Fibo_num, result + 1);

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

int Factorial_main() {

	int factorial_num;
	int result;

	printf("Enter factorial number : ");
	scanf_s("%d", &factorial_num);

	result = Exec_Factorial(factorial_num);

	printf("result = %d\n\n", result);

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

int Hanoi_main() {

	int hanoi_floor;
	int movement_num, init_movement_num;

	init_movement_num = 0;

	printf("This Algorithm is made to calculate the number of times disks are moved\n");
	printf("Enter floor of hanoi tower : ");
	scanf_s("%d", &hanoi_floor);

	movement_num = Exec_Hanoi(hanoi_floor, 1, 3, init_movement_num);

	printf("Number of disk are moved at %d-th floor is %d\n\n", hanoi_floor, movement_num);

	return 0;
}

int Exec_Hanoi(int floor_num, int from, int to, int movement_num) {

	int fun_floor_num, fun_from, fun_to;
	int fun_movement_num;

	fun_floor_num = floor_num;
	fun_from = from;
	fun_to = to;
	fun_movement_num = movement_num;

	if (fun_floor_num == 1 && fun_movement_num == 0)
		fun_movement_num = 1;
	else if (fun_floor_num == 1)
		fun_movement_num++;
	else
		fun_movement_num = 1 + 2 * Exec_Hanoi(fun_floor_num - 1, abs(fun_from - fun_to), fun_to, fun_movement_num);


	return fun_movement_num;
}