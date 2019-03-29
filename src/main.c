/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:44 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdbool.h>


//#include "scop.h"
//// Our SDL_Window ( just like with SDL2 wihout OpenGL)
//SDL_Window *mainWindow;
//// Our opengl context handle
//SDL_GLContext mainContext;
//bool Init();
//bool SetOpenGLAttributes();
//bool SetOpenGLAttributes();
//void PrintSDL_GL_Attributes();
////void CheckSDLError(int line);
//void mainLoop(int shaderProgram, unsigned int VAO);
//void Cleanup();
////Triangle
//int buildAndCompileShaders();
//unsigned int setUpVertexData();
////Read file
//int	read_file(char file_name);
////tmp shader strings
//const char *vertexShaderSource = "#version 400 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char *fragmentShaderSource = "#version 400 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//int main(int argc, char *argv[])
//{
//
//if (!Init())
//return -1;
//// Clear our buffer with a black background
//// This is the same as :
//// 		SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
//// 		SDL_RenderClear(&renderer);
////
//glClearColor(0.0, 0.0, 0.0, 1.0);
//glClear(GL_COLOR_BUFFER_BIT);
//SDL_GL_SwapWindow(mainWindow);
////PrintSDL_GL_Attributes();
//int shaderProgram = buildAndCompileShaders();
//unsigned int VAO = setUpVertexData();
//glFrontFace(GL_CW);
//mainLoop(shaderProgram, VAO);
//Cleanup();
//return 0;
//}
//
//void mainLoop(int shaderProgram, unsigned int VAO)
//{
//	bool loop = true;
//	while (loop)
//	{
//		SDL_Event event;
//		while (SDL_PollEvent(&event))
//		{
//			if (event.type == SDL_QUIT)
//				loop = false;
//			if (event.type == SDL_KEYDOWN)
//			{
//				switch (event.key.keysym.sym)
//				{
//				case SDLK_ESCAPE:
//					loop = false;
//					break;
//				case SDLK_r:
//					// Cover with red and update
//					glClearColor(1.0, 0.0, 0.0, 1.0);
//					glClear(GL_COLOR_BUFFER_BIT);
//					SDL_GL_SwapWindow(mainWindow);
//					break;
//				case SDLK_g:
//					// Cover with green and update
//					glClearColor(0.0, 1.0, 0.0, 1.0);
//					glClear(GL_COLOR_BUFFER_BIT);
//					SDL_GL_SwapWindow(mainWindow);
//					break;
//				case SDLK_b:
//					// Cover with blue and update
//					glClearColor(0.0, 0.0, 1.0, 1.0);
//					glClear(GL_COLOR_BUFFER_BIT);
//					SDL_GL_SwapWindow(mainWindow);
//					break;
//				default:
//					break;
//				}
//			}
//		}
//		// draw our first triangle
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		//glDrawArrays(GL_TRIANGLES, 0, 6);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		// glBindVertexArray(0); // no need to unbind it every time
//		SDL_GL_SwapWindow(mainWindow);
//		// Swap our back buffer to the front
//		// This is the same as :
//		// 		SDL_RenderPresent(&renderer);
//	}
//}
//bool Init()
//{
//	// Initialize SDL's Video subsystem
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("Failed to init SDL\n");
//		return false;
//	}
//	SetOpenGLAttributes();
//	// Create our window centered at 512x512 resolution
//	mainWindow = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		512, 512, SDL_WINDOW_OPENGL);
//	// Check that everything worked out okay
//	if (!mainWindow)
//	{
//		printf("Unable to create window\n");
//		//CheckSDLError(__LINE__);
//		return false;
//	}
//	// Create our opengl context and attach it to our window
//	mainContext = SDL_GL_CreateContext(mainWindow);
//
//	// This makes our buffer swap syncronized with the monitor's vertical refresh
//	SDL_GL_SetSwapInterval(1);
//	// Init GLEW
//	// Apparently, this is needed for Apple. Thanks to Ross Vander for letting me know
//	//#ifndef __APPLE__
//	glewExperimental = GL_TRUE;
//	if (GLEW_OK != glewInit())
//	{
//		printf("Failed to initialize GLEW\n");
//		return false;
//	}
//	//#endif
//	glViewport(0, 0, 512, 512);
//	return true;
//}
//bool SetOpenGLAttributes()
//{
//	// Set our OpenGL version.
//	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
//	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//	// Turn on double buffering with a 24bit Z buffer.
//	// You may need to change this to 16 or 32 for your system
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//	return true;
//}
//void Cleanup()
//{
//	// Delete our OpengL context
//	SDL_GL_DeleteContext(mainContext);
//	// Destroy our window
//	SDL_DestroyWindow(mainWindow);
//	// Shutdown SDL 2
//	SDL_Quit();
//}
//int buildAndCompileShaders()
//{
//	// build and compile our shader program
//	// ------------------------------------
//	// vertex shader
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// check for shader compile errors
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		printf("%s\n\n", infoLog);
//		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
//	}
//	// fragment shader
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	// check for shader compile errors
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
//	}
//	// link shaders
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// check for linking errors
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	return shaderProgram;
//}
//unsigned int setUpVertexData()
//{
//	float vertices[] = {
//	0.5f,  0.5f, 0.0f,  // top right
//	0.5f, -0.5f, 0.0f,  // bottom right
//	-0.5f, -0.5f, 0.0f,  // bottom left
//	-0.5f,  0.5f, 0.0f   // top left
//	};
//	unsigned int indices[] = {  // note that we start from 0!
//	0, 1, 3,  // first Triangle
//	1, 2, 3   // second Triangle
//	};
//	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//	return VAO;
//}
//void PrintSDL_GL_Attributes()
//{
//	int value = 0;
//	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
//	printf("Major: %d\n", value);
//	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
//	printf("Minor: %d\n", value);
//}


//----------------------------------------------
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
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(scop->main_window);
		main_loop(scop);
		cleanup_sdl(scop);
	}
	return (0);
}

void			send_all_textures(t_scop *scop)
{	int			i;

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
				scop->t[n].tga_height, 0, GL_RGB, GL_UNSIGNED_BYTE,
				scop->t[n].img_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	free(scop->t[n].img_data);
	glBindTexture(GL_TEXTURE_2D, 0);
}

const char * GetGLErrorStr(GLenum err)
{
	switch (err)
	{
		case GL_NO_ERROR:          return "No error";
		case GL_INVALID_ENUM:      return "Invalid enum";
		case GL_INVALID_VALUE:     return "Invalid value";
		case GL_INVALID_OPERATION: return "Invalid operation";
		case GL_STACK_OVERFLOW:    return "Stack overflow";
		case GL_STACK_UNDERFLOW:   return "Stack underflow";
		case GL_OUT_OF_MEMORY:     return "Out of memory";
		default:                   return "Unknown error";
	}
}

void CheckGLError()
{
	while (1)
	{
		const GLenum err = glGetError();
		if (GL_NO_ERROR == err)
			break;

		printf("GL Error: %s", GetGLErrorStr(err));
	}
}