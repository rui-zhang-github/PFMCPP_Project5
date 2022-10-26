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
#include "LeakedObjectDetector.h"
#include "Wrapper.h"
#include "Hotel.h"
#include "Laptop.h"
#include "PassengerPlane.h"
#include "Airport.h"
#include "VacationResort.h"

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
    int numberOfColorCodes = macBookPro.laptopPtr->displayImage("juce.jpg");
    std::cout << "The file displayed has " << numberOfColorCodes << " different hex colors." << std::endl;
    macBookPro.laptopPtr->playAudio("Suspended Animation.mp3");
    macBookPro.laptopPtr->storeData("main.cpp");
    macBookPro.laptopPtr->printSizeOfScreenInInch();
    macBookPro.laptopPtr->formatDisk(10);
    std::cout << "This laptop has a RAM of " << macBookPro.laptopPtr->sizeOfRamInGb << " GB." << std::endl;
    macBookPro.laptopPtr->printSizeOfRamInGb();
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
