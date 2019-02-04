/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:02:15 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 15:56:35 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		padding_recusion(int nb_arg, char *path, t_env *e, t_list **in_dir)
{
	if (e->cap == 1 || nb_arg > 1)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	classic_read(path, in_dir, e->opt, e);
	manag_tri(*in_dir, e->opt);
	if (check_option(e->opt, 'l'))
		print_all(*in_dir, e);
	else
		print_list(*in_dir, e);
}

void		read_dir(t_list *tmp, t_env *e, char *path_r, char *path)
{
	char *name;

	name = NULL;
	while (tmp)
	{
		name = ((t_inode *)(tmp->content))->name;
		if (((t_inode *)(tmp->content))->type == 1
			&& ft_strcmp(name, ".") != 0
			&& ft_strcmp(name, "..") != 0)
		{
			ft_putchar('\n');
			e->cap = 1;
			if (ft_strcmp(path, "/") == 0)
				path_r = ft_strjoin(path, name);
			else
				path_r = ft_strjoin_add(path, name, '/');
			recursion(path_r, e);
			ft_strdel(&path_r);
		}
		tmp = tmp->next;
	}
}

void		recur_dir(DIR *d, t_env *e, char *path, t_list *in_dir)
{
	struct dirent	*dir;
	t_list			*tmp;
	char			*path_r;

	tmp = NULL;
	path_r = NULL;
	if ((dir = readdir(d)))
	{
		closedir(d);
		padding_recusion(e->nb_arg, path, e, &in_dir);
		tmp = in_dir;
		read_dir(tmp, e, path_r, path);
		ft_lstdel(&in_dir, del);
	}
}

void		recursion(char *path, t_env *e)
{
	DIR				*d;
	t_list			*in_dir;

	in_dir = NULL;
	if (!(d = opendir(path)))
	{
		ft_putstr(path);
		ft_putendl(":");
		catch_error(path);
		return ;
	}
	recur_dir(d, e, path, in_dir);
	e->cap = 0;
}
