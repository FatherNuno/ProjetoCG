#pragma once
#include <GL/glut.h>

class Texture{

private:
	GLuint _id;
public:
	Texture();
	Texture(GLuint texture);
	~Texture(void);
	GLuint LoadTexture();
	void DeleteTexture();
};