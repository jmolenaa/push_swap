/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 08:46:47 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/21 14:15:41 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	set_first_stack(t_number **from, t_number *pushed)
{
	if (pushed->next == pushed)
		*from = NULL;
	else
	{
		*from = pushed->next;
		pushed->prev->next = pushed->next;
		pushed->next->prev = pushed->prev;
	}
}

static void	set_second_stack(t_number **to, t_number *pushed)
{
	t_number	*temp;

	temp = *to;
	if (temp == NULL)
	{
		pushed->next = pushed;
		pushed->prev = pushed;
	}
	else
	{
		pushed->next = temp;
		pushed->prev = temp->prev;
		temp->prev->next = pushed;
		temp->prev = pushed;
	}
	*to = pushed;
}

static void	push(t_number **from, t_number **to)
{
	t_number	*pushed;

	pushed = *from;
	if (*from == NULL)
		return ;
	set_first_stack(from, pushed);
	set_second_stack(to, pushed);
}

void	pa(t_number **head_a, t_number **head_b)
{
	push(head_b, head_a);
	ft_printf("pa\n");
}

void	pb(t_number **head_a, t_number **head_b)
{
	push(head_a, head_b);
	ft_printf("pb\n");
}
