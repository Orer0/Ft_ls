/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:32:54 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:20:58 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ls.h"

char	mode_type(mode_t mode)
{
	if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISREG(mode))
		return ('-');
	else
		return ('u');
}

void	padding_link(t_list *tmp, t_env *e)
{
	int		max_size;
	int		size_link;
	int		tmp_size;
	char	*len;

	len = ft_itoa(((t_inode *)(tmp->content))->buf.st_nlink);
	size_link = ((t_inode *)(tmp->content))->buf.st_nlink;
	tmp_size = ft_strlen(len);
	ft_strdel(&len);
	max_size = e->max_link;
	if (tmp_size == max_size)
		ft_putnbr(size_link);
	else
	{
		while (tmp_size < max_size)
		{
			ft_putchar(' ');
			tmp_size++;
		}
		ft_putnbr(size_link);
	}
	ft_putchar(' ');
}
