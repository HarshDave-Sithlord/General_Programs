#include "test.h"

void test_linklist(void)
{
	sl_list_init();
	struct sl_node_t **list1 = SLlist_create(BYTE4);
	struct sl_node_t **list2 = SLlist_create(STRING);
	struct sl_node_t **list3 = SLlist_create(BYTE8);
	unsigned int data = 1;
	double ll = 15.609;
	unsigned char str[10] = {0};
	memcpy(str, "abc", 3);
	SLlist_add_element(list1, &data, 4);
	SLlist_add_element(list2, str, 3);
	SLlist_add_element(list3, &ll, 8);
	data = 2;
	memcpy(str, "def", 3);
	SLlist_add_element(list1, &data, 4);
	SLlist_add_element(list2, str, 3);
	ll = 69.069;
	SLlist_add_element(list3, &ll, 8);
	data = 3;
	memcpy(str, "ghi", 3);
	SLlist_add_element(list1, &data, 4);
	SLlist_add_element(list2, str, 3);
	data = 4;
	memcpy(str, "jkl", 3);
	SLlist_add_element(list1, &data, 4);
	SLlist_add_element(list2, str, 3);

	ll = 96.069;
	SLlist_add_element(list3, &ll, 8);
	ll = 13.069;
	SLlist_add_element(list3, &ll, 8);
	display_list(*list1);
	display_list(*list2);
	display_list(*list3);
}

void test_queue(void)
{
	printf(KGRN"Testing Queue...\n"KNRM);
	struct queue *string_queue = NULL;
	char buff[100] = {0};
	init_queue(5, &string_queue);
	enqueue(5, "Hello", &string_queue);
	enqueue(5, "World", &string_queue);
	enqueue(4, "ABCD", &string_queue);
	enqueue(4, "BCDE", &string_queue);
	enqueue(3, "XYZ", &string_queue);
	enqueue(3, "AAA", &string_queue);
	enqueue(3, "BBB", &string_queue);
	enqueue(5, "BBBCC", &string_queue);
	display_string_queue(string_queue);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	enqueue(3, "AAA", &string_queue);
	enqueue(3, "BBB", &string_queue);
	enqueue(5, "BBBCC", &string_queue);
	enqueue(3, "AAA", &string_queue);
	enqueue(3, "BBB", &string_queue);
	enqueue(5, "BBBCC", &string_queue);
	display_string_queue(string_queue);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	dequeue(buff, &string_queue);
	printf(KCYN"deq :: %s\n"KNRM, buff);
}

void test_stack(void)
{
	printf(KGRN"Testing Stack...\n"KNRM);
	struct stack *string_stack = NULL;
	char buff[100] = {0};
	init_stack(5, &string_stack);
	push(5, "Hello", &string_stack);
	push(5, "World", &string_stack);
	push(4, "ABCD", &string_stack);
	push(4, "BCDE", &string_stack);
	push(3, "XYZ", &string_stack);
	push(3, "AAA", &string_stack);
	push(3, "BBB", &string_stack);
	push(5, "BBBCC", &string_stack);
	display_string_stack(string_stack);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	push(3, "AAA", &string_stack);
	push(3, "BBB", &string_stack);
	push(5, "BBBCC", &string_stack);
	push(3, "AAA", &string_stack);
	push(3, "BBB", &string_stack);
	push(5, "BBBCC", &string_stack);
	display_string_stack(string_stack);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
	pop(buff, &string_stack);
	printf(KCYN"deq :: %s\n"KNRM, buff);
}

void test_merge_sort(void)
{
	int arr[10] = {0};
	for(int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 65;
	}
	printf("\nOriginal Array :: ");
	disp_arr(arr, 10);
	merge_sort(arr, 0, 9);
	printf("Sorted Array :: ");
	disp_arr(arr, 10);
}

void test_quick_sort(void)
{
	int arr[10] = {0};
	for(int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 65;
	}
	printf("\nOriginal Array :: ");
	disp_arr(arr, 10);
	quick_sort(arr, 0, 9);
	printf("Sorted Array :: ");
	disp_arr(arr, 10);
}



