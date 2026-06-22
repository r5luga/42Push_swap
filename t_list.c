/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:54:11 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/11 15:23:16 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Creates new node and returns the pointer of it
t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

//Adds the specified node to stack in 1st position
void	ft_lstadd_front(t_list **stack, t_list *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

//Returns the last node of a list 
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

//Adds the specified node to stack in last position
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

//Returns the size of the linked List
int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
