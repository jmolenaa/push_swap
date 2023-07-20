/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 14:28:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 07:48:26 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rra(t_number **head_a)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->prev;
	ft_printf("rra\n");
}

void	rrb(t_number **head_b)
{
	if (*head_b != NULL)
		*head_b = (*head_b)->prev;
	ft_printf("rrb\n");
}

void	rrr(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->prev;
	if (*head_b != NULL)
		*head_b = (*head_b)->prev;
	ft_printf("rrr\n");
}
