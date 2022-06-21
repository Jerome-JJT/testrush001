/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:52:52 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:35:59 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_info *info)
{
	int	smallest;
	int	i;
	int	smallest_pos;

	smallest = INT_MAX;
	i = 0;
	smallest_pos = 0;
	while (i < info->array_a_nbr)
	{
		if (info->first_step[i] < smallest)
		{
			smallest = info->first_step[i];
			smallest_pos = i;
		}
		i++;
	}
	info->first_step[smallest_pos] = INT_MAX;
	return (smallest_pos);
}

void	from_step_to_array_a(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->array_a_nbr)
	{
		info->array_a[i] = info->second_step[i];
		i++;
	}
}