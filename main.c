#include "queue.h"


void main(void)
{
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
