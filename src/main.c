/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:44 by mvlad             #+#    #+#             */
/*   Updated: 2019/04/09 13:31:05 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	if (argc == 2)
	{
		scop = init_scop();
		if (load_all_tga(scop) == -1)
			return (0);
		if (init_sdl_gl(scop) == -1)
			return (0);
		init_key(scop);
		init_open_gl_attributes();
		scop->obj_file_name = argv[1];
		if (obj_pars_main(scop) == -1)
			return (0);
		load_shaders(scop);
		send_all_textures(scop);
		main_colors(scop);
		create_gl_buffers(scop);
		main_matrix(scop);
		main_loop(scop);
		cleanup_sdl(scop);
	}
	return (0);
}

void			send_all_textures(t_scop *scop)
{
	int			i;

	i = 0;
	while (i < TEX_COUNT)
	{
		send_texture_to_opengl(scop, i);
		i++;
	}
}

void			send_texture_to_opengl(t_scop *scop, int n)
{
	glGenTextures(1, &scop->t[n].gl_id);
	glActiveTexture(GL_TEXTURE0 + n);
	glBindTexture(GL_TEXTURE_2D, scop->t[n].gl_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->t[n].tga_width,
	scop->t[n].tga_height, 0, GL_RGB, GL_UNSIGNED_BYTE, scop->t[n].img_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	free(scop->t[n].img_data);
	glBindTexture(GL_TEXTURE_2D, 0);
}
