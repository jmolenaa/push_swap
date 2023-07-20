/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 13:08:28 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 11:49:44 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_info info)
{
	size_t		i;
	t_number	*temp;

	temp = *(info.stack_a);
	i = 1;
	if (temp == NULL)
		return (0);
	while (i <= info.size)
	{
		if (i != temp->index)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

size_t	stack_size(t_number *stack)
{
	size_t		i;
	t_number	*temp;

	i = 0;
	temp = stack;
	if (temp)
	{
		while (temp != stack->prev)
		{
			i++;
			temp = temp->next;
		}
		i++;
	}
	return (i);
}

void	free_list(t_number **stack_a)
{
	t_number	*temp;
	t_number	*temp2;
	t_number	*last;

	temp = *(stack_a);
	if (temp == NULL)
		return ;
	last = (*stack_a)->prev;
	while (temp != last)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	free(temp);
}

t_info	set_struct_info(t_number **stack_a, t_number **stack_b)
{
	t_info	info;

	info.size = stack_size(*stack_a);
	info.stack_a = stack_a;
	info.stack_b = stack_b;
	return (info);
}
