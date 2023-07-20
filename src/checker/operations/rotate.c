/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 14:21:26 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 08:38:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_number **head_a, t_number **head_b)
{
	(void)head_b;
	if (*head_a != NULL)
		*head_a = (*head_a)->next;
}

void	rb(t_number **head_a, t_number **head_b)
{
	(void)head_a;
	if (*head_b != NULL)
		*head_b = (*head_b)->next;
}

void	rr(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		*head_a = (*head_a)->next;
	if (*head_b != NULL)
		*head_b = (*head_b)->next;
}
