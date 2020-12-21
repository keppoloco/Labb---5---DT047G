#include "Car.h"
bool Car::operator==(const Car& c1) const
{
	return this->name == c1.name;
}

std::string Car::getName() const
{
	return name;
}

double Car::getSpeed() const
{
	return speed;
}
