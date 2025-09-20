#include "Vehicle.h"
#include <sstream>

std::string Vehicle::toString() {
    std::ostringstream oss;

    oss << "Vehicle ID: " << m_vehicleID
        << "\nLicense Plate Year: " << m_licensePlateYear
        << "\nBrand: " << m_brand << "\n";

    return oss.str();
}