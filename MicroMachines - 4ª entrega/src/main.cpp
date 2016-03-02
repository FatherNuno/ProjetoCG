#include "stdlib.h"
#include <GL/glut.h>
#include "GameManager.h"
#include "Car.h"

#define WIDTH 800
#define HEIGHT 700


GameManager *gm;
Car  *car;


int _id = 1;
int _somb = 1;		//para o tipo de sombreamento
int _pause = 0;     //para pausa do jogo
double oldTimeSinceStart = 0;
double delta_t = 0;

void myDisplay() {	
	gm->display(_pause);
}

void myReshape(GLsizei largura, GLsizei altura) {
	gm->reshape(largura, altura);
}

//quando a tecla A é premida

void keyPressed(unsigned char key) {
	if (key == 'a' || key == 'A') {
		if (_id) {
			_id--;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glutPostRedisplay();
		}
		else {
			_id++;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glutPostRedisplay();
		}
	}
	if (key == 'g' || key == 'G') {
		if (_somb) {
			_somb--;
			glShadeModel(GL_SMOOTH);
			glutPostRedisplay();
		}
		else {
			_somb++;
			glShadeModel(GL_FLAT);
			glutPostRedisplay();
		}
	}
	if (key == 's' || key == 'S') {
		if (_pause) {
			_pause--;
			gm->pause();
		}
		else {
			_pause++;
		}
	}
	if (key == 'r' || key == 'R')
		gm->reinicia();

	else if(key == '1' || key == '2' || key == '3'){
		gm->cameraKey(key);
	}	

	else if (key == 'l' || key == 'L'|| key =='n' || key == 'N' || key == 'c' || key == 'C' || key == 'h' || key == 'H' || key == 'j' || key == 'J') {
		gm-> lightKey(key);
	}
}

// quando as teclas para o carro sao premidas

void specialKeys(int key, int x, int y) {
	gm->specialKey(key, x, y);
}

// quando as teclas para o carro deixam de ser premidas

void specialUpKeys(int key, int x, int y){
	gm->specialKeyUp(key, x , y);
}

void myKeyboardDown(unsigned char key, int x, int y) {
	keyPressed(key);
}

void onTimer(int value) {
	double timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	delta_t = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	if(_pause)
		delta_t=0;
	if (value == 0){
		gm->update(delta_t);
		glutTimerFunc(10, onTimer, 0);
	}
	if (value == 1){
	    gm->orangeVelocity(delta_t);
		glutTimerFunc(5000,onTimer,1);  
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE );
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MicroMachines");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glEnable (GL_DEPTH_TEST);
	gm = new GameManager();
	gm->init();
	glutKeyboardFunc(myKeyboardDown);
	glutSpecialUpFunc(specialUpKeys);
	glutSpecialFunc(specialKeys);
	glutTimerFunc(10,onTimer,0);  //temporizador de update
	glutTimerFunc(5000,onTimer,1); //temporizador de velocidade de laranjas
	glutMainLoop();
	return 0;
}