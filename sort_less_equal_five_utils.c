/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_equal_five_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:31:22 by lpedroso          #+#    #+#             */
/*   Updated: 2026/06/23 17:27:32 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss_find_min_pos(t_list **stack_a)
{
	int		pos;
	int		i;
	t_list	*a;

	i = 0;
	a = *stack_a;
	while (a)
	{
		if (a->index == 0)
			pos = i;
		a = a->next;
		i++;
	}
	return (pos);
}

void	ss_rotate_to_top(t_list **stack_a, int pos, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra_cnt(stack_a, bench);
	else
		while (pos++ < size)
			rra_cnt(stack_a, bench);
}
