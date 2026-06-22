/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:14:33 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/27 12:22:19 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return (temp + i);
		i++;
	}
	return (0);
}
// int main(void)
// {
// 	const char str[] = "Screw you buster";
// 	const char c = 'w';
// 	char *r;

// 	r = ft_memchr(str, c, 20);
// 	printf("%s",r);
// }