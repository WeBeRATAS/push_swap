/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:13:18 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/06 11:16:09 by rbuitrag         ###   ########.fr       */
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
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	find_cheapest(t_stack_node *stack);

//Handle arguments
void		checks_args(int ac, char **av);
int			isduplicate(int i, char **av);
void		check_limits(long n);
void		put_error(void);

// Stack operations
int		find_max(t_stack_node *a);
void	sort_three(t_stack_node **a);


//Stacks initiation
void	stack_init_a(t_stack_node **stack, char **av);
void	stack_init_b(t_stack_node **stack);
void 	free_error(t_stack_node **stack);
void	add_node(t_stack_node **stack, int n);
void	ft_atol(const char *str);

#endif
