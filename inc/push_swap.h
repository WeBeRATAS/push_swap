/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:13:18 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/10/01 19:15:20 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack_node
{
	long				num;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Stack functions
bool			is_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_small(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*find_big(t_stack_node *a);
long			ft_atol(char *str);
t_stack_node	*ft_last_node(t_stack_node *upper);
void			init_node(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_index(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);

//Handle arguments
int				check_args(int ac, char **av);
int				ft_isduplicate(int i, char **av);
void			ft_check_limits(long n);
int				ft_isnum(char *s);
void			put_error(void);

// Algorithm Sort operations
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			push_stacks(t_stack_node **a, t_stack_node **b);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			prep_push(t_stack_node **stack, \
		t_stack_node *head_node, char stack_name);

//Stacks initiation
void			stack_init(t_stack_node **stack, char **av);
void			stack_free(t_stack_node **stack);
//void			set_target_node(t_stack_node *a, t_stack_node *b);
void			add_node(t_stack_node **stack, int n, int index);
void			align_on_top(t_stack_node **a);

//Operations
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);

#endif
