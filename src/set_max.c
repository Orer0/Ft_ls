/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:03:17 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 15:04:06 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	set_max_uid(t_env *e, struct stat buf)
{
	struct passwd	*pass;
	char			*pass_char;
	int				fail_pass;

	fail_pass = 0;
	if ((pass = getpwuid(buf.st_uid)))
		pass_char = pass->pw_name;
	else if ((fail_pass = 1))
		pass_char = ft_itoa(buf.st_uid);
	if (e->max_uid < ft_strlen(pass_char))
		e->max_uid = ft_strlen(pass_char);
	if (fail_pass != 0)
		ft_strdel(&pass_char);
}

void	set_max_gid(t_env *e, struct stat buf)
{
	struct group	*gr;
	char			*gr_char;
	int				fail_gr;

	fail_gr = 0;
	if ((gr = getgrgid(buf.st_gid)))
		gr_char = gr->gr_name;
	else if ((fail_gr = 0))
		gr_char = ft_itoa(buf.st_gid);
	if (e->max_gid < ft_strlen(gr_char))
		e->max_gid = ft_strlen(gr_char);
	if (fail_gr != 0)
		ft_strdel(&gr_char);
}

void	set_max_size_link(t_env *e, struct stat buf)
{
	char			*size;
	char			*maj;
	char			*min;
	char			*link;

	size = ft_itoa(buf.st_size);
	maj = ft_itoa(major(buf.st_rdev));
	min = ft_itoa(minor(buf.st_rdev));
	link = ft_itoa(buf.st_nlink);
	if (e->max_size < ft_strlen(size))
		e->max_size = ft_strlen(size);
	if (e->max_maj < ft_strlen(maj))
		e->max_maj = ft_strlen(maj);
	if (e->max_min < ft_strlen(min))
		e->max_min = ft_strlen(min);
	if (e->max_link < ft_strlen(link))
		e->max_link = ft_strlen(link);
	ft_strdel(&size);
	ft_strdel(&maj);
	ft_strdel(&min);
	ft_strdel(&link);
}

void	set_max(t_env *e, struct stat buf)
{
	set_max_uid(e, buf);
	set_max_gid(e, buf);
	set_max_size_link(e, buf);
}
