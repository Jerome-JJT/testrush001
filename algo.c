/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:04:14 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 11:49:11 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	try_push_next(t_info *info, int swap)
{
	if (info->array_b[0] == info->array_b[info->array_b_nbr - 2] && !swap)
	{
		ps_pa(info);
		return (1);
	}
	return (0);
}

int	smart_rotate_b(t_info *info)
{
	int	cnt;
	int	swap;
	int	i;
	int	sz;

	i = 0;
	cnt = 0;
	swap = 0;
	sz = info->array_b_nbr;
	info->b = info->array_b[i];
	while (info->array_b[i] != sz && ++cnt)
		i++;
	while (info->array_b[0] != sz)
	{
		if (!try_push_next(info, swap))
		{
			if (cnt > sz / 2)
				ps_rrb(info);
			else
				ps_rb(info);
		}
		else
			swap = 1;
	}
	return (swap);
}

static void	push_in_chunks(t_info *info)
{
	int	cnt;

	cnt = 0;
	while (info->array_a_nbr > 0)
	{
		if (info->array_a[0] <= (info->chunk_size * info->chunk_done))
		{
			ps_pb(info);
			if (info->array_b[0]
				< info->chunk_size * info->chunk_done - (info->chunk_size / 2))
				ps_rb(info);
			cnt++;
		}
		else
		{
			ps_ra(info);
		}
		if (cnt >= info->chunk_size * info->chunk_done)
			info->chunk_done = info->chunk_done + 1;
	}
}

static void	push_back_in_order(t_info *info)
{
	while (info->array_b_nbr > 0)
	{
		if (smart_rotate_b(info))
		{
			ps_pa(info);
			if (info->array_b_nbr > 1
				&& info->array_b[0] < info->array_b[1])
				ps_ss(info);
			else
				ps_sa(info);
		}
		else
			ps_pa(info);
	}
}

void	algo_five_hundred(t_info *info)
{
	if (info->argc < 500)
		info->chunk_size = info->argc / 12 + 22;
	push_in_chunks(info);
	while (info->array_b_nbr > 0)
		push_back_in_order(info);
}