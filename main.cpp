#include <iostream>
#include "calculator.cpp"
using namespace std;

int main() {
    Calculator cal;
    cal.displayMenu();

    string numLine;
    do {
        cout << ">> ";
        getline(cin, numLine);
    } 
    while(cal.checkContinue(numLine));
    return 0;
}
