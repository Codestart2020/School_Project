//
// Created by jemon nixon on 10/24/23.
// This program evaluates expressions in post-fix notation
// csc 331 501l[38867]
// Due  11-7-2023

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    stack<double> s;
    string input;
    double op1, op2, result;
    char op;
    cout << "Please enter an expression in post-fix notation " << endl;
    while (cin >> input) {
        if (input == "end-of-file") {
            break;
        }
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i])) {
                s.push(input[i] - '0');
            } else {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                op = input[i];

                // switch statement to evaluate the expression
                switch (op) {
                    case '+':
                        result = op1 + op2;
                        break;
                    case '-':
                        result = op1 - op2;
                        break;
                    case '*':
                        result = op1 * op2;
                        break;
                    case '/':
                        if (op2 == 0) {
                            cout << "error: division by zero" << endl;
                            break;
                        }
                        result = op1 / op2;
                        break;
                    case '%':
                        if (op2 != (int)op2 || op1 != (int)op1) {
                            cout << "error: non-integer operand for %" << endl;
                            break;
                        }
                        result = (int)op1 % (int)op2;
                        break;
                    case '^':
                        result = pow(op1, op2);
                        break;
                }
                s.push(result);
            }
        }
        cout << "Result: " << s.top() << endl;
        s.pop();
        cout << "Please enter an expression in post-fix notation " << endl;
    }

    return 0;
}
