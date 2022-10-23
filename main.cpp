/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7
 
 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.
        
        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */




#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
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

struct HotelWrapper 
{
    HotelWrapper(Hotel* ptr) : hotelPtr(ptr) {}
    ~HotelWrapper() { delete hotelPtr; }
    Hotel* hotelPtr = nullptr;
};

/*
 copied UDT 2:
 */
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

struct LaptopWrapper
{
    LaptopWrapper(Laptop* ptr) : LaptopPtr(ptr) {}
    ~LaptopWrapper() { delete LaptopPtr; }
    Laptop* LaptopPtr = nullptr;
};

/*
 copied UDT 3:
 */
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

struct PassengerPlaneWrapper
{
    PassengerPlaneWrapper(PassengerPlane* ptr) : passengerPlanePtr(ptr) {}
    ~PassengerPlaneWrapper() { delete passengerPlanePtr; }
    PassengerPlane* passengerPlanePtr = nullptr;
};

/*
 new UDT 4:
 with 2 member functions
 */
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

struct AirportWrapper
{
    AirportWrapper(Airport* ptr) : airportPtr(ptr) {}
    ~AirportWrapper() { delete airportPtr; }
    Airport* airportPtr = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */
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

struct VacationResortWrapper
{
    VacationResortWrapper(VacationResort* ptr) : vacationResortPtr(ptr) {}
    ~VacationResortWrapper() { delete vacationResortPtr; }
    VacationResort* vacationResortPtr = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "UDT #1-1: Hotel" << std::endl;
    HotelWrapper daysInn( new Hotel() );
    int tLugages = daysInn.hotelPtr->storeLugages(2);
    std::cout << "Stored " << tLugages << " lugages." << std::endl;
    int tCustomers = daysInn.hotelPtr->hostCustomers(6);
    std::cout << "Hosted " << tCustomers << " customers." << std::endl;
    daysInn.hotelPtr->providLaundryServices(8);
    daysInn.hotelPtr->numberOfCafes = 5;
    std::cout << "There are " << daysInn.hotelPtr->numberOfCafes << " cafes in this hotel." << std::endl;
    daysInn.hotelPtr->printNumberOfCafes();
    daysInn.hotelPtr->printRoomRatePerNight();
    int roomsBooked = daysInn.hotelPtr->reserveRooms(31);
    std::cout << "Booked " << roomsBooked << " rooms." << std::endl;
    std::cout << std::endl;

    std::cout << "UDT #1-2: Front Desk within a Hotel" << std::endl;
    Hotel::FrontDesk daysInnFrontDesk;
    daysInnFrontDesk.checkCustomersIn(2);
    daysInnFrontDesk.takeServiceRequests("Spa");
    daysInnFrontDesk.printBills(6);
    daysInnFrontDesk.numberOfPrinters = 8;
    std::cout << "There are " << daysInnFrontDesk.numberOfPrinters << " printers in this hotel." << std::endl;
    daysInnFrontDesk.printNumberOfPrinters();
    daysInnFrontDesk.printNumberOfReceptionists();
    bool isCalling = daysInnFrontDesk.coordinateCalls(4);
    std::cout << "Is the Front Desk Taking Phone Calls? " << (isCalling == true ? "Yes." : "No.") << std::endl;
    std::cout << std::endl;

    std::cout << "UDT #2-1: Laptop" << std::endl;
    LaptopWrapper macBookPro( new Laptop() );
    int numberOfColorCodes = macBookPro.LaptopPtr->displayImage("juce.jpg");
    std::cout << "The file displayed has " << numberOfColorCodes << " different hex colors." << std::endl;
    macBookPro.LaptopPtr->playAudio("Suspended Animation.mp3");
    macBookPro.LaptopPtr->storeData("main.cpp");
    macBookPro.LaptopPtr->printSizeOfScreenInInch();
    macBookPro.LaptopPtr->formatDisk(10);
    std::cout << "This laptop has a RAM of " << macBookPro.LaptopPtr->sizeOfRamInGb << " GB." << std::endl;
    macBookPro.LaptopPtr->printSizeOfRamInGb();
    std::cout << std::endl;

    std::cout << "UDT #2-2: Display of a Laptop" << std::endl;
    Laptop::Display macBookProRetinaDisplay;
    macBookProRetinaDisplay.displayColor("000000");
    macBookProRetinaDisplay.adjustBrightness(70);
    macBookProRetinaDisplay.adjustClarity(50);
    macBookProRetinaDisplay.numberOfPixles = 1000000000;
    std::cout << "The Laptop has display with " << macBookProRetinaDisplay.numberOfPixles << " pixles." << std::endl;
    macBookProRetinaDisplay.printNumberOfPixles();
    macBookProRetinaDisplay.printElectricPowerConsumedPerYearInWatts(); 
    double totalElectricityConsumed = macBookProRetinaDisplay.consumeElectricity(5, 80);
    std::cout << "Consumed " << totalElectricityConsumed << " Watts of electricity." << std::endl;
    std::cout << std::endl;

    std::cout << "UDT #3: Passenger Plane" << std::endl;
    PassengerPlaneWrapper boeing737( new PassengerPlane() );
    boeing737.passengerPlanePtr->carryPassengers(300);
    boeing737.passengerPlanePtr->provideMultimediaEntertainment("Movies");
    boeing737.passengerPlanePtr->flyAboveTheClouds("New York", "San Francisco");
    boeing737.passengerPlanePtr->numberOfSeats = 31;
    std::cout << "This plane has " << boeing737.passengerPlanePtr->numberOfSeats << " seats." << std::endl;
    boeing737.passengerPlanePtr->printNumberOfSeats();
    boeing737.passengerPlanePtr->printNumberOfSeatsOnPlane();
    int numberOfLoopsToFullyUnload = boeing737.passengerPlanePtr->numberOfLoopsToUnloadAllPassengers(6);
    std::cout << "It will take " << numberOfLoopsToFullyUnload << " loops to fully unload all passengers from the plane." << std::endl;
    std::cout << std::endl; 

    std::cout << "UDT #4: Airport" << std::endl;
    AirportWrapper airportA( new Airport() );
    std::string parkingZone = airportA.airportPtr->parkAirplane(100, 200);
    std::cout << "Please park at the " << parkingZone << "." << std::endl;
    int diskSpaceRemainingInGB = airportA.airportPtr->saveFlightData(50, 8);
    std::cout << "Disk space remaining: " << diskSpaceRemainingInGB << " GB." << std::endl;
    std::cout << "There are " << airportA.airportPtr->airplaneA.numberOfDoors << " doors on the plane A in this airport." << std::endl;
    airportA.airportPtr->printNumberOfDoorsOnPlane();
    std::cout << std::endl;

    std::cout << "UDT #5: Vacation Resort" << std::endl;
    VacationResortWrapper vacationResortA( new VacationResort() );
    vacationResortA.vacationResortPtr->provideFood(5);
    int numberOfTransactionsPerSecond = vacationResortA.vacationResortPtr->processTransactions("Quad-Core Intel Core i5", 8);
    std::cout << "The number of transactions the computer of the resort can handle per second: " << numberOfTransactionsPerSecond << "." << std::endl;
    std::cout << "There are " << vacationResortA.vacationResortPtr->hotelA.numberOfElevators << " elevators in the hotel of this vacation resort." << std::endl;
    vacationResortA.vacationResortPtr->printNumberOfElevatorsInHotel();
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
