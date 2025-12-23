#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>
using namespace std;

class AEROFLOT {
private:
    string destination;    // Пункт назначения
    int flightNumber;      // Номер рейса
    string airplaneType;   // Тип самолета

public:
    // --- Конструкторы ---
    AEROFLOT();  // Конструктор по умолчанию
    AEROFLOT(string dest, int num, string type);  // С параметрами
    AEROFLOT(const AEROFLOT& other);  // Конструктор копирования
    ~AEROFLOT(); // Деструктор

    // --- Методы доступа ---
    void setDestination(string dest);
    string getDestination() const;

    void setFlightNumber(int num);
    int getFlightNumber() const;

    void setAirplaneType(string type);
    string getAirplaneType() const;

    // --- Перегрузка операторов ввода/вывода ---
    friend istream& operator>>(istream& in, AEROFLOT& obj);
    friend ostream& operator<<(ostream& out, const AEROFLOT& obj);
};

#endif
