#include <stdlib.h>
#include <assert.h>

#define   QUEUE_TYPE    int
#define   QUEUE_SIZE    100
#define   ARRAY_SIZE    (QUEUE_SIZE + 1)

static    QUEUE_TYPE   queue[ARRAY_SIZE];
static    size_t       front = 1;
static    size_t       rear = 0;

void insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear = (rear + 1) % ARRAY_SIZE;//loop
	queue[rear] = value;
}

QUEUE_TYPE delete(void)
{
	QUEUE_TYPE temp;
	assert(!is_empty());
	temp = queue[front];
	front = (front + 1) % ARRAY_SIZE;
	return temp;
}

QUEUE_TYPE first(void)
{
	assert(!is_empty());
	return queue[front];
}

int is_empty(void)
{
	return (rear + 1) % ARRAY_SIZE == front;//as 'empty'
}

int is_full(void)
{
	return (rear + 2) % ARRAY_SIZE == front;//as 'full'
}