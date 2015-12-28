/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_properjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:15:29 by avacher           #+#    #+#             */
/*   Updated: 2015/12/28 13:22:10 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_properjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		ret = ft_strdup(s2);
		ft_strdel(&s2);
		return (ret);
	}
	if (s2 == NULL)
	{
		ret = ft_strdup(s1);
		ft_strdel(&s1);
		return (ret);
	}
	if (s1 != NULL && s2 != NULL)
	{
		ret = ft_strjoin(s1, s2);
		ft_strdel(&s1);
		ft_strdel(&s2);
		return (ret);
	}
	return (NULL);
}
