#include "../includes/push_swap.h"

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r'
			|| *str == ' '))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
