/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:41:17 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 18:53:13 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		main(int ac, char **av)
{
	t_env e;

	set_env(&e, ac);
	arg_way(av, ac, &e);
	manag_ls(e.opt, e.arg, &e);
	ft_lstdel(&e.arg, del);
	ft_strdel(&e.path);
	ft_strdel(&e.opt);
	return (0);
}
