#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"


class Car : public Vehicle {

private:
	int m_numPorts{};

public:

	Car(unsigned int licensePlateYear, const std::string& brand) : Vehicle(licensePlateYear, brand){}

	Car(int numPorts, unsigned int licensePlateYear, const std::string& brand) : 
		Vehicle(licensePlateYear, brand), 
		m_numPorts{ numPorts } 
	{}

	void setNumPorts(int numPorts) { m_numPorts = numPorts; };
	int getNumPorts() const { return m_numPorts; };

	virtual std::string toString() const override;
};


#endif
