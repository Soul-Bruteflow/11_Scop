/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:41 by mvlad             #+#    #+#             */
/*   Updated: 2019/04/09 13:28:21 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		load_shaders(t_scop *scop)
{
	scop->vertex_shdr_src = parser_shader(VERT_PATH);
	scop->fragment_shdr_src = parser_shader(FRAG_PATH);
	build_shaders(scop);
}

const char	*parser_shader(const char *file_path)
{
	char	*buffer;
	long	length;
	FILE	*f;

	f = fopen(file_path, "r");
	fseek(f, 0, SEEK_END);
	length = ftell(f);
	rewind(f);
	fseek(f, 0, SEEK_SET);
	buffer = malloc(length + 1);
	buffer[length] = '\0';
	fread(buffer, 1, length, f);
	fclose(f);
	return (buffer);
}

void		build_shaders(t_scop *scop)
{
	int		success;
	char	log[512];

	scop->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(scop->vertex_shader, 1, &scop->vertex_shdr_src, NULL);
	compile_shader(scop->vertex_shader);
	scop->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(scop->fragment_shader, 1, &scop->fragment_shdr_src, NULL);
	compile_shader(scop->fragment_shader);
	scop->shdr_prog = glCreateProgram();
	glAttachShader(scop->shdr_prog, scop->vertex_shader);
	glAttachShader(scop->shdr_prog, scop->fragment_shader);
	glLinkProgram(scop->shdr_prog);
	glGetProgramiv(scop->shdr_prog, GL_LINK_STATUS, &success);
	if (!success)
		print_error(scop->shdr_prog, log);
	glDeleteShader(scop->vertex_shader);
	glDeleteShader(scop->fragment_shader);
}

void		compile_shader(unsigned int shader)
{
	int		success;
	char	log[512];

	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
		print_error(shader, log);
}
