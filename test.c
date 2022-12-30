#include "test.h"

void test_queue(void)
{
	printf("Testing Queue...\n");
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
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	enqueue(3, "AAA", &string_queue);
	enqueue(3, "BBB", &string_queue);
	enqueue(5, "BBBCC", &string_queue);
	enqueue(3, "AAA", &string_queue);
	enqueue(3, "BBB", &string_queue);
	enqueue(5, "BBBCC", &string_queue);
	display_string_queue(string_queue);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
	dequeue(buff, &string_queue);
	printf("deq :: %s\n", buff);
}

void test_stack(void)
{
	printf("Testing Stack...\n");
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
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	push(3, "AAA", &string_stack);
	push(3, "BBB", &string_stack);
	push(5, "BBBCC", &string_stack);
	push(3, "AAA", &string_stack);
	push(3, "BBB", &string_stack);
	push(5, "BBBCC", &string_stack);
	display_string_stack(string_stack);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
	pop(buff, &string_stack);
	printf("deq :: %s\n", buff);
}



