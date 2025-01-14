
#include "arwing.h"

#pragma region  Retained Mode

static glm::vec2 vertices[] = {

	glm::vec2(0.0f, 9.0f), // v0
	glm::vec2(-1.0f, 1.0f),  // v1
	glm::vec2(-0.184, 0.0f),  // v2
	glm::vec2(0.184f, 0.0f),  // v3
	glm::vec2(1.0f, 1.0f),  // v4
	glm::vec2(-0.656f, -0.876f),  // v5
	glm::vec2(-0.262f, -1.394f),  // v6
	glm::vec2(0.262f, -1.394f),  // v7
	glm::vec2(0.656f, -0.876f),  // v8
	glm::vec2(-1.169f, -3.0f),  // v9
	glm::vec2(-0.421f, -1.940f),  // v10
	glm::vec2(0.421f, -1.940f),  // v11
	glm::vec2(1.169f, -3.0f),  // v12
	glm::vec2(0.0f, -5.5f),  // v13

	glm::vec2(-1.720f, -0.426f), // v14
	glm::vec2(-1.623f, -2.097f), // v15
	glm::vec2(-2.310f, 4.0f), // v16
	glm::vec2(-2.805f,-0.211f), // v17
	glm::vec2(-2.440f, -0.540f), // v18
	glm::vec2(-2.099f, -0.540f), // v19
	glm::vec2(-2.926f, -1.618f), // v20
	glm::vec2(-2.471f, -2.096f), // v21
	glm::vec2(-2.094f, -2.083f), // v22
	glm::vec2(-2.931f, -2.786f), // v23
	glm::vec2(-2.310f, -5.202f), // v24
	glm::vec2(-4.667f, -0.637f), // v25
	glm::vec2(-4.394f, -1.848f), // v26
	glm::vec2(-4.333f, -2.890f), // v27
	glm::vec2(-4.669f, -3.975f), // v28
	glm::vec2(-6.444f, -1.396f), // v29
	glm::vec2(-6.198f, -2.297f), // v30
	glm::vec2(-6.266f, -3.557f), // v31
	glm::vec2(-7.806f, -1.169f), // v32
	glm::vec2(-7.339f, -2.251f), // v33
	glm::vec2(-7.089f, -3.187f), // v34
	glm::vec2(-9.773f, -4.944f), // v35
	glm::vec2(-3.517f, -3.691f), // v36

	glm::vec2(1.720f, -0.426f), // v37
	glm::vec2(1.623f, -2.097f), // v38
	glm::vec2(2.310f, 4.0f), // v39
	glm::vec2(2.805f,-0.211f), // v40
	glm::vec2(2.440f, -0.540f), // v41
	glm::vec2(2.099f, -0.540f), // v42
	glm::vec2(2.926f, -1.618f), // v43
	glm::vec2(2.471f, -2.096f), // v44
	glm::vec2(2.094f, -2.083f), // v45
	glm::vec2(2.931f, -2.786f), // v46
	glm::vec2(2.310f, -5.202f), // v47
	glm::vec2(4.667f, -0.637f), // v48
	glm::vec2(4.394f, -1.848f), // v49
	glm::vec2(4.333f, -2.890f), // v50
	glm::vec2(4.669f, -3.975f), // v51
	glm::vec2(6.444f, -1.396f), // v52
	glm::vec2(6.198f, -2.297f), // v53
	glm::vec2(6.266f, -3.557f), // v54
	glm::vec2(7.806f, -1.169f), // v55
	glm::vec2(7.339f, -2.251f), // v56
	glm::vec2(7.089f, -3.187f), // v57
	glm::vec2(9.773f, -4.944f), // v58
	glm::vec2(3.517f, -3.691f) // v59
};

static GLuint indices[] = {

	0, 1, 2,
	0, 2, 3,
	0, 3, 4,
	1, 5, 2,
	3, 8, 4,
	2, 5, 6,
	2, 6, 3,
	3, 6, 7,
	3, 7, 8, 
	4, 3, 8,
	5, 9, 10,
	6, 5, 10,
	7, 6, 10,
	7, 10, 11,
	8, 7, 11,
	8, 11, 12,
	9, 13, 10,
	10, 13, 11,
	11, 13, 12,

	// left engine
	1, 14, 5,
	14, 15, 5,
	5, 15, 9,
	16, 17, 18,
	16, 18, 19,
	16, 19, 14,
	17, 20, 18,
	18, 20, 21,
	18, 21, 19,
	19, 21, 22,
	19, 22, 14,
	14, 22, 15,
	23, 24, 21,
	21, 24, 22,
	22, 24, 15,
	20, 23, 21,

	// left wing
	17, 25, 26,
	17, 26, 20,
	26, 27, 20,
	20, 27, 23,
	27, 28, 23,
	23, 28, 36,
	29, 30, 25,
	25, 30, 26,
	26, 30, 27,
	30, 31, 27,
	27, 31, 28,
	32, 33, 29,
	33, 34, 29,
	29, 34, 30,
	34, 31, 30,
	32, 35, 33,
	33, 35, 34,

	// right engine
	4, 14 + 23, 5,
	14 + 23, 15 + 23, 8,
	8, 15 + 23, 12,
	16 + 23, 17 + 23, 18 + 23,
	16 + 23, 18 + 23, 19 + 23,
	16 + 23, 19 + 23, 14 + 23,
	17 + 23, 20 + 23, 18 + 23,
	18 + 23, 20 + 23, 21 + 23,
	18 + 23, 21 + 23, 19 + 23,
	19 + 23, 21 + 23, 22 + 23,
	19 + 23, 22 + 23, 14 + 23,
	14 + 23, 22 + 23, 15 + 23,
	23 + 23, 24 + 23, 21 + 23,
	21 + 23, 24 + 23, 22 + 23,
	22 + 23, 24 + 23, 15 + 23,
	20 + 23, 23 + 23, 21 + 23,

	// --- right wing
	17 + 23, 25 + 23, 26 + 23,
	17 + 23, 26 + 23, 20 + 23,
	26 + 23, 27 + 23, 20 + 23,
	20 + 23, 27 + 23, 23 + 23,
	27 + 23, 28 + 23, 23 + 23,
	23 + 23, 28 + 23, 36 + 23,
	29 + 23, 30 + 23, 25 + 23,
	25 + 23, 30 + 23, 26 + 23,
	26 + 23, 30 + 23, 27 + 23,
	30 + 23, 31 + 23, 27 + 23,
	27 + 23, 31 + 23, 28 + 23,
	32 + 23, 33 + 23, 29 + 23,
	33 + 23, 34 + 23, 29 + 23,
	29 + 23, 34 + 23, 30 + 23,
	34 + 23, 31 + 23, 30 + 23,
	32 + 23, 35 + 23, 33 + 23,
	33 + 23, 35 + 23, 34 + 23
};

void drawArwingVertexArray() {

	glShadeModel(GL_FLAT);

	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	//glColorPointer(3, GL_UNSIGNED_BYTE, 0, colours);

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);

	// Draw the object
	glDrawElements(GL_TRIANGLES, 95 * 3, GL_UNSIGNED_INT, indices);
}

#pragma endregion


void drawArwingImmediate() {

	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLES);

#pragma region main body

	glColor3ub(230, 232, 247);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-0.184f, 0.0f);

	glColor3ub(166, 167, 179);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(1.0f, 1.0f);

	glColor3ub(190, 191, 204);
	glVertex2f(0.0f, 9.0f);
	glVertex2f(-0.184f, 0.0f);
	glVertex2f(0.184f, 0.0f);


	glColor3ub(200, 201, 214);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.184f, 0.0f);

	glColor3ub(166, 167, 179);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(0.656f, -0.876f);
	

	glColor3ub(230, 232, 247);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-0.656f, -0.876f);
	
	glColor3ub(157, 158, 168);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(1.720f, -0.426f);
	

	glColor3ub(204, 206, 219);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-0.656f, -0.876f);

	glColor3ub(138, 139, 148);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(0.656f, -0.876f);


	glColor3ub(176, 177, 189);
	glVertex2f(-0.184f, 0.0f);	
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.262f, -1.394f);

	glColor3ub(121, 127, 135);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(0.656f, -0.876f);
	
	glColor3ub(164, 165, 176);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-1.169f, -3.0f);

	glColor3ub(112, 113, 120);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(1.169f, -3.0f);
	glVertex2f(1.623f, -2.097f);
	

	glColor3ub(154, 156, 166);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-1.169f, -3.0f);
	glVertex2f(-0.421f, -1.940f);
	
	glColor3ub(102, 103, 110);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(0.421f, -1.940f);
	glVertex2f(1.169f, -3.0f);
	

	glColor3ub(130, 128, 200);
	glVertex2f(-0.656f, -0.876f);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(-0.262f, -1.394f);

	glColor3ub(130, 128, 200);
	glVertex2f(0.656f, -0.876f);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(0.421f, -1.940f);
	

	glColor3ub(138, 139, 148);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(-1.169f, -3.0f);
	glVertex2f(0.0f, -5.5f);
	
	glColor3ub(91, 91, 97);
	glVertex2f(0.421f, -1.940f);
	glVertex2f(0.0f, -5.5f);
	glVertex2f(1.169f, -3.0f);


	glColor3ub(129, 130, 138);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(0.0f, -5.5f);
	glVertex2f(0.421f, -1.940f);


	glColor3ub(0, 128, 255);
	glVertex2f(-0.184f, 0.0f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(0.184f, 0.0f);

	glColor3ub(0, 128, 255);
	glVertex2f(0.184f, 0.0f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(0.262f, -1.394f);

	glColor3ub(0, 118, 245);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(-0.262f, -1.394f);
	glVertex2f(-0.421f, -1.940f);

	glColor3ub(0, 118, 245);
	glVertex2f(0.262f, -1.394f);
	glVertex2f(-0.421f, -1.940f);
	glVertex2f(0.421f, -1.940f);

#pragma endregion

#pragma region Left Engine

	glColor3ub(59, 93, 195);
	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.094, -2.083);

	glVertex2f(-1.720f, -0.426f);
	glVertex2f(-2.094, -2.083);
	glVertex2f(-1.623f, -2.097f);

	glColor3ub(76, 115, 229);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.440f, -0.540f);
	glVertex2f(-2.471f, -2.096f);

	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.094f, -2.083f);

	glColor3ub(86, 131, 252);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-2.471f, -2.096f);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.440f, -0.540f);
	
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-2.471f, -2.096f);

	glColor3ub(126, 157, 252);

	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-2.440f, -0.540f);
	
	glColor3ub(84, 127, 242);
	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.440f, -0.540f);
	glVertex2f(-2.099f, -0.540f);

	glColor3ub(65, 102, 214);
	glVertex2f(-2.310, 4.0f);
	glVertex2f(-2.099f, -0.540f);
	glVertex2f(-1.720f, -0.426f);

	glColor3ub(77, 117, 227);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-2.310, -5.202f);
	
	glColor3ub(69, 105, 209);

	glVertex2f(-2.094f, -2.083f);
	glVertex2f(-2.471f, -2.096f);
	glVertex2f(-2.310, -5.202f);

	glColor3ub(54, 85, 179);
	glVertex2f(-1.623f, -2.097f);
	glVertex2f(-2.094f, -2.083f);
	glVertex2f(-2.310, -5.202f);

#pragma endregion


#pragma region Left wing

	glColor3ub(230, 232, 247);
	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-4.394f, -1.84f);

	glVertex2f(-2.805f, -0.211f);
	glVertex2f(-4.394f, -1.84f);
	glVertex2f(-2.926f, -1.618f);

	glColor3ub(190, 191, 204);
	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-4.333f, -2.890f);

	glVertex2f(-2.926f, -1.618f);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-2.931f, -2.786f);

	glColor3ub(166, 167, 179);
	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-4.669f, -3.975f);

	glVertex2f(-2.931f, -2.786f);
	glVertex2f(-4.669f, -3.975f);
	glVertex2f(-3.517f, -3.691f);


	glColor3ub(218, 220, 235);
	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-6.198f, -2.297f);

	glVertex2f(-4.667f, -0.637f);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-4.394f, -1.848f);


	glColor3ub(180, 181, 194);
	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-6.266f, -3.557f);

	glVertex2f(-4.394f, -1.848f);
	glVertex2f(-6.266f, -3.557f);
	glVertex2f(-4.333f, -2.890f);


	glColor3ub(157, 158, 168);
	glVertex2f(-4.333f, -2.890f);
	glVertex2f(-6.266f, -3.557f);
	glVertex2f(-4.669f, -3.975f);


	glColor3ub(228, 230, 245);

	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-7.089f, -3.187f);

	glVertex2f(-6.444f, -1.396f);
	glVertex2f(-7.089f, -3.187f);
	glVertex2f(-6.198f, -2.297f);


	glColor3ub(190, 191, 204);
	glVertex2f(-6.198f, -2.297f);
	glVertex2f(-7.089f, -3.187f);
	glVertex2f(-6.266f, -3.557f);

	glColor3ub(190, 191, 204);
	glVertex2f(-7.806f, -1.169f);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-6.444f, -1.396f);

	glColor3ub(237, 201, 61);
	glVertex2f(-7.806f, -1.169f);
	glVertex2f(-9.773f, -4.944f);
	glVertex2f(-7.339f, -2.251f);

	glColor3ub(201, 171, 52);
	glVertex2f(-7.339f, -2.251f);
	glVertex2f(-9.773f, -4.944f);
	glVertex2f(-7.089f, -3.187f);

#pragma endregion




#pragma region Right Engine

	glColor3ub(59, 93, 195);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(2.094, -2.083);
	glVertex2f(2.099f, -0.540f);

	glVertex2f(1.720f, -0.426f);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(2.094, -2.083);
	

	glColor3ub(76, 115, 229);
	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.440f, -0.540f);

	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.094f, -2.083f);
	glVertex2f(2.471f, -2.096f);
	

	glColor3ub(86, 131, 252);
	glVertex2f(2.805f, -0.211f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.926f, -1.618f);
	
	glVertex2f(2.805f, -0.211f);
	glVertex2f(2.440f, -0.540f);
	glVertex2f(2.471f, -2.096f);
	
	glVertex2f(2.926f, -1.618f);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.931f, -2.786f);
	

	glColor3ub(126, 157, 252);
	glVertex2f(2.310, 4.0f);
	glVertex2f(2.440f, -0.540f);
	glVertex2f(2.805f, -0.211f);


	glColor3ub(84, 127, 242);
	glVertex2f(2.310, 4.0f);
	glVertex2f(2.099f, -0.540f);
	glVertex2f(2.440f, -0.540f);
	

	glColor3ub(65, 102, 214);
	glVertex2f(2.310, 4.0f);
	glVertex2f(1.720f, -0.426f);
	glVertex2f(2.099f, -0.540f);
	

	glColor3ub(77, 117, 227);
	glVertex2f(2.471f, -2.096f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.931f, -2.786f);
	

	glColor3ub(69, 105, 209);
	glVertex2f(2.094f, -2.083f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.471f, -2.096f);
	

	glColor3ub(54, 85, 179);
	glVertex2f(1.623f, -2.097f);
	glVertex2f(2.310, -5.202f);
	glVertex2f(2.094f, -2.083f);
	
#pragma endregion



#pragma region Right wing

	glColor3ub(230, 232, 247);
	glVertex2f(2.805f, -0.211f);
	glVertex2f(4.667f, -0.637f);
	glVertex2f(4.394f, -1.84f);

	glVertex2f(2.805f, -0.211f);
	glVertex2f(4.394f, -1.84f);
	glVertex2f(2.926f, -1.618f);

	glColor3ub(190, 191, 204);
	glVertex2f(2.926f, -1.618f);
	glVertex2f(4.394f, -1.848f);
	glVertex2f(4.333f, -2.890f);

	glVertex2f(2.926f, -1.618f);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(2.931f, -2.786f);

	glColor3ub(166, 167, 179);
	glVertex2f(2.931f, -2.786f);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(4.669f, -3.975f);

	glVertex2f(2.931f, -2.786f);
	glVertex2f(4.669f, -3.975f);
	glVertex2f(3.517f, -3.691f);


	glColor3ub(218, 220, 235);
	glVertex2f(4.667f, -0.637f);
	glVertex2f(6.444f, -1.396f);
	glVertex2f(6.198f, -2.297f);

	glVertex2f(4.667f, -0.637f);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(4.394f, -1.848f);


	glColor3ub(180, 181, 194);
	glVertex2f(4.394f, -1.848f);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(6.266f, -3.557f);

	glVertex2f(4.394f, -1.848f);
	glVertex2f(6.266f, -3.557f);
	glVertex2f(4.333f, -2.890f);


	glColor3ub(157, 158, 168);
	glVertex2f(4.333f, -2.890f);
	glVertex2f(6.266f, -3.557f);
	glVertex2f(4.669f, -3.975f);


	glColor3ub(228, 230, 245);

	glVertex2f(6.444f, -1.396f);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(7.089f, -3.187f);

	glVertex2f(6.444f, -1.396f);
	glVertex2f(7.089f, -3.187f);
	glVertex2f(6.198f, -2.297f);


	glColor3ub(190, 191, 204);
	glVertex2f(6.198f, -2.297f);
	glVertex2f(7.089f, -3.187f);
	glVertex2f(6.266f, -3.557f);

	glColor3ub(190, 191, 204);
	glVertex2f(7.806f, -1.169f);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(6.444f, -1.396f);

	glColor3ub(237, 201, 61);
	glVertex2f(7.806f, -1.169f);
	glVertex2f(9.773f, -4.944f);
	glVertex2f(7.339f, -2.251f);

	glColor3ub(201, 171, 52);
	glVertex2f(7.339f, -2.251f);
	glVertex2f(9.773f, -4.944f);
	glVertex2f(7.089f, -3.187f);

#pragma endregion

	glEnd();
}