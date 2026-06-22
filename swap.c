/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:10:09 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/11 14:17:37 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps first two elements of a stack

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_putendl_fd("Error occured while swapping!", 1);
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}
//Swaps the first 2 elements of stack a

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}
//Swaps the first 2 elements of stack b

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}
//Swaps the first 2 elements of stack a and stack b

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
