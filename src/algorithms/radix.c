/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 17:58:44 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 13:22:58 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_stack_b(t_number **stack_a, t_number **stack_b)
{
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

static void	move_stack_a(t_number **stack_a, t_number **stack_b, size_t test)
{
	t_number	*last;

	last = (*stack_a)->prev;
	while (*stack_a != last)
	{
		if (((*stack_a)->index & test) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (((*stack_a)->index & test) == 0)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

static size_t	get_loop_amount(size_t max_index)
{
	size_t	loops;

	loops = 1;
	while (max_index > 1)
	{
		max_index = max_index >> 1;
		loops++;
	}
	return (loops);
}

void	radix(t_info info)
{
	size_t	test;
	size_t	loops;

	test = 1;
	loops = get_loop_amount(info.size);
	while (loops > 0)
	{
		move_stack_a(info.stack_a, info.stack_b, test);
		move_stack_b(info.stack_a, info.stack_b);
		test = test << 1;
		loops--;
	}
}
