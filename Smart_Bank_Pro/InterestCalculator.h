#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H

#include <iostream>
using namespace std;

class InterestCalculator {
public:
    static double simpleInterest(double principal, double rate, int years);
    static double compoundInterest(double principal, double rate, int years);
    static void displaySimpleInterest(double principal, double rate, int years);
    static void displayCompoundInterest(double principal, double rate, int years);
};

#endif