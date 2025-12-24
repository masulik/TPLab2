#ifndef AEROFLOTARRAY_H
#define AEROFLOTARRAY_H

#include "AEROFLOT.h"

class AeroflotArray {
private:
    AEROFLOT* flights;  // динамический массив рейсов
    int size;           // текущее количество элементов

public:
    AeroflotArray();
    ~AeroflotArray();

    void addFlight(const AEROFLOT& flight, int position); // добавление в любую позицию
    void deleteFlight(int position);                      // удаление по индексу
    void editFlight(int position);                        // редактирование
    void showAll() const;                                 // показать все рейсы
    void sortByNumber();                                  // сортировка по номеру рейса
    void findByDestination(const string& dest) const;     // поиск по пункту назначения
    int getSize() const;                                  // получить размер массива
};

#endif
