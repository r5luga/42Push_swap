/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:33:50 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/16 10:30:46 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setup(int argc, char **argv, t_stacks *st, t_flags *flags)
{
	if (ft_parse_flags(argc, argv, flags) == -1)
		return (-1);
	if (flags->clean_argc < 2)
		return (free(flags->clean_argv), 1);
	if (ft_check_args(flags->clean_argc, flags->clean_argv) == -1)
		return (free(flags->clean_argv), 1);
	st->a = NULL;
	st->b = NULL;
	ini_stack(&st->a, flags->clean_argc, flags->clean_argv);
	flags->disorder = ft_disorder(st->a);
	if (flags->disorder == 0.0)
	{
		free_all(st, flags);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks		st;
	t_flags			flags;
	t_bench			bench;
	t_bench			*benchp;
	t_sort_strategy	used_strat;

	if (argc < 2)
		return (ft_putendl_fd("Error", 2), -1);
	if (setup(argc, argv, &st, &flags) != 0)
		return (ft_putendl_fd("Error", 2), 0);
	benchp = NULL;
	if (flags.bench)
	{
		bench = (t_bench){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		benchp = &bench;
	}
	used_strat = sort_stacks(&st, &flags, benchp);
	if (flags.bench)
		ft_print_bench(benchp, flags.disorder, used_strat);
	free_all(&st, &flags);
	return (0);
}
