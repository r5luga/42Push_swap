/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:51:15 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/23 17:24:05 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ini_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	assign_indice(*stack, ft_lstsize(*stack));
	if (argc == 2)
		ft_free(args);
}

static t_sort_strategy	resolve_strategy(t_flags *flags)
{
	if (flags->strategy != SORT_ADAPTIVE)
		return (flags->strategy);
	if (flags->disorder < 0.2)
		return (SORT_SIMPLE);
	if (flags->disorder < 0.5)
		return (SORT_MEDIUM);
	return (SORT_COMPLEX);
}

t_sort_strategy	sort_stacks(t_stacks *st, t_flags *flags, t_bench *bench)
{
	t_sort_strategy	strat;

	strat = resolve_strategy(flags);
	if (flags->disorder == 0.0)
		return (strat);
	if (flags->args_2_sort <= 5 && flags->strategy == SORT_ADAPTIVE)
	{
		sort_small(&st->a, &st->b, bench);
	}
	else
	{
		if (strat == SORT_SIMPLE)
			simple_sort(&st->a, &st->b, bench);
		else if (strat == SORT_MEDIUM)
			medium_sort(&st->a, &st->b, bench);
		else
			complex_sort(&st->a, &st->b, bench);
	}
	return (strat);
}

void	free_all(t_stacks *st, t_flags *flags)
{
	free_stack(&st->a);
	free_stack(&st->b);
	free(flags->clean_argv);
}
