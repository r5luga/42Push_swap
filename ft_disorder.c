/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:32:19 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/12 13:38:26 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Gets the disorder value from 0.0 to 1.0,the bigger the more disordelly
double	ft_disorder(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;
	int		mistakes;
	int		pairs;

	mistakes = 0;
	pairs = 0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)pairs);
}
