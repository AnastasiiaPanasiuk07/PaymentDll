#include <iostream>
#include <Windows.h>
#include "Payment.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Перевірка динамічної бібліотеки (Dll)\n";

    Payment a;
    a.Display();

    Payment b("Пертенко", "Тарас", "Вікторович", 20000, 2018, 15.0, 20, 22);
    b.Display();

    Payment c = b;
    cout << "\nВиведення скопійованого об'єкта c:\n";
    c.Display();

    string resultText = b.toString();
    cout << "\nОтримано:\n" << resultText;

    system("pause");
    return 0;
}