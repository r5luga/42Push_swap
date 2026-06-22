/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:18:14 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/28 11:40:33 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && !len)
		return (0);
	if (little[0] == '\0' || little == big)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/* 
int main(void)
{
	char *str = "This is a test";

	printf("Test 1: %s \n", ft_strnstr(str, "is", 20));
	printf("Test 2: %s \n", ft_strnstr(str, "This", 20));
	printf("Test 3: %s \n", ft_strnstr(str, "test", 20));
	printf("Test 4: %s \n", ft_strnstr(str, "\0", 10));
	printf("Test 5: %s \n", ft_strnstr(str, "h", 1));
	return (0);
}
 */