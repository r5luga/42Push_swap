/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:51:44 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/16 10:51:45 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//counts the reverse rotation of both stacks
int	rrr_cnt(t_list **stack_a, t_list **stack_b, t_bench *b)
{
	int	ret;

	ret = rrr(stack_a, stack_b);
	if (b && ret != -1)
	{
		b->rrr++;
		b->total++;
	}
	return (ret);
}

//puts the disorder percentage in bench txt
static void	bench_disorder(double disorder)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)((disorder * 10000) + 0.5) % 100;
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(whole, 2);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	ft_putnbr_fd(frac, 2);
	write(2, "%\n", 2);
}

//writes the strategy used
static void	bench_strategy(t_sort_strategy strat)
{
	write(2, "[bench] strategy: ", 18);
	if (strat == SORT_SIMPLE)
		write(2, "Simple / O(n^2)\n", 16);
	else if (strat == SORT_MEDIUM)
		write(2, "Medium / O(n*sqrt(n))\n", 22);
	else if (strat == SORT_COMPLEX)
		write(2, "Complex / O(n*log(n))\n", 22);
	else
		write(2, "Adaptive\n", 9);
}

//writes the number of individual operations used
static void	bench_ops_line1(t_bench *b)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(b->sa, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(b->sb, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(b->ss, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(b->pa, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(b->pb, 2);
	write(2, "  ra: ", 6);
	ft_putnbr_fd(b->ra, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(b->rb, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(b->rr, 2);
	write(2, "\n", 1);
}

//writtes the total number of operations used
void	ft_print_bench(t_bench *b, double disorder, t_sort_strategy strat)
{
	bench_disorder(disorder);
	bench_strategy(strat);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(b->total, 2);
	write(2, "\n", 1);
	bench_ops_line1(b);
	write(2, "[bench] rra: ", 13);
	ft_putnbr_fd(b->rra, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(b->rrb, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(b->rrr, 2);
	write(2, "\n", 1);
}
