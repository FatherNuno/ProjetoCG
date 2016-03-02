#include "Candle.h"



Candle::Candle(GLenum number) {

	_num = number;
	

}

Candle::~Candle() {
}


void Candle::draw() {

	//Material

	GLfloat candle_amb[] = {0.55f,0.27f,0.05f,1.0f};
	GLfloat candle_diff[] = {0.92f,0.61f,0.1f,1.0f};
	GLfloat candle_spec[] = {0.53f,0.0f,0.0f,1.0f};
	GLfloat candle_shine = 128;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, candle_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, candle_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, candle_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, candle_shine);

	//Solido

	glColor3d(1.0, 1.5, 0);

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), 0.625);

	glScalef(1.0, 1.0, 10);
	glutSolidCube(0.025);
	glPopMatrix();

	GLfloat amb[] = { getAmbient()->getX(), getAmbient()->getY(), getAmbient()->getZ(), getAmbient()->getW() };
	GLfloat diffuse[] = { getDiffuse()->getX(), getDiffuse()->getY(), getDiffuse()->getZ(),getDiffuse()->getW() };
	GLfloat specular[] = { getSpecular()->getX(), getSpecular()->getY(), getSpecular()->getZ(), getSpecular()->getW() };
	GLfloat pos[] = { getPosition()->getX(), getPosition()->getY(), 1.0, 1.0 };

	glLightfv(_num, GL_AMBIENT, amb);
	glLightfv(_num, GL_DIFFUSE, diffuse);
	glLightfv(_num, GL_SPECULAR, specular);
	glLightfv(_num, GL_POSITION, pos);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 3);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 3);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 3);


	
}

