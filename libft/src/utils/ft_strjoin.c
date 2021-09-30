/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:14:17 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/30 21:49:32 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(char *s1, char *s2)
{
	int		p;
	int		q;
	int		i;
	char	*tmp;
	
	if (!s1 || !s2)
		return (NULL);
	p = ft_strlen(s1);
	q = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (p + q + 1));
	i = 0;
	while (*s1)
		tmp[i++] = *(s1++);
	while (*s2)
		tmp[i++] = *(s2++);
	tmp[i] = '\0';
	return (tmp);
}
