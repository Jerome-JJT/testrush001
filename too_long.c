/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:29:32 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:35:22 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three_long(t_info *info)
{
	if (info->array_a[0] > info->array_a[2])
	{
		if (info->array_a[1] < info->array_a[2])
			ps_ra(info);
		else
		{
			ps_sa(info);
			ps_rra(info);
		}
	}
	else
		ps_sa(info);
}

int	ft_split_shit_long(t_info *info, int i)
{
	info->first_step = malloc(sizeof(int) * (i + 1));
	info->second_step = malloc(sizeof(int) * (i + 1));
	info->array_a = malloc(sizeof(int) * (i + 1));
	info->array_b = malloc(sizeof(int) * (i + 1));
	info->array_a_nbr = i;
	info->nbr_of_int = i;
	info->nbr_of_int2 = i;
	info->argc = info->array_a_nbr;
	i = 0;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	hate_the_letters(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (ft_strlen(argv[i])))
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	str_command_replace(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_command_stock[i])
	{
		info->str_command_stock[i] = '+';
		i++;
	}
	i = 0;
	while (info->str_command[i])
	{
		info->str_command_stock[i] = info->str_command[i];
		i++;
	}
	info->str_command_stock[i] = '\0';
}