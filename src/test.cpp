#include "test.hpp"

#define MULTISAMPLING true

int test()
{
	/* Variables */

	bool run = true; // The main loop runs as long as it is true
	SDL_Surface *window; // Opened window
	
	Input input; // Contains all booleans of the SDL events
		memset(&input, 0, sizeof(input)); // Set all the events to false

    Vector apex1(50, 25), apex2(25, 75), apex3(75, 75);
    Color white(255, 255, 255, 255);

	/* Triangle */

	Triangle tri(
		Vector(50, 0),
		Vector(8, 76),
		Vector(92, 76),
		Color(255, 0, 0, 255),
		Color(0, 255, 0, 255),
		Color(0, 0, 255, 255)
	);

	tri.rotate(Vector(50, 50), 180);

	/* Initialisation */

	SDL_Init(SDL_INIT_VIDEO);

    // Enabling OpenGL multisampling
    if (MULTISAMPLING)
    {
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
        glEnable(GL_MULTISAMPLE);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST );
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST );
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    }

    window = SDL_SetVideoMode(600, 600, 32, SDL_OPENGL);

    /* Main loop */

    while (run)
    {
        updateEvents(&input);
        if (input.key[SDLK_ESCAPE] || input.quit)
            run = false;

        glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);

        	tri.draw();
        	tri.rotate(Vector(50, 50), 0.5);

		glEnd();
        glFlush();
    	SDL_GL_SwapBuffers();
    }

    /* Quit */

    SDL_Quit();

    return 0;
}