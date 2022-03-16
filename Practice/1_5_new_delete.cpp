#include <iostream>
using namespace std;

int practice1_5(){
    //정수형 배열을 만든 후 , 원하는 index 요소 출력하기

    int size;
    cin >> size;

    int * arr = new int [size];

    for (int j = 0; j < size; ++j){
        cin >> arr[j];
    }

    int i;
    cin >> i;

    cout << arr[arr[i]] << endl;
    delete [] arr;
}

