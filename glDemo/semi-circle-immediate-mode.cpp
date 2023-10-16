
#include "semi-circle-immediate-mode.h"


void drawSemiCircleImmediate() {

	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.25f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.75f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.216506351f, 0.125f);
	//
	glColor3ub(255, 0, 0);
	glVertex2f(-0.649519053f, 0.375f);
	//
	glColor3ub(255, 255, 0);
	glVertex2f(-0.125, 0.216506351f);
	//
	glColor3ub(255, 255, 0);
	glVertex2f(-0.375f, 0.649519053f);
	//
	glColor3ub(0, 255, 0);
	glVertex2f(0.0f, 0.25f);
	//
	glColor3ub(0, 255, 0);
	glVertex2f(0.0f, 0.75f);
	//
	glColor3ub(112, 231, 243);
	glVertex2f(0.125f, 0.216506351f);
	//
	glColor3ub(112, 231, 243);
	glVertex2f(0.375f, 0.649519053f);
	//
	glColor3ub(0, 0, 255);
	glVertex2f(0.216506351f, 0.125f);
	//
	glColor3ub(0, 0, 255);
	glVertex2f(0.649519053f, 0.375f);
	//
	glColor3ub(234, 53, 230);
	glVertex2f(0.25f, 0.0f);

	glColor3ub(234, 53, 230);
	glVertex2f(0.75f, 0.0f);

	glEnd();
}
