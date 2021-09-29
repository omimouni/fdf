/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/29 23:33:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 2

char
	*ft_gnl(int fd)
{
	static char	*ptr = NULL;
	char		*buff;
	char		*tmp;
	int			read_n;

	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_n = 1;
	while (read_n > 0)
	{
		read_n = read(fd, buff, BUFFER_SIZE);
		buff[read_n] = '\0';
		if (ptr == NULL)
			ptr = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(ptr, buff);
			free(ptr);
			ptr = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	printf("-> %s \n", ptr);
}
