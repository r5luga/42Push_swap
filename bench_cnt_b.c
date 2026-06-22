/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_cnt_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:51:49 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/16 10:51:50 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//counts rotations and reverse rotations
int	ra_cnt(t_list **stack_a, t_bench *b)
{
	int	ret;

	ret = ra(stack_a);
	if (b && ret != -1)
	{
		b->ra++;
		b->total++;
	}
	return (ret);
}

int	rb_cnt(t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = rb(stack_b);
	if (b && ret != -1)
	{
		b->rb++;
		b->total++;
	}
	return (ret);
}

int	rr_cnt(t_list **stack_a, t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = rr(stack_a, stack_b);
	if (b && ret != -1)
	{
		b->rr++;
		b->total++;
	}
	return (ret);
}

int	rra_cnt(t_list **stack_a, t_bench *b)
{
	int	ret;

	ret = rra(stack_a);
	if (b && ret != -1)
	{
		b->rra++;
		b->total++;
	}
	return (ret);
}

int	rrb_cnt(t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = rrb(stack_b);
	if (b && ret != -1)
	{
		b->rrb++;
		b->total++;
	}
	return (ret);
}
