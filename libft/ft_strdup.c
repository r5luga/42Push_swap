/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:13:21 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/28 12:06:19 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc (sizeof(char) * len);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
int	main (void)
{
	char	*c = "Is it correct";
	char	*d;

	d = (ft_strdup(c));
	printf ("%s", d);
	free(d);
}
*/