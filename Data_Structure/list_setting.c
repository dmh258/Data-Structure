#include<stdio.h>
#include<math.h>
#include"list_setting.h"

//////////////////////////////////// �⺻ ����Ʈ ���� �Լ� ////////////////////////////////////////
// ����Ʈ �ʱ�ȭ �Լ�
void ListInit(List* plist) {
	plist->head = NULL;        // ����Ʈ�� head �����͸� NULL�� �ʱ�ȭ
	plist->cur = NULL;         // ���� Ž�� ���� ��� �����͸� NULL�� �ʱ�ȭ
	plist->before = NULL;      // ���� ��� �����͸� NULL�� �ʱ�ȭ
	plist->numOfData = 0;      // ������ ���� 0���� �ʱ�ȭ
}

// ������ ���� �Լ�
void LInsert(List* plist, LData pdata) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����
	newNode->data = pdata;                        // ���ο� ��忡 ������ ����

	newNode->next = plist->head;                  // ���ο� ����� ���� ��带 ���� ����Ʈ�� ù ��° ���� ����
	plist->head = newNode;                        // ����Ʈ�� head �����͸� ���ο� ���� ����

	(plist->numOfData)++;                         // ������ �� ����
}

// ù ��° ������ ���� �Լ�
int LFirst(List* plist, LData* pdata) {
	if (plist->head == NULL)                      // ����Ʈ�� ��� ������
		return 0;                                 // 0 ��ȯ (���� ����)

	plist->before = NULL;                         // before ������ �ʱ�ȭ
	plist->cur = plist->head;                     // cur �����͸� ����Ʈ�� ù ��° ���� ����
	*pdata = plist->cur->data;                    // ù ��° ����� �����͸� pdata�� ����
	return 1;                                     // 1 ��ȯ (���� ����)
}

// ���� ������ ���� �Լ�
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)                 // ���� ����� ���� ��尡 ������
		return 0;                                 // 0 ��ȯ (���� ����)

	plist->before = plist->cur;                   // before �����͸� ���� ���� ����
	plist->cur = plist->cur->next;                // cur �����͸� ���� ���� �̵�

	*pdata = plist->cur->data;                    // ���� ����� �����͸� pdata�� ����
	return 1;                                     // 1 ��ȯ (���� ����)
}

// ������ ���� �Լ�
LData LRemove(List* plist) {
	Node* rpos = plist->cur;                      // ������ ��带 rpos�� ����
	LData rdata = rpos->data;                     // ������ ����� �����͸� rdata�� ����

	if (rpos == plist->head) {                    // ������ ��尡 ù ��° ����̸�
		plist->head = plist->cur->next;           // ����Ʈ�� head �����͸� ���� ���� ����
	}
	else {
		plist->before->next = plist->cur->next;   // ���� ����� next �����͸� ���� ���� ����
	}

	plist->cur = plist->before;                   // cur �����͸� ���� ���� ����
	free(rpos);                                   // ������ ��� �޸� ����
	(plist->numOfData)--;                         // ������ �� ����

	return rdata;                                 // ������ ����� ������ ��ȯ
}

// ����� ������ �� ��ȯ �Լ�
int LCount(List* plist) {
	return plist->numOfData;                      // ����Ʈ�� ����� ������ �� ��ȯ
}

//////////////////////////////////// �⺻ ����Ʈ ���� �Լ� ////////////////////////////////////////


//////////////////////////////////// �迭 ����Ʈ ���� �Լ� ////////////////////////////////////////

void Arr_ListInit(arr_list* plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = FALSE;
}

void Arr_LInsert(arr_list* plist, arr_data data) {
	if (plist->numOfData >= LIST_LEN) // ���̻� ������ �Ұ����� ��
		printf("����Ʈ�� �ִ� ���� ���� Ƚ���� �����߽��ϴ�.\n");

	//���� �Ʒ��� ������ ������ �� ����
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int Arr_LFirst(arr_list* plist, arr_data* pdata) {

	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];

	return TRUE;
}

int Arr_LNext(arr_list* plist, arr_data* pdata) {
	if (plist->curPosition >= (plist->numOfData) - 1)
		return 0;

	(plist->curPosition)++;
	*pdata = plist->arr[plist -> curPosition];
	
	return TRUE;
}

LData Arr_LRemove(arr_list* plist) {

	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int Arr_LCount(arr_list* plist) {
	return plist->numOfData;
}

//////////////////////////////////// �迭 ����Ʈ ���� �Լ� ////////////////////////////////////////

//////////////////////////////////// ����ü ����Ʈ ���� �Լ� ////////////////////////////////////////

void SetPointPos(Point* ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

int ReturnPointXpos(Point* ppos) {
	return ppos->xpos;
}

int ReturnPointYpos(Point* ppos) {
	return ppos->ypos;
}

int PointComp(Point* pos1, Point* pos2) {
	return sqrt((pos1->xpos - pos2->xpos) ^ 2 - (pos1->ypos - pos2->ypos) ^ 2);
}

//////////////////////////////////// ����ü ����Ʈ ���� �Լ� ////////////////////////////////////////