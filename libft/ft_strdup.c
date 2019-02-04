/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:02:46 by aroblin           #+#    #+#             */
/*   Updated: 2017/11/24 19:19:42 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dest;

	if (!(dest = (char*)malloc((ft_strlen(s) + 1) * sizeof(*s))))
		return (0);
	ft_strcpy(dest, s);
	return (dest);
}
