/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 16:17:09 by omimouni         ###   ########.fr       */
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
// char
// 	*ft_gnl(int fd)
// {
// 	static char	*ptr = NULL;
// 	char		*buff;
// 	char		*tmp;
// 	int			read_n;
// 	int			i;

// 	if (fd < 0)
// 		return (NULL);	
// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	while (1)
// 	{
// 		read_n = read(fd, buff, BUFFER_SIZE);
// 		if (read_n > 0)
// 		{
// 			buff[read_n] = '\0';
// 			if (ptr == NULL)
// 				ptr = ft_strdup(buff);
// 			else
// 			{
// 				tmp = ft_strjoin(ptr, buff);
// 				free(ptr);
// 				ptr = tmp;
// 			}
// 			if (ft_strchr(buff, '\n'))
// 				break ;
// 		}
// 		else
// 			break ;
// 	}
// 	free(buff);


// 	// Return error
// 	if (ptr == NULL)
// 		return (NULL);
// 	// Get next line
// 	char	*line;
// 	int		len;

// 	len = 0;
// 	while (ptr[len] != '\n' && ptr[len] != '\0')
// 		len++;
// 	line = malloc(sizeof(char) * (len + 1));
// 	if (ptr[len] == '\n')
// 	{
// 		i = 0;
// 		while (i < len)
// 		{
// 			line[i] = ptr[i];
// 			i++;
// 		}
// 		line[i] = '\0';
// 		tmp = ft_strdup(ptr + len + 1);
// 		free(ptr);
// 		ptr = tmp;
// 		if (ptr[0] == '\0')
// 		{
// 			free(ptr);
// 			ptr = NULL;
// 		}
// 	}
// 	else
// 	{
// 		free(line);
// 		line = ft_strdup(ptr);
// 		free(ptr);
// 		ptr = NULL;
// 	}
// 	return (line);
// }
