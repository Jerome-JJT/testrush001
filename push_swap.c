/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:56:21 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:45:59 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_toolong(t_info *info, int argc, char **argv)
{
	if (argc > 2)
	{
		info->array_a_nbr = (argc - 1);
		info->first_step = malloc(sizeof(int) * argc);
		info->second_step = malloc(sizeof(int) * argc);
		info->array_a = malloc(sizeof(int) * argc);
		info->array_b = malloc(sizeof(int) * argc);
		info->str_i = 0;
		info->nbr_of_int = (argc - 1);
		info->nbr_of_int2 = (argc - 1);
		while (info->nbr_of_int-- > 0)
		{
			info->first_step[info->i] = ft_atoi(argv[info->i + 1], info);
			info->i = info->i + 1;
		}
		same_arg(info);
		while (info->nbr_of_int2 > 0)
		{
			info->smallest_pos = find_smallest(info);
			info->nbr_of_int2--;
			info->second_step[info->smallest_pos] = info->j;
			info->j = info->j + 1;
		}
		from_step_to_array_a(info);
	}
}

void	main_toolong2(t_info *info, int argc)
{
	info->i = 0;
	info->j = 1;
	info->array_b_nbr = 0;
	info->argc = argc - 1;
	if (argc <= 100)
		info->chunk_size = 20;
	info->chunk_done = 1;
	info->done = 0;
	info->nbr_done = 0;
	info->posi_in_chunk = 0;
	info->error = 1;
	if (argc == 1)
		free_me(info);
}

void	main_unique(int argc, char **argv, t_info *info, int checker)
{
	main_toolong2(info, argc);
	main_toolong(info, argc, argv);
	if (hate_the_letters(argc, argv) == 0)
		error(info);
	if (argc == 2)
		ft_split_shit(info, argv[1]);
	if (already_sorted(*info) == 1)
		free_me(info);
	if (checker == 0)
	{
		if (info->array_a_nbr == 2)
			algo_two(info);
		else if (info->array_a_nbr == 3)
			algo_three(info);
		else if (info->array_a_nbr == 4)
			algo_four(info);
		else if (info->array_a_nbr == 5)
			algo_five(info);
		else
			algo_five_hundred(info);
		replace_double_ra_rb(info);
	}
}

void	duck_norminette(t_info *info, int argc, char **argv)
{
	int	i;

	i = -1;
	info->n_command = 0;
	info->chunk_size = info->argc / 12 + info->chunk_size2;
	main_unique(argc, argv, info, 0);
	while (info->str_command[++i])
		if (info->str_command[i] == '\n')
			info->n_command = info->n_command + 1;
	if (info->n_command < info->n_command_stock)
	{
		info->n_command_stock = info->n_command;
		str_command_replace(info);
	}
	i = -1;
	while (info->str_command[++i])
		info->str_command[i] = '+';
	info->chunk_size2 = info->chunk_size2 + 1;
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = malloc(sizeof(t_info));
	info->str_command = malloc(sizeof(char) * (N_SIZE));
	info->str_command_stock = malloc(sizeof(char) * (N_SIZE));
	info->chunk_size2 = 17;
	info->n_command_stock = 10000;
	while (info->chunk_size2 < 28)
	{
		duck_norminette(info, argc, argv);
	}
	i = -1;
	while (info->str_command_stock[++i])
		if (info->str_command_stock[i] != '+')
			printf("%c", info->str_command_stock[i]);
	free_me(info);
}