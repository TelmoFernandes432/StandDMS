#ifndef FACTORY_H
#define FACTORY_H
#include <algorithm>
#include "Vehicle.h"
#include "Sedan.h"
#include "Coupe.h"
#include "MotorCycle.h"


class VehicleFactory {
private:

public:

    virtual ~VehicleFactory() {};
    virtual std::unique_ptr<Vehicle> FactoryMethod() const = 0;

    std::unique_ptr<Vehicle> createVehicle();

};

class SedanFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override;
};

class CoupeFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override;
};

class MotorcycleFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> FactoryMethod() const override;
};

#endif