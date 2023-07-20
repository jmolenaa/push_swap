/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/08 17:52:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/04/12 12:19:07 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	square_root(float i)
{
	float	result1;
	float	result2;

	if (i < 0)
		return (0);
	result1 = i / 4;
	result2 = i / result1;
	while (result1 - result2 > 0.1 || result1 - result2 < -0.1)
	{
		result1 = (result1 + result2) / 2;
		result2 = i / result1;
	}
	return (result1);
}

size_t	get_half(size_t block)
{
	static size_t	previous_block;
	size_t			half;

	half = block - (block - previous_block) / 2;
	previous_block = block;
	return (half);
}

size_t	get_block(t_info info, size_t previous_block)
{
	size_t	remaining_size;
	size_t	block;

	remaining_size = info.size - previous_block;
	block = remaining_size / (square_root(square_root(remaining_size)));
	if (block < square_root(info.size) * 2)
		return (square_root(info.size) * 2);
	return (block);
}
