/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:27:57 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 19:25:27 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ls.h"

void	padding_block(t_list *list)
{
	t_list	*tmp;
	int		size;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size = size + ((t_inode *)(tmp->content))->buf.st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbrndl(size);
}

void	padding_suid(mode_t right)
{
	if ((right & S_IXUSR) && (right & S_ISUID))
		ft_putchar('s');
	else if (right & S_ISUID)
		ft_putchar('S');
	else if (right & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	padding_sgid(mode_t right)
{
	if ((right & S_IXUSR) && (right & S_ISGID))
		ft_putchar('s');
	else if (right & S_ISGID)
		ft_putchar('S');
	else if (right & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	padding_sticky(mode_t right)
{
	if ((right & S_IXUSR) && (right & S_ISVTX))
		ft_putchar('t');
	else if (right & S_ISVTX)
		ft_putchar('T');
	else if (right & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	padding_right(mode_t right)
{
	(right & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(right & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	padding_suid(right);
	(right & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(right & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	padding_sgid(right);
	(right & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(right & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	padding_sticky(right);
	ft_putchar(' ');
}
