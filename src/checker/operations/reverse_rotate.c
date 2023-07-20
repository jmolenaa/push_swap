/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 14:28:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 08:39:05 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_number **head_a, t_number **head_b)
{
	(void)head_b;
	if (*head_a != NULL)
		*head_a = (*head_a)->prev;
}

void	rrb(t_number **head_a, t_number **head_b)
{
	(void)head_a;
	if (*head_b != NULL)
		*head_b = (*head_b)->prev;
}

void	rrr(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->prev;
	if (*head_b != NULL)
		*head_b = (*head_b)->prev;
}
