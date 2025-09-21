#ifndef VEHICLESTAND_H
#define VEHICLESTAND_H
#include "Stand.h"
#include "Vehicle.h"
#include <vector>

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


	std::vector<std::unique_ptr<Vehicle>> const& getUnits() const
	{
		return m_vehiclesConteiner;
	}

	~StandAggregate() {};

};


class VehicleStand {
private:
	std::vector<StandAggregate> m_standVehicleInventory;

public:
	VehicleStand() = default;


};


#endif
