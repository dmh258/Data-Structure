#include "list_setting.h"

//////////////////////////////////// 기본 리스트 실행 함수 ////////////////////////////////////////

void exec_ordinary_list() {

	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		printf("this was LFirst\n");

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
}

//////////////////////////////////// 기본 리스트 실행 함수 ////////////////////////////////////////

//////////////////////////////////// 배열 리스트 실행 함수 ////////////////////////////////////////

void exec_array_list() {
	ArrayList list;
	int data;
	Arr_ListInit(&list);

	Arr_LInsert(&list, 11);	Arr_LInsert(&list, 11);
	Arr_LInsert(&list, 22);	Arr_LInsert(&list, 22);
	Arr_LInsert(&list, 33);

	printf("현재 데이터 수 : %d \n", Arr_LCount(&list));

	if (Arr_LFirst(&list, &data)) {
		printf("%d ", data);
		printf("this was LFirst\n");

		while (Arr_LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (Arr_LFirst(&list, &data))
	{
		if (data == 22)
			Arr_LRemove(&list);

		while (Arr_LNext(&list, &data))
		{
			if (data == 22)
				Arr_LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d \n", Arr_LCount(&list));

	if (Arr_LFirst(&list, &data))
	{
		printf("%d ", data);

		while (Arr_LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
}
//////////////////////////////////// 배열 리스트 실행 함수 ////////////////////////////////////////


void output_statement() {

	printf("Welcome to my algorithm & data_structure program \n");
	printf("Here is a list you can choose \n\n");
	printf("1. ordinary_list\n");
	printf("2. array_list\n");
//	printf("3. Hanoi Tower\n");
	printf("\n\n");
}

void select_fun_at_main() {
	int source_num; // 어떤 프로그램을 실행시킬지 고르는 숫자
	int exit; // while문 탈출할 때 활용, 0은 탈출 못하고 1이면 탈출

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
		case 1: exec_ordinary_list();
			break;
		case 2: exec_array_list();
			break;
			/*		case 3: Hanoi_main();
			break;
*/		default: printf("You Enter a wrong number \n");
			break;
		}

		if (exit == 1)
			break;
	}
}

//////////////////////////////////// 기본 리스트 실행 함수 ////////////////////////////////////////