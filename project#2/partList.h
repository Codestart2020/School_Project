//
// Created by jemon nixon on 10/7/23.
// Date due 10/19/23.
// course CSC 331 501L[38867]
// linked list program

#ifndef PROJECT_2_PARTLIST_H
#define PROJECT_2_PARTLIST_H
#include <iostream>
#include <string>
using namespace std;
class partList{
public:
    void add(string partID, int qty);
    //Function to insert part ID and/or quantity at the end of the list.
    bool exists(string partID);
    //Function to determine whether or not part ID is on the list.
    void list() const;
    //Function to output a numbered list of part ID and quantity, one part ID per line
    void remove(string partID, int qty);
    //Function to reduce the qty for a part ID on the list.
    partList();
    //Default constructor
    //Sets start and last pointers to null.
private:
    struct partType{
        string partID_pt;
        int qty_pt;
        partType *next_pt;
    };
    partType *first,*last;
};
void partList::add(string partID, int qty) {

    if(!exists(partID)) {


        if (qty > 100) {
            cout << "transaction not processed due to excessive quantity" << endl;
            return;
        }



        // create a new node
        partType *newNode = new partType;
        newNode->partID_pt = partID;
        newNode->qty_pt = qty;
        newNode->next_pt = NULL;

          // if list is empty, make first and last point to the new node
        if (first == NULL) {
            first = last = newNode;
        } else {
            last->next_pt = newNode;
            last = newNode;
        }
        cout << "transaction processed" << endl;
    }else
    {
        partType *current = first;
        while(current != NULL)
        {
            if(current->partID_pt == partID)
            {
                if(current->qty_pt + qty > 100)
                {
                    cout << "transaction not processed due to excessive quantity" << endl;
                }
                else
                {
                    current->qty_pt += qty;
                    cout << "transaction processed" << endl;
                }
            }
            current = current->next_pt;
        }
        return;
    }
}


bool partList::exists(string partID) {
    partType *current=first;
    while(current != NULL){
        if(current->partID_pt == partID)
            return true;
        current=current->next_pt;
    }
    return false;

}
void partList::list() const {
    if(first == NULL)
        cout << "list is empty" << endl;
    else {
        partType *current=first;
        int i=0;
        while(current != NULL){
            i++;
            cout << i << ". " << current->partID_pt << " " << current->qty_pt << endl;
            current=current->next_pt;
        }
    }
}
partList::partList() {
    first=last=NULL;
}
void partList::remove(string partID, int qty) {

    // first check if the part ID exists if it doesn't exist then print a message saying that the part ID doesn't exist.

    if(!exists(partID))
    {
        cout << "transaction not processed due to invalid part ID" << endl;
    }
    else
    {

        partType *current = first;
        while(current != NULL)
        {
            if(current->partID_pt == partID)
            {
                if(current->qty_pt - qty < -100)
                {
                    cout << "transaction not processed due to excessive backorder" << endl;
                }
                else
                {
                    current->qty_pt -= qty;
                    cout << "transaction processed" << endl;
                }
            }
            current = current->next_pt;
        }
        return;
    }


}

















#endif //PROJECT_2_PARTLIST_H
