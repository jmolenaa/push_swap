/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 14:58:58 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:31:18 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_stacks(t_info info, t_rot rotation)
{
	while (rotation.steps_a > 0 || rotation.steps_b > 0)
	{
		if (rotation.direction_a == rotation.direction_b && \
			rotation.steps_a > 0 && rotation.steps_b > 0)
			rotate_both(info, rotation.direction_a);
		else
		{
			if (rotation.steps_a > 0)
				rotate_a(info.stack_a, rotation.direction_a);
			if (rotation.steps_b > 0)
				rotate_b(info.stack_b, rotation.direction_b);
		}
		if (rotation.steps_a > 0)
			rotation.steps_a--;
		if (rotation.steps_b > 0)
			rotation.steps_b--;
	}
}

static void	get_stacks_into_position(t_info info, int current_block)
{
	t_rot	rotation;

	find_path(info, &rotation, current_block);
	rotate_stacks(info, rotation);
}

void	push_blocks_back(t_info info)
{
	int	current_block;

	current_block = info.blocks;
	while (current_block > 0)
	{
		while (1)
		{
			if (*(info.stack_b) == NULL || \
				((*(info.stack_b))->block != current_block && \
				(*(info.stack_b))->prev->block != current_block && \
				(*(info.stack_b))->next->block != current_block))
				break ;
			get_stacks_into_position(info, current_block);
			pa(info.stack_a, info.stack_b);
		}
		current_block--;
	}
}
