/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:51:14 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 12:39:45 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	l;

	l = 0;
	if ((int)start > ft_strlen(s))
	{
		ptr = (char *)malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	while (l < len && s[l + start] != '\0')
		l++;
	ptr = (char *)malloc(sizeof(char) * l + 1);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
