#ifndef VEHICLESTAND_H
#define VEHICLESTAND_H
#include "Stand.h"
#include "Vehicle.h"
#include <vector>
#include <optional>


namespace StandFunctionReturnValue {

	enum class valueReturn {
		standInsertedSucceed,
		standNotFound,
	};
}

class StandAggregate {

private:
	std::unique_ptr<Stand> m_stand;
	std::vector<std::unique_ptr<Vehicle>> m_vehiclesConteiner{};
public:

	StandAggregate() = default;

	StandAggregate(std::unique_ptr<Stand> stand)
		: m_stand{ std::move(stand) }
	{
		m_vehiclesConteiner.reserve(2);
	}

	Stand* getStand() const { /* Care: if I did something like return std::move(m_stand), I would change m_stand properti and this would become null after move */
		return m_stand.get();
	}

	std::vector<std::unique_ptr<Vehicle>> const& getVehiclesUnits() const
	{
		return m_vehiclesConteiner;
	}
	
	void setVehicleIntoStand(std::unique_ptr<Vehicle> vehicleInsert);
	void setStand(Stand& standInsert);

	StandFunctionReturnValue::valueReturn insertVehicleIntoStand(std::unique_ptr<Vehicle> vehicle, const Stand& stand);

	~StandAggregate() {};

};


class VehicleStandGroup {

private:
	std::vector<StandAggregate> m_standVehicleInventory;

public:
	VehicleStandGroup() = default; /*See notes down there */

	void insertNewStand(Stand& stand);

	StandFunctionReturnValue::valueReturn insertVehicleIntoStand(std::unique_ptr<Vehicle> vehicle, const Stand& stand);
	
};
#endif


/*
	StandAggregate standAgg;
	VehicleStand vs;

	vs.m_standVehicleInventory.push_back(standAgg);       // copia
	vs.m_standVehicleInventory.push_back(std::move(standAgg)); // move (standAgg fica "vazio")
	vs.m_standVehicleInventory.emplace_back(/* args );
*/
