#include <iostream>
#include <iomanip>
using namespace std;

int practice1_3() {

    //두 실수를 입력 받은 후, 두 실수의 사칙연산 결과 출력하기

    float num1, num2;
    cin >> num1 >> num2;

    cout << fixed << setprecision(2) << num1 <<" + " << num2 << " = "  << num1 + num2 << endl;
    cout << num1 <<" - " << num2 << " = " <<fixed << setprecision(2) << num1 - num2 << endl;
    cout << num1 <<" * " << num2 << " = " <<fixed << setprecision(2) << num1 * num2 << endl;
    cout << num1 <<" / " << num2 << " = " <<fixed << setprecision(2) << num1 / num2 << endl;

    return 0;
}