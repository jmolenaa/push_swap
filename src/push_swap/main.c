/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 17:12:04 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/05/05 10:48:51 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_number	*stack_a;
	t_number	*stack_b;
	t_info		info;

	if (argc == 1)
		return (EXIT_SUCCESS);
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	info = set_struct_info(&stack_a, &stack_b);
	if (is_sorted(info))
	{
		free_list(&stack_a);
		return (0);
	}
	if (info.size <= 10)
		sort_small_list(info);
	else if (info.size <= 5000)
		quicksort(info);
	else
		radix(info);
	free_list(&stack_a);
	return (EXIT_SUCCESS);
}
