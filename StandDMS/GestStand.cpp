#include "GestStand.h"
#include "UserMenu.h"
#include "FactoryClass.h"



std::unique_ptr<Vehicle> deduceVehicleFromUser(const std::string& userVehicleType) {
	std::unique_ptr<Vehicle> myVehicle;

	/*or switch*/
	if (userVehicleType == "SEDAN") {
		std::unique_ptr<VehicleFactory> createVehicle = std::make_unique<SedanFactory>();
		myVehicle = createVehicle->createVehicle();
		myVehicle->toString();
	}
	else if (userVehicleType == "COUPE") {
		std::unique_ptr<VehicleFactory> createVehicle = std::make_unique<CoupeFactory>();
		myVehicle = createVehicle->createVehicle();
		myVehicle->toString();
	}
	else if (userVehicleType == "MOTORCYCLE") {
		std::unique_ptr<VehicleFactory> createVehicle = std::make_unique<MotorcycleFactory>();
		myVehicle = createVehicle->createVehicle();
		myVehicle->toString();
	}
	else {
		std::cerr << "Tipo de veículo desconhecido: " << userVehicleType << std::endl;
	}

	return myVehicle;  /*Move the owernship*/
}

void GestStand::listStandCitysIndex() {

	for (auto& it : m_standCity)
	{
		std::cout << "City -> " << it.first << "[";
		auto first = begin(it.second), last = end(it.second);

		if (first != last) {
			while (true) {
				std::cout << *first++; /*vector position increment*/
				if (first == last) break;
				std::cout << ", ";
			}
		}
		std::cout << "] \n";
	}
}

void GestStand::listCitys() {
	std::cout << "Cities hosting stands: \n";
	for (const auto& [citys, _] : m_standCity) {
		std::cout << citys << "\n";
	}
	std::cout << std::endl;
}

void GestStand::listCitysStands(VehicleStandGroup& objectStand) {

	auto const& v = objectStand.getStandVehicleInventory(); /* std::unqiue_ptr cant be copied I need auto const& and not auto const */

	std::cout << "Stands available: \n";

	for (auto& it : m_standCity) {

		std::cout << "--> " << it.first << " <--" << std::endl;

		for (const auto& i : it.second) {
			Stand standcodeinfo = v[i]->getStand();
			std::cout << "- " << standcodeinfo.getCode() << std::endl;
		}
		std::cout << std::endl;
	}
}


bool GestStand::getStandCitys(const std::string& city, VehicleStandGroup& objectStand) {

	std::string cityFirstLeterCapitalized = CapitalizeFirstLetter(city);
	std::vector<size_t> v{};

	try {
		 v = m_standCity.at(cityFirstLeterCapitalized);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "City not found -> " << cityFirstLeterCapitalized << "Details: " << e.what() << std::endl;
		return false;
	}

	const auto& vec = objectStand.getStandVehicleInventory();

	/* val gives me every element of vector associated key(city) */
	for (size_t val : v) {
		auto standHandler = vec[val]->getStand();
		std::cout << "Stand information: " << standHandler.toString();
	}
	std::cout << std::endl;
}

void GestStand::insertNewStandCity(const std::string& city, size_t idx) {
	m_standCity[city].push_back(idx);
}

void GestStand::insertVehicleIntoStand(const std::string& userVehicleType, const std::string& city, const std::string& standCode, VehicleStandGroup& objectStand) {

	auto Vehicle = deduceVehicleFromUser(userVehicleType);

	std::string cityFirstLeterCapitalized = CapitalizeFirstLetter(city);
	auto& standVehicleInventory = objectStand.getStandVehicleInventory();

	const std::vector<size_t> vec = m_standCity.at(cityFirstLeterCapitalized);

	for (auto v : vec) {
		auto standHandler = standVehicleInventory[v]->getStand();
		if (standHandler.getCode() == standCode) {
			standVehicleInventory[v]->setVehicle(std::move(Vehicle));
		}	
	}
}

void GestStand::listVehiclesStand(std::string& standCode, VehicleStandGroup& objectStand) {

	/*Just other way to do it*/
	const auto& standVehicleInventory = objectStand.getStandVehicleInventory();

	for (const auto& it : m_standCity) {


		const std::vector<size_t> vec = it.second;

		for (auto v : vec) {
			std::string currentStandCode = standVehicleInventory[v]->getStand().getCode();
			if (currentStandCode == standCode) {
				const auto& vehicleConteiner = standVehicleInventory[v]->getVehiclesConteiner();
				for (const auto& it : vehicleConteiner) {
					std::cout << "Vehicle information: " << it->toString() << std::endl;
				}
			}

		}
	}
	std::cout << std::endl;
}



