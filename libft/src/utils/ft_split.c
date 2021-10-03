/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:41:43 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 18:40:59 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_word(char *str, int i, int *nbword, int c)
{
	*nbword += 1;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

void
	ft_split_free(char **tab, int n)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < n)
			free(tab[i++]);
		free(tab);
	}
	tab = NULL;
}

static int
	ft_add_word(char **tab, char *str, int *nbword, int c)
{
	int		wlen;
	int		j;
	char	*tmp;
	int		sv;

	wlen = 0;
	sv = 0;
	while (str[wlen] != c && str[wlen] != '\0')
		wlen++;
	tmp = (char *)malloc((wlen + 1) * sizeof(char));
	tmp[wlen] = '\0';
	j = 0;
	while (sv < wlen)
	{
		tmp[j] = str[sv++];
		j++;
	}
	tab[*nbword] = tmp;
	*nbword += 1;
	return (wlen);
}

static void
	reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char
	**ft_split(char *str, char c)
{
	int		i;
	char	**tab;
	int		number_words;

	reset(&i, &number_words);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		if (str[i] != c)
			i = ft_word(str, i, &number_words, c);
	else
		i++;
	tab = (char **)malloc((number_words + 1) * sizeof(char *));
	tab[number_words] = 0;
	reset(&i, &number_words);
	while (str[i] != '\0')
		if (str[i] != c)
			i += ft_add_word(tab, str + i, &number_words, c);
	else
		i++;
	if (!number_words && !tab)
		return (NULL);
	return (tab);
}
