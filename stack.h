
#include <assert.h>

#define STACK_TYPE int
#define STACK_SIZE 100

static    STACK_TYPE stack[STACK_SIZE];
static    int        top_element = 1;

void push(STACK_TYPE value)
{
	assert(!is_full());
	stack[++top_element] = value;
}

STACK_TYPE pop(void)
{
	assert(!is_empty());
	return stack[top_element--];
}

STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

int is_empty(void)
{
	return top_element == -1;
}

int is_full(void)
{
	return top_element == STACK_SIZE - 1;
=======
#include <assert.h>

#define STACK_TYPE int
#define STACK_SIZE 100

static STACK_TYPE stack[STACK_SIZE];
static int        top_element = 1;

void push(STACK_TYPE value)
{
	assert(!is_full());
	stack[++top_element] = value;
}

STACK_TYPE pop(void)
{
	assert(!is_empty());
	return stack[top_element--];
}

STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

int is_empty(void)
{
	return top_element == -1;
}

int is_full(void)
{
	return top_element == STACK_SIZE - 1;
>>>>>>> 13656ecb156b237b7423085eeba95cd12f125e32
}