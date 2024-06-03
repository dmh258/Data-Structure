#include "list_setting.h"

//////////////////////////////////// �⺻ ����Ʈ ���� �Լ� ////////////////////////////////////////

void exec_ordinary_list() {

	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("���� ������ �� : %d \n", LCount(&list));

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

	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
}

//////////////////////////////////// �⺻ ����Ʈ ���� �Լ� ////////////////////////////////////////

//////////////////////////////////// �迭 ����Ʈ ���� �Լ� ////////////////////////////////////////

void exec_array_list() {
	ArrayList list;
	int data;
	Arr_ListInit(&list);

	Arr_LInsert(&list, 11);	Arr_LInsert(&list, 11);
	Arr_LInsert(&list, 22);	Arr_LInsert(&list, 22);
	Arr_LInsert(&list, 33);

	printf("���� ������ �� : %d \n", Arr_LCount(&list));

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

	printf("���� �������� �� : %d \n", Arr_LCount(&list));

	if (Arr_LFirst(&list, &data))
	{
		printf("%d ", data);

		while (Arr_LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");
}
//////////////////////////////////// �迭 ����Ʈ ���� �Լ� ////////////////////////////////////////


void output_statement() {

	printf("Welcome to my algorithm & data_structure program \n");
	printf("Here is a list you can choose \n\n");
	printf("1. ordinary_list\n");
	printf("2. array_list\n");
//	printf("3. Hanoi Tower\n");
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

//////////////////////////////////// �⺻ ����Ʈ ���� �Լ� ////////////////////////////////////////