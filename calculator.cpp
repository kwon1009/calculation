#include "calculator.h"

void Calculator::calculate(string calLine) {
    vector<double> nums;
    vector<char> opers;
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

        // 입력한 수식이 정상적인지 확인
        if(nums.size() != opers.size()+1) throw others;

        // 계산하기
        m_result = nums[0];
        for(i=0; i<opers.size(); i++) {
            switch(opers[i]) {
                case add:   
                    m_result += nums[i+1];
                    break;
                case sub:
                    m_result -= nums[i+1];
                    break;
                case mul:
                    m_result *= nums[i+1];
                    break;
                case div:
                    m_result /= nums[i+1];
                    break;
                default:
                    throw others;
                    break;
            }
        }
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