//
// Created by Jemon Nixon on 8/30/23.
//  CSC 311 - 501L[38867]
// Due 9-21-2023



#include <iostream>
#include "personType.h"
using namespace std;


int main()
{
    // create personType objects
    personType person1("Jemon", "Nixon");

    // print person1
    cout << "Student: ";
    person1.print();


    return 0;

}