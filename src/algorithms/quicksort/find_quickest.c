/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_quickest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 11:02:41 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/10/15 17:29:20 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	adjust_steps(t_rot *rotation, t_rot temp_a, size_t i, t_rotate rotate)
{
	size_t	steps;

	if (rotate == temp_a.direction_a)
	{
		if (i > temp_a.steps_a)
			steps = i;
		else
			steps = temp_a.steps_a;
	}
	else
		steps = i + temp_a.steps_a;
	if (steps < rotation->steps_total)
	{
		rotation->steps_total = steps;
		rotation->direction_b = rotate;
		rotation->steps_b = i;
		rotation->direction_a = temp_a.direction_a;
		rotation->steps_a = temp_a.steps_a;
	}
}

static void	path_down(t_info info, t_rot *rotation, int current_block)
{
	size_t		i;
	t_number	*temp;
	t_rot		temp_a;

	i = 0;
	temp = *info.stack_b;
	if (temp->block != current_block)
	{
		temp = temp->next;
		i++;
	}
	if (temp->block != current_block)
		return ;
	while (i < rotation->steps_total)
	{
		temp_a = find_path_a(temp->index, info.stack_a);
		adjust_steps(rotation, temp_a, i, ROTATE);
		i++;
		temp = temp->next;
		if (temp->block != current_block)
			break ;
	}
}

static void	path_up(t_info info, t_rot *rotation, int current_block)
{
	size_t		i;
	t_number	*temp;
	t_rot		temp_a;

	i = 0;
	temp = *info.stack_b;
	if (temp->block != current_block)
	{
		i++;
		temp = temp->prev;
	}
	if (temp->block != current_block)
		return ;
	while (i < rotation->steps_total)
	{
		temp_a = find_path_a(temp->index, info.stack_a);
		adjust_steps(rotation, temp_a, i, REVERSE_ROTATE);
		i++;
		temp = temp->prev;
		if (temp->block != current_block)
			break ;
	}
}

void	find_path(t_info info, t_rot *rotation, int current_block)
{
	rotation->steps_total = UINT_MAX;
	path_up(info, rotation, current_block);
	path_down(info, rotation, current_block);
}
