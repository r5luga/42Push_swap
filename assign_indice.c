/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cruz <dda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:59:44 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/11 14:02:07 by dda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//follows the Lomuto partition algoritm
static	int	lomuto_partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}

//quicksorts the array
static	void	quicksort(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

//
static	int	put_index(int *array, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] == target)
			return (mid);
		else if (array[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	assign_indice(t_list *stack_a, int size)
{
	int		*temp;
	int		i;
	t_list	*current;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return ;
	current = stack_a;
	i = 0;
	while (current)
	{
		temp[i++] = current->value;
		current = current->next;
	}
	quicksort(temp, 0, size - 1);
	current = stack_a;
	while (current)
	{
		current->index = put_index(temp, size, current->value);
		current = current->next;
	}
	free(temp);
}
/* 
int	main(void)
{
	t_list	*stack_a;
	t_list	*current;
	int		size;

	stack_a = NULL;
	ft_lstadd_back(&stack_a, ft_lstnew(5));
	ft_lstadd_back(&stack_a, ft_lstnew(-3));
	ft_lstadd_back(&stack_a, ft_lstnew(42));
	ft_lstadd_back(&stack_a, ft_lstnew(1));
	ft_lstadd_back(&stack_a, ft_lstnew(17));
	
	size = ft_lstsize(stack_a);
	assign_indice(stack_a, size);

	current = stack_a;
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putendl_fd(" -> index: ", 1);
		ft_putnbr_fd(current->index, 1);
		ft_putendl_fd("\n", 1);
		current = current->next;
	}
	return (0);
}
 */