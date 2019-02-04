/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:53:15 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:24:56 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		count_file(t_list *arg, char *option)
{
	int		nb_file;
	t_list	*tmp;

	tmp = arg;
	nb_file = 0;
	while (tmp)
	{
		if (((t_inode *)(tmp->content))->type == 3)
			nb_file++;
		if (((t_inode *)(tmp->content))->type == 8)
			nb_file++;
		if (((t_inode *)(tmp->content))->type == 2
				&& check_option(option, 'l'))
			nb_file++;
		tmp = tmp->next;
	}
	return (nb_file);
}

int		count_arg(t_list *arg)
{
	int		nb_arg;
	t_list	*tmp;

	tmp = arg;
	nb_arg = 0;
	while (tmp)
	{
		if (((t_inode *)(tmp->content))->type != 9)
			nb_arg++;
		tmp = tmp->next;
	}
	return (nb_arg);
}

int		count_dir(t_list *arg)
{
	int		nb_arg;
	t_list	*tmp;

	tmp = arg;
	nb_arg = 0;
	while (tmp)
	{
		if (((t_inode *)(tmp->content))->type == 1)
			nb_arg++;
		tmp = tmp->next;
	}
	return (nb_arg);
}
