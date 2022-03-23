#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int practice2_6(){
    // 벡터의 크기를 입력한 후, 그 크기만큼 벡터에 원소를 추가
    //<algorithm>에 있는 sort를 활용하여 vector 정렬하기

    int size;
    cin >> size;

    vector<int> vec (size);

    for (int i = 0; i < vec.size(); i ++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i ++){
        cout << vec[i] << " ";
    }

    return 0;
}