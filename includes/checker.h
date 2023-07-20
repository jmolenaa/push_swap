/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 08:06:25 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:37:00 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>

typedef struct s_number
{
	int				nbr;
	size_t			index;
	struct s_number	*next;
	struct s_number	*prev;
	struct s_number	*left;
	int				pasjans;
	int				block;
}					t_number;

typedef struct s_info
{
	size_t		size;
	int			blocks;
	t_number	**stack_a;
	t_number	**stack_b;
}				t_info;

// utils
t_info		set_struct_info(t_number **stack_a, t_number **stack_b);
int			is_sorted(t_info info);
size_t		stack_size(t_number *stack);
void		free_list(t_number **stack_a);

// functions for parsing
t_number	*parse_input(int argc, char *argv[]);
void		free_split_argument(char **array);
void		check_if_valid_number(char *nbr);
void		check_for_duplicates_and_single_number(t_number *stack_a_head);
void		index_numbers(t_number *stack_a_head);

// funtions for parsing the input and putting in list
void		link_end_to_head(t_number *stack_a_head);
t_number	*create_new_node(int number);
void		add_node_to_stack_a(t_number *new_node, t_number **stack_a_head);

// operations
void		sa(t_number **head_a, t_number **head_b);
void		sb(t_number **head_a, t_number **head_b);
void		ss(t_number **head_a, t_number **head_b);
void		pa(t_number **head_a, t_number **head_b);
void		pb(t_number **head_a, t_number **head_b);
void		ra(t_number **head_a, t_number **head_b);
void		rb(t_number **head_a, t_number **head_b);
void		rr(t_number **head_a, t_number **head_b);
void		rra(t_number **head_a, t_number **head_b);
void		rrb(t_number **head_a, t_number **head_b);
void		rrr(t_number **head_a, t_number **head_b);

#endif