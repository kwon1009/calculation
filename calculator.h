#include <iostream>
#include <vector>
using namespace std;
enum errors { alpha, blank, zero, character, others };

void displayError(errors e) {
    cout << "Error: ";
    switch(e) {
        case alpha:
            cout << "It is Invalid Format." << endl;
            break;
        case blank:
            cout << "Blanks cannot be entered." << endl;
            break;
        case zero:
            cout << "It cannot be divided by zero." << endl;
            break;
        case character:
            cout << "This is not an appropriate operator." << endl;
            break;
        default:
            cout << "It cannot be calculated." << endl;
            break;
    }
    cout << "Please re-enter." << endl;
}

class Calculator {
    vector<double> nums;
    vector<char> opers;
    double result = 0;

    void calculate(string calLine);
    double add(double x, double y);
    double sub(double x, double y);
    double mul(double x, double y);
    double div(double x, double y);

public:
    void displayMenu();     // display clear 필요
    bool checkContinue(string calLine);
};