#ifndef VEHICLESTAND_H
#define VEHICLESTAND_H
#include "Vehicle.h"
#include "Stand.h"
#include <vector>
#include <list>
#include <unordered_map>

class VehicleStand {
private:
	std::vector<Stand> m_standsContainer{};
public:

	VehicleStand() {
		m_standsContainer.reserve(2); /*Lets alocate initialy at least space for 2 spaces*/
	}

	void insertVehicle(Stand stand, Vehicle vehicle) {
		m_standsContainer.push_back(stand);
		stand.insertVehicle(std::move(vehicle));
	}

};

#endif
