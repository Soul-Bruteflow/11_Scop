/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_str_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:48:30 by mvlad             #+#    #+#             */
/*   Updated: 2019/04/09 12:55:45 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

unsigned int		ft_2d_str_count(char **str)
{
	unsigned int	element_count;

	element_count = 0;
	while (str[element_count])
		element_count++;
	return (element_count);
}
