/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 06:46:12 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:32:39 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_number **head)
{
	int		temp_nbr;
	size_t	temp_index;
	int		temp_pasjans;
	int		temp_block;

	temp_block = (*head)->block;
	(*head)->block = (*head)->next->block;
	(*head)->next->block = temp_block;
	temp_pasjans = (*head)->pasjans;
	(*head)->pasjans = (*head)->next->pasjans;
	(*head)->next->pasjans = temp_pasjans;
	temp_nbr = (*head)->nbr;
	(*head)->nbr = (*head)->next->nbr;
	(*head)->next->nbr = temp_nbr;
	temp_index = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = temp_index;
}

void	sa(t_number **head_a, t_number **head_b)
{
	(void)head_b;
	if (*head_a != NULL)
		swap(head_a);
}

void	sb(t_number **head_a, t_number **head_b)
{
	(void)head_a;
	if (*head_b != NULL)
		swap(head_b);
}

void	ss(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		swap(head_a);
	if (*head_b != NULL)
		swap(head_b);
}
