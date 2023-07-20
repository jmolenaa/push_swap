/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_quickest_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:56:50 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:23:48 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_steps_a_down(size_t index_b, t_number **stack_a)
{
	size_t		steps;
	size_t		high_a;
	size_t		low_a;
	t_number	*temp;

	high_a = highest(stack_a);
	low_a = lowest(stack_a);
	temp = *stack_a;
	steps = 0;
	while (temp != NULL && temp != (*stack_a)->prev)
	{
		if ((index_b > high_a || index_b < low_a) && temp->index == low_a)
			return (steps);
		if (index_b < temp->index && index_b > temp->prev->index)
			return (steps);
		steps++;
		temp = temp->next;
	}
	return (steps);
}

static size_t	find_steps_a_up(size_t index_b, t_number **stack_a)
{
	size_t		steps;
	size_t		high_a;
	size_t		low_a;
	t_number	*temp;

	high_a = highest(stack_a);
	low_a = lowest(stack_a);
	temp = *stack_a;
	steps = 0;
	while (temp != NULL && temp != (*stack_a)->next)
	{
		if ((index_b > high_a || index_b < low_a) && temp->index == low_a)
			return (steps);
		if (index_b < temp->index && index_b > temp->prev->index)
			return (steps);
		steps++;
		temp = temp->prev;
	}
	return (steps);
}

t_rot	find_path_a(size_t index_b, t_number **stack_a)
{
	size_t	steps_up;
	size_t	steps_down;
	t_rot	temp_a;

	steps_up = find_steps_a_up(index_b, stack_a);
	steps_down = find_steps_a_down(index_b, stack_a);
	if (steps_up < steps_down)
	{
		temp_a.direction_a = REVERSE_ROTATE;
		temp_a.steps_a = steps_up;
	}
	else
	{
		temp_a.direction_a = ROTATE;
		temp_a.steps_a = steps_down;
	}
	return (temp_a);
}
