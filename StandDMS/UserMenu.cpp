#include "UserMenu.h"
#include <iostream>
#include <string>
#include <tuple>
#include <stdexcept>
#include "GestStand.h"
#include "FunctionReturn.h"


enum class options {
	InsertStandCity /* 0 */,
	ListStandsCity /* 1 */,
	InsertVehicleStand /* 2 */,
	ListVehicleStand /* 3 */ ,
	MoveVehicleStand /* 4 */,
	MaxOptions
};

std::string optionsToString(const options& option) {

	std::string result = "You have chosen: ";

	switch (option) {
	case options::InsertStandCity:     result += "Insert a new stand in a city \n"; break;
	case options::ListStandsCity:       result += "List stands in a city \n"; break;
	case options::InsertVehicleStand:  result += "Insert a new vehicle and place it in a stand \n"; break;
	case options::ListVehicleStand:    result += "List vehicles in a stand \n"; break;
	case options::MoveVehicleStand:    result += "Move a vehicle from one stand to another \n"; break;
	default:                           return "Unknown option"; 
	}

	return result;
}


std::string CapitalizeFirstLetter(const std::string& input) {
	if (input.empty()) return input;

	std::string result = input;
	result[0] = std::toupper(result[0]);
	std::transform(result.begin() + 1, result.end(), result.begin() + 1, ::tolower);
	return result;
}


void userMenu() {

	GestStand gestStandVehicles;
	VehicleStandGroup VehicleStand;

	std::cout << "Welcome to the Stand Manager application!\n\n\n";

	while (true) {

		int userOpt{};

		std::cout << "Choose a valid option:\n";
		std::cout << "Options:\n";
		std::cout << "1) Insert a new stand in a city\n";
		std::cout << "2) List stands in a city\n";
		std::cout << "3) Insert a new vehicle and place it in a stand\n";
		std::cout << "4) List vehicles in a stand\n";
		std::cout << "5) Move a vehicle from one stand to another\n";

		std::cout << "Option number: ";

		while (true) {

			try {
				std::cin.exceptions(std::ios::failbit | std::ios::badbit); /* Activate failbit & badbit exception */
				std::cin >> userOpt;
				userOpt -= 1;

				if (userOpt < 0 || userOpt >= static_cast<int>(options::MaxOptions)) {
					throw std::out_of_range("Invalid menu option selected.");
				}
				break;
			}
			catch (const std::ios_base::failure& e) {
				cleanCinBuffer();
				std::cerr << "Input error: Please enter a valid number.\nOption number: ";
				continue;
			}
			catch (const std::out_of_range& e) {
				cleanCinBuffer();
				std::cerr << "\nPlease enter a valid option.\n" << e.what();
				continue;
			}
		}

		std::cout << optionsToString(static_cast<options>(userOpt)) << '\n';
		cleanCinBuffer();

		switch (static_cast<options>(userOpt)) {

		case options::InsertStandCity: {
			while (true) {

				std::cout << "Stand Creator \n";

				Stand standCreate;
				auto standObject = UserInputObjectParameterHandler::userStandCreator();

				try {
					standCreate = Stand(std::get<0>(standObject), std::get<1>(standObject), std::get<2>(standObject)); // usa o nome correto
				}
				catch (const std::out_of_range& e) {
					std::cerr << "Invalid Parameter: " << e.what();
					cleanCinBuffer();
					continue;
				}
				catch (const std::invalid_argument& e) {
					std::cerr << "\nInvalid code: " << e.what();
					continue;
				}

				/* Associate city to m_standVehicleInventory */
				auto idx = VehicleStand.InsertNewStand(standCreate); /* VehicleStandGroup vector insert */
				std::string StandCity = standCreate.getStandCity();
				std::string StandCityCapitalized = CapitalizeFirstLetter(StandCity);
				gestStandVehicles.insertNewStandCity(StandCityCapitalized, idx);
				std::cout << "Stand successfully Inserted.\n\n";
				break;
			}
			break;
		}

		case options::ListStandsCity: {
			while (true) {

				std::cout << "Which city do you want to get information about?\n";
				gestStandVehicles.listCitys();

				std::string city{};
				std::cout << "Please insert a valid City:\n";
				std::getline(std::cin, city);
				CapitalizeFirstLetter(city);

				if (!gestStandVehicles.getStandCitys(city, VehicleStand)) {
					continue;
				}

				break;
			}
			break;
		}

		case options::InsertVehicleStand: {
			std::string userStandCode{};
			std::string userCity{};
			std::string UserVehicleType;

			while (true) {

				gestStandVehicles.listCitysStands(VehicleStand);
				std::cout << "Which city and stand do want to add vehcle? \n";
				std::cout << "1º City: ";
				std::cin >> userCity;
				std::cout << "2º StandCode (Example \"Lisbon01\"): ";
				std::cin >> userStandCode;
				std::cout << std::endl;
				break;

			}

			while (true) {
				std::cout << "What type of vehicle you want to create? (Sedan, Coupe, MortoCycle)\n";
				std::cin >> UserVehicleType;

				while (!std::cin) {
					cleanCinBuffer();
					std::cout << "Invalid input\n";
				}
				break;
			}

			std::transform(UserVehicleType.begin(), UserVehicleType.end(), UserVehicleType.begin(), ::toupper); /* Example - >std::vector<int> v = {1, 2, 3} _ std::transform(v.begin(), v.end(), r.begin(),  [](int x){ return x * 2; }); double value of each vector element*/
			cleanCinBuffer();
			
			gestStandVehicles.insertVehicleIntoStand(UserVehicleType, userCity, userStandCode, VehicleStand);

			break;
		}


		case options::ListVehicleStand: {

			while (true) {
				std::cout << "From which stand would you like to get vehicle information?\n";
				gestStandVehicles.listCitysStands(VehicleStand);

				std::string standCode{};
				std::cout << "Please Insert a standCode (Example \"Lisbon01\"): \n";
				std::cin >> standCode;

				CapitalizeFirstLetter(standCode);

				gestStandVehicles.listVehiclesStand(standCode, VehicleStand);

				break;
			}

			cleanCinBuffer();
		}

		default:
			std::cout << "Option not valid!\n";
			break;
		}

		

	}
}

