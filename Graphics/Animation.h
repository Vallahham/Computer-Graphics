#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

class Animation
{
public:

	Animation();
	~Animation();

	double a = 0.0;
	double b = 0.0;
	
	void Xrotate_local(double a);
	void Yrotate_world(double b);
	void init();
	void update(float delta_time);
	void reset();
	glm::mat4 get_model_mat() { return m_model_mat; };

private:
	glm::mat4 m_model_mat;
};

