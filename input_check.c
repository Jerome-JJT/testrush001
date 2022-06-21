/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:02:54 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:36:55 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_info info)
{
	int	i;

	i = 0;
	while (i < info.array_a_nbr)
	{
		if (info.array_a[i] != (i + 1))
			return (0);
		else
			i++;
	}
	return (1);
}

void	error(t_info *info)
{
	write(1, "Error\n", 6);
	free(info->first_step);
	free(info->second_step);
	free(info->array_a);
	free(info->array_b);
	free(info);
	exit(0);
}

void	free_me(t_info *info)
{
	free(info->first_step);
	free(info->second_step);
	free(info->array_a);
	free(info->array_b);
	free(info);
	exit(0);
}