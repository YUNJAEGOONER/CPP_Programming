#include <iostream>
using namespace std;

void swap();

int practice2_3(){
    //참조 변수 활용하기
    int num1, num2;
    cin >> num1 >> num2;

    swap(num1, num2);

    cout << num1 << " " << num2;
    return 0;
}

void swap(int &num1,int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}