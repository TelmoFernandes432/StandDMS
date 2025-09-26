#include "VehicleStand.h"
#include "Stand.h"
#include "Vehicle.h"


void VehicleStandGroup::InsertNewStand(const Stand& stand) {
	auto aggregatePtr = std::make_unique<StandVehicleAggregate>();
	aggregatePtr->setStand(stand);
	m_standVehicleInventory.push_back(std::move(aggregatePtr));
}

StandFunctionReturnValue::valueReturn VehicleStandGroup::insertNewVehicleStand(std::unique_ptr<Vehicle> vehicle, Stand& stand) {
	for (auto& it : m_standVehicleInventory) {
		if (stand.getCode() == it->getStand().getCode()) {
			it->setVehicle(std::move(vehicle));
			return StandFunctionReturnValue::valueReturn::standInsertedSucceed;
		}
	}

	return StandFunctionReturnValue::valueReturn::standNotFound;
}

const std::string VehicleStandGroup::toString() {
	std::cout << "\n \n";
	std::ostringstream oss;

	for (const auto& it : m_standVehicleInventory) {
		std::cout << it->getStand().getCode() << "\n";
		
		for (const auto& i : it->getVehiclesConteiner())
			std::cout << i->toString();
	}

	return oss.str();
}