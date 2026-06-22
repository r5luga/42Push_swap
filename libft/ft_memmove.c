/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:44:44 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 18:07:57 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (s1 > s2)
	{
		i = n;
		while (i-- > 0)
			((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
			i++;
		}
	}
	return (s1);
}

/*
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
	
int main(void)
{
	char str1[15];
	char str2[20];
	ft_strcpy(str1, "This is a test");
	puts(str1);
	ft_memmove(str2, str1, 20);
	puts(str2);
	return (0);
}
*/