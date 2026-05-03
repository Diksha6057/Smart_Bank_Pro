#ifndef BANK_UTILITIES_H
#define BANK_UTILITIES_H

#include <iostream>

using namespace std;

template <typename T>
class BankUtilities
{
public:

    T calculateSimpleInterest(
        T principalAmount,
        T interestRate,
        T numberOfYears)
    {
        return (principalAmount * interestRate * numberOfYears) / 100;
    }

    T addAmounts(T firstValue, T secondValue)
    {
        return firstValue + secondValue;
    }

    void displayResult(T result)
    {
        cout << "Calculated Result: "
             << result
             << endl;
    }
};

#endif
