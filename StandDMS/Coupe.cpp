#include "Coupe.h"
#include "Car.h"
#include <string>

std::string Coupe::toString() const {

	return Car::toString() + " Coupe\" ";

}