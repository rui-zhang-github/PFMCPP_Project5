#pragma once
#include "LeakedObjectDetector.h"

struct PassengerPlane
{
    PassengerPlane();
    ~PassengerPlane();
    int numberOfSeats = 20;
    int nubmerOfBathrooms { 2 };
    int numberOfDoors;
    double sizeOfThePlane { 100 };
    int numberOfEngines;

    void carryPassengers(const int numberOfPassengers) const;
    void provideMultimediaEntertainment(const std::string mediaType) const;
    void flyAboveTheClouds(const std::string from, const std::string to) const;
    void printNumberOfSeats() const;
    int numberOfLoopsToUnloadAllPassengers(const int numberOfDoorsOpened) const;
    void printNumberOfSeatsOnPlane() const;

    JUCE_LEAK_DETECTOR(PassengerPlane)
};
