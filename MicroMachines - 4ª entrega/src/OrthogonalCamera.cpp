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


OrthogonalCamera::~OrthogonalCamera() { 
}

void OrthogonalCamera::computeProjectionMatrix() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(_left, _right, _bottom, _top, _far, _near);
	computeVisualizationMatrix();
}

void OrthogonalCamera::computeVisualizationMatrix() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

