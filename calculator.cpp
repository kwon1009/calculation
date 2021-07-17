#include <iostream>
#include <vector>
using namespace std;

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

void Calculator::calculate(string calLine) {
    nums.clear();
    opers.clear();
    int s = 0;
    int i;
    for(i=0; i<calLine.length(); i++) {
        if(isalpha(calLine[i]) == 0) {
            if(!isdigit(calLine[i])) {
                if(calLine[i] != '.') {
                    opers.push_back(calLine[i]);
                    double num = stod(calLine.substr(s, i));
                    s = i + 1;
                    nums.push_back(num);
                }
            }
        } else {
            cout << "It is Invalid Format." << endl;
            cout << "Please re-enter." << endl;
            return;
        }
    }
    if(s < i) {
        double num = stod(calLine.substr(s, i));
        nums.push_back(num);
    }

    // if(result == 0) {
    result = nums[0];
    // }
    for(i=0; i<opers.size(); i++) {
        switch(opers[i]) {
            case '+':   
                result = add(result, nums[i+1]);
                break;
            case '-':
                result = sub(result, nums[i+1]);
                break;
            case '*':
                result = mul(result, nums[i+1]);
                break;
            case '/':
                result = div(result, nums[i+1]);
                break;
            default:
                cout << "wrong." << endl;
                break;
        }
    }
    cout << result << endl;
}

double Calculator::add(double x, double y) {
    return x + y;
}

double Calculator::sub(double x, double y) {
    return x - y;
}

double Calculator::mul(double x, double y) {
    return x * y;
}

double Calculator::div(double x, double y) {
    if(y == 0) {
        // 에러처리 필요
        return 0;
    }
    return x / y;
}


void Calculator::displayMenu() {
    cout << "< Calculator >" << endl;
    cout << "You can do numeric calculations. For example, 3+2-5." << endl;
    cout << "Please enter without spaces." << endl;
    cout << "* option 'r' or 'R': Restart" << endl;
    cout << "* option 'f' or 'F': Finish" << endl;
    cout << "* option 'c' or 'C': Clear" << endl;
    cout << endl;
}

bool Calculator::checkContinue(string calLine) {
    if (calLine == "r" || calLine == "R") {
        // restart
        result = 0;
        displayMenu();
        cout << ">> ";
    } else if (calLine == "f" || calLine == "F") {
        // finish
        cout << "Thank you for using it." << endl;
        return false;
    } else if (calLine == "c" || calLine == "C") {
        // clear
        displayMenu();
        cout << ">> " << result << " ";
    }

    // calculate
    calculate(calLine);
    return true;
}

