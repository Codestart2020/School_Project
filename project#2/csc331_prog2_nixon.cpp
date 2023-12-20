//
// Created by jemon nixon on 10/7/23.
//
#include "partList.h"
#include <iostream>
#include <string>
using namespace std;





int main(){

    // create a partList object
    partList List;

    // create a string variable to hold the user input
    string input;
    int qty;


    // switch statement to handle the user input
    char choice;


    // do while loop to keep the program running until the user enters q

    do {
        cout << "Enter a to add a part, r to remove a part, l to list all parts, or q to quit: ";
        cin >> choice;
        switch (choice) {
            case 'a':
                cout << "Enter a part ID and quantity: ";
                cin >> input >> qty;

                List.add(input, qty);
                break;
            case 'r':
                cout << "Enter a part ID and quantity: ";
                cin >> input >> qty;
                List.remove(input, qty);
                break;
            case 'l':
                List.list();
                break;
            case 'q':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    } while (choice != 'q');



}