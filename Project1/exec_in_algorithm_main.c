#include <stdio.h>

void output_statement() {

	printf("Welcome to my algorithm & data_structure program \n");
	printf("Here is a list you can choose \n\n");
	printf("1. Fibonacci\n");
	printf("2. Factorial\n");
	printf("3. Hanoi Tower\n");
	printf("\n\n");
}

void select_fun_at_main() {
	int source_num; // � ���α׷��� �����ų�� ���� ����
	int exit; // while�� Ż���� �� Ȱ��, 0�� Ż�� ���ϰ� 1�̸� Ż��

	exit = 0;

	while (1) {
		printf("Select which one you want to execute(If you want to quit, enter 0) :");
		scanf_s("%d", &source_num);

		switch (source_num) {
		case 0: {
			printf("Thank you for enjoying\n");
			exit = 1;
		}
			  break;
		case 1: Fibo_main();
			break;
		case 2: Factorial_main();
			break;
		case 3: Hanoi_main();
			break;
		default: printf("You Enter a wrong number \n");
			break;
		}

		if (exit == 1)
			break;
	}
}