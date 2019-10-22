#include <iostream>
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

glm::vec3
WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
	return normalize(b)*(dot(a,normalize(b)));
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
	return a-normalize(b)*(dot(a,normalize(b)));
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	 return normalize(cross((r-q),(s-q)));
}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	 //return (1/2)*length(cross((r-q),(s-q)));
	return (.5)*length(cross((r-q),(s-q)));
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	glm::vec3 n = cross((r-q),(s-q));
	glm::vec3 nq = cross((r-q),(p-q));
	glm::vec3 nr = cross((s-r),(p-r));
	glm::vec3 ns = cross((q-s),(p-s));

	if(dot(n,nq) >= 0 && dot(n,nr) >= 0 && dot(n,ns) >= 0){
		return true;
	}
	else{
		return false;
	}
}


float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	return dot((p-q),normalize(cross((r-q),(s-q))));
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Cody McKenzie";
	yourEmailAddress = "mckencod@oregonstate.edu" ;
}

int main(){
	std::cout << "VECTORS!!\n\n";
	
	glm::vec3 a = glm::vec3(1,1,1);
	glm::vec3 b = glm::vec3(2,3,4);
	glm::vec3 c = glm::vec3(7,8,9);
	glm::vec3 d = glm::vec3(8,4,10);
	float g = -1;

	glm::vec3 n = WhatPartOfALivesInBDir(a,b);
	std::cout << n.x << " " << n.y << " " << n.z << std::endl;

	glm::vec3 o = WhatPartOfALivesPerpToB(a,b);
	std::cout << o.x << " " << o.y << " " << o.z << std::endl;

	glm::vec3 f = UnitSurfaceNormal(a,b,c);
	std::cout << f.x << " " << f.y << " " << f.z << std::endl;

	g = Area(a,b,c);
	std::cout << g << std::endl;

	bool m = IsPointInTriangle(a,b,c,d);
	std::string booly = m ? "True" : "False";
	std::cout << booly << std::endl;

	float e = DistanceFromPointToPlane(a,b,c,d);
	std::cout << e << std::endl;	

	return 0;
}