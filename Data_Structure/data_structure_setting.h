#include <stdio.h>
#include <string.h>

#ifndef LIST_H
#define LIST_H

// ����Ʈ�� ������ Ÿ�Կ� ���� ����
typedef int LData; // ���⼭�� ������ int�� �����մϴ�.

// ���� ����Ʈ�� ��� ����ü ����
typedef struct _node {
    LData data;
    struct _node* next;
} Node;

// ���� ����Ʈ ����ü ����
typedef struct _List {
    Node* head;
    Node* cur;
    Node* before;
    int numOfData;
} List;

// �������� ����Ʈ �ʱ�ȭ, ������ ����, ù ��° ������ ����, ���� ������ ����, ������ ����, ����� ������ �� ��ȯ �Լ�
void ListInit(List* plist);
void LInsert(List* plist, LData pdata);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);

#endif