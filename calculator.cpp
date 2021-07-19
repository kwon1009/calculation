#include "calculator.h"


void Calculator::setValues(string calLine) {
    int s = 0;
    int i;
    for(i=0; i<calLine.length(); i++) {
        
        if(isalpha(calLine[i]) != 0) throw alpha;   // 알파벳을 입력한 경우
        if(calLine[i] == ' ') throw blank;          // 띄어쓰기 에러 처리

        if(!isdigit(calLine[i]) && calLine[i] != '.') {
            opers.push_back(calLine[i]);
            double num = stod(calLine.substr(s, i));
            s = i + 1;
            nums.push_back(num);
        }
    }
    if(s >= i) throw others;    // 연산자로 끝난 경우

    double num = stod(calLine.substr(s, i));
    nums.push_back(num);
}

void Calculator::cal_mul(int i) {
    nums[i] = nums[i] * nums[i+1];
    nums.erase(nums.begin()+i+1);
    opers.erase(opers.begin()+i);
}

void Calculator::cal_div(int i) {
    if(nums[i+1] == 0) throw div_zero; // 0으로 나누는 경우

    nums[i] = nums[i] / nums[i+1];
    nums.erase(nums.begin()+i+1);
    opers.erase(opers.begin()+i);
}

double Calculator::getResult() {
    // 곱셈과 나눗셈 먼저 계산
    int i=0;
    while(i < opers.size()) {
        switch(opers[i]) {
            case mul:
                cal_mul(i);
                break;
            case div:
                cal_div(i);
                break;
            default:
                i++;
                break;
        }
    }

    // 덧셈과 뺄셈 계산
    double result = nums[0];
    for(i=0; i<opers.size(); i++) {
        switch(opers[i]) {
            case add:   
                result += nums[i+1];
                break;
            case sub:
                result -= nums[i+1];
                break;
            default:
                throw others;   // 연산자가 아닌 경우
                break;
        }
    }
    return result;
}

void Calculator::calculate(string calLine) {
    nums.clear();
    opers.clear();

    try {
        setValues(calLine); // nums와 opers 구하기
        
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