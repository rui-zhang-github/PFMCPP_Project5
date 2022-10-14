/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
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

    int storeLugages(int numberOfLugages = 1); 
    int hostCustomers(int numberOfCustomers = 1); 
    void providLaundryServices(int numberOfClothes = 1);
    void printRoomRatePerNight();
    int reserveRooms(int numberOfRoomsNeeded);
    void printNumberOfCafes();

    struct FrontDesk
    {
        FrontDesk();
        ~FrontDesk();
        int numberOfCounters = 1;
        int numberOfComputers { 1 };
        int numberOfPrinters;
        int numberOfTelephones = 3;
        int numberOfReceptionists { 2 };

        void checkCustomersIn(int numberOfCustomers = 1);
        void takeServiceRequests(std::string typeOfServices);
        void printBills(int numberOfBillsToPrint = 1);
        void printNumberOfReceptionists();
        bool coordinateCalls(unsigned int numberOfIncomingCalls);
        void printNumberOfPrinters();
    };
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

int Hotel::storeLugages(int numberOfLugages)
{
    totalNumberOfLugages += numberOfLugages;
    std::cout << "After adding "  << numberOfLugages << " lugages, the hotel is storing a total of " << totalNumberOfLugages <<  " lugages."  << std::endl;
    return totalNumberOfLugages;
}

int Hotel::hostCustomers(int numberOfCustomers)
{
    totalNumberOfCustomersStayingTonight += numberOfCustomers;
    std::cout << "After checking in "  << numberOfCustomers << " new guest(s), the hotel now has a total number of " << totalNumberOfCustomersStayingTonight <<  " guest(s) staying." << std::endl;
    return totalNumberOfCustomersStayingTonight;
}

void Hotel::providLaundryServices(int numberOfClothes)
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

void Hotel::printRoomRatePerNight()
{
    std::cout << "Tonight's room rate is $" << roomRatePerNight << "." <<  std::endl;
}

int Hotel::reserveRooms(int numberOfRoomsNeeded)
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

void Hotel::printNumberOfCafes()
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

void Hotel::FrontDesk::checkCustomersIn(int numberOfCustomers)
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

void Hotel::FrontDesk::takeServiceRequests(std::string typeOfServices)
{
    std::cout << typeOfServices << " service request has been taken." << std::endl; 
}

void Hotel::FrontDesk::printBills(int numberOfBillsToPrint)
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

void Hotel::FrontDesk::printNumberOfReceptionists()
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

bool Hotel::FrontDesk::coordinateCalls(unsigned int numberOfIncomingCalls)
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

void Hotel::FrontDesk::printNumberOfPrinters()
{
    std::cout << "There are " << this->numberOfPrinters << " printers in this hotel." << std::endl;
}

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

    int displayImage(std::string fileName); 
    void playAudio(std::string fileName);
    void storeData(std::string fileName);
    void printSizeOfScreenInInch();
    void formatDisk(unsigned int percentageOfTotalDiskSpaceNeededToBeFreedUp);
    void printSizeOfRamInGb();

    struct Display
    {
        Display();
        ~Display();
        double electricPowerConsumedPerYearInWatts = 1.0;
        int numberOfPixles { 1 };
        std::string colorProfile;
        float lengthInCm { 1.0f };
        float WidthInCm;

        void displayColor(std::string hexColorCode = "FF5733");
        void adjustBrightness(int brightnessInPercentage = 50);
        void adjustClarity(float clarityInPercentage = 100);
        void printElectricPowerConsumedPerYearInWatts();
        double consumeElectricity(int numberOfYears, int brightnessInPercentage);
        void printNumberOfPixles();
    };
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

int Laptop::displayImage(std::string fileName)
{
    std::cout << "Now displaying: " << fileName << std::endl;
    int numberOfDifferentHexColorCodes = 0;
    return numberOfDifferentHexColorCodes;
}

void Laptop::playAudio(std::string fileName)
{
    std::cout << "Now playing: " << fileName << std::endl;
}

void Laptop::storeData(std::string fileName)
{
    std::cout << fileName << " has been stored the hard drive." << std::endl;
}

void Laptop::printSizeOfScreenInInch()
{
    std::cout << "This is a " << sizeOfScreenInInch << "in screen."<< std::endl;
}

void Laptop::formatDisk(unsigned int percentageOfTotalDiskSpaceNeededToBeFreedUp)
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

void Laptop::printSizeOfRamInGb()
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

void Laptop::Display::displayColor(std::string hexColorCode)
{
    std::cout << "This is the color of hex code " << hexColorCode << std::endl;
}

void Laptop::Display::adjustBrightness(int brightnessInPercentage)
{
    std::cout << "Current brightness is " << brightnessInPercentage << "%." << std::endl;
}

void Laptop::Display::adjustClarity(float clarityInPercentage)
{
    std::cout << "Current clarity is " << clarityInPercentage << "%." << std::endl;
}

void Laptop::Display::printElectricPowerConsumedPerYearInWatts()
{
    std::cout << "This display consumes " << electricPowerConsumedPerYearInWatts << "W electricity per year."<< std::endl;
}

double Laptop::Display::consumeElectricity(int numberOfYears, int brightnessInPercentage)
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

void Laptop::Display::printNumberOfPixles()
{
    std::cout << "The Laptop has a display with " << this->numberOfPixles << " pixles." << std::endl;
}

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

    void carryPassengers(int numberOfPassengers);
    void provideMultimediaEntertainment(std::string mediaType);
    void flyAboveTheClouds(std::string from, std::string to);
    void printNumberOfSeats();
    int numberOfLoopsToUnloadAllPassengers(int numberOfDoorsOpened);
    void printNumberOfSeatsOnPlane();
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

void PassengerPlane::carryPassengers(int numberOfPassengers)
{
    std::cout << "There are " << numberOfPassengers << " passengers on the plane." << std::endl;
}

void PassengerPlane::provideMultimediaEntertainment(std::string mediaType)
{
    std::cout << "Now playing: " << mediaType << std::endl;
}

void PassengerPlane::flyAboveTheClouds(std::string from, std::string to)
{
    std::cout << "This flight is from " << from << " to " << to << std::endl;
}

void PassengerPlane::printNumberOfSeats()
{
    std::cout << "There are " << numberOfSeats << " seats on the plane." << std::endl;
}

int PassengerPlane::numberOfLoopsToUnloadAllPassengers(int numberOfDoorsOpened)
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

void PassengerPlane::printNumberOfSeatsOnPlane()
{
    std::cout << "This plane has " << this->numberOfSeats << " seats." << std::endl;
}

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

    std::string parkAirplane(int numberOfSeats, double sizeOfThePlane); // return the parking zone name given the number of seats and size of an airplane
    int saveFlightData(int diskSpaceInGb, int fileSizeInGb); // return disk space after saving some flight data of a certain size
    void printNumberOfDoorsOnPlane();
};

Airport::Airport()
{
    std::cout << "Created an airport that includes passenger planes and computers/laptops." << std::endl;
}

Airport::~Airport()
{
    std::cout << "Destroyed an airport that includes passenger planes and computers/laptops." << std::endl;
}

std::string Airport::parkAirplane(int numberOfSeats, double sizeOfThePlane)
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

int Airport::saveFlightData(int diskSpaceInGb, int fileSizeInGb)
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

void Airport::printNumberOfDoorsOnPlane()
{
    std::cout << "There are " << this->airplaneA.numberOfDoors << " doors on the plane A in this airport." << std::endl;
}

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

    void provideFood(int numberOfCafeInHotel); // print number of people that the resort can provide food to
    int processTransactions(std::string CPU, int sizeOfRamInGb); // return the number of transactions that resort can process in a second with the CPU and size of RAM of the PC.
    void printNumberOfElevatorsInHotel();
};

VacationResort::VacationResort()
{
    std::cout << "Created a vacation resort that includes hotels and computers/laptops." << std::endl;
}

VacationResort::~VacationResort()
{
    std::cout << "Destroyed a vacation resort that includes hotels and computers/laptops." << std::endl;
}

void VacationResort::provideFood(int numberOfCafeInHotel)
{
    hotelA.numberOfCafes = numberOfCafeInHotel;
    std::cout << "The vacation resort can provide food to " << hotelA.numberOfCafes * 100 << " people per hour." << std::endl;
}

int VacationResort::processTransactions(std::string CPU, int sizeOfRamInGb)
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

void VacationResort::printNumberOfElevatorsInHotel()
{
    std::cout << "There are " << this->hotelA.numberOfElevators << " elevators in the hotel of this vacation resort." << std::endl;
}

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
    Hotel daysInn;
    int tLugages = daysInn.storeLugages(2);
    std::cout << "Stored " << tLugages << " lugages." << std::endl;
    int tCustomers = daysInn.hostCustomers(6);
    std::cout << "Hosted " << tCustomers << " customers." << std::endl;
    daysInn.providLaundryServices(8);
    daysInn.numberOfCafes = 5;
    std::cout << "There are " << daysInn.numberOfCafes << " cafes in this hotel." << std::endl;
    daysInn.printNumberOfCafes();
    daysInn.printRoomRatePerNight();
    int roomsBooked = daysInn.reserveRooms(31);
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
    Laptop macBookPro;
    int numberOfColorCodes = macBookPro.displayImage("juce.jpg");
    std::cout << "The file displayed has " << numberOfColorCodes << " different hex colors." << std::endl;
    macBookPro.playAudio("Suspended Animation.mp3");
    macBookPro.storeData("main.cpp");
    macBookPro.printSizeOfScreenInInch();
    macBookPro.formatDisk(10);
    std::cout << "This laptop has a RAM of " << macBookPro.sizeOfRamInGb << " GB." << std::endl;
    macBookPro.printSizeOfRamInGb();
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
    PassengerPlane boeing737;
    boeing737.carryPassengers(300);
    boeing737.provideMultimediaEntertainment("Movies");
    boeing737.flyAboveTheClouds("New York", "San Francisco");
    boeing737.numberOfSeats = 31;
    std::cout << "This plane has " << boeing737.numberOfSeats << " seats." << std::endl;
    boeing737.printNumberOfSeats();
    boeing737.printNumberOfSeatsOnPlane();
    int numberOfLoopsToFullyUnload = boeing737.numberOfLoopsToUnloadAllPassengers(6);
    std::cout << "It will take " << numberOfLoopsToFullyUnload << " loops to fully unload all passengers from the plane." << std::endl;
    std::cout << std::endl; 

    std::cout << "UDT #4: Airport" << std::endl;
    Airport airportA;
    std::string parkingZone = airportA.parkAirplane(100, 200);
    std::cout << "Please park at the " << parkingZone << "." << std::endl;
    int diskSpaceRemainingInGB = airportA.saveFlightData(50, 8);
    std::cout << "Disk space remaining: " << diskSpaceRemainingInGB << " GB." << std::endl;
    std::cout << "There are " << airportA.airplaneA.numberOfDoors << " doors on the plane A in this airport." << std::endl;
    airportA.printNumberOfDoorsOnPlane();
    std::cout << std::endl;

    std::cout << "UDT #5: Vacation Resort" << std::endl;
    VacationResort vacationResortA;
    vacationResortA.provideFood(5);
    int numberOfTransactionsPerSecond = vacationResortA.processTransactions("Quad-Core Intel Core i5", 8);
    std::cout << "The number of transactions the computer of the resort can handle per second: " << numberOfTransactionsPerSecond << "." << std::endl;
    std::cout << "There are " << vacationResortA.hotelA.numberOfElevators << " elevators in the hotel of this vacation resort." << std::endl;
    vacationResortA.printNumberOfElevatorsInHotel();
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
