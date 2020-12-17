#include "Car.h"
#include <algorithm>
#include <random>

struct MyPrint {
	void operator()(const Car& c)
	{
		std::cout << "Name: " << c.getName() << " " << "Speed: " << c.getSpeed() << '\n';
	}
};

struct greater {
	greater(const int val) : val(val) {}
	bool operator()(const Car& c)
	{
		return c.getSpeed() > val;
	}
	const int val;
};

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<unsigned> speed(20, 140);

	setlocale(LC_ALL, "");
	Car arr[] = { 
		Car("Mustang", speed(gen)),
		Car("Mustang", speed(gen)),
		Car("Volvo", speed(gen)), 
		Car("Citroën", speed(gen)),
		Car("Volvo", speed(gen)),
		Car("Toyota", speed(gen)),
		Car("Volkswagen", speed(gen))
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	

	std::vector<Car> vec(arr, arr+n);
	
	MyPrint print;

	// Uppgift 1
	/*std::for_each(vec.begin(), vec.end(), print);

	std::cout << '\n';

	int val = 50;

	// Uppgift 2
	std::cout << "Greater than: "<< val << '\n';
	auto found = std::find_if(vec.begin(), vec.end(), greater(val));
	Car tmp(found->getName(), found->getSpeed());
	print(tmp);*/
	
	// Uppgift 3
	/*auto foundd = std::adjacent_find(vec.begin(), vec.end());
	if (foundd != vec.end())
		print(*foundd);

	else
		std::cout << "No adjacent vehicles with the same name found." << std::endl;


	// Uppgift 4
	if (std::equal(vec.begin(), vec.end(), &arr[0]))
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;
		*/
	// Uppgift 5

	auto sub = std::search(vec.begin(), vec.end(), &arr[2], &arr[5]);
	std::for_each(sub, vec.begin() + 5, print);

	return 0;
}