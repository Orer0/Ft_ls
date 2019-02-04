/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:59:10 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:29:14 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		ft_swap_inode(t_inode *a, t_inode *b)
{
	t_inode	tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

int			check_option(char *option, char letter)
{
	int	i;

	i = 0;
	if (option == NULL)
		return (0);
	while (option[i] != '\0')
	{
		if (option[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

t_list		*index_list(t_list **list, int index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	while (i < index && list != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int			check_time(time_t tmp)
{
	double	timediff;

	timediff = time(NULL) - tmp;
	if ((timediff > 15778800) || (timediff < -15778800))
		return (1);
	return (0);
}
