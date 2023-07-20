/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_to_b.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 14:56:57 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:20:02 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pasjans(t_number **stack_a)
{
	t_number	*temp;

	temp = *stack_a;
	while (temp != (*stack_a)->prev)
	{
		if (temp->pasjans == 0)
			return (1);
		temp = temp->next;
	}
	if (temp->pasjans == 0)
		return (1);
	return (0);
}

static int	check_block(t_number **stack_a, size_t block)
{
	t_number	*temp;

	temp = *stack_a;
	while (temp != (*stack_a)->prev)
	{
		if (temp->index <= block && temp->pasjans == 0)
			return (1);
		temp = temp->next;
	}
	if (temp->index <= block && temp->pasjans == 0)
		return (1);
	return (0);
}

static void	consider_node(t_info info, int i, size_t block, size_t half)
{
	if ((*(info.stack_a))->index <= block && (*(info.stack_a))->pasjans == 0)
	{
		(*(info.stack_a))->block = i * 2;
		pb(info.stack_a, info.stack_b);
		if ((*(info.stack_b))->index < half)
		{
			(*(info.stack_b))->block = i * 2 - 1;
			if ((*(info.stack_a))->index <= block && \
				(*(info.stack_a))->pasjans == 0)
				rb(info.stack_b);
			else
				rr(info.stack_a, info.stack_b);
		}
	}
	else
		ra(info.stack_a);
}

static void	push_block(t_info info, int i, size_t block)
{
	size_t	half;

	half = get_half(block);
	while (check_block(info.stack_a, block))
		consider_node(info, i, block, half);
}

void	push_blocks_to_b(t_info *info)
{
	size_t	i;
	size_t	block;

	i = 1;
	block = 0;
	while (check_pasjans(info->stack_a))
	{
		block = block + get_block(*info, block);
		if (block > info->size)
			block = info->size;
		push_block(*info, i, block);
		i++;
	}
	info->blocks = i * 2;
}
