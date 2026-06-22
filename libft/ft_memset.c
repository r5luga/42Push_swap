/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:27:39 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/27 12:17:43 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		temp[n - 1] = c;
		n--;
	}
	return (s);
}

// int main(void)
// {
// 	char str[5] = "WHAT\0";
// 	ft_memset(str, 'a', 2);
// 	printf("%s", str);
// 	return (0);
// }