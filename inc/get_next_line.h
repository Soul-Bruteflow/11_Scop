/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruteflow <bruteflow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:59:19 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/28 12:18:01 by bruteflow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 20
# define PROTECT_N1(x) if (!x) return (-1);
# define PROTECT_N2(x, z, w) if (x == NULL || z < 0 || w) return (-1);

int	get_next_line(const int fd, char **line);

#endif
