/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 17:08:37 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 11:51:16 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <sys/errno.h>

static int	change_string_to_number(char *str)
{
	long int	number;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	number = 0;
	if (*(str) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(str + i) != '\0')
	{
		number = number * 10 + *(str + i) - 48;
		i++;
	}
	number = number * sign;
	if (number > INT32_MAX || number < INT32_MIN)
		ft_exit_with_error("Error\n", EXIT_FAILURE);
	return ((int)number);
}

static void	parse_single_number(char *number_str, t_number **stack_a_head)
{
	int			number;
	t_number	*new_node;

	check_if_valid_number(number_str);
	number = change_string_to_number(number_str);
	new_node = create_new_node(number);
	if (new_node == NULL)
		ft_exit_with_error("Error\n", errno);
	add_node_to_stack_a(new_node, stack_a_head);
}

static void	parse_single_argument(char *arg, t_number **stack_a_head)
{
	char	**array;
	int		i;

	if (*arg == '\0')
		ft_exit_with_error("Error\n", EXIT_FAILURE);
	array = ft_split(arg, ' ');
	if (array == NULL)
		ft_exit_with_error("Error\n", errno);
	i = 0;
	while (*(array + i) != NULL)
	{
		parse_single_number(*(array + i), stack_a_head);
		i++;
	}
	free_split_argument(array);
}

t_number	*parse_input(int argc, char *argv[])
{
	int			i;
	t_number	*stack_a_head;

	i = 1;
	stack_a_head = NULL;
	while (i < argc)
	{
		parse_single_argument(*(argv + i), &stack_a_head);
		i++;
	}
	check_for_duplicates_and_single_number(stack_a_head);
	link_end_to_head(stack_a_head);
	index_numbers(stack_a_head);
	return (stack_a_head);
}
