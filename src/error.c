/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:14:25 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:10:57 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	catch_error(char *path)
{
	ft_putstr("fl_ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

void	illegal_option(char *option)
{
	char	*legal_option;
	int		i;
	int		j;

	i = 0;
	j = 0;
	legal_option = "-Rralt";
	while (option[i] != '\0')
	{
		if (!(ft_strfind(legal_option, option[i])))
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(option[i]);
			ft_putchar('\n');
			ft_putendl("usage: ls [-Ralrt] [file ...]");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
