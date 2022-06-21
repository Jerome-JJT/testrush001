/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:52:50 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/11/24 09:26:16 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_info *info)
{
	int	i;

	i = 1;
	while (info->array_a_nbr > 0)
	{
		while ((info->array_a[0]) != i)
		{
			ps_ra(info);
		}
		ps_pb(info);
		i++;
	}
	while (info->array_b_nbr > 0)
	{
		ps_pa(info);
	}
}