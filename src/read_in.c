/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:44:42 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:09:11 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		set_type(mode_t mode)
{
	int type;

	type = 0;
	if (mode_type(mode) == 'd')
		type = 1;
	if (mode_type(mode) == '-')
		type = 3;
	if (mode_type(mode) == 'l')
		type = 2;
	if (mode_type(mode) == 'b')
		type = 4;
	if (mode_type(mode) == 'c')
		type = 5;
	if (mode_type(mode) == 'p')
		type = 6;
	if (mode_type(mode) == 'u')
		type = 8;
	return (type);
}

void	content(struct dirent *dir, t_inode *inode, t_list **list, t_env *e)
{
	t_list			*tmp;

	tmp = NULL;
	inode->real_path = ft_strjoin_add(e->path, dir->d_name, '/');
	if ((lstat(inode->real_path, &inode->buf) < 0))
	{
		catch_error(e->path);
		return ;
	}
	inode->name = ft_strdup(dir->d_name);
	inode->path = ft_strdup(e->path);
	if (check_option(e->opt, 'l'))
		set_max(e, inode->buf);
	inode->type = set_type(inode->buf.st_mode);
	tmp = ft_lstnew(inode, sizeof(*inode));
	ft_lst_add_end(list, tmp);
}

void	classic_read(char *path, t_list **list, char *option, t_env *e)
{
	DIR				*d;
	struct dirent	*dir;
	t_inode			*inode;

	if (!(d = opendir(path)))
	{
		catch_error(path);
		return ;
	}
	inode = (t_inode *)ft_memalloc(sizeof(t_inode));
	e->path = ft_strdup(path);
	while ((dir = readdir(d)) != NULL)
	{
		if (check_option(option, 'a'))
			content(dir, inode, list, e);
		else
		{
			if (dir->d_name[0] != '.')
				content(dir, inode, list, e);
		}
	}
	ft_strdel(&e->path);
	ft_memdel((void **)&inode);
	closedir(d);
}
