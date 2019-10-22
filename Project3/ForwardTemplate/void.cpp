void
Forward( float th1, float th2, float th3,  float l1, float l2,
	 glm::mat4& m1g, glm::mat4& m2g, glm::mat4& m3g )
{
	glm::mat4 t1 = glm::translate(glm::mat4(1.), glm::vec3(l1, 0, 0));
	glm::mat4 t2 = glm::translate(glm::mat4(1.), glm::vec3(l2, 0, 0));
	glm::mat4 r1 = glm::rotate(glm::mat4(1.), th1, glm::vec3(0, 0, 1));
	glm::mat4 r2 = glm::rotate(glm::mat4(1.), th2, glm::vec3(0, 0, 1));
	glm::mat4 r3 = glm::rotate(glm::mat4(1.), th3, glm::vec3(0, 0, 1));

	glm::mat4 m21 = t1 * r2;
	glm::mat4 m32 = t2 * r3;

	m1g = r1;
	m2g = m1g * m21;
	m3g = m2g * m32;
}

void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
        yourName = "Cody McKenzie";
        yourEmailAddress = "mckencod@oregonstate.edu" ;
}