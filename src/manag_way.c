/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:50:54 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 18:53:16 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	normal_way(t_list *tmp, t_list *arg, t_env *e, int cap)
{
	t_list	*list;

	list = NULL;
	while (tmp)
	{
		global_padding_file(cap, e, tmp);
		tmp = tmp->next;
	}
	if (e->file > 0 && e->file < e->nb_arg)
		ft_putchar('\n');
	tmp = arg;
	while (tmp)
	{
		global_padding_dir(e, tmp, &list);
		ft_lstdel(&list, del);
		tmp = tmp->next;
	}
}

void	recur_way(t_list *tmp, t_list *arg, t_env *e, int cap)
{
	while (tmp)
	{
		global_padding_file(cap, e, tmp);
		tmp = tmp->next;
	}
	if (e->file > 0 && e->file < e->nb_arg)
		ft_putchar('\n');
	tmp = arg;
	while (tmp)
	{
		global_padding_recur(cap, e, tmp);
		tmp = tmp->next;
	}
}

void	ft_lst_way(t_list *arg, int cap, t_env *e)
{
	int		i;
	DIR		*dir;
	int		nb_dir;
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	tmp = arg;
	i = 1;
	e->arg_t = 0;
	dir = NULL;
	e->nb_file = 0;
	nb_dir = count_dir(arg);
	if (cap == 1)
		e->nb_arg = count_arg(arg);
	else
		e->nb_arg = count_dir(arg);
	e->file = count_file(arg, e->opt);
	if (!(check_option(e->opt, 'R')))
		normal_way(tmp, arg, e, cap);
	else
		recur_way(tmp, arg, e, cap);
}

void	manag_ls(char *option, t_list *arg, t_env *e)
{
	t_list	*list;

	list = NULL;
	if (option)
		illegal_option(option);
	if (arg == NULL)
	{
		if (check_option(option, 'R'))
		{
			print_first_rep(&list, option, e);
			ft_putchar('\n');
			manag_tri(list, option);
			ft_lst_way(list, 2, e);
		}
		else
			print_first_rep(&list, option, e);
	}
	else
	{
		tri_arg(arg, option);
		ft_lst_way(arg, 1, e);
	}
	ft_lstdel(&list, del);
}
