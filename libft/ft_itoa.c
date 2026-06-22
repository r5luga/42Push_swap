/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:22:52 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/25 15:08:58 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	l;
	size_t		len;

	l = n;
	len = ft_size(l) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (l < 0)
	{
		l *= -1;
		str[0] = '-';
	}
	str[--len] = '\0';
	if (l == 0)
		str[0] = '0';
	while (l)
	{
		str[--len] = (l % 10) + '0';
		l /= 10;
	}
	return (str);
}

/*
int main ()
{
	int	c = -124030;
	char	*res;

	res = ft_itoa(c);
	printf("%s\n", res);
}
*/