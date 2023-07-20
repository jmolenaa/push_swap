/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pasjans.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 10:09:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/10 17:54:12 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <sys/errno.h>

static void	find_pasjans_stack(t_number *temp, t_number **stacks)
{
	int	i;

	i = 1;
	if (*stacks == NULL || (*stacks)->index > temp->index)
		*stacks = temp;
	else
	{
		while (*(stacks + i) != NULL)
		{
			if ((*(stacks + i))->index > temp->index)
				break ;
			i++;
		}
		*(stacks + i) = temp;
		temp->left = *(stacks + i - 1);
	}
}

static void	adjust_pasjans_variable(t_number **stacks)
{
	int			i;
	t_number	*temp;

	i = 0;
	while (*(stacks + i) != NULL)
		i++;
	temp = *(stacks + i - 1);
	while (temp != NULL)
	{
		temp->pasjans = 1;
		temp = temp->left;
	}
}

void	pasjans(t_number **stack_a)
{
	t_number	**stacks;
	t_number	*temp;

	stacks = ft_calloc(stack_size(*stack_a) + 1, sizeof(t_number *));
	if (stacks == NULL)
		ft_exit_with_error("Error\n", errno);
	temp = *stack_a;
	while (temp != (*stack_a)->prev)
	{
		find_pasjans_stack(temp, stacks);
		temp = temp->next;
	}
	find_pasjans_stack(temp, stacks);
	adjust_pasjans_variable(stacks);
	free(stacks);
}
