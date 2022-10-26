#pragma once
#include "Laptop.h"

Laptop::Laptop() :
sizeOfScreenInInch(13.3f),
sizeOfDiskSpaceInGb(256)
{
    std::cout << "Created a laptop." << std::endl;
}

Laptop::~Laptop()
{
    std::cout << "Destroyed a laptop." << std::endl;
}

int Laptop::displayImage(const std::string fileName) const
{
    std::cout << "Now displaying: " << fileName << std::endl;
    int numberOfDifferentHexColorCodes = 0;
    return numberOfDifferentHexColorCodes;
}

void Laptop::playAudio(const std::string fileName) const
{
    std::cout << "Now playing: " << fileName << std::endl;
}

void Laptop::storeData(const std::string fileName) const
{
    std::cout << fileName << " has been stored the hard drive." << std::endl;
}

void Laptop::printSizeOfScreenInInch() const
{
    std::cout << "This is a " << sizeOfScreenInInch << "in screen."<< std::endl;
}

void Laptop::formatDisk(const unsigned int percentageOfTotalDiskSpaceNeededToBeFreedUp) const
{
    std::cout << "This function prints out the disk space that has been freed up by formatting based on the user input as the function parameter." << std::endl;
    if(percentageOfTotalDiskSpaceNeededToBeFreedUp <= 100)
    {
        int i = 0;
        while(i <= percentageOfTotalDiskSpaceNeededToBeFreedUp / 100.0 * sizeOfDiskSpaceInGb)
        {
            std::cout << i << "GB disk space has been formatted and freed." << std::endl;
            i += 1;
        }
    }
    else
    {
        std::cout << "Disk formatting failed." << std::endl;
    }
}

void Laptop::printSizeOfRamInGb() const
{
    std::cout << "This laptop has a RAM of " << this->sizeOfRamInGb << " GB." << std::endl;
}

Laptop::Display::Display() :
colorProfile("Adobe RGB"),
WidthInCm(1.0f)
{
    std::cout << "Created a display of a laptop." << std::endl;
}

Laptop::Display::~Display()
{
    std::cout << "Destroyed a display of a laptop." << std::endl;
}

void Laptop::Display::displayColor(const std::string hexColorCode) const
{
    std::cout << "This is the color of hex code " << hexColorCode << std::endl;
}

void Laptop::Display::adjustBrightness(const int brightnessInPercentage) const
{
    std::cout << "Current brightness is " << brightnessInPercentage << "%." << std::endl;
}

void Laptop::Display::adjustClarity(const float clarityInPercentage) const
{
    std::cout << "Current clarity is " << clarityInPercentage << "%." << std::endl;
}

void Laptop::Display::printElectricPowerConsumedPerYearInWatts() const
{
    std::cout << "This display consumes " << electricPowerConsumedPerYearInWatts << "W electricity per year."<< std::endl;
}

double Laptop::Display::consumeElectricity(const int numberOfYears, const int brightnessInPercentage) const
{
    std::cout << "Print electricity consumed while it is on for X number of years." << std::endl;
    double electricityConsumedInWatt = 0.00;
    for(int i = 0; i <= numberOfYears; ++i)
    {
        electricityConsumedInWatt = i * electricPowerConsumedPerYearInWatts * brightnessInPercentage / 100;
        std::cout << "The display has been on for " << i << " years and consumed " << electricityConsumedInWatt << "W of electricity." << std::endl;
    }
    return electricityConsumedInWatt;
}

void Laptop::Display::printNumberOfPixles() const
{
    std::cout << "The Laptop has a displconst ay with " << this->numberOfPixles << " pixles." << std::endl;
}
