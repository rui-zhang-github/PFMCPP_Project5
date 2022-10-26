#pragma once
#include "PassengerPlane.h"

PassengerPlane::PassengerPlane() :
numberOfDoors(6),
numberOfEngines(4)
{
    std::cout << "Created a passenger plane." << std::endl;
}

PassengerPlane::~PassengerPlane()
{
    std::cout << "Destroyed a passenger plane." << std::endl;
}

void PassengerPlane::carryPassengers(const int numberOfPassengers) const
{
    std::cout << "There are " << numberOfPassengers << " passengers on the plane." << std::endl;
}

void PassengerPlane::provideMultimediaEntertainment(const std::string mediaType) const
{
    std::cout << "Now playing: " << mediaType << std::endl;
}

void PassengerPlane::flyAboveTheClouds(const std::string from, const std::string to) const
{
    std::cout << "This flight is from " << from << " to " << to << std::endl;
}

void PassengerPlane::printNumberOfSeats() const
{
    std::cout << "There are " << numberOfSeats << " seats on the plane." << std::endl;
}

int PassengerPlane::numberOfLoopsToUnloadAllPassengers(const int numberOfDoorsOpened) const
{
    std::cout << "Print and return number of loops to unload all the passengers assuming flying at full capacity." << std::endl;
    int numberOfLoops = 0;
    for(int i = 0; i * numberOfDoorsOpened < numberOfSeats; ++i)
    {
        std::cout << "A total of " << i * numberOfDoorsOpened << " people can be unloaded in loop " << i << "." << std::endl;
        numberOfLoops = i;
    }
    int lastLoop = (numberOfLoops * numberOfDoorsOpened < numberOfSeats) ? 1 : 0;
    numberOfLoops = numberOfLoops + lastLoop;
    std::cout << "The plane can be fully unloaded at full capacity at loop " << numberOfLoops << "." << std::endl;
    return numberOfLoops;
}

void PassengerPlane::printNumberOfSeatsOnPlane() const
{
    std::cout << "This plane has " << this->numberOfSeats << " seats." << std::endl;
}
