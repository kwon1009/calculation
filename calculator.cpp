#include "calculator.h"

void Calculator::calculate(string calLine) {
    nums.clear();
    opers.clear();
    int s = 0;
    int i;

    try {
        for(i=0; i<calLine.length(); i++) {
            // 알파벳을 입력한 경우
            if(isalpha(calLine[i]) != 0) throw alpha;
            // 띄어쓰기 에러 처리
            if(calLine[i] == ' ') throw blank;

            if(!isdigit(calLine[i]) && calLine[i] != '.') {
                opers.push_back(calLine[i]);
                double num = stod(calLine.substr(s, i));
                s = i + 1;
                nums.push_back(num);
            }
        }
        if(s < i) {
            double num = stod(calLine.substr(s, i));
            nums.push_back(num);
        }

        // 계산하기
        result = nums[0];
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
                    throw others;
                    break;
            }
        }
        cout << result << endl;
    } catch (errors e) {
        displayError(e);
    }
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
        throw zero;
    }
    return x / y;
}


void Calculator::displayMenu() {
    cout << "< Calculator >" << endl;
    cout << "You can do numeric calculations. For example, 3+2-5." << endl;
    cout << "Please enter without spaces." << endl;
    cout << "* Operator : +, -, *, /" << endl;
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