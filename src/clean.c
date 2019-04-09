/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:48:07 by mvlad             #+#    #+#             */
/*   Updated: 2019/04/09 12:55:17 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	cleanup_sdl(t_scop *scop)
{
	SDL_GL_DeleteContext(scop->main_context);
	SDL_DestroyWindow(scop->main_window);
	SDL_Quit();
}
