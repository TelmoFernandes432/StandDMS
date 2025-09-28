#ifndef COUPE_H
#define COUPE_H
#include <string>
#include "Car.h"


class Coupe : public Car {

private:
	/*This is an equal value for every object, so lets turn it in class instance and not an object instance static constexpr */
	static constexpr int NUMBER_OF_PORTS = 2;

public:

	Coupe() = default;

	Coupe(unsigned int licensePlateYear, const std::string& brand) :
		Car(licensePlateYear, brand)
	{}

	Coupe(unsigned int licensePlateYear, const std::string& brand, fuelType fuel)
		: Car(NUMBER_OF_PORTS, licensePlateYear, brand, fuel)
	{}


	std::string toString() const override;

	~Coupe() {};

};

#endif