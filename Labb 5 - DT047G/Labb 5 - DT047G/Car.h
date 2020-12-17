#pragma once
#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>
#include <iostream>
class Car {
public:
	Car(std::string name, int speed) : name(name), speed(speed) {}
	bool operator==(const Car& c1) const;

	std::string getName() const;
	int getSpeed() const;

private:
	std::string name;
	int speed;
};


#endif