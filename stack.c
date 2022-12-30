#include "stack.h"

static bool_t stack_full(struct stack *s)
{
	bool_t ret = FAIL;
	if(s)
	{
		if( (s->top + 1) == (s->stack_size) )
		{
			ret = OK;
		}
		else
		{
			ret = FAIL;
		}
	}
	return ret;
}

bool_t init_stack(int stack_size, struct stack **memory )
{
	bool_t ret = FAIL;
	if(*memory)
	{
		;//
	}
	else
	{
		(*memory) = (struct stack *)malloc(sizeof(struct stack)
				+ sizeof(struct stack) * stack_size);
		if(*memory)
		{
			(*memory)->top = -1;
			(*memory)->stack_size = stack_size;
			for(int i = 0; i < stack_size; i++)
			{
				(*memory)->data_items[i].data = NULL;
				(*memory)->data_items[i].data_length = 0;
			}
			ret = OK;
		}
	}

	return ret;
}

bool_t push(int element_size, void *data, struct stack **memory)
{
	bool_t ret = FAIL;
	if(stack_full(*memory) != OK)
	{
		(*memory)->top = ((*memory)->top + 1) % (*memory)->stack_size;
		(*memory)->data_items[(*memory)->top].data = malloc(element_size);
		if((*memory)->data_items[(*memory)->top].data)
		{
			memcpy((*memory)->data_items[(*memory)->top].data, data, element_size);
			(*memory)->data_items[(*memory)->top].data_length = element_size;
		}
		ret = OK;
	}
}

bool_t pop(void *data, struct stack **memory)
{
	bool_t ret = FAIL;
	if(*memory)
	{
		if((*memory)->top != -1)
		{
			memcpy(data, (*memory)->data_items[(*memory)->top].data,
					(*memory)->data_items[(*memory)->top].data_length);
			*(char *)(data + (*memory)->data_items[(*memory)->top].data_length) = '\0';
			free((*memory)->data_items[(*memory)->top].data);
			(*memory)->data_items[(*memory)->top].data_length = 0;
			(*memory)->top = (((*memory)->top - 1) % (*memory)->stack_size);
			if(stack_full(*memory) == OK)
			{
				(*memory)->top = -1;
			}
		}
		else
		{
			*(char *)data = '\0';
			;//Error
		}
	}
}

void display_string_stack(struct stack *m)
{
	if(m)
	{
		for(int i = 0; i < m->stack_size; i++)
		{
			if(m->data_items[i].data)
			{
				for(int j = 0; j < m->data_items[i].data_length; j++)
					printf("%c", *(char *)(m->data_items[i].data + j));
			}
			printf("\t|\t");
		}
		printf("\n");
	}
}
