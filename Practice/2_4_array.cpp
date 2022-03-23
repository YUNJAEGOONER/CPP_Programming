#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int practice2_4(){
    //10개의 정수를 입력 받아 가장 큰 수와 가장 작은 출력
    //<algorithm>에 있는 min_element, max_element를 활용하기

    array<int,10> arr;

    for(auto &iter : arr){
        cin >>iter;
    }

    auto min = min_element(arr.cbegin(),arr.cend());
    auto max = max_element(arr.cbegin(),arr.cend());

    cout << *max  << " " << *min;

}