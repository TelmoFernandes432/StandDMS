#include <sstream>
#include <string>
#include "Stand.h"

std::vector<std::string> Stand::m_codesArray;

namespace standCaution {
	static const int MIN_STAND_NUMBER = 1;
	static const int MAX_STAND_NUMBER = 99;
}

int Stand::standNumberCheck(int standNumber) {
	if (standNumber < standCaution::MIN_STAND_NUMBER || standNumber > standCaution::MAX_STAND_NUMBER) {
		throw std::out_of_range( std::format("stand nuumber {} is outside of range [{}-{}] \n \n", standNumber, standCaution::MIN_STAND_NUMBER,standCaution::MAX_STAND_NUMBER));
	}
	return standNumber;
}


void Stand::addCode(const std::string& code) {
	if (!existCode(code)) {
		m_codesArray.push_back(code);
	}
	else
		throw std::invalid_argument("Duplicated element " + code + '\n');
}

bool Stand::existCode(const std::string& code) {
	for (const auto& it : m_codesArray) {
		if (code == it)
			return true;
	}
	return false;
}

std::string Stand::generateCode(const std::string& standCity, int standNumber) {
	return std::format("{}{:02}", standCity, standNumber);
}

/*std::format already return a string*/
std::string Stand::toString() const {
	std::ostringstream oss;
	oss << std::format("{}{:02}", m_standCity, m_standNumber) << std::endl;

	return oss.str();
}
