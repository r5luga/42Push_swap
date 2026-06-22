/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:51:21 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/16 10:51:22 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_streq(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

static int	ft_is_flag(const char *arg)
{
	if (ft_streq(arg, "--simple") || ft_streq(arg, "--medium"))
		return (1);
	if (ft_streq(arg, "--complex") || ft_streq(arg, "--adaptive"))
		return (1);
	if (ft_streq(arg, "--bench"))
		return (1);
	return (0);
}

static void	ft_apply_flag(t_flags *flags, const char *arg)
{
	if (ft_streq(arg, "--bench"))
	{
		flags->bench = 1;
		return ;
	}
	if (flags->strategy_set)
		return ;
	if (ft_streq(arg, "--simple"))
		flags->strategy = SORT_SIMPLE;
	else if (ft_streq(arg, "--medium"))
		flags->strategy = SORT_MEDIUM;
	else if (ft_streq(arg, "--complex"))
		flags->strategy = SORT_COMPLEX;
	else if (ft_streq(arg, "--adaptive"))
		flags->strategy = SORT_ADAPTIVE;
	flags->strategy_set = 1;
}

int	ft_parse_flags(int argc, char **argv, t_flags *flags)
{
	int		i;
	int		j;

	flags->strategy = SORT_ADAPTIVE;
	flags->strategy_set = 0;
	flags->bench = 0;
	flags->clean_argv = malloc(sizeof(char *) * (argc + 1));
	if (!flags->clean_argv)
		return (-1);
	j = 0;
	flags->clean_argv[j++] = argv[0];
	i = 1;
	while (i < argc)
	{
		if (ft_is_flag(argv[i]))
			ft_apply_flag(flags, argv[i]);
		else
			flags->clean_argv[j++] = argv[i];
		i++;
	}
	flags->clean_argv[j] = NULL;
	flags->clean_argc = j;
	return (0);
}
