//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by Matthew Dasch on 11/14/2024

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getCreditPayment(double carPrice,double rebate,double creditRate,int term)
{
    carPrice=carPrice-rebate;
    double creditPayment= carPrice * (creditRate/12)/(1-pow(1+(creditRate/12),-(term*12)));
    return creditPayment;
}
double getDealerPayment(double carPrice,double dealerRate,int term){
    double dealerPayment=carPrice*(dealerRate/12)/(1-pow(1+(dealerRate/12),-(term*12)));
    return dealerPayment;
}

int main()
{
    double carPrice = 0.0;
    double rebate = 0.0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;

    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): "<<endl;
    cin >> carPrice;
    cout << "Rebate: "<<endl;
    cin >> rebate;
    cout << "Credit union rate: "<<endl;
    cin >> creditRate;
    cout << "Dealer rate: "<<endl;
    cin >> dealerRate;
    cout << "Term in years: "<<endl;
    cin >> term;

    creditPayment = getCreditPayment(carPrice,rebate,creditRate,term);
    dealerPayment = getDealerPayment(carPrice,dealerRate,term);

    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment<<endl;
    cout << "Dealer payment: $" << dealerPayment << endl;

    return 0;
}//end of main function    