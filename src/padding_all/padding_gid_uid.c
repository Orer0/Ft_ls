/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_gid_uid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:29:46 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:21:31 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ls.h"

void	print_gid(t_env *e, char *gr_char)
{
	size_t	j;

	j = 0;
	if (e->max_gid == ft_strlen(gr_char))
		ft_putstr(gr_char);
	else
	{
		j = e->max_gid;
		ft_putstr(gr_char);
		while (ft_strlen(gr_char) < j)
		{
			ft_putchar(' ');
			j--;
		}
	}
}

void	padding_gid(t_list *tmp, t_env *e)
{
	char			*gr_char;
	struct group	*gr;
	size_t			j;
	int				fail;

	fail = 0;
	j = 0;
	if (!(gr = getgrgid(((t_inode *)(tmp->content))->buf.st_gid)))
	{
		fail = 1;
		gr_char = ft_itoa(((t_inode *)(tmp->content))->buf.st_gid);
	}
	else
		gr_char = gr->gr_name;
	print_gid(e, gr_char);
	if (fail == 1)
		ft_strdel(&gr_char);
	ft_putchar(' ');
}

void	print_uid(char *pass_char, t_env *e)
{
	size_t		i;

	i = 0;
	if (e->max_uid == ft_strlen(pass_char))
		ft_putstr(pass_char);
	else
	{
		ft_putstr(pass_char);
		i = e->max_uid;
		while (ft_strlen(pass_char) < i)
		{
			ft_putchar(' ');
			i--;
		}
	}
}

void	padding_uid(t_list *tmp, t_env *e)
{
	size_t			i;
	struct passwd	*pass;
	char			*pass_char;
	int				fail;

	fail = 0;
	i = 0;
	if (!(pass = getpwuid(((t_inode *)(tmp->content))->buf.st_uid)))
	{
		pass_char = ft_itoa(((t_inode *)(tmp->content))->buf.st_uid);
		fail = 1;
	}
	else
		pass_char = pass->pw_name;
	print_uid(pass_char, e);
	if (fail == 1)
		ft_strdel(&pass_char);
	ft_putchar(' ');
}
