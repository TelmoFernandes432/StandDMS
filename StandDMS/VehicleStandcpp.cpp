#include "VehicleStand.h"
#include "Stand.h"


void StandAggregate::setVehicleIntoStand(std::unique_ptr<Vehicle> vehicleInsert) {
	m_vehiclesConteiner.push_back(std::move(vehicleInsert));
}

void StandAggregate::setStand(const Stand& standInsert) { /*Here function doenst have ownership  const Stand& standInsert != std::unique_ptr<Stand> standInsert*/
	m_stand = std::make_unique<Stand>(standInsert);
}

void VehicleStandGroup::insertNewStand(Stand& stand) {
	StandAggregate standToInsert;
	standToInsert.setStand(stand);
}

StandFunctionReturnValue::valueReturn VehicleStandGroup::insertVehicleIntoStand(std::unique_ptr<Vehicle> vehicle, const Stand& stand) {
	for (auto& it : m_standVehicleInventory) {
		if (stand.getCode() == it.getStand()->getCode()) {
			it.setVehicleIntoStand(std::move(vehicle));
			return StandFunctionReturnValue::valueReturn::standInsertedSucceed;
		}
	}

	return StandFunctionReturnValue::valueReturn::standNotFound;
}