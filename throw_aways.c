#include "push_swap.h"

void    print_stacks(t_stack *a, t_stack *b)
{
    t_stack *curr_a;
    t_stack *curr_b;

    curr_a = a;
    curr_b = b;
	printf("stack a\n");
	if (curr_a)
	{
		printf("content: %d", curr_a->content);
		printf(" target: %d", curr_a->target);
		printf(" value: %d", curr_a->value);
		printf(" posotion: %d", curr_a->position);
		printf(" cost: %d\n", curr_a->cost);
		curr_a = curr_a->next;
		while (curr_a != a)
		{
			printf("content: %d", curr_a->content);
			printf(" target: %d", curr_a->target);
			printf(" value: %d", curr_a->value);
			printf(" posotion: %d", curr_a->position);
			printf(" cost: %d\n", curr_a->cost);
			curr_a = curr_a->next;
		}
	}
	printf("stack b\n");
	if (curr_b)
	{
		printf("content: %d", curr_b->content);
		printf(" target: %d", curr_b->target);
		printf(" value: %d", curr_b->value);
		printf(" posotion: %d", curr_b->position);
		printf(" cost: %d\n", curr_b->cost);
		curr_b = curr_b->next;
		while (curr_b != b)
		{
			printf("content: %d", curr_b->content);
			printf(" target: %d", curr_b->target);
			printf(" value: %d", curr_b->value);
			printf(" posotion: %d", curr_b->position);
			printf(" cost: %d\n", curr_b->cost);
			curr_b = curr_b->next;
		}
	}
	printf("\n");
}
