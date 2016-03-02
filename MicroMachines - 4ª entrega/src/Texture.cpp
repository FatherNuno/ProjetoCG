#include "Texture.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

Texture::Texture() {
}

Texture::Texture(GLuint texture) {
	_id = texture;
}

GLuint Texture::LoadTexture(){
    int width=256;
	int height=256;
    BYTE data[256][256];
    FILE* file;

    // abrir dados de textura
	file = fopen("textura.bmp" , "rb" );
    if ( file == NULL ) 
		return 0;

    // ler dados de textura
    fread( data, width * height * 3, 1, file );
    fclose( file );

    // allocar nome de textura
    glGenTextures( 1, &_id);

    // selecionar textura atual
    glBindTexture( GL_TEXTURE_2D, _id );

    // textura reage a limunicao
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // constroi mipmaps de textura
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );

    return _id;
}

void Texture::DeleteTexture(){
	glDeleteTextures( 1, &_id);
}

Texture::~Texture(void)
{