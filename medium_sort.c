/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 08:14:22 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/23 17:30:04 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Chunksort-inspired medium strategy (Martinez, C.): O(n*sqrt(n)).
**
** Phase 1: push all elements to b in sqrt(n) chunk windows.
**   For window [low, low+chunk_sz-1], scan a and push every element
**   in that range. Use sb to keep each chunk segment on b descending,
**   so elements within a chunk arrive in ascending order when pa'd.
**
** Phase 2: insert each b-top into its sorted position in a.
**   Count "smaller" elements in a, rotate a by min(smaller, larger)
**   steps in the cheaper direction, pa, then undo rotation.
*/

static int	ft_isqrt(int n)
{
	int	r;

	r = 1;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, t_chunk *ck,
		t_bench *bench)
{
	int	remaining;
	int	scanned;
	int	high;

	high = ck->chunk + ck->chunk_size - 1;
	remaining = ft_lstsize(*stack_a);
	while (remaining > 0)
	{
		scanned = 0;
		while (scanned < remaining && ((*stack_a)->index < ck->chunk
				|| (*stack_a)->index > high))
			ra_cnt(stack_a, bench), scanned++;
		if (scanned == remaining)
			return ;
		pb_cnt(stack_a, stack_b, bench);
		if (*stack_b && (*stack_b)->next
			&& (*stack_b)->index < (*stack_b)->next->index
			&& (*stack_b)->next->index <= high)
			sb_cnt(stack_b, bench);
		remaining--;
	}
}

static int	count_smaller_in_a(t_list *a, int val, int sorted)
{
	int	smaller;
	int	i;

	smaller = 0;
	i = 0;
	while (i++ < sorted)
	{
		if (a->index < val)
			smaller++;
		a = a->next;
	}
	return (smaller);
}

static void	insert_top_b_into_a(t_list **stack_a, t_list **stack_b, int sorted,
		t_bench *bench)
{
	int	smaller;
	int	larger;
	int	i;

	smaller = count_smaller_in_a(*stack_a, (*stack_b)->index, sorted);
	larger = sorted - smaller;
	i = 0;
	if (smaller <= larger)
	{
		while (i++ < smaller)
			ra_cnt(stack_a, bench);
		pa_cnt(stack_a, stack_b, bench);
		i = 0;
		while (i++ < smaller)
			rra_cnt(stack_a, bench);
		return ;
	}
	while (i++ < larger)
		rra_cnt(stack_a, bench);
	pa_cnt(stack_a, stack_b, bench);
	i = 0;
	while (i++ < smaller)
		rra_cnt(stack_a, bench);
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int		size;
	int		sorted;
	t_chunk	ck;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	ck.chunk_size = ft_isqrt(size);
	ck.total_size = size;
	ck.chunk = 0;
	while (ck.chunk < size)
	{
		push_chunk_to_b(stack_a, stack_b, &ck, bench);
		ck.chunk += ck.chunk_size;
	}
	sorted = 0;
	while (*stack_b)
	{
		insert_top_b_into_a(stack_a, stack_b, sorted, bench);
		sorted++;
	}
}
