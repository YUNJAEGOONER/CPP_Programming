#include <iostream>
using namespace std;

int practice2_1(){
    // 정수의 배열을 만든 후, index를 반대로해 배열출력하기

    int size;
    cin >> size;

    int intArray[size];

    for (int i = 0; i < size ; i ++){
        cin >> intArray[i];
    }

    for (int j = size-1 ; j != -1 ; --j){
        cout << intArray[j] << " ";
    }
    return 0;

}

