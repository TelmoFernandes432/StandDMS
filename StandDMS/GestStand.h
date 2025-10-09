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

	void listStandCitys() {

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

	void listCitys() {
		std::cout << "Cities hosting stands: \n";
		for (const auto& [citys, _] : m_standCity) {
			std::cout << citys << "\n";
		}
	}

	void insertNewStandCity(const std::string& city, size_t idx) {
		m_standCity[city].push_back(idx);
	}


};

#endif // !GESTSTAND_H
