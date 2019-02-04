/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:15:55 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/13 20:02:15 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;
	int		x;

	i = 0;
	len = ft_count_words(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * len + 1)) || !(s))
		return (NULL);
	len = 0;
	while (s[i] == c)
		++i;
	while (s[i] != '\0')
	{
		x = i;
		while (s[i] != c && s[i] != '\0')
			++i;
		dest[len] = ft_strsub(s, x, (i - x));
		++len;
		while (s[i] == c)
			++i;
	}
	dest[len] = NULL;
	return (dest);
}
