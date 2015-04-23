#include "Transformable.h"


Transformable::Transformable(int ID) : Component(ID)
{
	position[0] = 0;
	position[1] = 0;
	position[2] = 0;

	rotation[0] = 0;
	rotation[1] = 0;
	rotation[2] = 0;
}


Transformable::~Transformable()
{
}
