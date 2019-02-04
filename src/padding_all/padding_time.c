/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:30:58 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:24:16 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ls.h"

void	print_time(char **tab)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strsub(tab[4], '\0', 4);
	ft_strdel(&tab[4]);
	tab[4] = ft_strdup(tmp);
	ft_putstr(tab[1]);
	ft_putchar(' ');
	if (ft_strlen(tab[2]) == 1)
		ft_putchar(' ');
	ft_putstr(tab[2]);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(tab[4]);
	ft_putchar(' ');
	ft_strdel(&tmp);
}

void	print_time_2(char **tab)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	tmp = ft_strsub(tab[3], '\0', 5);
	ft_strdel(&tab[3]);
	tab[3] = ft_strdup(tmp);
	while (i < 4)
	{
		if (i == 2 && ft_strlen(tab[2]) < 2)
			ft_putchar(' ');
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_strdel(&tmp);
}

void	padding_time(t_list *list)
{
	char	*tim;
	int		ret;
	char	**tab;
	int		word;
	int		i;

	i = 0;
	tim = ctime(&((t_inode *)(list->content))->buf.st_mtime);
	ret = check_time(((t_inode *)(list->content))->buf.st_mtime);
	tab = ft_strsplit(tim, ' ');
	word = ft_count_words(tim, ' ');
	if (ret == 1)
		print_time(tab);
	else
		print_time_2(tab);
	while (i < 6)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
}
