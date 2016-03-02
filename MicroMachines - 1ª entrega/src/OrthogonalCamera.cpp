#include "OrthogonalCamera.h"
#include <GL/glut.h>

OrthogonalCamera::OrthogonalCamera() {

}

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) {

	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;

	_near = near;
	_far = far;
}


OrthogonalCamera::~OrthogonalCamera() 
{ 
}

void OrthogonalCamera::computeProjectionMatrix(float aspect) {

	float _right = 2, _left = -2, _top = 2, _bottom = -2;

	float ratio = (_right - _left) / (_top - _bottom);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (ratio < aspect)
	{
		float delta = ((_top - _bottom) * aspect - (_right - _left)) / 2;
		gluOrtho2D(_left - delta, _right + delta, _bottom, _top);
	}
	else
	{
		float delta = ((_right - _left) / aspect - (_top - _bottom)) / 2;
		gluOrtho2D(_left, _right, _bottom - delta, _top + delta); //define a projeccao, left, right, bottom, top
	}

}

void OrthogonalCamera::computeVisualizationMatrix() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void OrthogonalCamera::computeReshape(float aspect) {
	this->computeProjectionMatrix(aspect);
	this->computeVisualizationMatrix();
}

