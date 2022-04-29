#include "Object.h"

unsigned int Object::count = 0;

unsigned int Object::Count()
{
	return count;
}

Object::Object()
{
	count++;
}

Object::~Object()
{
	count--;
}