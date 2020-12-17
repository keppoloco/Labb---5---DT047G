#include "Car.h"
#include <iostream>
int main()
{
	Car arr[] = { Car("Mustang", 100), Car("Porsche", 140), Car("Volvo", 90), Car("Citroën", 45)};
	int n = sizeof(arr) / sizeof(arr[0]);

	std::vector<Car[]> vec(arr, arr+n);


	return 0;
}