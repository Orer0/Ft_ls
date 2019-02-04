/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:56:41 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 15:56:43 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	set_env(t_env *e, int ac)
{
	e->opt = NULL;
	e->arg = NULL;
	e->path = NULL;
	e->ac = ac;
	e->cap = 0;
	e->max_uid = 0;
	e->max_gid = 0;
	e->max_size = 0;
	e->max_maj = 0;
	e->max_min = 0;
	e->max_link = 0;
	e->file = 0;
	e->nb_arg = 0;
	e->nb_file = 0;
}
