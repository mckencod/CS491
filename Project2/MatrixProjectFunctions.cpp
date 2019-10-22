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