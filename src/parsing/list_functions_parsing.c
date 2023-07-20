/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_functions_parsing.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 12:30:54 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:26:01 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	add_node_to_stack_a(t_number *new_node, t_number **stack_a_head)
{
	t_number	*temp;

	temp = *stack_a_head;
	if (temp == NULL)
		*stack_a_head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

t_number	*create_new_node(int number)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	if (new == NULL)
		return (NULL);
	new->nbr = number;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	new->left = NULL;
	new->pasjans = 0;
	return (new);
}

void	link_end_to_head(t_number *stack_a_head)
{
	t_number	*temp;

	temp = stack_a_head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = stack_a_head;
	stack_a_head->prev = temp;
}
