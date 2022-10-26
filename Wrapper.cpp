#pragma once
#include "Wrapper.h"

#include "Hotel.h"
#include "Laptop.h"
#include "PassengerPlane.h"
#include "Airport.h"
#include "VacationResort.h"

HotelWrapper::HotelWrapper(Hotel* ptr) : hotelPtr(ptr) {}

HotelWrapper::~HotelWrapper() { delete hotelPtr; }

LaptopWrapper::LaptopWrapper(Laptop* ptr) : laptopPtr(ptr) {}

LaptopWrapper::~LaptopWrapper() { delete laptopPtr; }

PassengerPlaneWrapper::PassengerPlaneWrapper(PassengerPlane* ptr) : passengerPlanePtr(ptr) {}

PassengerPlaneWrapper::~PassengerPlaneWrapper() { delete passengerPlanePtr; }

AirportWrapper::AirportWrapper(Airport* ptr) : airportPtr(ptr)  {}

AirportWrapper::~AirportWrapper() { delete airportPtr; }

VacationResortWrapper::VacationResortWrapper(VacationResort* ptr) : vacationResortPtr(ptr) {}

VacationResortWrapper::~VacationResortWrapper() { delete vacationResortPtr; }
