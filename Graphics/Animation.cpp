#include "Animation.h"

Animation::Animation()
{ 
	this->m_model_mat = glm::mat4(1.0);
}

Animation::~Animation()
{
}

void Animation::Xrotate_local(double a)
{
	double p = glm::pi<double>();
	glm::mat4 rotateX = glm::mat4(1.0, 0.0, 0.0, 0.0,
								0.0, cos(a*p/180.0), -sin(a*p / 180.0), 0.0,
								0.0, sin(a*p / 180.0), cos(a*p / 180.0), 0.0,
								0.0, 0.0, 0.0, 1.0);
	this->m_model_mat = this->m_model_mat*rotateX;
}

void Animation::Yrotate_world(double b)
{
	double p = glm::pi<double>();
	glm::mat4 rotateY = glm::mat4(cos(b*p / 180.0), 0.0, sin(b*p / 180.0), 0.0,
		0.0, 1.0, 0.0, 0.0,
		-sin(b*p / 180.0), 0.0, cos(b*p / 180.0), 0.0,
		0.0, 0.0, 0.0, 1.0);

	//trans_rotate = glm::translate(rotateY);
	this->m_model_mat = rotateY*this->m_model_mat;
}
void Animation::init()
{
	reset();
}
void Animation::update(float delta_time)
{
}

void Animation::reset()
{
	m_model_mat = glm::translate(glm::mat4(1.0), glm::vec3(5.0, 0.0, 0.0));
}
