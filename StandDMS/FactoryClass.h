#ifndef FACTORY_H
#define FACTORY_H
#include <algorithm>
#include "Vehicle.h"
#include "Sedan.h"
#include "Coupe.h"
#include "MotorCycle.h"


namespace UserInputHandler {      //Coupe(unsigned int licensePlateYear, const std::string& brand, fuelType fuel)      
    inline unsigned int LincenseYaerPlate() {

        unsigned int userLicensePlate{};

        while (1) {
            std::cout << "Insert vehicle license plate year (xxxx): " << std::endl;
            std::cin >> userLicensePlate;
            while (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input" << std::endl;
            }
            break;
        }
        return userLicensePlate;
    }

    inline std::string brand() {
        std::string userbrand;

        while (true) {
            std::cout << "Insert vehicle brand: ";
            std::getline(std::cin, userbrand);

            // Verifica se contém números
            bool hasDigits = std::any_of(userbrand.begin(), userbrand.end(),
                [](unsigned char c) { return std::isdigit(c); });

            if (hasDigits || userbrand.empty()) {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
            }
            else {
                break; 
            }
        }

        return userbrand;
    }
    

    inline fuelType Ftype() {

        unsigned int option{};

        std::cout << "Choose vehicle fuel type:" << std::endl;

        auto fuelTypeToString = [](fuelType f) -> std::string {
            switch (f) {
            case fuelType::DIESEL:    return "Diesel";
            case fuelType::ELETRIC:   return "Electric";
            case fuelType::GASOLINE:  return "Gasoline";
            case fuelType::LPG:       return "LPG";
            case fuelType::HYBRID:    return "Hybrid";
            case fuelType::UNKNOWN:   return "Unknown";
            default:                  return "Invalid fuel type";
            }
        };

        for (std::size_t i = 0; i < static_cast<size_t>(fuelType::MAX_FUEL_TYPE); ++i) {
            fuelType f = static_cast<fuelType>(i);
            std::cout << i << ": " << fuelTypeToString(f) << std::endl;
        }

        while (1) {
            while (!(std::cin >> option) || (option >= static_cast<unsigned int>(fuelType::MAX_FUEL_TYPE))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input" << std::endl;
            }
            break;
        }

        return fuelType(option);
    }

    inline Fairing MotorCycleFairing() {

        unsigned char option{};

        while (1) {
            std::cout << "MotorCycle has Fairing? (y)yes or (n)no: \n" << std::endl;
            std::cin >> option;
            while (!(std::cin) || (static_cast<char>(std::toupper(option)) != 'Y' && static_cast<char>(std::toupper(option)) != 'N')) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input" << std::endl;
            }
            if (option == 'Y') {
                return Fairing::hasFairing;
            }
            else
                return Fairing::hasntFairing;
        }
    }
}



class VehicleFactory {
private:

public:

    virtual ~VehicleFactory() {};
    virtual std::unique_ptr<Vehicle> FactoryMethod() const = 0;

    std::unique_ptr<Vehicle> createVehicle() {
        std::unique_ptr<Vehicle> vehicleCreated = this->FactoryMethod(); /* Here doing this-> we are making sure that we apply polimorphism */
        return vehicleCreated;
    }

};


class SedanFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {

        unsigned int license = UserInputHandler::LincenseYaerPlate();
        std::string brand = UserInputHandler::brand();
        fuelType fType = UserInputHandler::Ftype();

        return std::make_unique<Sedan>(license, brand, fType);
    }
};

class CoupeFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {
        return std::make_unique<Coupe>(UserInputHandler::LincenseYaerPlate(), UserInputHandler::brand(), UserInputHandler::Ftype());
    }
};

class MotorcycleFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {
        return std::make_unique<Motorcycle>(UserInputHandler::LincenseYaerPlate(), UserInputHandler::brand(), UserInputHandler::Ftype(), UserInputHandler::MotorCycleFairing());
    }
};

#endif