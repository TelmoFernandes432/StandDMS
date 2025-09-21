#include <sstream>
#include <string>
#include "Stand.h"

std::vector<std::string> Stand::m_codes;

namespace standCaution {
	static const int MIN_STAND_NUMBER = 1;
	static const int MAX_STAND_NUMBER = 99;
}

int Stand::standNumberCheck(int standNumber) {
	if (standNumber < standCaution::MIN_STAND_NUMBER || standNumber > standCaution::MAX_STAND_NUMBER) {
		throw std::out_of_range( std::format("standNumber {}, this is out of range [{}-{}]", standNumber, standCaution::MIN_STAND_NUMBER,standCaution::MAX_STAND_NUMBER)); /*try catch here!*/
	}
	return standNumber;
}

void Stand::addCode(const std::string& code) {
	if(!existCode(code))
		m_codes.push_back(code);
}

bool Stand::existCode(const std::string& code) {
	for (const auto& it : Stand::m_codes) {
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
	return std::format("{}{:02}", m_standCity, m_standNumber);
}

