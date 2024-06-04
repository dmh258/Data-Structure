#include<stdio.h>
#include<math.h>
#include"list_setting.h"

//////////////////////////////////// 기본 리스트 구현 함수 ////////////////////////////////////////
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

//////////////////////////////////// 기본 리스트 구현 함수 ////////////////////////////////////////


//////////////////////////////////// 배열 리스트 구현 함수 ////////////////////////////////////////

void Arr_ListInit(arr_list* plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = FALSE;
}

void Arr_LInsert(arr_list* plist, arr_data data) {
	if (plist->numOfData >= LIST_LEN) // 더이상 저장이 불가능할 때
		printf("리스트의 최대 저장 가능 횟수에 도달했습니다.\n");

	//여기 아래는 저장이 가능할 때 실행
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

//////////////////////////////////// 배열 리스트 구현 함수 ////////////////////////////////////////

//////////////////////////////////// 구조체 리스트 구현 함수 ////////////////////////////////////////

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

//////////////////////////////////// 구조체 리스트 구현 함수 ////////////////////////////////////////