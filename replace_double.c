/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:24:27 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 12:01:23 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	line_too_long(t_info *info, int i)
{
	if (info->str_command[i] == 'r' && info->str_command[i + 1] == 'a')
	{
		if (info->str_command[i + 3] == 'r' && info->str_command[i + 4] == 'b')
		{
			info->str_command[i + 1] = 'r';
			info->str_command[i + 3] = '+';
			info->str_command[i + 4] = '+';
			info->str_command[i + 5] = '+';
		}
	}
	if (info->str_command[i] == 'r' && info->str_command[i + 1] == 'b')
	{
		if (info->str_command[i + 3] == 'r' && info->str_command[i + 4] == 'a')
		{
			info->str_command[i + 1] = 'r';
			info->str_command[i + 3] = '+';
			info->str_command[i + 4] = '+';
			info->str_command[i + 5] = '+';
		}
	}
}

void	replace_double_ra_rb(t_info *info)
{
	int	i;

	i = -1;
	while (info->str_command[++i])
	{
		line_too_long(info, i);
	}
	i = -1;
}