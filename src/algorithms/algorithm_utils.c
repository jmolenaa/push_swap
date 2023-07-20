/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 13:11:14 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:14:52 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

size_t	lowest(t_number **stack_a)
{
	t_number	*temp;
	size_t		lowest;

	lowest = INT32_MAX;
	temp = *stack_a;
	while (temp != (*stack_a)->prev)
	{
		if (temp->index < lowest)
			lowest = temp->index;
		temp = temp->next;
	}
	if (temp->index < lowest)
		lowest = temp->index;
	return (lowest);
}

size_t	highest(t_number **stack_a)
{
	t_number	*temp;
	size_t		highest;

	highest = 0;
	temp = *stack_a;
	while (temp != (*stack_a)->prev)
	{
		if (temp->index > highest)
			highest = temp->index;
		temp = temp->next;
	}
	if (temp->index > highest)
		highest = temp->index;
	return (highest);
}

size_t	find_steps_up(size_t index, t_number **stack)
{
	size_t		steps;
	t_number	*temp;

	steps = 0;
	temp = *stack;
	while (temp != (*stack)->next)
	{
		if (temp->index == index)
			return (steps);
		steps++;
		temp = temp->prev;
	}
	return (steps);
}

size_t	find_steps_down(size_t index, t_number **stack)
{
	size_t		steps;
	t_number	*temp;

	steps = 0;
	temp = *stack;
	while (temp != (*stack)->prev)
	{
		if (temp->index == index)
			return (steps);
		steps++;
		temp = temp->next;
	}
	return (steps);
}

void	rotate(size_t steps, t_number **stack_a, int rotate)
{
	while (steps > 0)
	{
		if (rotate == ROTATE)
			ra(stack_a);
		else
			rra(stack_a);
		steps--;
	}
}
