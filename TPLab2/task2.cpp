#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <windows.h>
using namespace std;

// Проверка, начинается ли слово с гласной буквы (английской)
bool startsWithVowel(const string& word) {
    if (word.empty()) return false;
    char c = tolower(word[0]);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main2() {
    // Устанавливаем кодировку консоли для корректного вывода английских символов
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string filename;
    cout << "Enter the file name to read (for example, text.txt): ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: failed to open the file!\n";
        return 1;
    }

    cout << "\nWords that start with a vowel:\n";

    string line, word;
    while (getline(file, line)) {
        stringstream ss(line);
        while (ss >> word) {
            // Удалим пунктуацию в начале/конце слова
            while (!word.empty() && ispunct(word.front()))
                word.erase(word.begin());
            while (!word.empty() && ispunct(word.back()))
                word.pop_back();

            if (startsWithVowel(word))
                cout << word << "\n";
        }
    }

    file.close();
    cout << "\nProcessing completed.\n";
    return 0;
}
