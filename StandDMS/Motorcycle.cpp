#include "Vehicle.h"
#include "Motorcycle.h"


std::string Motorcycle::toString() const {
	std::ostringstream oss;

	oss << "\"" << m_vehicleID << ' ' << m_licensePlateYear << ' ' << m_brand << " FuelType:"<< convertString(m_fuelType) << " Fairing:" << (static_cast<bool>(m_hasFairing) ? "Yes" : "No") << " MotorCycle\" \n";

	return oss.str();

}
