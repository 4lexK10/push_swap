#include "push_swap.h"

int count_rotates(int nbr, t_stack *first)
{
	t_stack *temp;
	t_stack *target_node;
	int	cnt;
	int	r_cnt;

	temp = first;
	cnt = 0;
	r_cnt = 0;
	if (nbr < find_borders(MIN, &first) || nbr > first->target)
		return (0);
	while (temp->target > nbr)
		temp = temp->next;
	target_node = temp;
	while (temp != first)
	{
		++cnt;
		temp = temp->previous;
	}
	temp = target_node;
	while (temp != first)
	{
		++r_cnt;
		temp = temp->next;
	}
	if (r_cnt < cnt)
		return (-r_cnt);
	return (cnt);
}
