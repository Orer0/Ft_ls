/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:57:03 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:15:23 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		check_link(char *path)
{
	char		*buff;
	struct stat	buf;

	buff = ft_strnew(256);
	readlink(path, buff, 256);
	if (lstat(buff, &buf) < 0)
	{
		ft_strdel(&buff);
		return (0);
	}
	if (set_type(buf.st_mode) == 1)
	{
		ft_strdel(&buff);
		return (1);
	}
	ft_strdel(&buff);
	return (0);
}

void	global_padding_file(int cap, t_env *e, t_list *arg)
{
	if (cap == 1)
	{
		if (((t_inode *)(arg->content))->type != 9
				&& ((t_inode *)(arg->content))->type != 1)
		{
			e->arg_t++;
			if (!check_option(e->opt, 'l'))
				ft_putendl(((t_inode *)(arg->content))->name);
			else
			{
				print_file_all(arg, e);
				ft_putchar('\n');
			}
		}
	}
}

void	global_padding_dir(t_env *e, t_list *arg, t_list **list)
{
	if (((t_inode *)(arg->content))->type == 1)
	{
		e->arg_t++;
		if (e->nb_arg > 1)
		{
			ft_putstr(((t_inode *)(arg->content))->path);
			ft_putendl(":");
		}
		classic_read(((t_inode *)(arg->content))->name, list, e->opt, e);
		manag_tri(*list, e->opt);
		if (check_option(e->opt, 'l'))
			print_all(*list, e);
		else
			print_list(*list, e);
		if (e->arg_t < e->nb_arg)
			ft_putchar('\n');
	}
}

void	global_padding_recur(int cap, t_env *e, t_list *arg)
{
	if (((t_inode *)(arg->content))->type == 1)
	{
		e->arg_t++;
		if (cap == 2)
			recursion(((t_inode *)(arg->content))->real_path, e);
		else
			recursion(((t_inode *)(arg->content))->path, e);
		if (e->arg_t < e->nb_arg)
			ft_putchar('\n');
	}
}
