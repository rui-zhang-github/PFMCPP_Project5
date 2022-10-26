#pragma once
#include "Hotel.h"

Hotel::Hotel() : 
roomRatePerNight(123.0f),
totalNumberOfCustomersStayingTonight(0) 
{
    std::cout << "Created a hotel." << std::endl;
}

Hotel::~Hotel() 
{
    std::cout << "Destroyed a hotel." << std::endl;
}

int Hotel::storeLugages(const int numberOfLugages)
{
    totalNumberOfLugages += numberOfLugages;
    std::cout << "After adding "  << numberOfLugages << " lugages, the hotel is storing a total of " << totalNumberOfLugages <<  " lugages."  << std::endl;
    return totalNumberOfLugages;
}

int Hotel::hostCustomers(const int numberOfCustomers)
{
    totalNumberOfCustomersStayingTonight += numberOfCustomers;
    std::cout << "After checking in "  << numberOfCustomers << " new guest(s), the hotel now has a total number of " << totalNumberOfCustomersStayingTonight <<  " guest(s) staying." << std::endl;
    return totalNumberOfCustomersStayingTonight;
}

void Hotel::providLaundryServices(const int numberOfClothes) const
{
    if(numberOfClothes < 2)
    {
        std::cout << numberOfClothes << " cloth has been taken for Laundry Service." << std::endl;
    }
    else 
    {
        std::cout << numberOfClothes << " clothes have been taken for Laundry Service." << std::endl;
    }
}

void Hotel::printRoomRatePerNight() const
{
    std::cout << "Tonight's room rate is $" << roomRatePerNight << "." <<  std::endl;
}

int Hotel::reserveRooms(const int numberOfRoomsNeeded)
{
    std::cout << "Return the number of rooms reserved per function call." << std::endl;
    int i = 0;
    std::string word = " room";
    while(numberOfBookedRooms < totalNumberOfGuestRooms && i < numberOfRoomsNeeded)
    {
        numberOfBookedRooms += 1;
        i += 1;
        word = (i <= 1) ? " room" : " rooms";
        std::cout << "Reserved " << i << word << "." << std::endl;
    }
    if(numberOfBookedRooms >= totalNumberOfGuestRooms)
    {
        std::cout << "Fully booked now." << std::endl;
    }
    std::cout << "Reserved " << i << word << " in total." << std::endl;
    std::string word2 = (totalNumberOfGuestRooms - numberOfBookedRooms <= 1) ? " room" : " rooms";
    std::cout << totalNumberOfGuestRooms - numberOfBookedRooms << word2 << " available." << std::endl;
    return i;
}

void Hotel::printNumberOfCafes() const
{
    std::cout << "There are " << this->numberOfCafes << " cafes in this hotel." << std::endl;
}

Hotel::FrontDesk::FrontDesk() :
numberOfPrinters(1)
{
    std::cout << "Created a front desk within the hotel." << std::endl;
}

Hotel::FrontDesk::~FrontDesk()
{
    std::cout << "Destroyed a front desk within the hotel." << std::endl;
}

void Hotel::FrontDesk::checkCustomersIn(const int numberOfCustomers) const
{
    if(numberOfCustomers < 2)
    {
        std::cout << "Checking in " << numberOfCustomers << " customer." << std::endl;
    }
    else 
    {
        std::cout << "Checking in " << numberOfCustomers << " customers." << std::endl;
    }  
}

void Hotel::FrontDesk::takeServiceRequests(const std::string typeOfServices) const
{
    std::cout << typeOfServices << " service request has been taken." << std::endl; 
}

void Hotel::FrontDesk::printBills(const int numberOfBillsToPrint) const
{
    if(numberOfBillsToPrint < 2)
    {
        std::cout << numberOfBillsToPrint << " bill has been printed." << std::endl;
    }
    else 
    {
        std::cout << numberOfBillsToPrint << " bills have been printed." << std::endl;
    }
}

void Hotel::FrontDesk::printNumberOfReceptionists() const
{
    if(numberOfReceptionists > 1)
    {
        std::cout << "There are " << numberOfReceptionists << " receptionists at the front desk." <<std::endl;
    }
    else
    {
        std::cout << "There is " << numberOfReceptionists << " receptionist at the front desk." <<std::endl;                
    }
}

bool Hotel::FrontDesk::coordinateCalls(const unsigned int numberOfIncomingCalls) const
{
    std::cout << "Return boolean values if there are incoming calls to the front desk." << std::endl;
    if(numberOfIncomingCalls > 0)
    {
        for(int i = 1; i <= numberOfReceptionists && i <= numberOfTelephones; ++i)
        {
            std::string word = (i < 2) ? " call" : " calls";
            std::cout << "Taking " << i << word << "." << std::endl;
        }
        std::cout << "Please hold. All staff are taking calls from other guests." << std::endl;
        return true;
    }
    else
    {
        std::cout << "No call taken." << std::endl;
        return false;
    }
}

void Hotel::FrontDesk::printNumberOfPrinters() const
{
    std::cout << "There are " << this->numberOfPrinters << " printers in this hotel." << std::endl;
}
