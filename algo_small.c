/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:45:57 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/06 15:39:18 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_two(t_info *info)
{
	if (info->array_a[0] > info->array_a[1])
		ps_ra(info);
}

int	algo_three(t_info *info)
{
	if (already_sorted(*info) == 1)
		return (0);
	if (info->array_a[0] < info->array_a[1])
	{
		if (info->array_a[0] < info->array_a[2])
		{
			ps_ra(info);
			ps_sa(info);
			ps_rra(info);
		}
		else
			ps_rra(info);
	}
	else if (info->array_a[0] > info->array_a[1])
	{
		algo_three_long(info);
	}
	else
		ps_sa(info);
	return (0);
}

void	algo_four(t_info *info)
{
	while (info->array_b_nbr < 1)
	{
		while (info->array_a[0] != 4)
		{
			ps_ra(info);
		}
		ps_pb(info);
	}
	algo_three(info);
	ps_pa(info);
	ps_ra(info);
}

void	algo_five(t_info *info)
{
	while (info->array_b_nbr < 2)
	{
		while (info->array_a[0] != 4 && info->array_a[0] != 5)
		{
			ps_ra(info);
		}
		ps_pb(info);
	}
	algo_three(info);
	if (info->array_b[0] == 4)
	{
		ps_pa(info);
		ps_ra(info);
		ps_pa(info);
		ps_ra(info);
	}
	else
	{
		ps_pa(info);
		ps_pa(info);
		ps_ra(info);
		ps_ra(info);
	}
}