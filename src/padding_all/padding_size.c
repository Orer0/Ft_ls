/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:32:03 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 15:02:58 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ls.h"

void	padding_min(dev_t dev, t_env *e)
{
	char	*min;
	size_t	i;

	i = 0;
	min = ft_itoa(minor(dev));
	if (e->max_min == ft_strlen(min))
		ft_putstr(min);
	else
	{
		i = e->max_min;
		while (ft_strlen(min) < i)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(min);
	}
	ft_strdel(&min);
	ft_putchar(' ');
}

void	padding_maj(dev_t dev, t_env *e)
{
	char	*maj;
	size_t	i;

	i = 0;
	maj = ft_itoa(major(dev));
	if (e->max_maj == ft_strlen(maj))
		ft_putstr(maj);
	else
	{
		i = e->max_maj;
		while (ft_strlen(maj) < i)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(maj);
	}
	ft_putchar(',');
	ft_putchar(' ');
	ft_strdel(&maj);
}

void	print_size(int tmp_size, int size, t_env *e)
{
	if (tmp_size == (int)e->max_size)
		ft_putnbr(size);
	else
	{
		while (tmp_size < (int)e->max_size)
		{
			ft_putchar(' ');
			tmp_size++;
		}
		ft_putnbr(size);
	}
}

void	padding_size(t_list *tmp, t_env *e)
{
	int		size;
	int		tmp_size;
	size_t	i;
	char	*len;

	i = 0;
	size = ((t_inode *)(tmp->content))->buf.st_size;
	len = ft_itoa(((t_inode *)(tmp->content))->buf.st_size);
	tmp_size = ft_strlen(len);
	ft_strdel(&len);
	if (e->max_maj != 1 && e->max_min != 1)
	{
		while (i < (e->max_maj + e->max_min + 1))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(size);
	}
	else
		print_size(tmp_size, size, e);
	ft_putchar(' ');
}
