//Lab10-2.cpp - displays total owed
//Created/revised by Matthew Dasch on 11/14/2024

#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void displayOptions();
void getRegular(int ordered,double price,double &totalOwed);
void getBOGO(int ordered,double price,double &totalOwed);

int main()
{   int option = 0;
    int ordered = 0;
    double price = 0.0;
    double totalOwed = 0.0;

    cout << fixed << setprecision(2);
    displayOptions();
    cout << "Enter option: "<<endl;
    cin >> option;
    cout << "Enter number ordered: "<<endl;
    cin >> ordered;
    cout << "Enter price: "<<endl;
    cin >> price;
 
    if (option == 1){
        getRegular(ordered,price,totalOwed);
    }
    else if (option == 2){
        getBOGO(ordered,price,totalOwed);
    }
    else{
        cout << "Invalid option" << endl;
    }
    cout << "Total owed: $" << totalOwed << endl;
 
 
    return 0;
} //end of main function

void displayOptions(){
    cout << "1. Regular" << endl;
    cout << "2. BOGO" << endl;
}
void getRegular(int ordered,double price,double &totalOwed){
    totalOwed=ordered*price;
}
void getBOGO(int ordered,double price,double &totalOwed){
    totalOwed=((ordered/2)+ordered%2)*price;
}
