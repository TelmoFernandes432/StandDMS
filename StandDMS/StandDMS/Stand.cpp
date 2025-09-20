#include <sstream>
#include "Stand.h"

std::string Stand::toString() const {
	std::ostringstream oss;

	oss << m_code << "\n";

	return oss.str();
}