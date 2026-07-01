#include <SDL2/SDL.h>
#include <GL/gl.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }

    auto wnd = SDL_CreateWindow("sdlgl_test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 480, SDL_WINDOW_OPENGL);
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
        glColor3f(0.0f, 1.0f, 0.0f);
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
