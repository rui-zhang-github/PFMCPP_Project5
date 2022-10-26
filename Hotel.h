#pragma once
#include "LeakedObjectDetector.h"

struct Hotel
{
    Hotel();
    ~Hotel();
    int totalNumberOfGuestRooms = 30;
    int numberOfBookedRooms { 0 };
    float roomRatePerNight;
    int numberOfCafes = 1;
    int numberOfElevators { 2 };
    int totalNumberOfCustomersStayingTonight;
    int totalNumberOfLugages = 0;

    int storeLugages(const int numberOfLugages = 1); 
    int hostCustomers(const int numberOfCustomers = 1);  
    void providLaundryServices(const int numberOfClothes = 1) const;
    void printRoomRatePerNight() const;
    int reserveRooms(const int numberOfRoomsNeeded);
    void printNumberOfCafes() const;

    struct FrontDesk
    {
        FrontDesk();
        ~FrontDesk();
        int numberOfCounters = 1;
        int numberOfComputers { 1 };
        int numberOfPrinters;
        int numberOfTelephones = 3;
        int numberOfReceptionists { 2 };

        void checkCustomersIn(const int numberOfCustomers = 1) const;
        void takeServiceRequests(const std::string typeOfServices) const;
        void printBills(const int numberOfBillsToPrint = 1) const;
        void printNumberOfReceptionists() const;
        bool coordinateCalls(const unsigned int numberOfIncomingCalls) const;
        void printNumberOfPrinters() const;
    };

    JUCE_LEAK_DETECTOR(Hotel)
};
