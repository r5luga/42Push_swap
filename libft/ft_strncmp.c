/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:15:12 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 18:29:54 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("Test 1: %d (Expected: 0)\n", ft_strncmp("abc", "abc", 3));
	printf("Test 2: %d (Expected: >0)\n", ft_strncmp("abd", "abc", 3));
	printf("Test 3: %d (Expected: <0)\n", ft_strncmp("abc", "abd", 3));
	printf("Test 4: %d (Expected: 0)\n", ft_strncmp("abc", "abd", 2));
	printf("Test 5: %d (Expected: 0)\n", ft_strncmp("test", "testss", 4));
	return (0);
}
*/