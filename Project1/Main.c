#include <stdio.h>
#include "algorithm.h"

int main() {

	int source_num; // 어떤 프로그램을 실행시킬지 고르는 숫자

	printf("Welcome to my algorithm & data_structure program \n");
	printf("Here is a list you can choose \n\n");
	printf("1. Fibonacci\n");
	printf("2. Factorial\n");
	printf("\n\n");

	printf("Select which one you want to execute :");
	scanf_s("%d", &source_num);

	switch (source_num) {
	case 1: Fibo_main();
		break;
	case 2: Factorial_main();
		break;
	default: printf("You Enter a wrong number \n");
		break;
	}
}