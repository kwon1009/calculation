#include <iostream>
#include <vector>
using namespace std;

enum errors { alpha, blank, div_zero, others };

void displayError(errors e) {
    cout << "Error: ";
    switch(e) {
        case alpha:
            cout << "Alphabet is not allowed." << endl;
            break;
        case blank:
            cout << "Blanks cannot be entered." << endl;
            break;
        case div_zero:
            cout << "It cannot be divided by zero." << endl;
            break;
        default:
            cout << "It is Invalid Format." << endl;
            break;
    }
    cout << "Please re-enter." << endl;
}

class Calculator {
    enum m_opers { 
        add='+', sub='-', mul='*', div='/'
        // f_pare='(', b_pare=')'
        // 괄호 계산 추가시
    };

    vector<double> nums;
    vector<char> opers;
    double m_result = 0;
    string m_lastCal = "0";

    void calculate(string calLine);
    void setValues(string calLine);
    double getResult(int start, int end);

    void resetValue(int i);

public:
    void displayMenu();     // display clear 필요
    bool checkContinue(string calLine);
};