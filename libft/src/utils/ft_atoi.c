/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:33:36 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 11:33:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
