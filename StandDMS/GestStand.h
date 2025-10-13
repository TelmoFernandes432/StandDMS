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

	void listStandCitysIndex();
	bool getStandCitys(const std::string& City, VehicleStandGroup& objectStand);
	void listCitys();
	void listCitysStands(VehicleStandGroup&);
	void insertNewStandCity(const std::string& city, size_t idx);
	void insertVehicleIntoStand(const std::string& userVehicleType, const std::string& city, const std::string& standCode, VehicleStandGroup& objectStand);
	void listVehiclesStand(std::string& standCode, VehicleStandGroup&);
};

#endif 
