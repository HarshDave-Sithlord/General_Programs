#ifndef QUEUE_H_
#define QUEUE_H_

#include "common.h"

#define AVAILABLE 			0U
#define OCCUPIED		 	1U

struct queue_data{
	int data_length;
	void *data;
};

struct queue{
	int head;
	int tail;
	int queue_size;
	struct queue_data data_items[];
};

bool_t init_queue(int queue_size, struct queue **memory );
bool_t enqueue(int element_size, void *data, struct queue **memory);
bool_t dequeue(void *data, struct queue **memory);
void display_string_queue(struct queue *memory);



#endif /* QUEUE_H_ */
