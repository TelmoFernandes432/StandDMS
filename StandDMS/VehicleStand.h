#ifndef VEHICLESTAND_H
#define VEHICLESTAND_H
#include "Stand.h"
#include "Vehicle.h"
#include <vector>
#include <optional>
#include "FunctionReturn.h"


class StandVehicleAggregate {

private:
	Stand m_stand;
	std::vector<std::unique_ptr<Vehicle>> m_vehiclesConteiner{}; /* Polymorphism pointer needed here! */

public:

	StandVehicleAggregate() = default;

	void setStand(const Stand& stand) { m_stand = stand; };
	void setVehicle(std::unique_ptr<Vehicle> vehicle) { m_vehiclesConteiner.push_back(std::move(vehicle)); };
	Stand getStand() const { return m_stand; };

	const std::vector<std::unique_ptr<Vehicle>>& getVehiclesConteiner() const {
		return m_vehiclesConteiner;
	}

};


class VehicleStandGroup {

protected:
	std::vector<std::unique_ptr<StandVehicleAggregate>> m_standVehicleInventory;

public:

	VehicleStandGroup() {
		m_standVehicleInventory.reserve(3); /*At least reserve 3*/
	}

	const std::vector<std::unique_ptr<StandVehicleAggregate>>& getStandVehicleInventory() const {
		return m_standVehicleInventory;
	}

	void InsertNewStand(const Stand& stand);

	StandFunctionReturnValue::valueReturn insertNewVehicleStand(std::unique_ptr<Vehicle> vehicle, Stand& stand);

	const std::string toString();

};

#endif


