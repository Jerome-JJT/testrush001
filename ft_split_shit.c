/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:48:42 by jjaqueme            #+#    #+#             */
/*   Updated: 2021/01/06 15:35:39 by jjaqueme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_blockcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		else if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (count);
}

int	ft_blocklen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_freearray(char **array, int i)
{
	while (i-- > 0)
	{
		free(array[i]);
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		blockcount;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	blockcount = ft_blockcount((char *)s, c);
	array = (char **)malloc((blockcount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (blockcount--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_substr((char *)s, 0, ft_blocklen((char *)s, c));
		if (!array[i])
			return (ft_freearray(array, i));
		s = s + ft_blocklen((char *)s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	ft_split_shit(t_info *info, char *arguments)
{
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	j = 1;
	splitted = ft_split(arguments, ' ');
	while (splitted[i])
		i++;
	i = ft_split_shit_long(info, i);
	while (i < info->nbr_of_int)
	{
		info->first_step[i] = ft_atoi(splitted[i], info);
		i++;
	}
	same_arg(info);
	while (info->nbr_of_int2 > 0)
	{
		info->smallest_pos = find_smallest(info);
		info->nbr_of_int2--;
		info->second_step[info->smallest_pos] = j;
		j++;
	}
	free(splitted);
	from_step_to_array_a(info);
}