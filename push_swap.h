/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedroso <lpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:10 by dda-cruz          #+#    #+#             */
/*   Updated: 2026/06/23 17:23:48 by lpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef enum e_sort_strategy
{
	SORT_SIMPLE,
	SORT_MEDIUM,
	SORT_COMPLEX,
	SORT_ADAPTIVE
}	t_sort_strategy;

typedef struct s_flags
{
	t_sort_strategy	strategy;
	int				strategy_set;
	int				bench;
	char			**clean_argv;
	int				clean_argc;
	double			disorder;
	int				args_2_sort;
}	t_flags;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_insert
{
	int	sorted_len;
	int	remaining_unsorted;
}	t_insert;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef struct s_chunk
{
	int	chunk;
	int	chunk_size;
	int	total_size;
}	t_chunk;

void			printlist(t_list *head);

t_list			*ft_lstnew(int value);
void			ft_lstadd_front(t_list **stack, t_list *new);
t_list			*ft_lstlast(t_list *head);
void			ft_lstadd_back(t_list **stack, t_list *new);
int				ft_lstsize(t_list *head);

int				swap(t_list **stack);
int				sa(t_list **stack_a);
int				sb(t_list **stack_b);
int				ss(t_list **stack_a, t_list **stack_b);

int				push(t_list **stack_to, t_list **stack_from);
int				pa(t_list **stack_a, t_list **stack_b);
int				pb(t_list **stack_a, t_list **stack_b);

int				rotate(t_list **stack);
int				ra(t_list **stack_a);
int				rb(t_list **stack_b);
int				rr(t_list **stack_a, t_list **stack_b);

int				reverse_rotate(t_list **stack);
int				rra(t_list **stack_a);
int				rrb(t_list **stack_b);
int				rrr(t_list **stack_a, t_list **stack_b);

void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_free(char **str);
void			free_stack(t_list **stack);

int				ft_check_args(int argc, char **argv);
void			assign_indice(t_list *stack_a, int size);
double			ft_disorder(t_list *stack_a);

int				ss_find_min_pos(t_list **stack_a);
void			ss_rotate_to_top(t_list **stack_a, int pos, t_bench *bench);
void			sort_small(t_list **stack_a, t_list **stack_b, t_bench *bench);
void			simple_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void			medium_sort(t_list **stack_a, t_list **stack_b,
					t_bench *bench);
void			complex_sort(t_list **stack_a, t_list **stack_b,
					t_bench *bench);
int				get_median_index(t_list *stack_a, int size);
void			sort_small_3(t_list **stack_a, t_bench *bench);
void			insert_b_into_a(t_list **stack_a, t_list **stack_b,
					int sorted_size, t_bench *bench);
int				ft_isqrt_ceil(int n);
int				in_chunk(int index, t_chunk *ck);
void			pop_and_insert(t_list **stack_a, t_list **stack_b,
					t_insert *ins, t_bench *bench);

int				ft_parse_flags(int argc, char **argv, t_flags *flags);
void			ini_stack(t_list **stack, int argc, char **argv);
t_sort_strategy	sort_stacks(t_stacks *st, t_flags *flags, t_bench *bench);
void			free_all(t_stacks *st, t_flags *flags);

int				sa_cnt(t_list **a, t_bench *b);
int				sb_cnt(t_list **s, t_bench *b);
int				ss_cnt(t_list **a, t_list **s, t_bench *b);
int				pa_cnt(t_list **a, t_list **s, t_bench *b);
int				pb_cnt(t_list **a, t_list **s, t_bench *b);
int				ra_cnt(t_list **a, t_bench *b);
int				rb_cnt(t_list **s, t_bench *b);
int				rr_cnt(t_list **a, t_list **s, t_bench *b);
int				rra_cnt(t_list **a, t_bench *b);
int				rrb_cnt(t_list **s, t_bench *b);
int				rrr_cnt(t_list **a, t_list **s, t_bench *b);
void			ft_print_bench(t_bench *b, double disorder, t_sort_strategy s);

#endif
