#include "Sedan.h"
#include "Car.h"
#include <string>

std::string Sedan::toString() const {

	return Car::toString() + " Sedan\" ";

}