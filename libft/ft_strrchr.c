/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:18:31 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/28 18:02:53 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (i-- == 0)
			return (NULL);
	}
}

/* 
int main(void)
{
	char *str = "This is a test";

	printf("Testing 't': %s (Expected: t)\n", ft_strrchr(str, 't'));
	printf("Testing 'h': %s (Expected: his is a test)\n", ft_strrchr(str, 'h'));
	printf("Testing 's': %s (Expected: st)\n", ft_strrchr(str, 's'));
	printf("Testing 'z': %s (Expected: (null))\n", ft_strrchr(str, 'z'));
	return (0);
} */