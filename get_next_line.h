/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:16:40 by avacher           #+#    #+#             */
/*   Updated: 2015/12/19 18:06:57 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//    a virer
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
//    a virer
# define BUFF_SIZE 9 

typedef struct		s_line
{
	int				given_fd;
	char			*end_buff;
	struct s_line	*next;
}					t_line;

int		get_next_line(const int fd, char **line);

#endif
