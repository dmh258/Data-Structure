#include <stdio.h>
#include "data_structure_setting.h"

void ListInit(List* plist) {
	plist->head = NULL;
	plist -> cur = NULL;
	plist -> before = NULL;
	plist -> numOfData = NULL;
}
void LInsert(List* plist, LData pdata) {
	plist->cur++;
	plist->numOfData = pdata;
}
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);


int main() {

	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	return 0;
}