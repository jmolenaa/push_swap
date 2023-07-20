/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:52:01 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:29:52 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include <sys/errno.h>

void	reset_lowest(t_number **stack_a)
{
	size_t	steps_up;
	size_t	steps_down;

	steps_up = find_steps_up(lowest(stack_a), stack_a);
	steps_down = find_steps_down(lowest(stack_a), stack_a);
	if (steps_up < steps_down)
		rotate(steps_up, stack_a, REVERSE_ROTATE);
	else
		rotate(steps_down, stack_a, ROTATE);
}

void	quicksort(t_info info)
{
	pasjans(info.stack_a);
	push_blocks_to_b(&info);
	reset_lowest(info.stack_a);
	push_blocks_back(info);
	reset_lowest(info.stack_a);
}
