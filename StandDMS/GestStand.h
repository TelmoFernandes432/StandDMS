#ifndef GESTSTAND_H
#define GESTSTAND_H
#include "VehicleStand.h"
#include "FunctionReturn.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class GestStand {

private:
	std::unordered_map<std::string, std::vector<size_t>> m_standCity;
	
public:
	GestStand() = default;

	void listStandCitysIndex();
	bool getStandCitys(const std::string& City, VehicleStandGroup& objectStand);
	void listCitys();
	void listCitysStands(VehicleStandGroup&);
	void insertNewStandCity(const std::string& city, size_t idx);
	void insertVehicleIntoStand(const std::string& userVehicleType, const std::string& city, const std::string& standCode, VehicleStandGroup& objectStand);
	void listVehiclesStand(std::string& standCode, VehicleStandGroup&);
	void moveVehicleStand(std::string& sourceStandCode, std::string& destinationStandCode, const unsigned int vehicleID, VehicleStandGroup& standVehicleInventory);

	bool checkStandCodes(const std::string& standCode, const VehicleStandGroup&);
	bool checkVehicleID(unsigned int checkID, const VehicleStandGroup&);
};

#endif 
