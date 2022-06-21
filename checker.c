/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:50:16 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:51:39 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

void	false_command(t_info *info)
{
	write(1, "Error\n", 6);
	free_me(info);
}

void	execute_commands(t_info *info, char *commands)
{
	if (!ft_strncmp(commands, "sa\n", 4))
		ps_sa(info);
	else if (!ft_strncmp(commands, "sb\n", 4))
		ps_sb(info);
	else if (!ft_strncmp(commands, "ss\n", 4))
		ps_ss(info);
	else if (!ft_strncmp(commands, "pa\n", 4))
		ps_pa(info);
	else if (!ft_strncmp(commands, "pb\n", 4))
		ps_pb(info);
	else if (!ft_strncmp(commands, "ra\n", 4))
		ps_ra(info);
	else if (!ft_strncmp(commands, "rb\n", 4))
		ps_rb(info);
	else if (!ft_strncmp(commands, "rr\n", 4))
		ps_rr(info);
	else if (!ft_strncmp(commands, "rra\n", 5))
		ps_rra(info);
	else if (!ft_strncmp(commands, "rrb\n", 5))
		ps_rrb(info);
	else if (!ft_strncmp(commands, "rrr\n", 5))
		ps_rrr(info);
	else
		false_command(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char	*commands;

	info = malloc(sizeof(t_info));
	commands = malloc(sizeof(char) * 10);
	info->str_command = malloc(sizeof(char) * (6000 * 4));
	main_unique(argc, argv, info, 1);
	commands = get_next_line(1);
	while (commands != NULL)
	{
		execute_commands(info, commands);
		free(commands);
		commands = get_next_line(1);
	}
	//write(1, "\033[H\033[2J", 7);
	if (already_sorted(*info) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_me(info);
}