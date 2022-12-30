#ifndef STACK_H_
#define STACK_H_

#include "common.h"

struct stack_data{
	int data_length;
	void *data;
};

struct stack{
	int top;
	int stack_size;
	struct stack_data data_items[];
};

bool_t init_stack(int stack_size, struct stack **memory );
bool_t push(int element_size, void *data, struct stack **memory);
bool_t pop(void *data, struct stack **memory);
void display_string_stack(struct stack *memory);




#endif /* STACK_H_ */
