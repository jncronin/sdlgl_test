#include <SDL2/SDL.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

const int w = 800;
const int h = 480;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }

    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);


    auto wnd = SDL_CreateWindow("sdlgl_test", 0, 0,
        w, h, SDL_WINDOW_OPENGL);
    if(!wnd)
    {
        fprintf(stderr, "SDL_CreateWindow failed\n");
        return -1;
    }

    auto ctx = SDL_GL_CreateContext(wnd);
    if(!ctx)
    {
        fprintf(stderr, "SDL_GL_CreateContext failed\n");
        return -1;
    }

    bool running = true;
    float angle = 0.0f;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    while(running)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }

        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glLoadIdentity();
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLES);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
        
        SDL_GL_SwapWindow(wnd);

        angle += 0.01f;
    }

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(wnd);
    SDL_Quit();

    return 0;
}
