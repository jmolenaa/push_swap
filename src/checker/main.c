/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 18:19:21 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 09:30:55 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static void	setup_string_dictionary(char *str_dict[11])
{
	str_dict[0] = "sa\n";
	str_dict[1] = "sb\n";
	str_dict[2] = "ss\n";
	str_dict[3] = "pa\n";
	str_dict[4] = "pb\n";
	str_dict[5] = "ra\n";
	str_dict[6] = "rb\n";
	str_dict[7] = "rr\n";
	str_dict[8] = "rra\n";
	str_dict[9] = "rrb\n";
	str_dict[10] = "rrr\n";
}

static void	setup_function_dict(void (*func_dict[11])(t_number **, t_number **))
{
	func_dict[0] = sa;
	func_dict[1] = sb;
	func_dict[2] = ss;
	func_dict[3] = pa;
	func_dict[4] = pb;
	func_dict[5] = ra;
	func_dict[6] = rb;
	func_dict[7] = rr;
	func_dict[8] = rra;
	func_dict[9] = rrb;
	func_dict[10] = rrr;
}

static void	run_operation(	char *str, t_info info, char *str_dict[11], \
						void (*func_dict[11])(t_number **, t_number **))
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(str, str_dict[i], 5) == 0)
		{
			func_dict[i](info.stack_a, info.stack_b);
			break ;
		}
		i++;
	}
	if (i == 11)
		ft_exit_with_error("Error\n", EXIT_FAILURE);
}

static void	read_operations(t_info info)
{
	char	*str;
	char	*str_dict[11];
	void	(*func_dict[11])(t_number **, t_number **);

	setup_string_dictionary(str_dict);
	setup_function_dict(func_dict);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		run_operation(str, info, str_dict, func_dict);
		free(str);
	}
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
	read_operations(info);
	if (is_sorted(info) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&stack_a);
	return (EXIT_SUCCESS);
}
