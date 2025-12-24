#include "AeroflotArray.h"
#include <stdexcept>

// Конструктор
AeroflotArray::AeroflotArray() {
    flights = nullptr;
    size = 0;
    cout << "Empty flight list created.\n";
}

// Деструктор
AeroflotArray::~AeroflotArray() {
    delete[] flights;
    cout << "Memory for flights released.\n";
}

// Добавление рейса на позицию
void AeroflotArray::addFlight(const AEROFLOT& flight, int position) {
    if (position < 0 || position > size)
        throw invalid_argument("Invalid position for adding!");

    AEROFLOT* newArray = new AEROFLOT[size + 1];

    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == position)
            newArray[i] = flight;
        else
            newArray[i] = flights[j++];
    }

    delete[] flights;
    flights = newArray;
    size++;
    cout << "Flight successfully added!\n";
}

// Удаление рейса по позиции
void AeroflotArray::deleteFlight(int position) {
    if (position < 0 || position >= size)
        throw out_of_range("Invalid position for deletion!");

    if (size == 1) {
        delete[] flights;
        flights = nullptr;
        size = 0;
        cout << "The last flight was deleted.\n";
        return;
    }

    AEROFLOT* newArray = new AEROFLOT[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != position)
            newArray[j++] = flights[i];
    }

    delete[] flights;
    flights = newArray;
    size--;
    cout << "Flight successfully deleted!\n";
}

// Редактирование существующего рейса
void AeroflotArray::editFlight(int position) {
    if (position < 0 || position >= size)
        throw out_of_range("Invalid position for editing!");

    cout << "Editing flight #" << position + 1 << ":\n";
    cin >> flights[position];
}

// Показать все рейсы
void AeroflotArray::showAll() const {
    if (size == 0) {
        cout << "The list is empty.\n";
        return;
    }

    cout << "\nList of all flights:\n";
    for (int i = 0; i < size; i++) {
        cout << "----------------------\n";
        cout << "Flight #" << i + 1 << ":\n";
        cout << flights[i];
    }
    cout << "----------------------\n";
}

// Сортировка по номеру рейса (пузырьковая)
void AeroflotArray::sortByNumber() {
    if (size < 2) return;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (flights[j].getFlightNumber() > flights[j + 1].getFlightNumber()) {
                AEROFLOT temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
        }
    }
    cout << "Sorting completed.\n";
}

// Поиск по пункту назначения
void AeroflotArray::findByDestination(const string& dest) const {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (flights[i].getDestination() == dest) {
            if (!found)
                cout << "\nFlights heading to " << dest << ":\n";
            cout << "Flight number: " << flights[i].getFlightNumber()
                << ", Airplane type: " << flights[i].getAirplaneType() << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "No flights found with destination \"" << dest << "\".\n";
}

// Вернуть количество элементов
int AeroflotArray::getSize() const { return size; }
