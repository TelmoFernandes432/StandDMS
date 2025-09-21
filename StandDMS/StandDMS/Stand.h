#ifndef STAND_H
#define STAND_H
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>

class Stand {

private:
   
    std::string m_standCity;
    unsigned int m_standNumber;
    static std::vector<std::string> m_codes; /*This belongs to the class*/

    static std::string generateCode(const std::string& standCity, int standNumber);
    static bool existCode(const std::string& code);
    static void addCode(const std::string& code);
    static int standNumberCheck(int standNumber);

public:

    Stand() = default;

    Stand(const std::string& standCity, int standNumber) 
        : m_standCity(standCity), 
        m_standNumber(standNumberCheck(standNumber)) 
    {}

    std::string toString() const;

};


#endif
