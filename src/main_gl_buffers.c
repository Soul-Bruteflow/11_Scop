/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gl_buffers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:23 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:23 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_gl_buffers(t_scop *scop)
{
	create_vertices_buffer(scop);
	create_colors_buffer(scop);
	create_index_buffer(scop);

	glGenVertexArrays(1, &scop->vao);
	glBindVertexArray(scop->vao);

	glBindBuffer(GL_ARRAY_BUFFER,scop->vbo_pos);//Position Buffer
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER,scop->vbo_col);//Colour Buffer
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,scop->ebo);
	glBindVertexArray(0);

}

void	create_vertices_buffer(t_scop *scop)
{
	size_t s;

	s = sizeof(float) * scop->vert_num;
	glGenBuffers(1, &scop->vbo_pos);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vbo_pos);
	glBufferData(GL_ARRAY_BUFFER, s, scop->verts, GL_STATIC_DRAW);
}

void	create_colors_buffer(t_scop *scop)
{
	size_t s;

	s = sizeof(float) * (scop->vert_num + (scop->vert_num / 3));
	glGenBuffers(1, &scop->vbo_col);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vbo_col);
	glBufferData(GL_ARRAY_BUFFER, s, scop->colors, GL_STATIC_DRAW);
}

void	create_index_buffer(t_scop *scop)
{
	size_t s;

	s = sizeof(unsigned int) * scop->indic_num;
	glGenBuffers(1, &scop->ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, s, scop->indic, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}