#include <stdio.h>
#include <string.h>
#include <stdlib.h>


///////////////////////////// �⺻ ����Ʈ ���� /////////////////////////////

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

///////////////////////////// �⺻ ����Ʈ ���� /////////////////////////////


///////////////////////////// �迭 ����Ʈ ���� /////////////////////////////

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct _ArrayList {
    LData arr[LIST_LEN];    // ����Ʈ ����� �迭
    int numOfData;          // ����� ������ ��
    int curPosition;        // ������ ���� ��ġ
} ArrayList;

typedef ArrayList list;

void ListInit(List* plist);             // �ʱ�ȭ
void LInsert(List* plist, LData data);  // ������ ����

int LFirst(List* plist, LData* pdata);  // ù ������ ����
int LNext(List* plist, LData* pdata);   // �� ��° ���� ������ ����

LData LRemove(List* plist);     // ������ ������ ����
int LCount(List* plist);        // ����� ������ �� ��ȯ

#endif

///////////////////////////// �迭 ����Ʈ ���� /////////////////////////////