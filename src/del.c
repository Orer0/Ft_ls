/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:54:57 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:10:23 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	del(void *content, size_t size)
{
	(void)size;
	ft_strdel(&((t_inode *)(content))->name);
	ft_strdel(&((t_inode *)(content))->path);
	ft_strdel(&((t_inode *)(content))->real_path);
	ft_memdel(&content);
}
