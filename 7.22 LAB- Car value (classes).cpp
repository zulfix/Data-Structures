#ifndef CARH
#define CARH

class Car {
   private:
      int modelYear; 
      double purchasePrice;
      double currentValue;
   
   public:
      void SetModelYear(int userYear);
      int GetModelYear() const;
      void SetPurchasePrice(double price);   
      double GetPurchasePrice() const;
      void CalcCurrentValue(int currentYear);
      void PrintInfo() const;
};

#endif

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Car.h"
using namespace std;

void Car::SetModelYear(int userYear){
   modelYear = userYear;
}

int Car::GetModelYear() const {
   return modelYear;
}

void Car::SetPurchasePrice(double price) {
   purchasePrice = price;
}

double Car::GetPurchasePrice() const {
   return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear) {
   double depreciationRate = 0.15;
   int carAge = currentYear - modelYear;
      
   // Car depreciation formula
   currentValue = purchasePrice * pow((1 - depreciationRate), carAge);
}

void Car::PrintInfo() const {
   cout << "Car's information:" << endl;
   cout << "  Model year: " << modelYear << endl;
   cout << "  Purchase price: $" << purchasePrice << endl;
   cout << "  Current value: $" << fixed << setprecision(0) << currentValue << endl;
}

#include <iostream>
#include "Car.h"
using namespace std;

int main() {
   int userYear;
   int userPrice;
   int userCurrentYear;
   Car myCar;
      
   cin >> userYear;
   cin >> userPrice;
   cin >> userCurrentYear;
      
   myCar.SetModelYear(userYear);
   myCar.SetPurchasePrice(userPrice);
   myCar.CalcCurrentValue(userCurrentYear);
      
   myCar.PrintInfo();
   
   return 0;
}

/*7.22 LAB: Car value (classes)
Given main(), complete the Car class (in files Car.h and Car.cpp) with member functions to set and get the purchase price of a car (SetPurchasePrice(), GetPurchasePrice()), and to output the car's information (PrintInfo()).

Ex: If the input is:

2011
18000
2018
where 2011 is the car's model year, 18000 is the purchase price, and 2018 is the current year, the output is:

Car's information:
  Model year: 2011
  Purchase price: $18000
  Current value: $5770
Notes:

PrintInfo() should use two spaces for indentation.
Add cout << fixed << setprecision(0); right before printing currentValue to ignore cents in the output.
*/