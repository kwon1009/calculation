#include "calculator.h"

void Calculator::getValues(string calLine) {
    int s = 0;
    int i;
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
}

double Calculator::getResult() {
    double result = nums[0];
    for(int i=0; i<opers.size(); i++) {
        switch(opers[i]) {
            case add:   
                result += nums[i+1];
                break;
            case sub:
                result -= nums[i+1];
                break;
            case mul:
                result *= nums[i+1];
                break;
            case div:
                result /= nums[i+1];
                break;
            default:
                throw others;
                break;
        }
    }
    return result;
}

void Calculator::calculate(string calLine) {
    nums.clear();
    opers.clear();

    try {
        getValues(calLine); // nums와 opers 구하기

        if(nums.size() != opers.size()+1) throw others; // 입력한 수식이 정상적인지 확인

        // 계산
        m_result = getResult();
        cout << m_result << endl;
    } catch (errors e) {
        displayError(e);
    }
}

void Calculator::displayMenu() {
    cout << "< Calculator >" << endl;
    cout << "You can do numeric calculations. For example, 3+2-5." << endl;
    cout << "Please enter without spaces." << endl;
    cout << "* Operator : +, -, *, /" << endl;
    cout << "* option 'm' or 'M': Menu" << endl;
    cout << "* option 'f' or 'F': Finish" << endl;
    cout << endl;
}

bool Calculator::checkContinue(string calLine) {
    if (calLine == "m" || calLine == "M") {
        // Show menu
        cout << endl;
        displayMenu();
    } else if (calLine == "f" || calLine == "F") {
        // finish
        cout << "Thank you for using it." << endl;
        return false;
    } else {
        // calculate
        calculate(calLine);
    }
    return true;
}