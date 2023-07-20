/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 12:56:37 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:10:32 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_position(int steps, t_number **stack_a, t_rotate rotate)
{
	while (steps > 0)
	{
		rotate_a(stack_a, rotate);
		steps--;
	}
}

static void	push_lowest(t_info info)
{
	size_t	steps;
	size_t	size;

	size = stack_size(*(info.stack_a));
	steps = find_steps_up(lowest(info.stack_a), info.stack_a);
	if (steps < size - steps)
		put_in_position(steps, info.stack_a, REVERSE_ROTATE);
	else
		put_in_position(size - steps, info.stack_a, ROTATE);
	pb(info.stack_a, info.stack_b);
}

static void	sort_less_than_ten(t_info info)
{
	while ((*(info.stack_a))->next->next != (*(info.stack_a))->prev)
		push_lowest(info);
	sort_three(info.stack_a);
	while (*(info.stack_b) != NULL)
		pa(info.stack_a, info.stack_b);
}

void	sort_small_list(t_info info)
{
	if (info.size == 2)
		sa(info.stack_a);
	else if (info.size == 3)
		sort_three(info.stack_a);
	else
		sort_less_than_ten(info);
}
