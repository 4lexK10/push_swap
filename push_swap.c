/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:32:19 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 11:39:05 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;

	i = 0;
	if (ft_check(av, ac) == 3)
		return (0);
	if (ft_check(av, ac) == 2)
	{
		av = ft_split(ft_strjoin("./pushswap ", av[1]), ' ');
		while (av[i] != NULL)
			++i;
		if (av[1][0] == '\0')
			return (0);
		ac = i;
	}
	if (ft_check(av, ac) == 1)
		return (write(1, "Error\n", 6));
	head_a = NULL;
	head_b = NULL;
	head_a = create_stack(av, ac, &head_a);
	turk_algo(&head_a, &head_b);
	print_stacks(head_a, head_b);
	return (ft_mod_lstclear(&head_a), ft_mod_lstclear(&head_b), 0);
}
