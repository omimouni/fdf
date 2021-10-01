/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:08:30 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 09:14:09 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 100

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char
	*ft_gnl(int fd);
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

#endif