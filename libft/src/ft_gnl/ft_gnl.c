/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 19:13:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_read_buffer(int fd, char **ptr)
{
	char	*buffer;
	char	*tmp;
	int		n;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (*ptr == NULL)
			*ptr = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*ptr, buffer);
			free(*ptr);
			*ptr = tmp;
		}
		if (ft_strchr(*ptr, '\n'))
			break ;
	}
	free(buffer);
	return (n);
}

int	ft_set_line(char **ptr, int len, char **line)
{
	char	*tmp;

	if ((*ptr)[len] == '\n')
	{
		free(*line);
		*line = ft_substr(*ptr, 0, len);
		tmp = ft_strdup(*ptr + len + 1);
		free(*ptr);
		*ptr = tmp;
	}
	else
	{
		free(*line);
		*line = ft_strdup(*ptr);
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	return (1);
}

int	ft_gnl(int fd, char **line)
{
	static char	*ptr[1024];
	int			n;
	int			len;

	if (fd < 0 || line == NULL)
		return (-1);
	n = ft_read_buffer(fd, &ptr[fd]);
	if (n < 0)
		return (-1);
	*line = ft_strdup("");
	if (n == 0 && (ptr[fd] == NULL))
		return (0);
	len = 0;
	while (ptr[fd][len] != '\n' && ptr[fd][len] != '\0')
		len++;
	return (ft_set_line(&ptr[fd], len, line));
}

