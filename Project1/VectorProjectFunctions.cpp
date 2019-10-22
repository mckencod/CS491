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