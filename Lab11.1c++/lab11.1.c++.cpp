#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


bool findThirdDot(const string& filename, int& lineIndex, int& charIndex) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return false;
    }

    string line;
    int dotCount = 0;
    int currentLineIndex = 1;


    while (getline(file, line)) {
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '.') {
                dotCount++;
                if (dotCount == 3) {
                    lineIndex = currentLineIndex;
                    charIndex = static_cast<int>(i + 1);
                    file.close();
                    return true;
                }
            }
        }
        currentLineIndex++;
    }

    file.close();
    return false;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "t.txt";
    int lineIndex = 0, charIndex = 0;

    if (findThirdDot(filename, lineIndex, charIndex)) {
        cout << "Третя крапка знайдена у файлі " << filename << ":" << endl;
        cout << "Рядок: " << lineIndex << ", позиція: " << charIndex << endl;
    }
    else {
        cout << "Третя крапка у файлі " << filename << " не знайдена." << endl;
    }

    return 0;
}

