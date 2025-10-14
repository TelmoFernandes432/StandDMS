#ifndef VEHICLESTAND_H
#define VEHICLESTAND_H
#include "Stand.h"
#include "Vehicle.h"
#include <vector>
#include <optional>
#include "FunctionReturn.h"

class StandVehicleAggregate;

class VehicleStandGroup {

protected:
	std::vector<std::unique_ptr<StandVehicleAggregate>> m_standVehicleInventory;

public:


	VehicleStandGroup() {
		m_standVehicleInventory.reserve(3); /*At least reserve 3 in first instance*/
	}

	const std::vector<std::unique_ptr<StandVehicleAggregate>>& getStandVehicleInventory() const {
		return m_standVehicleInventory;
	}

	std::size_t InsertNewStand(const Stand& stand);

	StandFunctionReturnValue::valueReturn insertNewVehicleStand(std::unique_ptr<Vehicle> vehicle, Stand& stand);

	const std::string toString();

	virtual ~VehicleStandGroup() = default;

};


class StandVehicleAggregate : public VehicleStandGroup { /*onde o objeto StandVehicleAggregate  para aceder ao m_vehicles ? para passar para a função */

private:
	Stand m_stand;
	std::vector<std::unique_ptr<Vehicle>> m_vehiclesConteiner{}; /* Polymorphism pointer needed here! */

public:

	StandVehicleAggregate() = default;

	void setStand(const Stand& stand) { m_stand = stand; };
	void setVehicle(std::unique_ptr<Vehicle> vehicle) { m_vehiclesConteiner.push_back(std::move(vehicle)); };
	Stand getStand()  { return m_stand; };

	std::vector<std::unique_ptr<Vehicle>>& getVehiclesConteiner()  { /*don't const this!*/
		return m_vehiclesConteiner;
	}

	~StandVehicleAggregate() override = default;
};


#endif


