/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/30 00:08:39 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 1

char
	*ft_gnl(int fd)
{
	static char	*ptr = NULL;
	char		*buff;
	char		*tmp;
	int			read_n;
	int			i;

	if (fd < 0)
		return (NULL);	

	// Read until reaching \n
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_n = read(fd, buff, BUFFER_SIZE);
		if (read_n > 0)
		{
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
		else
		{
			break ;
		}
	}
	free(buff);


	// Return error
	if (ptr == NULL && read_n == 0)
	{
		return (NULL);
	}
	// Get next line
	char	*line;
	int		len;

	len = 0;
	while (ptr[len] != '\n' && ptr[len] != '\0')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (ptr[len] == '\n')
	{
		i = 0;
		while (i < len)
		{
			line[i] = ptr[i];
			i++;
		}
		line[i] = '\0';
		tmp = ft_strdup(ptr + len + 1);
		free(ptr);
		ptr = tmp;
		if (ptr[0] == '\0')
		{
			free(ptr);
			ptr = NULL;
		}
	}
	else
	{
		free(line);
		line = ft_strdup(ptr);
		free(ptr);
		ptr = NULL;
	}

	printf("-> %s \n", line);

	return (line);
}
