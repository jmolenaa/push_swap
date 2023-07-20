/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 14:21:26 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 07:49:00 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ra(t_number **head_a)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->next;
	ft_printf("ra\n");
}

void	rb(t_number **head_b)
{
	if (*head_b != NULL)
		*head_b = (*head_b)->next;
	ft_printf("rb\n");
}

void	rr(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->next;
	if (*head_b != NULL)
		*head_b = (*head_b)->next;
	ft_printf("rr\n");
}
