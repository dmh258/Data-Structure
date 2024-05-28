#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H

// ����Ʈ�� ������ Ÿ�Կ� ���� ����
typedef int LData; // ����Ʈ�� ����� ������ Ÿ���� int�� ����

// ���� ����Ʈ�� ��� ����ü ����
typedef struct _node {
    LData data;           // ��忡 ����� ������
    struct _node* next;   // ���� ��带 ����Ű�� ������
} Node;

// ���� ����Ʈ ����ü ����
typedef struct _List {
    Node* head;           // ����Ʈ�� ù ��° ��带 ����Ű�� ������
    Node* cur;            // ���� Ž�� ���� ��带 ����Ű�� ������
    Node* before;         // ���� Ž�� ���� ����� ���� ��带 ����Ű�� ������
    int numOfData;        // ����Ʈ�� ����� �������� ��
} List;

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ �Լ�
void LInsert(List* plist, LData pdata);// ������ ���� �Լ�
int LFirst(List* plist, LData* pdata);// ù ��° ������ ���� �Լ�
int LNext(List* plist, LData* pdata);// ���� ������ ���� �Լ�
LData LRemove(List* plist);// ������ ���� �Լ�
int LCount(List* plist);// ����� ������ �� ��ȯ �Լ�

#endif