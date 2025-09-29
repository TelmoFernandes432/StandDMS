#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"


class Car : public Vehicle {

private:
	int m_numPorts{};

public:

	Car(unsigned int licensePlateYear, const std::string& brand) : Vehicle(licensePlateYear, brand, fuelType::UKNOWN){}

	Car(int numPorts, unsigned int licensePlateYear, const std::string& brand, fuelType fuel) : 
		Vehicle(licensePlateYear, brand, fuel), 
		m_numPorts{ numPorts }
	{}

	void setNumPorts(int numPorts) { m_numPorts = numPorts; };
	int getNumPorts() const { return m_numPorts; };

	virtual std::string toString() const override;

	std::string objectType() const {
		return "Car!";
	}
};


#endif
