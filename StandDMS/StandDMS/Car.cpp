#include "Car.h"

std::string Car::toString() const {
   
    std::ostringstream oss;

    oss << "\"" << m_vehicleID << ' ' << m_licensePlateYear << ' ' << m_brand;
    
    return oss.str();
} 