#include <iostream>
#include <memory>

using namespace std;
void Update(int* a, int* b);

int practice1_6(){

    // 스마트 포인터 활용하기
    // 입력 받은 두 정수의 합과 차 구하기

    int integer1,integer2;
    cin >> integer1 >> integer2;

    unique_ptr<int> pA {new int(integer1)};
    unique_ptr<int> pB {new int(integer2)};

    Update(pA.get(),pB.get());

}


void Update(int* a, int* b){
    //이 함수를 구현하세요!
    cout << *a + *b << endl;
    cout << *a - *b << endl;

}