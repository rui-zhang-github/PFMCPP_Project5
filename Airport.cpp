#pragma once
#include "Airport.h"

Airport::Airport()
{
    std::cout << "Created an airport that includes passenger planes and computers/laptops." << std::endl;
}

Airport::~Airport()
{
    std::cout << "Destroyed an airport that includes passenger planes and computers/laptops." << std::endl;
}

std::string Airport::parkAirplane(const int numberOfSeats, const double sizeOfThePlane)
{
    airplaneA.numberOfSeats = numberOfSeats;
    airplaneA.sizeOfThePlane = sizeOfThePlane;
    if(airplaneA.numberOfSeats <= 20 && airplaneA.sizeOfThePlane <= 100)
    {
        return "Small Passenger Plane Zone";
    }
    else if(airplaneA.numberOfSeats <= 20 && airplaneA.sizeOfThePlane > 100)
    {
        return "Large Cargo Plane Zone";
    }
    else if(airplaneA.numberOfSeats >= 20 && airplaneA.sizeOfThePlane <= 100)
    {
        return "Mid-size Passenger Plane Zone";
    }
    else
    {
        return "Large Passenger Plane Zone";
    } 
}

int Airport::saveFlightData(const int diskSpaceInGb, int fileSizeInGb)
{
    laptopA.sizeOfRamInGb = diskSpaceInGb;
    if(fileSizeInGb <= laptopA.sizeOfRamInGb)
    {
        while(fileSizeInGb > 0)
        {
            std::cout << fileSizeInGb << "GB of flight data saved."<< std::endl;
            --fileSizeInGb;
            --laptopA.sizeOfRamInGb;
        }
        std::cout << "File saved." << std::endl;
    }
    else
    {
        std::cout << "Not enough disk space. File not saved." << std::endl;
    }
    return laptopA.sizeOfRamInGb;
}

void Airport::printNumberOfDoorsOnPlane() const
{
    std::cout << "There are " << this->airplaneA.numberOfDoors << " doors on the plane A in this airport." << std::endl;
}
