#include "testUtils.h"
#include "list_isort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void view_list_details(DoubleList *dlist){
	node *temp;int i;
	temp = dlist->head;
	for (i = 0; i < dlist->length;i++){
		// printf("-%d-\t",*(int*)temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}
int compare_lists(DoubleList *expected,DoubleList *actual,compare comp){
	node *temp1,*temp2;int i;
	temp1 = expected->head;
	temp2 = expected->head;
	for (i = 0; i < expected->length;i++){
		if(comp(temp1->data,temp2->data) != 0)
			return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 1;
}
int compareInt(void *element1,void *element2){
	return *(int*)element1 - *(int*)element2;
}
void test_isort_on_dList(){
	DoubleList *dList = create();
	DoubleList *expected = create();
	int nums[3] = {65,55,45};
	insert(dList, 0, nums);
	insert(dList, 1, &nums[1]);
	insert(dList, 2, &nums[2]);
	
	insert(expected, 0, &nums[2]);
	insert(expected, 1, &nums[1]);
	insert(expected, 2, nums);
	view_list_details(expected);
	sort(dList, compareInt);
	view_list_details(dList);
	compare_lists(expected, dList, compareInt);
		
}
// void test_isort_on_dList(){
// 	DoubleList *dList = create();
// 	DoubleList *expected = create();
// 	int nums[3] = {65,55,45};
// 	insert(dList, 0, nums);
// 	insert(dList, 1, &nums[1]);
// 	insert(dList, 2, &nums[2]);
	
// 	insert(expected, 0, &nums[2]);
// 	insert(expected, 1, &nums[1]);
// 	insert(expected, 2, nums);
// 	view_list_details(expected);
// 	sort(dList, compareInt);
// 	view_list_details(dList);
// 	compare_lists(expected, dList, compareInt);		
// }
