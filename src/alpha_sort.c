/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:40:31 by aroblin           #+#    #+#             */
/*   Updated: 2018/10/12 17:14:16 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char		*alpha_check(t_list **list, int index)
{
	int		i;
	char	*test;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	while (i < index && list != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	test = ft_strjoin_add(((t_inode *)(tmp->content))->path,
			((t_inode *)(tmp->content))->name, '/');
	return (test);
}

void		reverse_comp(int j, t_list *list)
{
	char	*copy;
	char	*copy2;

	copy = NULL;
	copy2 = NULL;
	while (j > 0 && ft_strcmp(copy = alpha_check(&list, j),
				copy2 = alpha_check(&list, j - 1)) > 0)
	{
		ft_swap_inode(((t_inode *)index_list(&list, j)->content),
				((t_inode *)(index_list(&list, j - 1)->content)));
		j--;
		ft_strdel(&copy);
		ft_strdel(&copy2);
	}
	ft_strdel(&copy);
	ft_strdel(&copy2);
}

void		reverse_alpha_sort(t_list *list)
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
			reverse_comp(j, list);
		}
		i++;
		temp = temp->next;
	}
}

void		alpha_comp(int j, t_list *list)
{
	char	*copy;
	char	*copy2;

	copy = NULL;
	copy2 = NULL;
	while (j > 0 && ft_strcmp(copy = alpha_check(&list, j),
				copy2 = alpha_check(&list, j - 1)) < 0)
	{
		ft_swap_inode(((t_inode *)index_list(&list, j)->content),
				((t_inode *)(index_list(&list, j - 1)->content)));
		j--;
		ft_strdel(&copy);
		ft_strdel(&copy2);
	}
	ft_strdel(&copy);
	ft_strdel(&copy2);
}

void		alpha_sort(t_list *list)
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
			alpha_comp(j, list);
		}
		i++;
		temp = temp->next;
	}
}
