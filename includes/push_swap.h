/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 17:12:25 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:43:31 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef enum e_rotate
{
	REVERSE_ROTATE,
	ROTATE
}	t_rotate;

typedef struct s_rotation
{
	t_rotate	direction_a;
	t_rotate	direction_b;
	size_t		steps_a;
	size_t		steps_b;
	size_t		steps_total;
}				t_rot;

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

// algorithms
void		sort_three(t_number **stack_a);
void		sort_small_list(t_info info);
void		radix(t_info info);
void		quicksort(t_info info);
void		push_blocks_to_b(t_info *info);
void		push_blocks_back(t_info info);
void		pasjans(t_number **stack_a);

// utils
t_info		set_struct_info(t_number **stack_a, t_number **stack_b);
int			is_sorted(t_info info);
size_t		stack_size(t_number *stack);
void		free_list(t_number **stack_a);

// finding quickest path
t_rot		find_path_a(size_t index_b, t_number **stack_a);
void		find_path(t_info info, t_rot *rotation, int current_block);

// rotations
void		rotate_b(t_number **stack_b, t_rotate rotate);
void		rotate_a(t_number **stack_a, t_rotate rotate);
void		rotate_both(t_info info, t_rotate rotate);

// quicksort utils
size_t		get_block(t_info info, size_t previous_block);
size_t		get_half(size_t block);
float		square_root(float i);

// funtions used by algorithms
size_t		lowest(t_number **stack_a);
size_t		highest(t_number **stack_a);
size_t		find_steps_up(size_t index, t_number **stack);
size_t		find_steps_down(size_t index, t_number **stack);
void		rotate(size_t steps, t_number **stack_a, int rotate);

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
void		sa(t_number **head_a);
void		sb(t_number **head_b);
void		ss(t_number **head_a, t_number **head_b);
void		pa(t_number **head_a, t_number **head_b);
void		pb(t_number **head_a, t_number **head_b);
void		rb(t_number **head_b);
void		ra(t_number **head_a);
void		rr(t_number **head_a, t_number **head_b);
void		rra(t_number **head_a);
void		rrb(t_number **head_b);
void		rrr(t_number **head_a, t_number **head_b);

#endif
