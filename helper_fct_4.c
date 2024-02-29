#include "push_swap.h"

int count_rotates(int nbr, t_stack *b)
{
	t_stack *temp;
	t_stack *target_node;
	int	cnt;
	int	r_cnt;

	temp = b;
	cnt = 0;
	r_cnt = 0;
	if (inside_interval(nbr, b) == 1)
		return (0);
	while (inside_interval(nbr, temp) == 0)
		temp = temp->next;
	target_node = temp;
	while (temp != b)
	{
		++cnt;
		temp = temp->previous;
	}
	temp = target_node;
	while (temp != b)
	{
		++r_cnt;
		temp = temp->next;
	}
	if (r_cnt < cnt)
		return (-r_cnt);
	return (cnt);
}

int	inside_interval(int nbr, t_stack *b)
{
	if (nbr > find_borders(MAX, b) && b->target == find_borders(MAX, b))
		return (1);
	if (nbr < find_borders(MIN, b) && b->target == find_borders(MAX, b))
		return (1);
	if (nbr > b->target && nbr < b->previous->target)
		return (1);
	return (0);
}