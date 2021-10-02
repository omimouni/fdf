/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:30 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 18:51:07 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 100

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	
	ft_gnl(int fd, char **line);

char
	*ft_strchr(char *s, char c);
char
	*ft_strdup(char *s);
char
	*ft_strjoin(char *s1, char *s2);
int
	ft_strlen(char *s);
char
	**ft_split(char *str, char c);
void
	ft_split_free(char **tab, int n);

char	*ft_substr(char *s, unsigned int start, size_t len);
#endif