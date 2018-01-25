#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	
	vertexes[0] = ClassVector3(1.0f, 1.0f, -5.0f);
	vertexes[1] = ClassVector3(-1.0f, 1.0f, -5.0f);
	vertexes[2] = ClassVector3(1.0f, -1.0f, -5.0f);
	vertexes[3] = ClassVector3(-1.0f, -1.0f, -5.0f);
	vertexes[4] = ClassVector3(1.0f, 1.0f, -15.0f);
	vertexes[5] = ClassVector3(-1.0f, 1.0f, -15.0f);
	vertexes[6] = ClassVector3(-1.0f, -1.0f, -15.0f);
	vertexes[7] = ClassVector3(1.0f, -1.0f, -15.0f);

}

Game::~Game(){}

void Game::run()
{

	
	
	Event event;
	initialize();

	while (isRunning){
		
	cout << "Game running..." << endl;

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			isRunning = false;
		}
	}
		initialize();
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vertexes[0].getX(), vertexes[0].getY(), vertexes[0].getZ());
		glVertex3f(vertexes[1].getX(), vertexes[1].getY(), vertexes[1].getZ());
		glVertex3f(vertexes[2].getX(), vertexes[2].getY(), vertexes[2].getZ());
		glVertex3f(vertexes[3].getX(), vertexes[3].getY(), vertexes[3].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vertexes[4].getX(), vertexes[4].getY(), vertexes[4].getZ());
		glVertex3f(vertexes[5].getX(), vertexes[5].getY(), vertexes[5].getZ());
		glVertex3f(vertexes[6].getX(), vertexes[6].getY(), vertexes[6].getZ());
		glVertex3f(vertexes[7].getX(), vertexes[7].getY(), vertexes[7].getZ());

		//Top face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vertexes[1].getX(), vertexes[1].getY(), vertexes[1].getZ());
		glVertex3f(vertexes[5].getX(), vertexes[5].getY(), vertexes[5].getZ());
		glVertex3f(vertexes[4].getX(), vertexes[4].getY(), vertexes[4].getZ());
		glVertex3f(vertexes[0].getX(), vertexes[0].getY(), vertexes[0].getZ());

		//Right face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(vertexes[0].getX(), vertexes[0].getY(), vertexes[0].getZ());
		glVertex3f(vertexes[2].getX(), vertexes[2].getY(), vertexes[2].getZ());
		glVertex3f(vertexes[7].getX(), vertexes[7].getY(), vertexes[7].getZ());
		glVertex3f(vertexes[4].getX(), vertexes[4].getY(), vertexes[4].getZ());

		//Left face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(vertexes[1].getX(), vertexes[1].getY(), vertexes[1].getZ());
		glVertex3f(vertexes[3].getX(), vertexes[3].getY(), vertexes[3].getZ());
		glVertex3f(vertexes[6].getX(), vertexes[6].getY(), vertexes[6].getZ());
		glVertex3f(vertexes[5].getX(), vertexes[5].getY(), vertexes[5].getZ());

		//Bottom face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vertexes[1].getX(), vertexes[1].getY(), vertexes[1].getZ());
		glVertex3f(vertexes[2].getX(), vertexes[2].getY(), vertexes[2].getZ());
		glVertex3f(vertexes[7].getX(), vertexes[7].getY(), vertexes[7].getZ());
		glVertex3f(vertexes[5].getX(), vertexes[5].getY(), vertexes[5].getZ());
		 
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.05f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	glScalef(1.0f, 1.5f, 1.0f);
	}
	
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning down" << endl;
}

