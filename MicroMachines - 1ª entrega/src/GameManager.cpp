#include "stdlib.h"
#include <GL/glut.h>
#include "Table1.h"
#include "Butter.h"
#include "Orange.h"
#include "RoadSide.h" 
#include "Camera.h"
#include "GameManager.h"
#include "OrthogonalCamera.h"
#include "Car.h"
#include <vector>





OrthogonalCamera orthocamera;
std::vector<GameObject*> _gameobjects;
Car car;

GameManager::GameManager() {
	_specialKeys = new bool[256];
	int i;
	for (i = 0; i < 256; i++) {
		_specialKeys[i] = false;
	}

}

GameManager::~GameManager() {

}

void GameManager::init() {
	int i;
	for (i = 0; i < 256; i++) {
		_specialKeys[i] = false;
	}
	_gameobjects.push_back(new Table1(0.0, 0.0, 1));

	_gameobjects.push_back(new Orange(1, 1.2, 1));
	_gameobjects.push_back(new Orange(0.5, 0.4, 1));
	_gameobjects.push_back(new Orange(-0.25, 0.2, 1));

	_gameobjects.push_back(new Butter(-1, 0.8, 1));
	_gameobjects.push_back(new Butter(1, 0.2, 1));
	_gameobjects.push_back(new Butter(0, -0.1, 1));
	_gameobjects.push_back(new Butter(-0.5, -0.8, 1));
	_gameobjects.push_back(new Butter(0.5, -1, 1));
	car = Car(0.90f, -0.65f, 1.0f, 0.0f, 0.0f, 0.4f, 0.8f);
	
	_gameobjects.push_back(&car); // azul
	//tamanho do torus 0,06
	//lado externo
	for (float x = -1.3; x <= 1.25; x+=0.15) {
		_gameobjects.push_back(new RoadSide(x, -1.25, 1));
	}
	for (float x = -1.3; x <= 1.25; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, 1.15, 1));
	}
	for (float y = -1.1; y < 1.15; y += 0.15) {
		_gameobjects.push_back(new RoadSide(-1.3, y, 1));
	}
	for (float y = -1.1; y < 1.15; y += 0.15) {
		_gameobjects.push_back(new RoadSide(1.25, y, 1));
	}
	//lado interno
	for (float x = -0.7; x <= 0.65; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, -0.65, 1));
	}
	for (float x = -0.7; x <= 0.65; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, 0.55, 1));
	}
	for (float y = -0.65; y < 0.55; y += 0.15) {
		_gameobjects.push_back(new RoadSide(-0.7, y, 1));
	}
	for (float y = -0.65; y < 0.55; y += 0.15) {
		_gameobjects.push_back(new RoadSide(0.65, y, 1));
	}




}

void GameManager:: display() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	orthocamera.computeVisualizationMatrix();

	for (unsigned int i = 0; i < _gameobjects.size(); i++) {
		(_gameobjects[i]->draw());
	}

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {

	glViewport(0, 0, w, h);	// x, y a cortar em baixo, largura, altura a ver
	
	float aspect = (float)w / h;

	orthocamera.computeReshape(aspect);
}

void GameManager::update(double delta_t) {
	if (_specialKeys[GLUT_KEY_LEFT] == true)
		car.moveLeftPressed();
	if (_specialKeys[GLUT_KEY_RIGHT] == true)
		car.moveRightPressed();
	if (_specialKeys[GLUT_KEY_UP] == true)
		car.moveUpPressed(delta_t);
	if (_specialKeys[GLUT_KEY_DOWN] == true)
		car.moveDownPressed(delta_t);
	if (_specialKeys[GLUT_KEY_DOWN] == false && _specialKeys[GLUT_KEY_UP] == false){
		car.moveUnpressed();
	}
	glutPostRedisplay();
	glFlush();
}

void GameManager::specialKey(int key, int x, int y) {
	_specialKeys[key] = true;
}

void GameManager::specialKeyUp(int key, int x, int y) {
	_specialKeys[key] = false;
}





