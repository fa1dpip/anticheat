#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Запуск проверки антивирусом... Пожалуйста, дождитесь окончания (примерно 10 секунд)..." << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::vector<std::wstring> cheats = {
        L"nginx",
        L"Копіювати",
        L"Редагувати",
        L"XONE",
        L"Midnight",
        L"Predator.systems",
        L"Nixware",
        L"MemeSense",
        L"Neverlose"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, cheats.size() - 1);
    std::wstring chosen = cheats[dist(gen)];

    system("cls");
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 48;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    std::wcout << chosen << L"\n\n";
    std::wcout << L"У ВАС ОБНАРУЖЕНЫ ЧИТЫ НА КОМПЬЮТЕРЕ" << std::endl;
    std::wcout << L"БАН НА СЕРВЕРЕ" << std::endl;

    PlaySound(TEXT("siren.wav"), NULL, SND_FILENAME | SND_SYNC);
    return 0;
}

// g++ fake_anticheat.cpp -o fake_anticheat.exe -lwinmm
