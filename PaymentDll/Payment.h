#pragma once
#include <iostream>
#include <string>
#include <sstream>

#ifdef PAYMENTDLL_EXPORTS
#define PAYMENTDLL_API __declspec(dllexport)
#else
#define PAYMENTDLL_API __declspec(dllimport)
#endif

class PAYMENTDLL_API Payment
{
private:
    std::string lastName;       // Прізвище
    std::string firstName;      // Ім'я
    std::string middleName;     // По батькові

    double salary = 0.0;        // Оклад
    double bonusPercent = 0.0;  // Відсоток надбавки
    double taxPercent = 13.0;   // Прибутковий податок (13%)

    int startYear = 0;          // Рік вступу на роботу
    int workedDays = 0;         // Відпрацьовано днів
    int totalWorkingDays = 0;   // Всього робочих днів у місяці

    double accruedAmount = 0.0; // Нарахована сума
    double withheldAmount = 0.0;// Утримана сума

public:
    Payment(); // Конструктор за замовчуванням
    Payment(std::string lastName, std::string firstName, std::string middleName, double salary, int startYear, double bonusPercent, int workedDays, int totalWorkingDays, double taxPercent = 13.0);
    Payment(const Payment& p);   // Конструктор копіювання 
    ~Payment(); // Деструктор

    void Init(std::string lastName, std::string firstName, std::string middleName, double salary, int startYear, double bonusPercent, int workedDays, int totalWorkingDays, double taxPercent = 13.0);
    void Read();
    void Display() const;
    std::string toString() const;

    double CalculateAccrued();
    double CalculateWithheld();
    double CalculateNetSalary();
    int CalculateExperience(int currentYear) const;
};
