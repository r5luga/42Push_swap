/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:01:04 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 18:23:17 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize > 0)
	{
		while (j < (dstsize - 1) && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

/*
int main(void)
{
	char	dest[10];
	char	*src = "This is a test";
	size_t	ret;

	ret = ft_strlcpy(dest, src, 10);
	printf("Dest: %s | Return: %zu (Expected: This is a  | 14)\n", dest, ret);
	ret = ft_strlcpy(dest, src, 5);
	printf("Dest: %s | Return: %zu (Expected: This  | 14)\n", dest, ret);
	return (0);
}
*/
