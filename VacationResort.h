#pragma once
#include "LeakedObjectDetector.h"
#include "Hotel.h"
#include "Laptop.h"

struct VacationResort
{
    VacationResort();
    ~VacationResort();

    Hotel hotelA;
    Laptop laptopA;

    void provideFood(const int numberOfCafeInHotel); // print number of people that the resort can provide food to
    int processTransactions(const std::string CPU, const int sizeOfRamInGb); // return the number of transactions that resort can process in a second with the CPU and size of RAM of the PC.
    void printNumberOfElevatorsInHotel() const;

    JUCE_LEAK_DETECTOR(VacationResort)
};
