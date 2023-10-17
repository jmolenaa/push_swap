/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 12:38:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/10/15 17:28:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include "libft.h"

void	check_if_valid_number(char *nbr)
{
	size_t	i;

	i = 0;
	if (*nbr == '0' && *(nbr + 1) != '\0')
		ft_exit_with_error("Error\n", EXIT_FAILURE);
	if (*nbr == '-')
		i++;
	if (i == 1 && (*(nbr + 1) == '\0' || *(nbr + 1) == '0'))
		ft_exit_with_error("Error\n", EXIT_FAILURE);
	while (ft_isdigit(*(nbr + i)))
		i++;
	if (*(nbr + i) != '\0')
		ft_exit_with_error("Error\n", EXIT_FAILURE);
	if (i > 11)
		ft_exit_with_error("Error\n", EXIT_FAILURE);
}

void	free_split_argument(char **array)
{
	size_t	i;

	i = 0;
	while (*(array + i) != NULL)
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

void	check_for_duplicates_and_single_number(t_number *stack_a_head)
{
	t_number	*temp;
	t_number	*temp2;

	temp = stack_a_head;
	if (temp == NULL)
		exit (EXIT_SUCCESS);
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->nbr == temp2->nbr)
				ft_exit_with_error("Error\n", EXIT_FAILURE);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

static t_number	*get_lowest_number(t_number *stack_a_head)
{
	t_number	*temp;
	t_number	*lowest;
	int			number;

	number = INT_MAX;
	lowest = NULL;
	temp = stack_a_head;
	while (temp != stack_a_head->prev)
	{
		if (temp->nbr <= number && temp->index == 0)
		{
			number = temp->nbr;
			lowest = temp;
		}
		temp = temp->next;
	}
	if (temp->nbr <= number && temp->index == 0)
		lowest = temp;
	return (lowest);
}

void	index_numbers(t_number *stack_a_head)
{
	t_number	*lowest;
	size_t		index;

	index = 1;
	while (1)
	{
		lowest = get_lowest_number(stack_a_head);
		if (lowest == NULL)
			break ;
		lowest->index = index;
		index++;
	}
}
