#include<stdio.h>
#include"list_setting.h"

// 리스트 초기화 함수
void ListInit(List* plist) {
	plist->head = NULL;        // 리스트의 head 포인터를 NULL로 초기화
	plist->cur = NULL;         // 현재 탐색 중인 노드 포인터를 NULL로 초기화
	plist->before = NULL;      // 이전 노드 포인터를 NULL로 초기화
	plist->numOfData = 0;      // 데이터 수를 0으로 초기화
}

// 데이터 삽입 함수
void LInsert(List* plist, LData pdata) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
	newNode->data = pdata;                        // 새로운 노드에 데이터 저장

	newNode->next = plist->head;                  // 새로운 노드의 다음 노드를 현재 리스트의 첫 번째 노드로 설정
	plist->head = newNode;                        // 리스트의 head 포인터를 새로운 노드로 변경

	(plist->numOfData)++;                         // 데이터 수 증가
}

// 첫 번째 데이터 참조 함수
int LFirst(List* plist, LData* pdata) {
	if (plist->head == NULL)                      // 리스트가 비어 있으면
		return 0;                                 // 0 반환 (참조 실패)

	plist->before = NULL;                         // before 포인터 초기화
	plist->cur = plist->head;                     // cur 포인터를 리스트의 첫 번째 노드로 설정
	*pdata = plist->cur->data;                    // 첫 번째 노드의 데이터를 pdata에 저장
	return 1;                                     // 1 반환 (참조 성공)
}

// 다음 데이터 참조 함수
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)                 // 현재 노드의 다음 노드가 없으면
		return 0;                                 // 0 반환 (참조 실패)

	plist->before = plist->cur;                   // before 포인터를 현재 노드로 설정
	plist->cur = plist->cur->next;                // cur 포인터를 다음 노드로 이동

	*pdata = plist->cur->data;                    // 다음 노드의 데이터를 pdata에 저장
	return 1;                                     // 1 반환 (참조 성공)
}

// 데이터 삭제 함수
LData LRemove(List* plist) {
	Node* rpos = plist->cur;                      // 삭제할 노드를 rpos에 저장
	LData rdata = rpos->data;                     // 삭제할 노드의 데이터를 rdata에 저장

	if (rpos == plist->head) {                    // 삭제할 노드가 첫 번째 노드이면
		plist->head = plist->cur->next;           // 리스트의 head 포인터를 다음 노드로 변경
	}
	else {
		plist->before->next = plist->cur->next;   // 이전 노드의 next 포인터를 다음 노드로 변경
	}

	plist->cur = plist->before;                   // cur 포인터를 이전 노드로 변경
	free(rpos);                                   // 삭제할 노드 메모리 해제
	(plist->numOfData)--;                         // 데이터 수 감소

	return rdata;                                 // 삭제한 노드의 데이터 반환
}

// 저장된 데이터 수 반환 함수
int LCount(List* plist) {
	return plist->numOfData;                      // 리스트에 저장된 데이터 수 반환
}