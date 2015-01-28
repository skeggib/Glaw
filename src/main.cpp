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

int main()
{
	/* Variables */

	bool run = true; // The main loop runs as long as it is true
	SDL_Surface *window; // Opened window
	
	Input input; // Contains all booleans of the SDL events
		memset(&input, 0, sizeof(input)); // Set all the events to false

    Vector2 apex1(50, 25), apex2(25, 75), apex3(75, 75);
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
        Vector2(0, 0), 
        Vector2(20, 0), 
        Vector2(0, 20), 
        cornerColor);

    Triangle corner2(
        Vector2(0, 100), 
        Vector2(20, 100), 
        Vector2(0, 80), 
        cornerColor);

    Triangle corner3(
        Vector2(100, 0), 
        Vector2(100, 20), 
        Vector2(80, 0), 
        cornerColor);

    Triangle corner4(
        Vector2(100, 100), 
        Vector2(100, 80), 
        Vector2(80, 100), 
        Color(255, 0, 0),
        Color(0, 255, 0),
        Color(0, 0, 255));

    /* Test Object */

    Object o1;
    o1.create(Triangle(
        apex1, 
        apex2, 
        apex3, 
        tColor));
    
    o1.create(Triangle(
        apex1 + Vector2(10, 10) * 1 , 
        apex2 + Vector2(10, 10) * 1 , 
        apex3 + Vector2(10, 10) * 1 , 
        red));
    
    o1.create(Triangle(
        apex1 + Vector2(10, 10) * 2 , 
        apex2 + Vector2(10, 10) * 2 , 
        apex3 + Vector2(10, 10) * 2 , 
        blue));
    
    o1.create(Triangle(
        apex1 + Vector2(10, 10) * 3 , 
        apex2 + Vector2(10, 10) * 3 , 
        apex3 + Vector2(10, 10) * 3 , 
        green));
    
    o1.create(Triangle(
        apex1 + Vector2(10, 10) * 4 , 
        apex2 + Vector2(10, 10) * 4 , 
        apex3 + Vector2(10, 10) * 4 , 
        white));

    o1.rem(&corner2);

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

            // t1.draw();
            // t2.draw();

            o1.draw();

		glEnd();
        glFlush();
    	SDL_GL_SwapBuffers();
    }

    /* Quit */

    SDL_Quit();
    cout << "Quit SDL" << endl;

    return 0;
}