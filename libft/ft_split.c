/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:33:18 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/28 12:23:35 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_free_all(char **lst, int i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
	return (NULL);
}

static char	**ft_fill(char **lst, char const *s, char c)
{
	size_t	word_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			word_len = 0;
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			lst[j] = ft_substr(s, i, word_len);
			if (!lst[j])
				return (ft_free_all(lst, j));
			j++;
			i = i + word_len;
		}
	}
	lst[j] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
	{
		return (NULL);
	}
	lst = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!lst)
	{
		return (NULL);
	}
	return (ft_fill(lst, s, c));
}

/* 
int	main(void)
{
	char str[] = "   ";
	char **str1;
	str1 = ft_split(str,' ');
	while(*str1)
	{
		printf("%s\n",*str1++);
	}
	free(str1);
}
 */
