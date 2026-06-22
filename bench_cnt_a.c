/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_cnt_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:51:55 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/16 10:51:56 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Counts swaps and pushes
int	sa_cnt(t_list **stack_a, t_bench *b)
{
	int	ret;

	ret = sa(stack_a);
	if (b && ret != -1)
	{
		b->sa++;
		b->total++;
	}
	return (ret);
}

int	sb_cnt(t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = sb(stack_b);
	if (b && ret != -1)
	{
		b->sb++;
		b->total++;
	}
	return (ret);
}

int	ss_cnt(t_list **stack_a, t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = ss(stack_a, stack_b);
	if (b && ret != -1)
	{
		b->ss++;
		b->total++;
	}
	return (ret);
}

int	pa_cnt(t_list **stack_a, t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = pa(stack_a, stack_b);
	if (b && ret != -1)
	{
		b->pa++;
		b->total++;
	}
	return (ret);
}

int	pb_cnt(t_list **stack_a, t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = pb(stack_a, stack_b);
	if (b && ret != -1)
	{
		b->pb++;
		b->total++;
	}
	return (ret);
}
