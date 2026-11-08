#include "pch.h"
#include "Payment.h"
#include <iostream>
#include <sstream>

Payment::Payment()
{
    this->lastName = "";
    this->firstName = "";
    this->middleName = "";
    this->salary = 0.0;
    this->taxPercent = 13.0;
    this->startYear = 0;
    this->bonusPercent = 0.0;
    this->workedDays = 0;
    this->totalWorkingDays = 1;
    this->accruedAmount = 0.0;
    this->withheldAmount = 0.0;
}

Payment::Payment(std::string lastName, std::string firstName, std::string middleName, double salary, int startYear, double bonusPercent, int workedDays, int totalWorkingDays, double taxPercent)
{
    this->Init(lastName, firstName, middleName, salary, startYear, bonusPercent, workedDays, totalWorkingDays, taxPercent);
}

Payment::Payment(const Payment& p)
{
    this->lastName = p.lastName;
    this->firstName = p.firstName;
    this->middleName = p.middleName;
    this->salary = p.salary;
    this->bonusPercent = p.bonusPercent;
    this->taxPercent = p.taxPercent;
    this->startYear = p.startYear;
    this->workedDays = p.workedDays;
    this->totalWorkingDays = p.totalWorkingDays;
    this->accruedAmount = p.accruedAmount;
    this->withheldAmount = p.withheldAmount;
}

void Payment::Init(std::string lastName, std::string firstName, std::string middleName, double salary, int startYear, double bonusPercent, int workedDays, int totalWorkingDays, double taxPercent)
{
    this->lastName = lastName;
    this->firstName = firstName;
    this->middleName = middleName;
    this->salary = salary;
    this->startYear = startYear;
    this->bonusPercent = bonusPercent;
    this->workedDays = workedDays;
    this->totalWorkingDays = (totalWorkingDays > 0) ? totalWorkingDays : 1;
    this->taxPercent = taxPercent;

    this->CalculateAccrued();
    this->CalculateWithheld();
}

void Payment::Read()
{
    std::cout << "Введіть прізвище: "; std::cin >> this->lastName;
    std::cout << "Введіть ім'я: "; std::cin >> this->firstName;
    std::cout << "Введіть по батькові: "; std::cin >> this->middleName;
    std::cout << "Введіть оклад: "; std::cin >> this->salary;
    std::cout << "Введіть рік вступу на роботу: "; std::cin >> this->startYear;
    std::cout << "Введіть відсоток надбавки: "; std::cin >> this->bonusPercent;
    std::cout << "Введіть кількість відпрацьованих днів: "; std::cin >> this->workedDays;
    std::cout << "Введіть кількість робочих днів у місяці: "; std::cin >> this->totalWorkingDays;

    if (this->totalWorkingDays <= 0)
    {
        this->totalWorkingDays = 1;
    }
    this->taxPercent = 13.0;

    this->CalculateAccrued();
    this->CalculateWithheld();
}

double Payment::CalculateAccrued()
{
    double baseEarned = (this->salary / this->totalWorkingDays) * this->workedDays;
    double bonusAmount = baseEarned * (this->bonusPercent / 100.0);
    this->accruedAmount = baseEarned + bonusAmount;
    return this->accruedAmount;
}

double Payment::CalculateWithheld()
{
    this->CalculateAccrued();
    double pension = this->accruedAmount * 0.01;
    double tax = this->accruedAmount * (this->taxPercent / 100.0);
    this->withheldAmount = pension + tax;
    return this->withheldAmount;
}

double Payment::CalculateNetSalary()
{
    return this->CalculateAccrued() - this->CalculateWithheld();
}

int Payment::CalculateExperience(int currentYear) const
{
    return (currentYear >= this->startYear) ? (currentYear - this->startYear) : 0;
}

std::string Payment::toString() const
{
    std::ostringstream ss;
    
    ss << "Працівник: " << this->lastName << " " << this->firstName << " " << this->middleName << "\n";
    ss << "Оклад: " << this->salary << " грн\n";
    ss << "Прибутковий податок: " << this->taxPercent << "%\n";
    ss << "Рік вступу: " << this->startYear << "\n";
    ss << "Стаж: " << this->CalculateExperience(2026) << " років\n";
    ss << "Відсоток надбавки: " << this->bonusPercent << "%\n";
    ss << "Відпрацьовано днів: " << this->workedDays << " з " << this->totalWorkingDays << "\n";
    ss << "Нарахована сума: " << this->accruedAmount << " грн\n";
    ss << "Утримана сума: " << this->withheldAmount << " грн\n";
    ss << "Сума до виплати: " << (this->accruedAmount - this->withheldAmount) << " грн\n";
    return ss.str();
}

void Payment::Display() const
{
    std::cout << this->toString();
}

Payment::~Payment()
{
}