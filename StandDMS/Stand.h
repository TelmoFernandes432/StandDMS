#ifndef STAND_H
#define STAND_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>

class Stand {

private:
   
    std::string m_standCity;
    unsigned int m_standNumber;
    std::string m_codes;
    static std::vector<std::string> m_codesArray; /*This belongs to the class*/

    static std::string generateCode(const std::string& standCity, int standNumber);
    static void addCode(const std::string& code);
    static bool existCode(const std::string& code);
    static int standNumberCheck(int standNumber);

public:


    Stand() = default;

    Stand(const std::string& standCity, int standNumber) 
        : m_standCity(standCity), 
        m_standNumber(standNumberCheck(standNumber)) 
    {
        m_codes = generateCode(standCity, standNumber);
        /*Validate before use constructer*/
    }
    
    const std::string& getCode() const {
        return m_codes;
    }

    std::string toString() const;

};


#endif
