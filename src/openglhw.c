//#include "SDL.h"
//#include <OpenGL/gl.h>
//
//#define RESOLUTION_WIDTH  640
//#define RESOLUTION_HEIGHT 480
//
//    void initGL(void);
//    void render(void);
//
//	void SetOpenGLAttributes(void);
//
//    int main(int argc, char* argv[])
//    {
//        int running;
//	    SDL_Window *mainWindow;
//	    SDL_GLContext mainContext;
//
//	    mainWindow = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL);
//
//	    // Check that everything worked out okay
//	    if (!mainWindow)
//	    {
//		    printf("Cannot create window.");
//	    }
//
//	    mainContext = SDL_GL_CreateContext(mainWindow);
//	    SetOpenGLAttributes();
//	    SDL_GL_SetSwapInterval(1);
//
//        initGL();
//
//        running = 1;
//        while(running)
//        {
//            SDL_Event sdl_event;
//            while(SDL_PollEvent(&sdl_event) > 0)
//            {
//                if(sdl_event.type == SDL_QUIT)
//                {
//                    running = 0;
//                }
//            }
//
//            render();
//        }
//
//        SDL_Quit();
//        return 0;
//    }
//
//void SetOpenGLAttributes(void)
//{
//	// Set our OpenGL version.
//	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//
//	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
//
//	// Turn on double buffering with a 24bit Z buffer.
//	// You may need to change this to 16 or 32 for your system
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//
//	return;
//}
//
//	void initGL(void)
//    {
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(-RESOLUTION_WIDTH/2, RESOLUTION_WIDTH/2, -RESOLUTION_HEIGHT/2, RESOLUTION_HEIGHT/2, 1, -1);
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//    }
//
//    void render(void)
//    {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glRotatef(1, 0, 0, 1);
//        glBegin(GL_TRIANGLES);
//            glColor3f(1, 0, 0); glVertex2f( 0,  32); /* Bottom      */
//            glColor3f(0, 1, 0); glVertex2f(-32, 0 ); /* Upper Left  */
//            glColor3f(0, 0, 1); glVertex2f( 32, 0 ); /* Upper Right */
//        glEnd();
//    }

// OpenGL / glew Headers
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>
#include <stdbool.h>

// SDL2 Headers
#include <SDL2/SDL.h>

// Our SDL_Window ( just like with SDL2 wihout OpenGL)
SDL_Window *mainWindow;

// Our opengl context handle
SDL_GLContext mainContext;

bool SetOpenGLAttributes();
void PrintSDL_GL_Attributes();
void CheckSDLError(int line);
void RunGame();
void Cleanup();


bool Init()
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to init SDL\n");
		return false;
	}

	// Create our window centered at 512x512 resolution
	mainWindow = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			512, 512, SDL_WINDOW_OPENGL);

	// Check that everything worked out okay
	if (!mainWindow)
	{
		printf("Unable to create window\n");
		//CheckSDLError(__LINE__);
		return false;
	}

	// Create our opengl context and attach it to our window
	mainContext = SDL_GL_CreateContext(mainWindow);

	SetOpenGLAttributes();

	// This makes our buffer swap syncronized with the monitor's vertical refresh
	SDL_GL_SetSwapInterval(1);

	// Init GLEW
	// Apparently, this is needed for Apple. Thanks to Ross Vander for letting me know
#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	glewInit();
#endif

	return true;
}

bool SetOpenGLAttributes()
{
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}

int main(int argc, char *argv[])
{
	if (!Init())
		return -1;

	// Clear our buffer with a black background
	// This is the same as :
	// 		SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
	// 		SDL_RenderClear(&renderer);
	//
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(mainWindow);

	PrintSDL_GL_Attributes();
	RunGame();

	Cleanup();

	return 0;
}

void RunGame()
{
	bool loop = true;

	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						loop = false;
						break;
					case SDLK_r:
						// Cover with red and update
						glClearColor(1.0, 0.0, 0.0, 1.0);
						glClear(GL_COLOR_BUFFER_BIT);
						SDL_GL_SwapWindow(mainWindow);
						break;
					case SDLK_g:
						// Cover with green and update
						glClearColor(0.0, 1.0, 0.0, 1.0);
						glClear(GL_COLOR_BUFFER_BIT);
						SDL_GL_SwapWindow(mainWindow);
						break;
					case SDLK_b:
						// Cover with blue and update
						glClearColor(0.0, 0.0, 1.0, 1.0);
						glClear(GL_COLOR_BUFFER_BIT);
						SDL_GL_SwapWindow(mainWindow);
						break;
					default:
						break;
				}
			}
		}

		// Swap our back buffer to the front
		// This is the same as :
		// 		SDL_RenderPresent(&renderer);
	}
}

void Cleanup()
{
	// Delete our OpengL context
	SDL_GL_DeleteContext(mainContext);

	// Destroy our window
	SDL_DestroyWindow(mainWindow);

	// Shutdown SDL 2
	SDL_Quit();
}

void PrintSDL_GL_Attributes()
{
	int value = 0;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
	printf("Major: %d\n", value);

	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
	printf("Minor: %d\n", value);
}