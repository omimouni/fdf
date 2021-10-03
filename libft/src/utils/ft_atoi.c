#include "fdf.h"

int
	ft_atoi(const char *str)
{
	double	sum;
	int		is_neg;

	sum = 0;
	is_neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (*str)
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum * is_neg);
}
