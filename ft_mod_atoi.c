/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:27 by akloster          #+#    #+#             */
/*   Updated: 2023/10/23 11:28:33 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

static int	overflow(long sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int	sign;
	int	nb;
	int	temp;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = nb;
		printf("temp->%d\n", temp);
		nb = nb * 10 + str[i++] - '0';
		printf("nb->%d\n", nb);
		if (temp > nb && !(nb == INT_MIN && sign == -1))
			return (overflow(sign));
	}
	nb = (nb * sign);
	return (nb);
}

#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("ft_atoi = %d\n", ft_atoi(av[1]));
	printf("atoi    = %d\n", atoi(av[1]));
	return(0);
}
