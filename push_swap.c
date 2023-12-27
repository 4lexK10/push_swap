#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac <= 1 || ft_check(av, ac))
		return (printf("no good\n"));
	printf("good\n");
	return (0);
}
