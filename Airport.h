#pragma once
#include "LeakedObjectDetector.h"
#include "PassengerPlane.h"
#include "Laptop.h"

struct Airport
{
    Airport();
    ~Airport();

    PassengerPlane airplaneA;
    Laptop laptopA;

    std::string parkAirplane(const int numberOfSeats, const double sizeOfThePlane); // return the parking zone name given the number of seats and size of an airplane
    int saveFlightData(const int diskSpaceInGb, int fileSizeInGb); // return disk space after saving some flight data of a certain size
    void printNumberOfDoorsOnPlane() const;

    JUCE_LEAK_DETECTOR(Airport)
};
