#include "AeroflotArray.h"

// Функция для вывода меню программы
void menu() {
    cout << "\n===== PROGRAM MENU =====\n";
    cout << "1. Add a flight\n";
    cout << "2. Delete a flight\n";
    cout << "3. Edit a flight\n";
    cout << "4. Show all flights\n";
    cout << "5. Sort flights by number\n";
    cout << "6. Find flights by destination\n";
    cout << "0. Exit\n";
    cout << "========================\n";
    cout << "Enter your choice: ";
}

int main() {
    setlocale(LC_ALL, "English");

    AeroflotArray list;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
            case 1: {
                AEROFLOT newFlight;
                cin >> newFlight;
                int pos;
                cout << "Enter the position to insert (0 - at the beginning, "
                    << list.getSize() << " - at the end): ";
                cin >> pos;
                list.addFlight(newFlight, pos);
                break;
            }
            case 2: {
                int pos;
                cout << "Enter the number of the flight to delete (starting from 1): ";
                cin >> pos;
                list.deleteFlight(pos - 1);
                break;
            }
            case 3: {
                int pos;
                cout << "Enter the number of the flight to edit (starting from 1): ";
                cin >> pos;
                list.editFlight(pos - 1);
                break;
            }
            case 4:
                list.showAll();
                break;
            case 5:
                list.sortByNumber();
                break;
            case 6: {
                string dest;
                cout << "Enter the destination to search for: ";
                getline(cin >> ws, dest);
                list.findByDestination(dest);
                break;
            }
            case 0:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid menu option!\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}
