#pragma once
#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>
class Car {
public:
	Car(std::string name, int speed) : name(name), speed(speed) {}
	friend bool operator==(const Car& c1, const Car& c2)
	{
		return c1.name == c2.name;
	}

private:
	std::string name;
	int speed;
};


#endif