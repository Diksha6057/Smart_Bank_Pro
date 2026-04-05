#include "InterestCalculator.h"
#include <cmath>

// Simple Interest = (P * R * T) / 100
double InterestCalculator::simpleInterest(double principal, double rate, int years) {
    return (principal * rate * years) / 100;
}

// Compound Interest = P * (1 + R/100)^T - P
double InterestCalculator::compoundInterest(double principal, double rate, int years) {
    return principal * pow((1 + rate / 100), years) - principal;
}

void InterestCalculator::displaySimpleInterest(double principal, double rate, int years) {
    double interest = simpleInterest(principal, rate, years);
    
    cout << "   Simple Interest Calculator   " << endl;
  
    cout << "Principal  : " << principal << endl;
    cout << "Rate       : " << rate << "%" << endl;
    cout << "Years      : " << years << endl;
    cout << "Interest   : " << interest << endl;
    cout << "Total      : " << principal + interest << endl;
   
}

void InterestCalculator::displayCompoundInterest(double principal, double rate, int years) {
    double interest = compoundInterest(principal, rate, years);
   
    cout << "  Compound Interest Calculator  " << endl;
    
    cout << "Principal  : " << principal << endl;
    cout << "Rate       : " << rate << "%" << endl;
    cout << "Years      : " << years << endl;
    cout << "Interest   : " << interest << endl;
    cout << "Total      : " << principal + interest << endl;
   
}