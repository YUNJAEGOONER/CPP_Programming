#include <iostream>
using namespace std;

int practice1_2() {
    //세 개의 정수를 입력 받은 후, 세 정수의 합 구하기
    
    int num1,num2,num3;
    cin >> num1 >> num2 >> num3;

    int sum;
    sum = num1 + num2 + num3;
    cout << sum;

    return 0;
}