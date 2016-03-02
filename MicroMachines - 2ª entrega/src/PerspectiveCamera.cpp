#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(){

}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Vector3 eye, Vector3 at, Vector3 up){
	_fovy = fovy;
	_aspect = aspect;
	_near = zNear;
	_far = zFar;
	_up = up;
	_at = at;
	_eye = eye;
}

PerspectiveCamera::~PerspectiveCamera() { }

void PerspectiveCamera::update(Vector3 reference){
	_at.set(reference.getX(), reference.getY(), reference.getZ());
}

void PerspectiveCamera::setAtVector(Vector3 new_at){
	_at.set(new_at.getX(), new_at.getY(), new_at.getZ());
}

void PerspectiveCamera::setEyeVector(Vector3 new_eye){
	_eye.set(new_eye.getX(), new_eye.getY(), new_eye.getZ());
}

void PerspectiveCamera::computeProjectionMatrix(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy,_aspect,_near,_far);
	computeVisualizationMatrix();
}

void PerspectiveCamera::computeVisualizationMatrix(){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(_eye.getX(), _eye.getY(), _eye.getZ(), _at.getX(), _at.getY(), _at.getZ(), _up.getX(), _up.getY(), _up.getZ());

}