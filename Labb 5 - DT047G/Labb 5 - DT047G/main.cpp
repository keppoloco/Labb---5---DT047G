#include "Car.h"
#include <algorithm>
#include <random>
#include <numeric>

struct MyPrint {
	void operator()(const Car& c)
	{
		std::cout << "Name: " << c.getName() << " " << "Speed: " << c.getSpeed() << '\n';
	}
};

struct greater {
	greater(const double val) : val(val) {}
	bool operator()(const Car& c)
	{
		return c.getSpeed() > val;
	}
	const double val;
};

struct MyBinOp {
	unsigned int n;
	MyBinOp(unsigned int val) :n(val) {}
	
	double operator()(double sum, const Car &c2)
	{
		return sum + (c2.getSpeed() / n);
	}
};

struct MyUnOp {
	double operator()(const Car &c){
		return c.getSpeed();
	}
};

struct MyFunc {
	MyFunc(double m) : m(m) {}
	double m;
	double operator()(double d)
	{
		return d - m;
	}
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
	std::for_each(vec.begin(), vec.end(), print);

	std::cout << '\n';
	/*


	// Uppgift 2
	double val = 50;
	std::cout << "Greater than: "<< val << '\n';

	auto found = std::find_if(vec.begin(), vec.end(), greater(val));
	Car tmp(found->getName(), found->getSpeed());

	print(tmp);
	
	// Uppgift 3
	auto foundd = std::adjacent_find(vec.begin(), vec.end());
	if (foundd != vec.end())
		print(*foundd);

	else
		std::cout << "No adjacent vehicles with the same name found." << std::endl;


	// Uppgift 4
	if (std::equal(vec.begin(), vec.end(), &arr[0]))
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;
	
	// Uppgift 5

	auto sub = std::search(vec.begin(), vec.end(), &arr[2], &arr[5]);
	std::for_each(sub, vec.begin() + 5, print);
	*/

	// Uppgift 6
	MyBinOp mean(vec.size());

	auto meanValue = std::accumulate(vec.begin(), vec.end(), 0.0, mean);

	std::cout << "Mean value: " << meanValue << '\n';


	// Uppgift 7
	std::vector<double> v2;
	v2.resize(vec.size());

	std::transform(vec.begin(), vec.end(), v2.begin(), MyUnOp());

	/*for (auto it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << ' ';*/

	// Uppgift 8
	std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(meanValue));

	std::cout << "new values: " << std::endl;
	for (auto it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << ' ';


	std::cout << std::endl;
	std::cout << std::endl;

	// Uppgift 9
	std::sort(v2.begin(), v2.end());

	std::cout << "Ascending order: " << '\n';
	for (auto it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << ' ';

	return 0;
}