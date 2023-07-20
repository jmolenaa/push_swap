/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 09:28:53 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:26:30 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_order_sorted(t_number **stack_a, size_t lowest_index)
{
	t_number	*temp;

	temp = *(stack_a);
	while (temp->index != lowest_index)
		temp = temp->next;
	if (temp->next->index > temp->prev->index)
		return (0);
	return (1);
}

void	sort_three(t_number **stack_a)
{
	size_t	lowest_index;

	lowest_index = lowest(stack_a);
	if (!is_order_sorted(stack_a, lowest_index))
		sa(stack_a);
	if ((*(stack_a))->index == lowest_index)
		return ;
	else if ((*(stack_a))->next->index == lowest_index)
		ra(stack_a);
	else
		rra(stack_a);
}
