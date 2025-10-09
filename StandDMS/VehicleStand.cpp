#include "VehicleStand.h"
#include "Stand.h"
#include "Vehicle.h"
#include "FunctionReturn.h"

std::size_t VehicleStandGroup::InsertNewStand(const Stand& stand) {
	auto aggregatePtr = std::make_unique<StandVehicleAggregate>();
	aggregatePtr->setStand(stand);
	m_standVehicleInventory.push_back(std::move(aggregatePtr));

	return m_standVehicleInventory.size() - 1;
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
	std::ostringstream oss;

	for (const auto& it : m_standVehicleInventory) {
		std::cout << it->getStand().getCode() << "\n";
		
		for (const auto& it : it->getVehiclesConteiner())
			std::cout << it->toString();

		std::cout << std::endl;
	}

	return oss.str();
}