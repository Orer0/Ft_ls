/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:38:55 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:16:09 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	stat_arg(t_inode *data_arg, char *av, t_env *e)
{
	if (check_option(e->opt, 'l'))
	{
		if ((lstat(data_arg->path, &data_arg->buf) < 0))
			catch_error(av);
		else
			data_arg->type = set_type(data_arg->buf.st_mode);
	}
	else
	{
		if ((stat(data_arg->path, &data_arg->buf) < 0))
		{
			if ((lstat(data_arg->path, &data_arg->buf) < 0))
				catch_error(av);
			else
				data_arg->type = set_type(data_arg->buf.st_mode);
		}
		else
			data_arg->type = set_type(data_arg->buf.st_mode);
	}
}

void	content_arg(t_inode *data_arg, t_env *e, char *av)
{
	t_list *tmp;

	tmp = NULL;
	data_arg = (t_inode *)ft_memalloc(sizeof(t_inode));
	data_arg->name = ft_strdup(av);
	data_arg->path = ft_strdup(av);
	data_arg->real_path = ft_strjoin("./", av);
	data_arg->type = 9;
	stat_arg(data_arg, av, e);
	if (data_arg->type == 2 && (!check_option(e->opt, 'l')))
	{
		if (check_link(av))
			data_arg->type = 1;
		else
			data_arg->type = 3;
	}
	set_max(e, data_arg->buf);
	tmp = ft_lstnew(data_arg, sizeof(*data_arg));
	ft_lst_add_end(&e->arg, tmp);
	ft_memdel((void **)&data_arg);
}

void	arg_way(char **av, int ac, t_env *e)
{
	int			i;
	int			cap;
	t_inode		*data_arg;

	cap = 0;
	i = 1;
	data_arg = NULL;
	while (ac > i)
	{
		if (av[i][0] == '-' && av[i][1] != 0 && cap == 0)
		{
			if (ft_strcmp(av[i], "--") == 0)
				cap = 1;
			if (e->opt == NULL)
				e->opt = ft_strdup(av[i]);
			else
				e->opt = ft_strjoin(e->opt, av[i]);
		}
		else
		{
			cap = 1;
			content_arg(data_arg, e, av[i]);
		}
		i++;
	}
}
