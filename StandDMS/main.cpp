// StandDMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Coupe.h"
#include "Sedan.h"
#include "Stand.h"
#include "VehicleStand.h"
#include "MotorCycle.h"
#include "FactoryClass.h"

int Vehicle::s_nextID = 0;

int main()
{

   /* Coupe mycoupe1(2017, "Nissan");
    Coupe mycoupe2(2021, "Opel");

    Sedan mySedan1(2018, "BMW");
    Sedan mySedan2(2022, "Mercedes");
    Sedan mySedan3(2018, "Audi");
    Sedan mySedan4(2022, "Volkswagen");

    Car* mycoupe1Ptr = &mycoupe1;
    Car* mycoupe2Ptr = &mycoupe2;

    Car* mySedanPtr1 = &mySedan1;
    Car* mySedanPtr2 = &mySedan2;
    Car* mySedanPtr3 = &mySedan3;
    Car* mySedanPtr4 = &mySedan4;

    std::cout << mycoupe1Ptr->toString() << std::endl;
    std::cout << mycoupe2Ptr->toString() << std::endl;

    std::cout << mySedanPtr1->toString() << std::endl;
    std::cout << mySedanPtr2->toString() << std::endl;
    std::cout << mySedanPtr3->toString() << std::endl;
    std::cout << mySedanPtr4->toString() << std::endl;*/



  /*  Motorcycle myMotorCycle1(2015, "Yamanha", fuelType::GASOLINE, Fairing::hasFair);

    std::cout << myMotorCycle1.toString();*/

   //Stand myStand1("Lisboa", 01);
   //Stand myStand2("Aveiro", 02);
   //Stand myStand3("Barcelos", 03);

   //std::cout << myStand1.toString();
   //std::cout << myStand2.toString();
   //std::cout << myStand3.toString() << "\n";

   //VehicleStandGroup VehicleStand;

 
   //std::unique_ptr<Vehicle> myVehiclePtr = std::make_unique<Sedan>(2018, "BMW");
   //std::unique_ptr<Vehicle> myVehiclePtr2 = std::make_unique<Coupe>(2019, "Opel");
   //std::unique_ptr<Vehicle> myVehiclePtr3 = std::make_unique<Motorcycle>(2015, "Yamanha", fuelType::GASOLINE, Fairing::hasFair);
   ////std::unique_ptr<Vehicle> myVehiclePtr3 = std::make_unique<Motorcycle>(2015, "KTM", fuelType::GASOLINE, Fairing::hasFair);

   //VehicleStand.InsertNewStand(myStand1);
   //VehicleStand.insertNewVehicleStand(std::move(myVehiclePtr), myStand1);
   //VehicleStand.InsertNewStand(myStand2);
   //VehicleStand.insertNewVehicleStand(std::move(myVehiclePtr2), myStand2);
   //VehicleStand.insertNewVehicleStand(std::move(myVehiclePtr3), myStand2);

   //std::cout << VehicleStand.toString();

   std::unique_ptr<VehicleFactory> creator = std::make_unique<SedanFactory>();
    

   return 0;

}

void ClientCode(const VehicleFactory& creator) {

    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.CreateObject() << std::endl;
   
}


