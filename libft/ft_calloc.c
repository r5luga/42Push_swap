/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:04:03 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/04/30 08:19:57 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*mem;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	if (elsize > (((size_t)-1) / nelem))
		return (NULL);
	mem = malloc(nelem * elsize);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, (nelem * elsize));
	return (mem);
}
/*
int main(void)
{
	int	*arr;
	size_t	n = 5;
	size_t	i;

	arr = (int *)ft_calloc(n, sizeof(int));
	if (!arr)
	{
		printf("Allocation failed\n");
		return (1);
	}
	
	printf("Array values (should all be 0):\n");
	i = 0;
	while (i < n)
	{
		printf("arr[%zu]: %d\n", i, arr[i]);
		i++;
	}

	free(arr);
	return (0);
}
*/