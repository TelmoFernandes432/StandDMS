#ifndef GESTSTAND_H
#define GESTSTAND_H
#include "VehicleStand.h"
#include <unordered_map>

class GestStand : public VehicleStandGroup {

private:
	std::unordered_map<std::string, VehicleStandGroup> StandCity;
	
public:
};

#endif // !GESTSTAND_H
