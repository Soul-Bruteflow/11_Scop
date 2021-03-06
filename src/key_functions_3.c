/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:06 by mvlad             #+#    #+#             */
/*   Updated: 2019/04/09 13:18:10 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	togle_auto_rotate(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_SPACE)
	{
		if (scop->enable_rotate == 1)
		{
			scop->enable_rotate = -1;
			scop->copy_auto = 1;
		}
		else
		{
			scop->enable_rotate = 1;
			scop->rot_a_fac = scop->rot_x_fac;
		}
	}
}

void	togle_draw_lines(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_1)
	{
		if (scop->is_draw_lines == 1)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			scop->is_draw_lines = -1;
		}
		else
		{
			scop->is_draw_lines = 1;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	}
}

void	togle_color_mod_1(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_2)
	{
		if (scop->color_mode_1 == 1)
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
		else
		{
			scop->color_mode_1 = 1;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}

void	togle_color_refresh(t_scop *scop)
{
	size_t s;

	if (scop->event.key.keysym.sym == SDLK_r)
	{
		generate_random_colors(scop);
		create_colors_buffer(scop);
		s = sizeof(float) * (scop->vert_num + (scop->vert_num / 3));
		glBindBuffer(GL_ARRAY_BUFFER, scop->vbo_col);
		glBufferData(GL_ARRAY_BUFFER, s, scop->colors, GL_STATIC_DRAW);
		glBindVertexArray(scop->vao);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		if (scop->cur_tex_num >= TEX_COUNT)
			scop->cur_tex_num = 0;
		else
			scop->cur_tex_num++;
	}
}

void	togle_color_mod_2(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_3)
	{
		if (scop->color_mode_2 == 1)
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
		else
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 1;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}
