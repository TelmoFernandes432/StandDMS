#ifndef SEDAN_H
#define SEDAN_H
#include "Car.h"
#include "Vehicle.h"

class Sedan : public Car {

private:
	/*This is an equal value for every object, so lets turn it in class instance and not an object instance making it static constexpr */
	static constexpr int NUMBER_OF_PORTS = 4;

public:
	Sedan();

	Sedan(unsigned int licensePlateYear, const std::string& brand) :
		Car(licensePlateYear, brand)
	{}

	std::string toString() const override;

	~Sedan() {};
};


#endif