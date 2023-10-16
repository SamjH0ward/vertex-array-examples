#include "semi-circle-interleaved.h"

struct ColourdVertex {
	GLfloat x, y; //position 
	GLubyte r, g, b; // colour

	ColourdVertex(GLfloat x, GLfloat y, GLubyte r, GLubyte g, GLubyte b) {
		this->x = x;
		this->y = y;

		this->r = r;
		this->g = g;
		this->b = b;
	}
};


static ColourdVertex vertices[] = {
	ColourdVertex(-0.25f, 0.0f, 255, 0, 0),
	ColourdVertex(-0.75f, 0.0f, 255, 0, 0),
	ColourdVertex(-0.216506351f, 0.125f, 255, 0, 0),
	ColourdVertex(-0.649519053f, 0.375f, 255, 0, 0),
	ColourdVertex(-0.125f, 0.216506351f, 255, 255, 0),
	ColourdVertex(-0.375f, 0.649519053f, 255, 255, 0),
	ColourdVertex(0.0f, 0.25f, 0, 255, 0),
	ColourdVertex(0.0f, 0.75f, 0, 255, 0),
	ColourdVertex(0.125f, 0.216506351f, 112, 231, 243),
	ColourdVertex(0.375f, 0.649519053f, 112, 231, 243),
	ColourdVertex(0.216506351f, 0.125f, 0, 0, 255),
	ColourdVertex(0.649519053f, 0.375f, 0, 0, 255),
	ColourdVertex(0.25f, 0.0f, 234, 53, 230),
	ColourdVertex(0.75f, 0.0f, 234, 53, 230)

};


static GLubyte someIndex[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};

void renderSemiCircleInterleaved() {
	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, sizeof(ColourdVertex), &(vertices[0].x));
	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(ColourdVertex), &(vertices[0].r));

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the object
	glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_BYTE, someIndex);
}
