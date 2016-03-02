#include <GL/glut.h>
#include <vector>

class GameManager {
	bool* _specialKeys;

public:
	GameManager();
	~GameManager();
	void display(int _pause);
	void reshape(GLsizei w, GLsizei h);
	void init();
	void update(double delta_t);
	void specialKey(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);
	void orangeVelocity(double delta_t);
	double randomDouble(double a, double b);
	void cameraKey(unsigned char key);
	void lightKey(unsigned char key);
	void setAmbientLight();
	void initLightPosts();
	void initLightCar();
	void pause();
	void gameover();
	void reinicia();
	void lives();
	void message(GLuint id);
};
