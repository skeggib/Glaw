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
#include "vector.hpp"
#include "object.hpp"

#define MULTISAMPLING true

int main()
{
	/* Variables */

	bool run = true; // The main loop runs as long as it is true
	SDL_Surface *window; // Opened window
	
	Input input; // Contains all booleans of the SDL events
		memset(&input, 0, sizeof(input)); // Set all the events to false

    Vector apex1(50, 25), apex2(25, 75), apex3(75, 75);
    Color red(255, 0, 0), green(0, 255, 0), blue(0, 0, 255), white(255, 255, 255), black(0, 0, 0);
    Color cornerColor(30, 30, 30);
    Color tColor(120, 120, 120);

	Triangle t1(
        apex1, 
	    apex2, 
	    apex3, 
	    tColor);

    Triangle t2(
        apex1 + (apex2 - apex1) / 2,
        apex2 + (apex3 - apex2) / 2,
        apex3 + (apex1 - apex3) / 2,
        black);

    Triangle corner1(
        Vector(0, 0), 
        Vector(20, 0), 
        Vector(0, 20), 
        cornerColor);

    Triangle corner2(
        Vector(0, 100), 
        Vector(20, 100), 
        Vector(0, 80), 
        cornerColor);

    Triangle corner3(
        Vector(100, 0), 
        Vector(100, 20), 
        Vector(80, 0), 
        cornerColor);

    Triangle corner4(
        Vector(100, 100), 
        Vector(100, 80), 
        Vector(80, 100), 
        Color(255, 0, 0),
        Color(0, 255, 0),
        Color(0, 0, 255));

    /* Test Object */

    Object o1(Vector(0, 0), Vector(50, 50));

    o1.add(&t1);
    o1.add(&t2);

    Object o2(Vector(50, 0), Vector(50, 50));

    o2.add(&t1);
    o2.add(&t2);

    Object fond;

    fond.create(Triangle(
        Vector(0, 0),
        Vector(50, 0),
        Vector(0, 50),
        red));

    fond.create(Triangle(
        Vector(50, 0),
        Vector(100, 0),
        Vector(100, 50),
        red));

	/* Initialisation */

	SDL_Init(SDL_INIT_VIDEO);
    cout << "Init SDL" << endl;

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

            // t1.draw();
            // t2.draw();

            fond.draw();
            o1.draw();
            o2.draw();

		glEnd();
        glFlush();
    	SDL_GL_SwapBuffers();
    }

    /* Quit */

    SDL_Quit();
    cout << "Quit SDL" << endl;

    return 0;
}