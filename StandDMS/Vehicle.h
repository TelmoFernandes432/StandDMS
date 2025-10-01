#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <expected>
#include <iostream>
#include <sstream>


enum class fuelType {
    DIESEL,
    ELETRIC,
    GASOLINE,
    LPG,
    HYBRID,
    UNKNOWN,
    MAX_FUEL_TYPE
};


class Vehicle {

protected:
    static int s_nextID;
    int m_vehicleID{};
    unsigned int m_licensePlateYear{};
    std::string m_brand{};
    fuelType m_fuelType{};
    
public:


    Vehicle() {};

    Vehicle(unsigned int licensePlateYear)
        : Vehicle(licensePlateYear, "Unknown", fuelType::UNKNOWN)
    {}

  
    Vehicle(unsigned int licensePlateYear, const std::string& brand, fuelType fuel)
        : m_vehicleID{ ++s_nextID },
        m_licensePlateYear{ licensePlateYear },
        m_brand{ brand },
        m_fuelType{ fuel }
    {
    }


    void setLicensePlateYear(unsigned int licensePlateYear) { m_licensePlateYear = licensePlateYear; };
    void setBrand(std::string& brand) { m_brand = brand; };
    
    unsigned int getLicensePlateYear() const { return m_licensePlateYear; };
    std::string getBrand() const { return m_brand; };
    unsigned int getVehicleID() const { return m_vehicleID; };
    virtual std::string toString() const;

    friend std::string convertString(fuelType type);

    virtual ~Vehicle() = default;

    /*Overload operator <<*/
   /* friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle){
        out << "Vehicle ID: " << vehicle.m_vehicleID
            << "\nLicense Plate Year: " << vehicle.m_licensePlateYear
            << "\nBrand: " << vehicle.m_brand << "\n";
        return out;
    }*/

};


inline std::string convertString(fuelType type) {
    switch (type) {
    case fuelType::DIESEL:   return "Diesel";
    case fuelType::ELETRIC:  return "Electric";
    case fuelType::GASOLINE: return "Gasoline";
    case fuelType::LPG:      return "LPG";
    case fuelType::HYBRID:   return "Hybrid";
    case fuelType::UNKNOWN:   return "Unknown";
    case fuelType::MAX_FUEL_TYPE: return "Invalid (MAX_FUEL_TYPE)";
    default: return "Invalid fuel type";
    }
}

#endif

