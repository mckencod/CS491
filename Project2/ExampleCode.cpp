#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "./glm/vec2.hpp"
#include "./glm/vec3.hpp"
#include "./glm/mat4x4.hpp"
#include "./glm/gtc/matrix_transform.hpp"
#include "./glm/gtc/matrix_inverse.hpp"

//Remove these includes
#include <iostream>
#include "./glm/gtx/string_cast.hpp"

void
PrintMatrix( glm::mat4 mat )
{
	for( int row = 0; row < 4; row++ )
	{
		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
	}
}

glm::mat4
Multiply( glm::mat4 a, glm::mat4 b )
{
	return a * b;
}



glm::vec3
Multiply( glm::mat4 a, glm::vec3 b )
{
	return glm::vec3(a * glm::vec4(b, 1.f));
}



glm::vec3
ScalePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale )
{
	glm::mat4 reverse_translation = glm::translate(glm::mat4(1.f), centerPoint); //Move to origin

	glm::mat4 scale_transform = glm::scale(reverse_translation, scale);

	glm::mat4 translation = glm::translate(scale_transform, -centerPoint);

	return Multiply(translation, inputPoint);
}



glm::vec3
RotatePoint( glm::vec3 inputPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third )
{
	return Multiply(Multiply(third, Multiply(second, first)), inputPoint);
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Jonathan Jones";
	yourEmailAddress = "jonesjon@oregonstate.edu" ;
}


// void
// PrintMatrix( glm::mat4 mat )
// {
// 	for( int row = 0; row < 4; row++ )
// 	{
// 		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
// 	}
// }

int main()
{
	//Initalize test variables
	glm::vec3 p1(3, 0, 0);
	glm::vec3 p2(4, 0, 0);
	glm::vec3 s1(2, 0, 0);

	glm::mat4 r1 = glm::rotate(glm::mat4(1.f), glm::radians(90.f), glm::vec3(0, 0, 1));
	glm::mat4 r2 = glm::rotate(glm::mat4(1.f), glm::radians(0.f), glm::vec3(0, 0, 1));

	//Display test variables
	std::cout << "Point 1: " << glm::to_string(p1) << std::endl;
	std::cout << "Point 2: " << glm::to_string(p2) << std::endl;
	std::cout << "Scale 1: " << glm::to_string(s1) << std::endl;

	std::cout << "Scale around point: " << glm::to_string(ScalePointAroundAnotherPoint(p1, p2, s1)) << std::endl;
	std::cout << "Rotate point: " << glm::to_string(RotatePoint(p2, r1, r2, r1)) << std::endl;
    return 0;
}
