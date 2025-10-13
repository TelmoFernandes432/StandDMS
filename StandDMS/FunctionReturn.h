#ifndef ERROHANDLING_H
#define ERROHANDLING_H
#include <utility>
#include <algorithm>
#include <tuple>
#include "Vehicle.h"
#include "Sedan.h"
#include "Coupe.h"
#include "MotorCycle.h"


void cleanCinBuffer();

namespace StandFunctionReturnValue {

	enum class valueReturn {
		standInsertedSucceed,
		standNotFound,
	};
}

namespace UserInputObjectParameterHandler {      //Coupe(unsigned int licensePlateYear, const std::string& brand, fuelType fuel)      
    inline unsigned int LincenseYaerPlate() {

        unsigned int userLicensePlate{};

        while (true) {
            std::cout << "Insert vehicle license plate year (xxxx): ";
            std::cin >> userLicensePlate;

            if (std::cin.fail()) { 
                cleanCinBuffer();
                std::cout << "Invalid input. Please enter a valid year.\n";
            }
            else if (userLicensePlate < 1000 || userLicensePlate > 9999) {
                std::cout << "Year must be 4 digits. Try again.\n";
            }
            else {
                break; 
            }
        }
        cleanCinBuffer();
        return userLicensePlate;
    }

    inline std::string brand() {
        std::string userbrand;

        while (true) {
            std::cout << "Insert vehicle brand: ";
            std::getline(std::cin, userbrand);

            bool hasDigits = std::any_of(userbrand.begin(), userbrand.end(), [](unsigned char c) { return std::isdigit(c); });

            if (hasDigits || userbrand.empty()) {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
            }
            else {
                break;
            }
        }
        cleanCinBuffer();
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
                cleanCinBuffer();
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
                cleanCinBuffer();
                std::cout << "Invalid input" << std::endl;
            }
            if (option == 'Y') {
                return Fairing::hasFairing;
            }
            else
                return Fairing::hasntFairing;
        }
    }

    inline std::tuple<std::string, std::string, int> userStandCreator() {
        
        std::string standCity{};

        while (true) {
            std::cout << "Please enter the name of the city where you want to create the stand: ";
            std::getline(std::cin, standCity);

            bool hasDigits = std::any_of(standCity.begin(), standCity.end(), [](unsigned char c) { return std::isdigit(c); });

            if (hasDigits || standCity.empty()) {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
            }
            else {
                break;
            }
        }

        unsigned int standNumber{};

        while (true) {
            std::cout << "Please enter a Stand number (Number between 1 and 99): ";
            std::cin >> standNumber;

            if (std::cin.fail()) {         
                cleanCinBuffer();
                std::cout << "Invalid input. Please enter a number between 1 and 99.\n";
            }
            else {
                break; 
            }
        }
        
        cleanCinBuffer();
        std::string standAdress;

        std::cout << "Please insert stand adress: ";
        std::getline(std::cin, standAdress);

        return std::make_tuple(standCity, standAdress, standNumber);
    }




}

#endif