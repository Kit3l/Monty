#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct stack
{
	int data[MAX_STACK_SIZE];
	int top;
} stack_t;

void push(stack_t *stack, int value)
{
	if (stack->top == MAX_STACK_SIZE - 1)
	{
		printf("Error: stack overflow\n");
		return;
	}

	stack->data[++stack->top] = value;
}

int main(int ac, char **av)
{
	stack_t stack;
	stack.top = -1;

	if (ac < 2)
	{
		printf("L%d: usage: push integer\n", __LINE__);
		return EXIT_FAILURE;
	}

	int value = atoi(av[1]);
	push(&stack, value);

	printf("pall:");
	for (int i = stack.top; i >= 0; i--)
	{
		printf(" %d", stack.data[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

