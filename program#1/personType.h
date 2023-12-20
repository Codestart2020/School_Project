//
// Created by jemon nixon on 8/30/23.
//

#ifndef PROGRAM_1_PERSONTYPE_H
#define PROGRAM_1_PERSONTYPE_H
#include <iostream>
#include <string>
using namespace std;

class personType {

private:
    // member variables

    string firstName;
    string lastName;

public:

    // default constructor
    personType(){
        firstName = "";
        lastName = "";
    }

    // constructor
    personType(string first, string last){
        firstName = first;
        lastName = last;
    }

    // accessors
    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    // mutators
    void setFirstName(string first){
        firstName = first;
    }

    void setLastName(string last){
        lastName = last;
    }

    // print
    void print() const {
        cout << firstName << " " << lastName << endl;
    }


};




#endif //PROGRAM_1_PERSONTYPE_H
