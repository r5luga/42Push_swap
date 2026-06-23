/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_equal_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:11:57 by lpedroso          #+#    #+#             */
/*   Updated: 2026/06/23 17:25:41 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a, t_bench *bench)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = (*stack_a)->index;
	i2 = (*stack_a)->next->index;
	i3 = (*stack_a)->next->next->index;
	if (i1 > i2 && i2 < i3 && i1 < i3)
		sa_cnt(stack_a, bench);
	else if (i1 > i2 && i2 > i3)
	{
		sa_cnt(stack_a, bench);
		rra_cnt(stack_a, bench);
	}
	else if (i1 > i3 && i2 < i3)
		ra_cnt(stack_a, bench);
	else if (i1 < i2 && i1 > i3)
		rra_cnt(stack_a, bench);
	else if (i1 < i3 && i2 > i3)
	{
		sa_cnt(stack_a, bench);
		ra_cnt(stack_a, bench);
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	min_pos;

	min_pos = ss_find_min_pos(stack_a);
	if (min_pos == 1)
		ra_cnt(stack_a, bench);
	else if (min_pos == 2)
	{
		ra_cnt(stack_a, bench);
		ra_cnt(stack_a, bench);
	}
	else if (min_pos == 3)
		rra_cnt(stack_a, bench);
	pb_cnt(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	pa_cnt(stack_a, stack_b, bench);
}

static void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	pos;

	pos = ss_find_min_pos(stack_a);
	ss_rotate_to_top(stack_a, pos, bench);
	pb_cnt(stack_a, stack_b, bench);
	pos = ss_find_min_pos(stack_a);
	ss_rotate_to_top(stack_a, pos, bench);
	pb_cnt(stack_a, stack_a, bench);
	sort_three(stack_a, bench);
	if ((*stack_a)->index < (*stack_a)->next->value)
		sb_cnt(stack_b, bench);
	pa_cnt(stack_a, stack_b, bench);
	pa_cnt(stack_a, stack_b, bench);
}

void	sort_small(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	if (size == 2)
		ra_cnt(stack_a, bench);
	else if (size == 3)
		sort_three(stack_a, bench);
	else if (size == 4)
		sort_four(stack_a, stack_b, bench);
	else if (size == 5)
		sort_five(stack_a, stack_b, bench);
}
