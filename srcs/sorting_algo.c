#include "../includes/push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp2 && temp2->next)
	{
		if (temp2->index > temp->index)
			temp = temp2;
		temp2 = temp2->next;
	}
	return (temp);
}

int	get_max_bits(int nb)
{
	int	i;

	i = 0;
	while (nb >> i)
		i++;
	return (i);
}

void	ft_putback_in_stck(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_exec_cmd("pa", stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, \
					t_stack *temp1, t_stack *temp2)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	temp1 = NULL;
	size = get_size(stack_a);
	//printf("%d\n", size);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size + 1)
		{
			temp1 = *stack_a;
			if (((temp1->num >> i) & 1) == 1)
				ft_exec_cmd("ra", stack_a, stack_b);
			else
				ft_exec_cmd("pb", stack_a, stack_b);
			++j;
		}
		ft_putback_in_stck(stack_a, stack_b);
		++i;
	}
	while ((*stack_a)->num != get_minimum(stack_a))
		ft_exec_cmd("ra", stack_a, stack_b);
}

char	**ft_cpy_num(int ac, char **av)
{
	char	**ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char *) * (ac + 1));
	i = 0;
	j = 1;
	while (i < ac)
	{
		ret[i] = ft_strdup(av[j]);
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_normalize(t_stack **stack, int ac, char **av)
{
	int		i;
	int		j;
	int		size;
	t_stack	*temp;
	char	**cpy;

	i = 0;
	temp = *stack;
	size = get_size(&temp);
	//ft_print_lst(&temp, &temp);
	cpy = ft_cpy_num(ac, av);
	ft_print_lst(&temp, &temp);
	//quicksort(av + 1, 0, size - 1);
	
	/*while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_atoi(cpy[i]) == (temp + j)->num)
				(temp + j)->index = i;
			j++;
			//printf("i = %d, j = %d", i, j);
		}
		i++;
	}*/
	return ;
}
