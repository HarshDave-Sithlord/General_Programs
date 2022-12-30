#include "queue.h"

static bool_t queue_full(struct queue *q)
{
	bool_t ret = FAIL;
	if(q)
	{
		if( ((q->head + 1) % q->queue_size) == ((q->tail) % q->queue_size) )
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

bool_t init_queue(int queue_size, struct queue **memory )
{
	bool_t ret = FAIL;
	if(*memory)
	{
		//resize... either shrink or grow
	}
	else
	{
		*memory = (struct queue *)malloc( sizeof(struct queue) + (sizeof(struct queue_data) * queue_size) );
		if(*memory)
		{
			(*memory)->head = -1;
			(*memory)->tail = -1;
			(*memory)->queue_size = queue_size;
			for(int i = 0; i < queue_size; i++)
			{
				(*memory)->data_items[i].data = NULL;
				(*memory)->data_items[i].data_length = 0;
			}
		}
	}
	return ret;
}

bool_t enqueue(int element_size, void *data, struct queue **memory)
{
	bool_t ret = FAIL;
	if(*memory)
	{
		if(queue_full(*memory) == FAIL)
		{
			if((*memory)->head == -1 && (*memory)->tail == -1)
			{
				(*memory)->tail = 0;
			}

			(*memory)->head = (((*memory)->head + 1) % (*memory)->queue_size);
			(*memory)->data_items[(*memory)->head].data = malloc(element_size);
			(*memory)->data_items[(*memory)->head].data_length = element_size;
			if((*memory)->data_items[(*memory)->head].data)
			{
				memcpy((*memory)->data_items[(*memory)->head].data, data, element_size);
			}
			else
			{
				;// Error
			}
			ret = OK;
		}
		else
		{
			;//Error
		}
	}

	return ret;
}

bool_t dequeue(void *data, struct queue **memory)
{
	bool_t ret = FAIL;
	if(*memory)
	{
		if((*memory)->tail != -1)
		{
			memcpy(data, (*memory)->data_items[(*memory)->tail].data,
					(*memory)->data_items[(*memory)->tail].data_length);
			*(char *)(data + (*memory)->data_items[(*memory)->tail].data_length) = '\0';
			free((*memory)->data_items[(*memory)->tail].data);
			(*memory)->data_items[(*memory)->tail].data_length = 0;
			(*memory)->tail = (((*memory)->tail + 1) % (*memory)->queue_size);
			if(queue_full(*memory) == OK)
			{
				(*memory)->head = -1;
				(*memory)->tail = -1;
			}
		}
		else
		{
			*(char *)data = '\0';
			;//Error
		}
	}
}

void display_string_queue(struct queue *m)
{
	if(m)
	{
		for(int i = 0; i < m->queue_size; i++)
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
