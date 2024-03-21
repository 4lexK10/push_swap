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

static	int	big_check(char **av, int ac, char ***pre_stack)
{
	char	*str;
	int	i;

	i = 0;
	if (ft_check(av, ac) == 3)
		return (0);
	if (ft_check(av, ac) == 2)
	{
		str = ft_strjoin("./pushswap ", av[1]); 
		*pre_stack = ft_split(str, ' ');
		free(str);
		if (!(*pre_stack))
			return (write(2, "Error\n", 6), 0);
		while ((*pre_stack)[i] != NULL)
			++i;
		if ((*pre_stack)[1][0] == '\0')
			return (my_free(*pre_stack, NULL), 0);
		ac = i;
		av = NULL;
	}
	if (ft_check(*pre_stack, ac) == 1)
		return (write(2, "Error\n", 6), 0);
	if (ft_check(av, ac) == 1)
		return (write(2, "Error\n", 6), 0);
	return (ac);
}

static void	free_ptr_array(char ***s)
{
	int	i;

	if (!*s)
		return ;
	i = 0;
	if (*s != NULL)
	{
		while ((*s)[i] != NULL)
		{
			free((*s)[i]);
			(*s)[i] = NULL;
			++i;
		}
		free(*s);
		*s = NULL;
	}
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**pre_stack;

	pre_stack = NULL;
	head_a = NULL;
	head_b = NULL;
	ac = big_check(av, ac, &pre_stack);
	if (ac == 0)
		return (0);
	if (pre_stack != NULL)
		head_a = create_stack(pre_stack, ac, &head_a);
	else
		head_a = create_stack(av, ac, &head_a);
	free_ptr_array(&pre_stack);
	if (!head_a)
		return (write(2, "Error\n", 6), 0);
	turk_algo(&head_a, &head_b);
	return (ft_mod_lstclear(&head_a), ft_mod_lstclear(&head_b), 0);
}
