#include "FactoryClass.h"
#include "FunctionReturn.h"

std::unique_ptr<Vehicle> VehicleFactory::createVehicle() {
    std::unique_ptr<Vehicle> vehicleCreated = this->FactoryMethod(); /* Here doing this-> we are making sure that we apply polimorphism */
    return vehicleCreated;
}


std::unique_ptr<Vehicle> CoupeFactory::FactoryMethod() const {

    unsigned int license = UserInputObjectParameterHandler::LincenseYaerPlate();
    std::string brand = UserInputObjectParameterHandler::brand();
    fuelType fType = UserInputObjectParameterHandler::Ftype();

    return std::make_unique<Sedan>(license, brand, fType);
}


std::unique_ptr<Vehicle> SedanFactory::FactoryMethod() const {

    unsigned int license = UserInputObjectParameterHandler::LincenseYaerPlate();
    std::string brand = UserInputObjectParameterHandler::brand();
    fuelType fType = UserInputObjectParameterHandler::Ftype();

    return std::make_unique<Sedan>(license, brand, fType);
}



std::unique_ptr<Vehicle>  MotorcycleFactory::FactoryMethod() const {

    unsigned int license = UserInputObjectParameterHandler::LincenseYaerPlate();
    std::string brand = UserInputObjectParameterHandler::brand();
    fuelType fType = UserInputObjectParameterHandler::Ftype();
    Fairing fairing = UserInputObjectParameterHandler::MotorCycleFairing();

    return std::make_unique<Motorcycle>(license, brand, fType, fairing);
}