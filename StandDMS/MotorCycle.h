#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"
#include <string>


enum class Fairing {
	hasntFair = false,
	hasFair = true,
};

class Motorcycle : public Vehicle {
private:
	Fairing m_hasFairing{};

public:
	Motorcycle() = default;

	Motorcycle(unsigned int licensePlateYear, const std::string& brand, fuelType fuel, Fairing hasFairing)
		: Vehicle(licensePlateYear, brand, fuel), 
		m_hasFairing{ hasFairing }
	{}

	void setFair(Fairing hasFairing) { m_hasFairing = hasFairing; };
	Fairing getFair() const { return m_hasFairing; };

	std::string toString() const override;
};

#endif

