#include "header_for_1_4.h";
#include <iostream>
using namespace std;
int practice1_4(){
    //두 개의 정수를 입력받은 후, 두 정수의 합과 차 구하기

    int a, b;
    int* pA = &a;
    int* pB = &b;
    cin >> *pA >> *pB;
    update(&a, &b);
    cout << a << endl;
    cout << b << endl;

}

