#include <stdio.h>
#include <string.h>
#include <stdlib.h>


///////////////////////////// 기본 리스트 정의 /////////////////////////////

#ifndef LIST_H
#define LIST_H

// 리스트의 데이터 타입에 대한 정의
typedef int LData; // 리스트에 저장될 데이터 타입을 int로 정의

// 연결 리스트의 노드 구조체 정의
typedef struct _node {
    LData data;           // 노드에 저장될 데이터
    struct _node* next;   // 다음 노드를 가리키는 포인터
} Node;

// 연결 리스트 구조체 정의
typedef struct _List {
    Node* head;           // 리스트의 첫 번째 노드를 가리키는 포인터
    Node* cur;            // 현재 탐색 중인 노드를 가리키는 포인터
    Node* before;         // 현재 탐색 중인 노드의 이전 노드를 가리키는 포인터
    int numOfData;        // 리스트에 저장된 데이터의 수
} List;

void ListInit(List* plist); // 리스트 초기화 함수
void LInsert(List* plist, LData pdata);// 데이터 삽입 함수
int LFirst(List* plist, LData* pdata);// 첫 번째 데이터 참조 함수
int LNext(List* plist, LData* pdata);// 다음 데이터 참조 함수
LData LRemove(List* plist);// 데이터 삭제 함수
int LCount(List* plist);// 저장된 데이터 수 반환 함수

#endif

///////////////////////////// 기본 리스트 정의 /////////////////////////////


///////////////////////////// 배열 리스트 정의 /////////////////////////////

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct _ArrayList {
    LData arr[LIST_LEN];    // 리스트 저장소 배열
    int numOfData;          // 저장된 데이터 수
    int curPosition;        // 데이터 참조 위치
} ArrayList;

typedef ArrayList list;

void ListInit(List* plist);             // 초기화
void LInsert(List* plist, LData data);  // 데이터 저장

int LFirst(List* plist, LData* pdata);  // 첫 데이터 참조
int LNext(List* plist, LData* pdata);   // 두 번째 이후 데이터 참조

LData LRemove(List* plist);     // 참조한 데이터 삭제
int LCount(List* plist);        // 저장된 데이터 수 반환

#endif

///////////////////////////// 배열 리스트 정의 /////////////////////////////