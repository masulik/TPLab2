#include "AEROFLOT.h"

// Конструктор по умолчанию
AEROFLOT::AEROFLOT() {
    destination = "Unknown";
    flightNumber = 0;
    airplaneType = "Unknown";
    cout << "Default constructor of AEROFLOT called\n";
}

// Конструктор с параметрами
AEROFLOT::AEROFLOT(string dest, int num, string type) {
    destination = dest;
    flightNumber = num;
    airplaneType = type;
    cout << "Parameterized constructor of AEROFLOT called\n";
}

// Конструктор копирования
AEROFLOT::AEROFLOT(const AEROFLOT& other) {
    destination = other.destination;
    flightNumber = other.flightNumber;
    airplaneType = other.airplaneType;
    cout << "Copy constructor of AEROFLOT called\n";
}

// Деструктор
AEROFLOT::~AEROFLOT() {
    cout << "Destructor of AEROFLOT called\n";
}

// --- Методы доступа ---
void AEROFLOT::setDestination(string dest) { destination = dest; }
string AEROFLOT::getDestination() const { return destination; }

void AEROFLOT::setFlightNumber(int num) { flightNumber = num; }
int AEROFLOT::getFlightNumber() const { return flightNumber; }

void AEROFLOT::setAirplaneType(string type) { airplaneType = type; }
string AEROFLOT::getAirplaneType() const { return airplaneType; }

// --- Перегрузка операторов ---
istream& operator>>(istream& in, AEROFLOT& obj) {
    cout << "Enter destination: ";
    getline(in >> ws, obj.destination);
    cout << "Enter flight number: ";
    in >> obj.flightNumber;
    in.ignore();
    cout << "Enter airplane type: ";
    getline(in, obj.airplaneType);
    return in;
}

ostream& operator<<(ostream& out, const AEROFLOT& obj) {
    out << "Destination: " << obj.destination << "\n";
    out << "Flight number: " << obj.flightNumber << "\n";
    out << "Airplane type: " << obj.airplaneType << "\n";
    return out;
}
