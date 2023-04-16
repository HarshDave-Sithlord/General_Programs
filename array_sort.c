#include "array_sort.h"

static void swap(int *a, int *b)
{
	if(*a != *b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void disp_arr(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Bubble sort
void bubble_sort(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < (size - i - 1); j++)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

//Selection sort
void selection_sort(int *arr, int size)
{
	int min = 0;
	for(int i = 0; i < size; i++)
	{
		min = arr[i];
		for(int j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				min = j;
			}
		}
	}
}


//Merge sort
static void sort(int *arr, int start, int mid, int end)
{
	int temp[end - start];
	memset(temp, 0, sizeof(temp));
	int i = start;
	int j = mid;
	int k = 0;

	while(i < mid && j <= end)
	{
		if(arr[i] > arr[j])
		{
			temp[k++] = arr[j++];
		}
		else
		{
			temp[k++] = arr[i++];
		}
	}

	while(i < mid)
	{
		temp[k++] = arr[i++];
	}

	while(j <= end)
	{
		temp[k++] = arr[j++];
	}

	k = 0;
	while(start <= end)
	{
		arr[start++] = temp[k++];
	}
}

void merge_sort(int *arr, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		sort(arr, start, mid+1, end);
	}
}


//Quick sort
static int partition(int *arr, int start, int end)
{
	int k = start;
	int pivot = arr[start];
	for(int i = start+1; i <= end; i++)
	{
		if(pivot > arr[i])
		{
			if(arr[k+1] > arr[k])
			{
				swap(&arr[k+1], &arr[k]);
			}
			swap(&arr[i], &arr[k]);
			k++;
		}
	}

	return k;
}

void quick_sort(int *arr, int start, int end)
{
	if(start < end)
	{
		int pivot = partition(arr, start, end);
		quick_sort(arr, start, pivot - 1 );
		quick_sort(arr, pivot + 1, end );
	}
}
