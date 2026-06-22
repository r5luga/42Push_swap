/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:17:48 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 18:27:02 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!src || !dst) && !dstsize)
		return (0);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
int main ()
{
	size_t	len;
	const char	p[19] = "Isto vai funcionar";
	char	dest[50] = "0123456789";

	len = ft_strlcat(dest, p, 17);
	printf("%zu | (Expected: 28)\n", len);
	printf("%s | (Expected: 0123456789Isto v)\n", dest);
}
*/