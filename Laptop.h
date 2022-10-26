#pragma once
#include "LeakedObjectDetector.h"

struct Laptop
{
    Laptop();
    ~Laptop();
    std::string typeOfCPU = "Quad-Core Intel Core i5";
    int sizeOfRamInGb { 8 };
    float sizeOfScreenInInch;
    std::string typeOfOperatingSystem = "Linux";
    int sizeOfDiskSpaceInGb;

    int displayImage(const std::string fileName) const; 
    void playAudio(const std::string fileName) const;
    void storeData(const std::string fileName) const;
    void printSizeOfScreenInInch() const;
    void formatDisk(const unsigned int percentageOfTotalDiskSpaceNeededToBeFreedUp) const;
    void printSizeOfRamInGb() const;

    struct Display
    {
        Display();
        ~Display();
        double electricPowerConsumedPerYearInWatts = 1.0;
        int numberOfPixles { 1 };
        std::string colorProfile;
        float lengthInCm { 1.0f };
        float WidthInCm;

        void displayColor(const std::string hexColorCode = "FF5733") const;
        void adjustBrightness(const int brightnessInPercentage = 50) const;
        void adjustClarity(const float clarityInPercentage = 100) const;
        void printElectricPowerConsumedPerYearInWatts() const;
        double consumeElectricity(const int numberOfYears, const int brightnessInPercentage) const;
        void printNumberOfPixles() const;
    };

    JUCE_LEAK_DETECTOR(Laptop)
};
