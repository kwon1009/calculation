#include <iostream> // 전처리지시자
#include "calculator.cpp"
using namespace std;
// std::cout

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