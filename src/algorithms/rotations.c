/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:40:08 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/10 15:41:23 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_number **stack_a, t_rotate rotate)
{
	if (rotate == REVERSE_ROTATE)
		rra(stack_a);
	else
		ra(stack_a);
}

void	rotate_b(t_number **stack_b, t_rotate rotate)
{
	if (rotate == REVERSE_ROTATE)
		rrb(stack_b);
	else
		rb(stack_b);
}

void	rotate_both(t_info info, t_rotate rotate)
{
	if (rotate == REVERSE_ROTATE)
		rrr(info.stack_a, info.stack_b);
	else
		rr(info.stack_a, info.stack_b);
}
