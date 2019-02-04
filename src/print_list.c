/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:39:58 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:27:53 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	print_first_rep(t_list **list, char *option, t_env *e)
{
	classic_read(".", list, option, e);
	manag_tri(*list, option);
	if (check_option(option, 'l'))
		print_all(*list, e);
	else
		print_list(*list, e);
}

void	print_list(t_list *list, t_env *e)
{
	t_list *tmp;

	if (list == NULL && e->nb_arg > 1)
		ft_putchar('\n');
	tmp = list;
	while (tmp != NULL)
	{
		ft_putendl(((t_inode *)tmp->content)->name);
		tmp = tmp->next;
	}
}

void	printing(t_env *e, t_list *tmp, char right)
{
	ft_putchar(right = mode_type((((t_inode *)(tmp->content))->buf.st_mode)));
	padding_right(((t_inode *)(tmp->content))->buf.st_mode);
	padding_link(tmp, e);
	padding_uid(tmp, e);
	padding_gid(tmp, e);
	if (right == 'c' || right == 'b')
	{
		padding_maj(((t_inode *)(tmp->content))->buf.st_rdev, e);
		padding_min(((t_inode *)(tmp->content))->buf.st_rdev, e);
	}
	else
		padding_size(tmp, e);
	padding_time(tmp);
}

void	print_all(t_list *list, t_env *e)
{
	t_list	*tmp;
	char	right;
	char	*buff;

	if (list == NULL)
		return ;
	tmp = list;
	padding_block(tmp);
	right = 0;
	while (tmp != NULL)
	{
		printing(e, tmp, right);
		if (mode_type((((t_inode *)(tmp->content))->buf.st_mode)) == 'l')
		{
			buff = ft_strnew(256);
			readlink(((t_inode *)(tmp->content))->real_path, buff, 256);
			ft_putstr(((t_inode *)tmp->content)->name);
			ft_putstr(" -> ");
			ft_putendl(buff);
			ft_strdel(&buff);
		}
		else
			ft_putendl(((t_inode *)tmp->content)->name);
		tmp = tmp->next;
	}
}

void	print_file_all(t_list *list, t_env *e)
{
	t_list	*tmp;
	char	right;
	char	*buff;

	tmp = list;
	right = 0;
	printing(e, tmp, right);
	if (mode_type((((t_inode *)(tmp->content))->buf.st_mode)) == 'l')
	{
		buff = ft_strnew(256);
		readlink(((t_inode *)(tmp->content))->path, buff, 256);
		ft_putstr(((t_inode *)tmp->content)->name);
		ft_putstr(" -> ");
		ft_putstr(buff);
		ft_strdel(&buff);
	}
	else
		ft_putstr(((t_inode *)tmp->content)->name);
}
