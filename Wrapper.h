struct Hotel;
struct Laptop;
struct PassengerPlane;
struct Airport;
struct VacationResort;

struct HotelWrapper 
{
    HotelWrapper(Hotel* ptr);
    ~HotelWrapper();
    Hotel* hotelPtr = nullptr;
};

struct LaptopWrapper
{
    LaptopWrapper(Laptop* ptr);
    ~LaptopWrapper();
    Laptop* laptopPtr = nullptr;
};

struct PassengerPlaneWrapper
{
    PassengerPlaneWrapper(PassengerPlane* ptr);
    ~PassengerPlaneWrapper();
    PassengerPlane* passengerPlanePtr = nullptr;
};

struct AirportWrapper
{
    AirportWrapper(Airport* ptr);
    ~AirportWrapper();
    Airport* airportPtr = nullptr;
};

struct VacationResortWrapper
{
    VacationResortWrapper(VacationResort* ptr);
    ~VacationResortWrapper();
    VacationResort* vacationResortPtr = nullptr;
};
