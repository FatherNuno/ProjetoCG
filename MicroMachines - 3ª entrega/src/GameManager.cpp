#include "stdlib.h"
#include <GL/glut.h>
#include "Table1.h"
#include "Butter.h"
#include "Orange.h"
#include "RoadSide.h" 
#include "Camera.h"
#include "GameManager.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "Car.h"
#include "LightSource.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Candle.h"
#include <vector>
#include <ctime>
#include <math.h>


#define PI 3.141592


Camera* _activecam; //camera ativa
std::vector<Camera*> _cameras; //vetor de cameras
int flag; //saber qual camera esta ativa

//std::vector<LightSource *> light_sources;
std::vector<Candle *> _candles;			//velas
std::vector<GameObject*> _gameobjects;
unsigned int _orange = 0;

LightSource *_ambientLight;

bool lightCalc = false;
bool daybool = true;
bool candlebool = false;
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

	//camaras
	Vector3 eye(0.0, -0.5, 2.8);
	Vector3 at(0.0, 0.0, 0.0);
	Vector3 up(0.0, 0.0, 1.0);

	double angle = car.getAngle();
	Vector3 eye2(car.getPosition() - (Vector3(0.2*cos(angle*(PI / 180)), 0.2*sin(angle*(PI / 180)), -0.2)));
	Vector3 at2(car.getPosition());
	Vector3 up2(0.0, 0.0, 1.0);

	_cameras.push_back(new OrthogonalCamera(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0));
	_cameras.push_back(new PerspectiveCamera(90.0, 1, 0.1, 100, eye, at, up));
	_cameras.push_back(new PerspectiveCamera(90.0, 1, 0.1, 100, eye2, at2, up2));

	srand(static_cast<unsigned int>(time(0)));  //seeds random function

	for (i = 0; i < 256; i++) {
		_specialKeys[i] = false;
	}
	_gameobjects.push_back(new Table1(0.0, 0.0, 0.0));
	_orange++;

	//tamanho do torus 0,06
	//lado externo
	for (float x = -1.3; x <= 1.25; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, -1.25, 0.51));
		_orange++;
	}
	for (float x = -1.3; x <= 1.25; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, 1.15, 0.51));
		_orange++;
	}
	for (float y = -1.1; y < 1.15; y += 0.15) {
		_gameobjects.push_back(new RoadSide(-1.3, y, 0.51));
		_orange++;
	}
	for (float y = -1.1; y < 1.15; y += 0.15) {
		_gameobjects.push_back(new RoadSide(1.25, y, 0.51));
		_orange++;
	}
	//lado interno
	for (float x = -0.7; x <= 0.65; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, -0.65, 0.51));
		_orange++;
	}
	for (float x = -0.7; x <= 0.65; x += 0.15) {
		_gameobjects.push_back(new RoadSide(x, 0.55, 0.51));
		_orange++;
	}
	for (float y = -0.50; y < 0.55; y += 0.15) {
		_gameobjects.push_back(new RoadSide(-0.7, y, 0.51));
		_orange++;
	}
	for (float y = -0.50; y < 0.55; y += 0.15) {
		_gameobjects.push_back(new RoadSide(0.65, y, 0.51));
		_orange++;
	}

	_gameobjects.push_back(new Orange(randomDouble(-1.5, 1.5), randomDouble(-1.5, 1.5), 0.55, randomDouble(0, 0.0001), randomDouble(-180, 180)));
	_gameobjects.push_back(new Orange(randomDouble(-1.5, 1.5), randomDouble(-1.5, 1.5), 0.55, randomDouble(0, 0.0001), randomDouble(-180, 180)));
	_gameobjects.push_back(new Orange(randomDouble(-1.5, 1.5), randomDouble(-1.5, 1.5), 0.55, randomDouble(0, 0.0001), randomDouble(-180, 180)));


	_gameobjects.push_back(new Butter(-1, 0.8, 0.55));
	_gameobjects.push_back(new Butter(1, 0.2, 0.55));
	_gameobjects.push_back(new Butter(0, -0.1, 0.55));
	_gameobjects.push_back(new Butter(-0.5, -0.8, 0.55));
	_gameobjects.push_back(new Butter(0.5, -1, 0.55));

	

	car = Car(0.90f, -0.65f, 0.5625f, 0.0f, 0.0f, 0.4f, 0.8f);
	
	_activecam = _cameras[0];
	flag = 1;

	//luzes
	_ambientLight = new LightSource(GL_LIGHT0);

	

	
	_candles.push_back(new Candle(GL_LIGHT1));
	_candles.push_back(new Candle(GL_LIGHT2));
	_candles.push_back(new Candle(GL_LIGHT3));
	_candles.push_back(new Candle(GL_LIGHT4));
	_candles.push_back(new Candle(GL_LIGHT5));
	_candles.push_back(new Candle(GL_LIGHT6));

	setAmbientLight();

	initLightPosts();

	
	
	glDisable(GL_LIGHTING);
	
	
}

void GameManager:: display() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 _activecam->computeProjectionMatrix();
		(_gameobjects[0]->draw());
	

	for (unsigned int i = 1; i < _gameobjects.size(); i++) {
		(_gameobjects[i]->draw());

	}
	for (unsigned int i = 0; i < _candles.size(); i++) {
		(_candles[i]->draw());

	}

	car.draw();
	_ambientLight->draw();

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h){
	float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
    float ratio = (xmax - xmin) / (ymax - ymin);
    float aspect = (float) w / h;
    if ( aspect > ratio )
		glViewport( (w-h*ratio)/2, 0, h*ratio, h);
    else
		glViewport( 0, (h-w/ratio)/2, w, w/ratio);
    glMatrixMode( GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


void GameManager::update(double delta_t) {
	if (_specialKeys[GLUT_KEY_LEFT] == true){
		car.setLeft(true);
		car.moveLeftPressed();
	}	
	if (_specialKeys[GLUT_KEY_RIGHT] == true){
		car.setRight(true);
		car.moveRightPressed();
	}
	if (_specialKeys[GLUT_KEY_UP] == true){
		car.setUp(true);
		car.moveUpPressed(delta_t);
	}
	if (_specialKeys[GLUT_KEY_DOWN] == true){
		car.setDown(true);
		car.moveDownPressed(delta_t);
	}
	if (_specialKeys[GLUT_KEY_LEFT] == false)
		car.setLeft(false);
	if (_specialKeys[GLUT_KEY_RIGHT] == false)
		car.setRight(false);
	if (_specialKeys[GLUT_KEY_UP] == false)
		car.setUp(false);
	if (_specialKeys[GLUT_KEY_DOWN] == false)
		car.setDown(false);
	if (_specialKeys[GLUT_KEY_DOWN] == false && _specialKeys[GLUT_KEY_UP] == false){
		car.moveUnpressed();
	}

	car.fall();  //ver se o carro caiu

	for (unsigned int i = _orange; i < (_orange+3); i++) {  //mover laranjas
		(_gameobjects[i]->move(delta_t));
	}

	for (unsigned int i = _orange; i < (_orange + 3); i++) { //verifica se laranja caiu
		(_gameobjects[i]->fall());
	}

	for (unsigned int i = 0; i < _gameobjects.size(); i++) {//verifica se colidiu com manteigas ou cheerios
		double distance =  ((car.getX()-_gameobjects[i]->getX())*(car.getX()-_gameobjects[i]->getX()) +  (car.getY()-_gameobjects[i]->getY())*(car.getY()-_gameobjects[i]->getY()));
		if(sqrt(distance)<= (car.getR() + _gameobjects[i]->getR())){
			_gameobjects[i]->colision(car.getId(),car.getVel(),car.getAngle());
			car.colision(_gameobjects[i]->getId(),_gameobjects[i]->getVel(),_gameobjects[i]->getAngle());
		}
	}

	if(flag==3){
		double angle=car.getAngle();
		((PerspectiveCamera *) _activecam)->setAtVector(car.getPosition());
		((PerspectiveCamera *) _activecam)->setEyeVector(car.getPosition()- (Vector3(0.2*cos(angle*(PI/180)),0.2*sin(angle*(PI/180)),-0.2)));
	}

	glutPostRedisplay();
	glFlush();
}

void GameManager::setAmbientLight(){

	_ambientLight->setState(true);

	_ambientLight->setAmbient(new Vector4(0.1, 0.1, 0.1, 1.0));
	_ambientLight->setDiffuse(new Vector4(1.0, 1.0, 1.0, 1.0));
	_ambientLight->setSpecular(new Vector4(1.0, 1.0, 1.0, 1.0));
	_ambientLight->setPosition(new Vector4(0.0, 1.0, 1.0, 0.0));
	

	

}

void GameManager::initLightPosts() {

	_candles[0]->setPosition(new Vector4(-1.35, -1.15, 1.05, 1.0));	
	_candles[1]->setPosition(new Vector4(-1.35, 1.20, 1.05, 1.0));
	_candles[2]->setPosition(new Vector4(1.30, -1.15, 1.05, 1.0));
	_candles[3]->setPosition(new Vector4(1.30, 1.20, 1.05, 1.0));
	_candles[4]->setPosition(new Vector4(-0.65, 0.0, 1.05, 1.0));
	_candles[5]->setPosition(new Vector4(0.60, 0.0, 1.05, 1.0));

	for (int i = 0; i < 6; i++) {
		_candles[i]->setState(false);

		_candles[i]->setAmbient(new Vector4(0.2, 0.2, 0.2, 1.0));
		_candles[i]->setDiffuse(new Vector4(1.0, 1.0, 1.0, 1.0));
		_candles[i]->setSpecular(new Vector4(1.0, 1.0, 1.0, 1.0));
	}

}

void GameManager::cameraKey(unsigned char key){
	switch (key){
		case '1':
			_activecam = _cameras[0];
			flag = 1;
			break;
		case '2':
			_activecam = _cameras[1];
			flag = 2;
			break;
		case '3':
			_activecam = _cameras[2];
			flag = 3;
			break;
	}
}

void GameManager::lightKey(unsigned char key) {
	switch (key) {
	case 'l':
	case 'L':
		if (glIsEnabled(GL_LIGHTING))
			glDisable(GL_LIGHTING);
		else
			glEnable(GL_LIGHTING);
		break;
	case 'n':
	case 'N':
			if (_ambientLight->getState()) {
				_ambientLight->setState(false);
				glDisable(GL_LIGHT0);
			}
			else if(!_ambientLight->getState())
			{
				_ambientLight->setState(true);
				glEnable(GL_LIGHT0);
			}
		
			break;
	case 'c':
	case 'C':
			if (candlebool) {
				candlebool = false;
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT4);
				glDisable(GL_LIGHT5);
				glDisable(GL_LIGHT6);
			}
			else if(!candlebool){
				candlebool = true;
				glEnable(GL_LIGHT1);
				glEnable(GL_LIGHT2);
				glEnable(GL_LIGHT3);
				glEnable(GL_LIGHT4);
				glEnable(GL_LIGHT5);
				glEnable(GL_LIGHT6);
			}
			break;
	}
}

void GameManager::specialKey(int key, int x, int y) {
	_specialKeys[key] = true;
}

void GameManager::specialKeyUp(int key, int x, int y) {
	_specialKeys[key] = false;
}

void GameManager::orangeVelocity() {
	for (unsigned int i = _orange; i < (_orange+3); i++) {
		(_gameobjects[i]->changeVelocity());
	}
}

double GameManager::randomDouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}





