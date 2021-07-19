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
    enum m_opers { add='+', sub='-', mul='*', div='/' };
    double m_result = 0;

    void calculate(string calLine);

public:
    void displayMenu();     // display clear 필요
    bool checkContinue(string calLine);
};