#ifndef FACTORY_H
#define FACTORY_H
#include "Vehicle.h"
#include "Sedan.h"
#include "Coupe.h"
#include "MotorCycle.h"


class VehicleFactory {
private:
public:
	virtual ~VehicleFactory() {};
	virtual std::unique_ptr<Vehicle> FactoryMethod() const = 0;

    std::unique_ptr<Vehicle> CreateObject(){
        auto VehicleObject = this->FactoryMethod();
        std::cout << "Obeject that we are currently working on: " << VehicleObject->objectType() << std::endl;
    }
};


class SedanFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {
        return std::make_unique<Sedan>();
    }
};

class CoupeFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {
        return std::make_unique<Coupe>();
    }
};

class SedanFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override {
        return std::make_unique<Motorcycle>();
    }
};

#endif