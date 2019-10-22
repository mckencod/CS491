#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

#include <iostream>
#include "./glm/gtx/string_cast.hpp"

glm::mat4
Multiply( glm::mat4 a, glm::mat4 b )
{
	return a*b;			//Multiplies two matrices.
}



glm::vec3
Multiply( glm::mat4 a, glm::vec3 b )
{
	glm::vec4 c = glm::vec4(b,1.);		// Turns b into a vec4 and inserted into variable c.
	c = a*c;							// Sets c to be mat4 a multipled byt vec4 c.
	b = glm::vec3(c);					// Turns c into a vec3 and assigns the result to b.
	return b;							// Returns b for us.
}



glm::vec3
ScalePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale )
{
	glm::mat4 reverse_translation = glm::translate(glm::mat4(1.f), centerPoint);	// Starting point.
	glm::mat4 scale_transform = glm::scale(reverse_translation, scale);				// Adjusts the scale.
	glm::mat4 translation = glm::translate(scale_transform, -centerPoint);			// Move to origin.

	return Multiply(translation, inputPoint);										// Resultant of many multiplications.
}



glm::vec3
RotatePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third )
{
	glm::mat4 reverse_translation = glm::translate(glm::mat4(1.f), centerPoint);					// Starting point.
	glm::mat4 rotation = Multiply(Multiply(Multiply(reverse_translation, third), second), first);	// Rotates the matrix.
	glm::mat4 translation = glm::translate(rotation, -centerPoint);									// Move to origin.

	return Multiply(translation, inputPoint);
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Cody McKenzie";
	yourEmailAddress = "mckencod@oregonstate.edu" ;
}


void
PrintMatrix( glm::mat4 mat )
{
	for( int row = 0; row < 4; row++ )
	{
		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
	}
}

int main(int argc, char const *argv[])
{
	glm::vec3 p1(3, 5, 4);
	glm::vec3 p2(2, 3, 4);
	glm::vec3 s1(9, 6, 2);

	glm::vec3 inputScale = glm::vec3(3, 3, -3);
    glm::vec3 centerScale = glm::vec3(2, 4, 2);
    glm::vec3 scaleVal = glm::vec3(2, 2, 2);

    glm::vec3 inputRot = glm::vec3(1.0f, 1.0f, 0.0f);
    glm::vec3 centerRot = glm::vec3(-2.0f, 0.0f, 0.0f);
    //glm::vec3 centerRot = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 firstRot = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 secondRot = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 thirdRot = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 r1 = glm::rotate(glm::mat4(1.f), glm::radians(90.f), glm::vec3(0, 0, 1));
	glm::mat4 r2 = glm::rotate(glm::mat4(1.f), glm::radians(0.f), glm::vec3(0, 0, 1));

	glm::mat4 r3 = glm::mat4(glm::vec4(2, 2, 2, 2), glm::vec4(2, 2, 2, 2), glm::vec4(2, 2, 2, 2), glm::vec4(2, 2, 2, 2));
	glm::mat4 r4 = glm::mat4(glm::vec4(3, 3, 3, 3), glm::vec4(3, 3, 3, 3), glm::vec4(3, 3, 3, 3), glm::vec4(3, 3, 3, 3));
	glm::mat4 r5 = glm::mat4(glm::vec4(4, 4, 4, 4), glm::vec4(4, 4, 4, 4), glm::vec4(4, 4, 4, 4), glm::vec4(4, 4, 4, 4));


	//Display test variables
	std::cout << "Point 1: " << glm::to_string(p1) << std::endl;
	std::cout << "Point 2: " << glm::to_string(p2) << std::endl;
	std::cout << "Scale 1: " << glm::to_string(s1) << std::endl;

	std::cout << "Scale around point: " << glm::to_string(ScalePointAroundAnotherPoint(p1, p2, s1)) << std::endl;
	std::cout << "Rotate point: " << glm::to_string(RotatePointAroundAnotherPoint(inputRot, centerRot, firstRot, secondRot, thirdRot)) << std::endl;
    return 0;
}