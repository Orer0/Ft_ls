/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:50:58 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:16:45 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	manag_tri(t_list *list, char *option)
{
	if (!(check_option(option, 't')))
	{
		(check_option(option, 'r'))
			? (reverse_alpha_sort(list)) : (alpha_sort(list));
	}
	if (!(check_option(option, 'r')) && (check_option(option, 't')))
	{
		alpha_sort(list);
		time_sort(list);
	}
	if (check_option(option, 'r') && check_option(option, 't'))
	{
		reverse_alpha_sort(list);
		reverse_time_sort(list);
	}
}

void	tri_arg(t_list *list, char *option)
{
	if (!(check_option(option, 't')))
	{
		if (check_option(option, 'r'))
			reverse_alpha_sort(list);
		else
			alpha_sort(list);
	}
	if (!(check_option(option, 'r')) && (check_option(option, 't')))
		time_sort(list);
	if (check_option(option, 'r') && check_option(option, 't'))
		reverse_time_sort(list);
}
