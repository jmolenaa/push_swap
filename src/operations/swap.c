/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 06:46:12 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:24:39 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

void	sa(t_number **head_a)
{
	if (*head_a != NULL)
		swap(head_a);
	ft_printf("sa\n");
}

void	sb(t_number **head_b)
{
	if (*head_b != NULL)
		swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_number **head_a, t_number **head_b)
{
	if (*head_a != NULL)
		swap(head_a);
	if (*head_b != NULL)
		swap(head_b);
	ft_printf("ss\n");
}
