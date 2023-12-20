//
// Created by jemon nixon on 11/1/23.
//JEMON NIXON
// CSC 331 501L[38867]
// Project 4
// Due Date: 11/24/23
// Priority queue
// environment : CLion and visual studio code


#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct RepairOrder {
    int priority;
    int ticketNumber;
    string customerName;
};

struct CompareRepairOrder {
    bool operator()(const RepairOrder& order1, const RepairOrder& order2) {
        if (order1.priority == order2.priority) {
            return order1.ticketNumber > order2.ticketNumber;
        }
        return order1.priority > order2.priority;
    }
};

int main() {
    priority_queue < RepairOrder, vector<RepairOrder>, CompareRepairOrder > repairQueue;

    while (true) {
        cout << "Enter transaction:";
        string transaction;
        getline(cin, transaction);


        if (transaction == "end-of-file") {
            cout << "Number of repair orders remaining: " << repairQueue.size() << endl;
            return 0;
        }

        if (transaction == "service") {
            if (repairQueue.empty()) {
                cout << "Error: queue is empty" << endl;
                continue;
            }

            RepairOrder order = repairQueue.top();
            repairQueue.pop();

            cout << "Servicing customer: " << order.customerName << endl;

            continue;
        }

        // Parse new repair order
        int priority = stoi(transaction.substr(0, 1));
        int ticketNumber = stoi(transaction.substr(2, 2));
        string customerName = transaction.substr(5);


        if (ticketNumber < 0) {
            cout << "Error: ticket number cannot be negative" << endl;
            continue;
        }



        if (repairQueue.size() >= 10) {
            cout << "Error: queue is full" << endl;
            break;
        }

        RepairOrder order;
        order.priority = priority;
        order.ticketNumber = ticketNumber;
        order.customerName = customerName;

        repairQueue.push(order);

    }

    return 0;
}

