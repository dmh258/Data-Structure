#include<stdio.h>
#include"list_setting.h"

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