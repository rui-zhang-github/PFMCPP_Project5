#pragma once
#include "VacationResort.h"

VacationResort::VacationResort()
{
    std::cout << "Created a vacation resort that includes hotels and computers/laptops." << std::endl;
}

VacationResort::~VacationResort()
{
    std::cout << "Destroyed a vacation resort that includes hotels and computers/laptops." << std::endl;
}

void VacationResort::provideFood(const int numberOfCafeInHotel)
{
    hotelA.numberOfCafes = numberOfCafeInHotel;
    std::cout << "The vacation resort can provide food to " << hotelA.numberOfCafes * 100 << " people per hour." << std::endl;
}

int VacationResort::processTransactions(const std::string CPU, const int sizeOfRamInGb)
{
    laptopA.typeOfCPU = CPU;
    laptopA.sizeOfRamInGb = sizeOfRamInGb;
    if(laptopA.typeOfCPU == "Quad-Core Intel Core i5" || laptopA.sizeOfRamInGb >= 32)
    {
        std::cout << "The computer in the resort runs fast." << std::endl;
        return 1000000;
    }
    std::cout << "The computer in the resort runs slowly." << std::endl;
    return 100000;
}

void VacationResort::printNumberOfElevatorsInHotel() const
{
    std::cout << "There are " << this->hotelA.numberOfElevators << " elevators in the hotel of this vacation resort." << std::endl;
}
