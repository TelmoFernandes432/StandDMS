#ifndef STAND_H
#define STAND_H
#include <string>
#include <iostream>
#include <iomanip>



class Stand {

private:
	std::string m_location{};
	unsigned int m_standID{};
	std::string m_code{};

public:

	Stand() = default;

	Stand(const std::string& location, unsigned int standID)
		: m_location{ location },
		m_standID{ standID }
	{
		m_code = std::format("{}{:02}", location, standID);
	}

	std::string toString() const;

};


#endif
