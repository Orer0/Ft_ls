/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:15:59 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:33:40 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

long		sort_on_time(t_list **list, int index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	while (i < index && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (((t_inode *)(tmp->content))->buf.st_mtimespec.tv_sec);
}

void		time_sort(t_list *list)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = list;
	while (temp != NULL)
	{
		if (i > 0)
		{
			j = i;
			while (j > 0
				&& sort_on_time(&list, j) > sort_on_time(&list, j - 1))
			{
				ft_swap_inode(((t_inode *)(index_list(&list, j)->content)),
						((t_inode *)(index_list(&list, j - 1)->content)));
				j--;
			}
		}
		i++;
		temp = temp->next;
	}
}

void		reverse_time_sort(t_list *list)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = list;
	while (temp != NULL)
	{
		if (i > 0)
		{
			j = i;
			while (j > 0
				&& sort_on_time(&list, j) < sort_on_time(&list, j - 1))
			{
				ft_swap_inode(((t_inode *)(index_list(&list, j)->content)),
						((t_inode *)(index_list(&list, j - 1)->content)));
				j--;
			}
		}
		i++;
		temp = temp->next;
	}
}
