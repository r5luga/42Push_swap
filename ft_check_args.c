/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:49:35 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/12 15:26:08 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static	long	int	ft_atoi_long(const char *str)
{
	long int	num;
	int			i;
	int			neg_pos;

	num = 0;
	i = 0;
	neg_pos = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg_pos = neg_pos * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg_pos);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			return (ft_putendl_fd("Error", 2), -1);
		tmp = ft_atoi_long(args[i]);
		if (ft_contains(tmp, args, i))
			return (ft_putendl_fd("Error", 2), -1);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (ft_putendl_fd("Error", 2), -1);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (0);
}
