#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <expected>
#include <iostream>
#include <sstream>

class Vehicle {

protected:
    static int s_nextID;
    int m_vehicleID;
    unsigned int m_licensePlateYear{};
    std::string m_brand{};

public:

    Vehicle();

    Vehicle(unsigned int licensePlateYear)
        : Vehicle(licensePlateYear, "Unknown")
    {}

    Vehicle(unsigned int licensePlateYear, const std::string& brand)
        : m_vehicleID{ ++s_nextID }, 
        m_licensePlateYear{ licensePlateYear }, 
        m_brand{ brand }
    {}

    void setLicensePlateYear(unsigned int licensePlateYear) { m_licensePlateYear = licensePlateYear; };
    void setBrand(std::string& brand) { m_brand = brand; };
    
    unsigned int getLicensePlateYear() const { return m_licensePlateYear; };
    std::string getBrand() const { return m_brand; };
    unsigned int getVehicleID() const { return m_vehicleID; };
    virtual std::string toString() const;


    virtual ~Vehicle() = default;

    /*Overload operator <<*/
   /* friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle){
        out << "Vehicle ID: " << vehicle.m_vehicleID
            << "\nLicense Plate Year: " << vehicle.m_licensePlateYear
            << "\nBrand: " << vehicle.m_brand << "\n";
        return out;
    }*/


};

#endif

