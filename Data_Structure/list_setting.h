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
typedef int arr_data;

typedef struct _ArrayList {
    arr_data arr[LIST_LEN];    // ����Ʈ ����� �迭
    int numOfData;          // ����� ������ ��
    int curPosition;        // ������ ���� ��ġ
} ArrayList;

typedef ArrayList arr_list;

void Arr_ListInit(arr_list* plist);             // �ʱ�ȭ
void Arr_LInsert(arr_list* plist, arr_data data);  // ������ ����

int Arr_LFirst(arr_list* plist, arr_data* pdata);  // ù ������ ����
int Arr_LNext(arr_list* plist, arr_data* pdata);   // �� ��° ���� ������ ����

LData Arr_LRemove(arr_list* plist);     // ������ ������ ����
int Arr_LCount(arr_list* plist);        // ����� ������ �� ��ȯ

#endif

///////////////////////////// �迭 ����Ʈ ���� /////////////////////////////

///////////////////////////// ����ü ����Ʈ ���� /////////////////////////////

#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
    int xpos;
    int ypos;
} Point;

void SetPointPos(Point* ppos, int xpos, int ypos); // Point ������ xpos, ypos �� ����
int ReturnPointXpos(Point* ppos); //Point ������ xpos ��ȯ
int ReturnPointYpos(Point* ppos); //Point ������ ypos ��ȯ

int PointComp(Point* pos1, Point* pos2); // �� Point �Ÿ� ���

#endif

///////////////////////////// ����ü ����Ʈ ���� /////////////////////////////