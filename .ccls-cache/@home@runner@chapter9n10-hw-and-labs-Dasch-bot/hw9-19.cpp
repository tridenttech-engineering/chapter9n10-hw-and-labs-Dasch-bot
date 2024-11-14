//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by Matthew Dasch on 11/14/2024

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
double getTotalPayment(double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCreditPayment = 0.0;
    double totalDealerPayment = 0.0;
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12);    //assign values to calculate payments

    totalCreditPayment = getTotalPayment(creditPayment, term*12);
    totalDealerPayment = getTotalPayment(dealerPayment, term*12);
    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Total credit union payment: $"
        << totalCreditPayment << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;
    cout << "Total dealer payment: $"
        << totalDealerPayment << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    if((1 - pow(monthRate + 1, -months))<=0){
        return -1;
    }
else{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
    return monthPay;
}
} //end of getPayment function//*****function definition*****

double getTotalPayment(double monthPay, int months)
{
    double totalPay = 0.0;
    totalPay = monthPay*months;
    return totalPay;
}