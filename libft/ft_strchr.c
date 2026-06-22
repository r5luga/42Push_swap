/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:35:13 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 18:19:02 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
	char *str = "This is a test";

	printf("Testing 'T': %s (Expected: This is a test)\n", ft_strchr(str, 'T'));
	printf("Testing 'i': %s (Expected: is is a test)\n", ft_strchr(str, 'i'));
	printf("Testing 'z': %s (Expected: (null))\n", ft_strchr(str, 'z'));
	return (0);
}
*/