#include "Table1.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SOIL.h"

Table1::Table1() {
}

Table1::Table1(double x, double y, double z) {
	_position.set(x, y, z); 
	tex_2d = SOIL_load_OGL_texture("wood3.jpg",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

Table1::~Table1(void){
}

void Table1::draw() {
	//Textura
	 glEnable(GL_TEXTURE_2D);
   
	 glBindTexture(GL_TEXTURE_2D, tex_2d);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//Material

	GLfloat table1_amb[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat table1_diff[] = {0.0f,0.0f,0.2f,1.0f};
	GLfloat table1_spec[] = {0.0f,0.0f,0.2f,1.0f};
	GLfloat table1_shine = 77;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, table1_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, table1_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, table1_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, table1_shine);

	//Solido

	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glColor3f(1.0, 1.0, 1.0);
	for (double y = -1.5; y < 1.5; y+=(1.5/20)) {
		for (double x = -1.5; x < 1.5; x += (1.5 / 20)) {
				glBegin(GL_POLYGON);
				glBindTexture(GL_TEXTURE_2D, tex_2d);
				glNormal3f(0, 0, 1);
				glTexCoord2d(0.0,0.0);
				glVertex3f(x,y,0.5);	//Bottom Left
				glTexCoord2d(1.0,0.0);
				glVertex3f(x+(1.5 / 20),y,0.5);	 //Bottom Right
				glTexCoord2d(1.0,1.0);
				glVertex3f(x+(1.5 / 20), y+(1.5 / 20), 0.5);	 //Top Right
				glTexCoord2d(0.0,1.0);
				glVertex3f(x,y + (1.5 / 20),0.5);	//Top Left	
				glEnd();
		}
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

double Table1::getR(){
	return 0;
}

double Table1::getX(){
	return _position.getX();
}

double Table1::getY(){
	return _position.getY();
}

int Table1::getId(){
	return 0;
}

double Table1::getVel(){
	return 0;
}

double Table1::getAngle(){
	return 0;
}

int Table1::colision(int id, double v, double angle){
	return 0;
}

void Table1::move(double delta_t) {
}

void Table1::changeVelocity(double delta_t) {
}

int Table1::fall() {
	return 0;
}

void Table1::setTexture(GLuint id){
}