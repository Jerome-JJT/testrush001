/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:04:14 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/06 09:15:22 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_hundred_chunk_send(t_info *info)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < info->chunk_size)
	{
		if (info->array_a[0] <= (info->chunk_size * info->chunk_done))
		{
			ps_pb(info);
			k++;
		}
		else
			ps_ra(info);
	}
}

/*int	find_biggest(t_info *info)
{
	int	biggest;
	int	i;
	int	biggest_pos;

	i = 0;
	biggest = info->array_b[i];
	biggest_pos = 0;
	while (i < info->array_b_nbr)
	{
		if (info->array_b[i] > biggest)
		{
			biggest = info->array_b[i];
			biggest_pos = i;
		}
		i++;
	}
	return (biggest_pos);
}

void	five_hundred_chunk_resend(t_info *info)
{
	int	biggest;
	int	stock;

	info->nbr_done = info->chunk_size;
	while (info->nbr_done > 0)
	{
		biggest = find_biggest(info);
		stock = info->array_b[biggest];
		if (biggest < info->chunk_size * 2)
		{
			while (biggest-- > 0)
				ps_rb(info);
		}
		else
		{
			while (info->array_b[0] != stock)
				ps_rrb(info);
		}
		ps_pa(info);
		info->nbr_done = info->nbr_done - 1;
	}
}*/

void	algo_five_hundred(t_info *info)
{
	five_hundred_chunk_send(info);
	while (info->array_a_nbr > 0)
	{
		info->chunk_done = info->chunk_done + 1;
		five_hundred_chunk_send(info);
	}
	while (info->array_a_nbr > 0)
		ps_pb(info);
	/*while (info->array_b_nbr > 0)
	{
		five_hundred_chunk_resend(info);
	}*/
}