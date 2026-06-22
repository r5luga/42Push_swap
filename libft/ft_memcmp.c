/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:04:15 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/24 12:37:47 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*

int main ()
{
	char str1[13];
	char str2[13];
	int res;

	memcpy(str1, "Filho da mãe", 13);
	memcpy(str2, "Filho da mãe", 13);

	res = ft_memcmp(str1, str2, 20);

	if(res > 0)
		printf("str2 is less than str1\n");
	else if(res < 0)
		printf("str1 is less than str2\n");
	else
		printf("str1 is equal to str2\n");
	return(0);
}
*/