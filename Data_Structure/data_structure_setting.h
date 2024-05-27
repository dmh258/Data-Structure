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
typedef struct _linkedList {
    Node* head;
    Node* cur;
    Node* before;
    int numOfData;
} LinkedList;

// �������� ����Ʈ �ʱ�ȭ, ������ ����, ù ��° ������ ����, ���� ������ ����, ������ ����, ����� ������ �� ��ȯ �Լ�
void ListInit(LinkedList* plist);
void LInsert(LinkedList* plist, LData pdata);
int LFirst(LinkedList* plist, LData* pdata);
int LNext(LinkedList* plist, LData* pdata);
LData LRemove(LinkedList* plist);
int LCount(LinkedList* plist);

#endif