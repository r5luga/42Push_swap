/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:50:23 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/23 17:17:43 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_list *stack_a, int size)
{
	t_list	*cur;
	int		min_idx;
	int		min_pos;
	int		pos;

	cur = stack_a;
	min_idx = cur->index;
	min_pos = 0;
	pos = 0;
	while (pos < size)
	{
		if (cur->index < min_idx)
		{
			min_idx = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_list **stack_a, int min_pos, int size,
		t_bench *bench)
{
	int	i;

	if (min_pos <= size / 2)
	{
		i = 0;
		while (i++ < min_pos)
			ra_cnt(stack_a, bench);
	}
	else
	{
		i = 0;
		while (i++ < size - min_pos)
			rra_cnt(stack_a, bench);
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;
	int	remaining;
	int	min_pos;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	remaining = size;
	while (remaining > 0)
	{
		min_pos = find_min_pos(*stack_a, remaining);
		rotate_min_to_top(stack_a, min_pos, remaining, bench);
		if ((ft_disorder(*stack_a) == 0) && *stack_b == NULL)
			break ;
		pb_cnt(stack_a, stack_b, bench);
		remaining--;
	}
	while (*stack_b)
		pa_cnt(stack_a, stack_b, bench);
}
