#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int range_base(){
    //배열 선언 방법 : array<int , size> arr; size개의 정수를 연속된 메모리 공간에 저장
    array<int, 5>array1;

    //range base for loop -> '&' 연산자를 이용해 실제 배열의 값이 변경됨
    for(auto &element :array1){
        cin >> element;
    }

    for(int element : array1){
        cout << element << " ";
    }
    cout << endl;

    //sort using algorithm

    //오름차순 정렬
    sort(array1.begin(), array1.end());

    for(int element : array1){
        cout << element << " ";
    }
    cout << endl;

    //내림차순 정렬
    sort(array1.begin(), array1.end(),greater<int>());

    for(int element : array1){
        cout << element << " ";
    }
    cout << endl;

    //min-max using algorithm -> max_element min_element 주소 값 return -> dereference 연산자 이용해 '값' 알아내기
    auto max = max_element(array1.begin(),array1.end());
    int * min = min_element(array1.begin(),array1.end());
    cout << *max << " " << *min << endl;

}
