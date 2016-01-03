/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:19:23 by avacher           #+#    #+#             */
/*   Updated: 2015/12/28 16:39:39 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int		concat_buff(char **end_buff, char **line)
{
	char			*newline;

	newline = ft_strchr(*end_buff, '\n');
	*line = ft_strsub(*end_buff, 0, newline - *end_buff);
	ft_strcpy(*end_buff, newline + 1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*end_buff[256];
	char			buff[BUFF_SIZE + 1];
	int				read_ret;

	read_ret = 0;
	if (end_buff[fd] && end_buff[fd][0] && (ft_strchr(end_buff[fd], '\n') != NULL))
		return (concat_buff(&(end_buff[fd]), line));
	while ((read_ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		if ((end_buff[fd] = ft_properjoin(end_buff[fd], buff)) == NULL)
			return (-1);
		if (ft_strchr(end_buff[fd], '\n') != NULL)
			return (concat_buff(&(end_buff[fd]), line));
	}
	if (read_ret == -1)
		return (-1);
	if (end_buff[fd] && *(end_buff[fd]))
	{
		*line = ft_strdup(end_buff[fd]);
		ft_strdel(&(end_buff[fd]));
		return (1);
	}
	return (0);
}
