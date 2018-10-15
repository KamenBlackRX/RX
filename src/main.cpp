#include "iostream"
#include <SDL2/SDL.h>
#include <GL/glew.h>

#ifdef __linux__
    #include <X11/Xlib.h>
#endif

#ifdef __WIN32__
    #include <windows.h>
#endif

const int SCREEN_HEIGHT = 800;
const int SCREEN_WIDTH = 640;


extern "C"
{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #ifdef __linux__
    int PrimitiveModal( char* title, char* message)
    {
        Display *x;
        Window w;
        XEvent e;
        int screenID;
        // Open Display for X and check if we got null display
        x = XOpenDisplay(NULL);
        if(x == NULL)
        {
            fprintf(stderr, "Cannot open DISPLAY\n");
            exit(1);
        }
        //Attribute default screen and create window with given pixels.
        screenID = DefaultScreen(x);
        w = XCreateSimpleWindow(x, RootWindow(x,screenID), 10,10,200,100,100,BlackPixel(x,screenID),WhitePixel(x,screenID));
        //Set select input and Xmap window.
        XSelectInput(x,w, ExposureMask | KeyPressMask);
        XMapWindow(x, w);

        while (1) 
        {
            XNextEvent(x, &e);
            if (e.type == Expose) 
            {
                XFillRectangle(x, w, DefaultGC(x, screenID), 20, 20, 10, 10);
                XDrawString(x, w, DefaultGC(x, screenID), 10, 50, message ,strlen(message));
            }
            if (e.type == KeyPress)
            {
                break;
            }
        }
    XCloseDisplay(x);
    return 0;
   }
 

    #endif

    #ifdef __WIN32__
    int PrimitiveModal(char* title, char* message)
    {
        HANDLE* wHandle;
        MessageBox(wHandle, title, message, 0x55);
    }
    #endif
};

/* Create single shader to applu to cube*/
const std::string gl_frag = " \ 
#version 150 \
uniform sampler2D tex; //this is the texture \
in vec2 fragTexCoord; //this is the texture coord \
out vec4 finalColor; //this is the output color of the pixel \
void main() { \
    finalColor = texture(tex, fragTexCoord); \
}";

static const GLfloat g_vertex_cube()
{
  -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f;
};

int main(int argc, char const *argv[])
{
    //Test modal
    PrimitiveModal("Test", "Test01");

    //The window we'll be rendering to
		SDL_Window *window = NULL;

		//The surface contained by the window
		SDL_Surface *screenSurface = NULL;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

                if(screenSurface == nullptr)
                {
                    

                    std::cout<<"We have failed to setup a screenSurface";

                }

				//Fill the surface white
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

				//Update the surface
				SDL_UpdateWindowSurface(window);

				//Wait two seconds
				SDL_Delay(2000);
			}
		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();

    /* code */
    return 0;
}
