#include <iostream>
#include <math.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

#include "events/events.hpp"
#include "operator-overloading/op_coord.hpp"
#include "triangle.hpp"
#include "color.hpp"
#include "coord.hpp"

int main()
{
	/* Variables */

	bool run = true; // The main loop runs as long as it is true
	SDL_Surface *window; // Opened window
	
	Input input; // Contains all booleans of the SDL events
		memset(&input, 0, sizeof(input)); // Set all the events to false

    Coord apex1(50, 25), apex2(25, 75), apex3(75, 75);
    Color red(255, 0, 0), green(0, 255, 0), blue(0, 0, 255), white(255, 255, 255), black(0, 0, 0);

	Triangle t1(apex1, 
				apex2, 
				apex3, 
				white);

    Triangle t2(apex1 + (apex2 - apex1) / 2,
                apex2 + (apex3 - apex2) / 2,
                apex3 + (apex1 - apex3) / 2,
                black);

    Coord left(0, 0), right(0, 0), down(0, 0);

	/* Initialisation */

	SDL_Init(SDL_INIT_VIDEO);
    cout << "Init SDL" << endl;

    // Enabling OpenGL multisampling
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    glEnable(GL_MULTISAMPLE);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    cout << "Init OpenGL Multisampling" << endl;

    window = SDL_SetVideoMode(800, 600, 32, SDL_OPENGL);
    cout << "Open window (" << 800 << "x" << 600 << ")" << endl;

    /* Main loop */

    while (run)
    {
        updateEvents(&input);
        if (input.key[SDLK_ESCAPE] || input.quit)
            run = false;

        glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);

            t1.draw();

            // t2.translate(left);
            // t2.draw();
            // t2.translate(-left);

            // t2.translate(right);
            // t2.draw();
            // t2.translate(-right);

            t2.translate(left);
            t2.draw();
            t2.translate(right - left);
            t2.draw();
            t2.translate(-right);

            left += Coord(0.03, -0.03);
            right += Coord(-0.03, -0.03);

		glEnd();
        glFlush();
    	SDL_GL_SwapBuffers();
    }

    /* Quit */

    SDL_Quit();
    cout << "Quit SDL" << endl;
}