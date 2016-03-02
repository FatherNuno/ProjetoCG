#include <GL/glut.h>
#include <vector>

class GameManager {
	bool* _specialKeys;

public:
	GameManager();
	~GameManager();
	void display();
	void reshape(GLsizei w, GLsizei h);
	void init();
	void update(double delta_t);
	void specialKey(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);
	void orangeVelocity();
	double randomDouble(double a, double b);
	void cameraKey(unsigned char key);
};
