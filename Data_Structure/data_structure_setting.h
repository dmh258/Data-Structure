#include <stdio.h>
#include <string.h>

#ifndef LIST_H
#define LIST_H

// 리스트의 데이터 타입에 대한 정의
typedef int LData; // 여기서는 간단히 int로 가정합니다.

// 연결 리스트의 노드 구조체 정의
typedef struct _node {
    LData data;
    struct _node* next;
} Node;

// 연결 리스트 구조체 정의
typedef struct _linkedList {
    Node* head;
    Node* cur;
    Node* before;
    int numOfData;
} LinkedList;

// 위에부터 리스트 초기화, 데이터 삽입, 첫 번째 데이터 참조, 다음 데이터 참조, 데이터 삭제, 저장된 데이터 수 반환 함수
void ListInit(LinkedList* plist);
void LInsert(LinkedList* plist, LData pdata);
int LFirst(LinkedList* plist, LData* pdata);
int LNext(LinkedList* plist, LData* pdata);
LData LRemove(LinkedList* plist);
int LCount(LinkedList* plist);

#endif