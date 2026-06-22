/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:19:53 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/08 12:29:00 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Shift up all elements of a stack by 1. The first element becomes the last one

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}
//Shift up all elements of stack a by 1. The first element becomes the last one

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}
//Shift up all elements of stack b by 1. The first element becomes the last one

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}
//Shift up all elements of stack a and b by 1

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
