/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:54:09 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/08 14:17:58 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define SA	"sa\n"
# define SB	"sb\n"
# define SS	"ss\n"
# define PA	"pa\n"
# define PB	"pb\n"
# define RA	"ra\n"
# define RB	"rb\n"
# define RR	"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

# define N_SIZE 240000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_info
{
	int		argc;
	int		nbr_of_int;
	int		nbr_of_int2;
	int		*first_step;
	int		*second_step;
	int		*array_a;
	int		*array_b;
	int		smallest_pos;
	int		array_a_nbr;
	int		array_b_nbr;
	int		chunk_size;
	int		chunk_done;
	int		done;
	int		nbr_done;
	int		posi_in_chunk;
	int		error;
	int		i;
	int		j;
	int		b;
	char	*str_command;
	char	*str_command_stock;
	int		str_i;
	int		chunk_size2;
	int		n_command_stock;
	int		n_command;
}	t_info;

void	ps_sa(t_info *info);
void	ps_sb(t_info *info);
void	ps_ss(t_info *info);
void	ps_pa(t_info *info);
void	ps_pb(t_info *info);
void	ps_ra(t_info *info);
void	ps_rb(t_info *info);
void	ps_rr(t_info *info);
void	ps_rra(t_info *info);
void	ps_rrb(t_info *info);
void	ps_rrr(t_info *info);
void	algo_simple(t_info *info);
int		already_sorted(t_info info);
void	algo_two(t_info *info);
int		algo_three(t_info *info);
void	algo_four(t_info *info);
void	algo_five(t_info *info);
void	algo_five_hundred(t_info *info);
void	algo_hundred(t_info *info);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str, t_info *info);
int		find_smallest(t_info *info);
void	from_step_to_array_a(t_info *info);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	ft_split_shit(t_info *info, char *arguments);
void	error(t_info *info);
void	same_arg(t_info *info);
void	algo_three_long(t_info *info);
int		ft_split_shit_long(t_info *info, int i);
void	free_me(t_info *info);
int		hate_the_letters(int argc, char **argv);
void	replace_double_ra_rb(t_info *info);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
void	main_unique(int argc, char **argv, t_info *info, int checker);
int		find_smallest(t_info *info);
void	from_step_to_array_a(t_info *info);
void	str_command_replace(t_info *info);

#endif