#include <iostream>
using namespace std;

//배열 : 같은 타입의 변수들의 집합
int array1() {

    //int형 자료 5개를 담을 수 있는 int형 배열 values
    int values[5] = {0,10,20,30,40};

    //배열의 접근 방식 2가지 : index , pointer
    int sum_index = 0;

    for (int i = 0; i != sizeof(values)/sizeof(int) ; ++ i){
        sum_index = sum_index + values[i];
    }
    cout << sum_index << endl;

    int sum_pointer = 0;
    for (int i = 0 ; i < sizeof(values)/sizeof(int) ; i ++ ){
        sum_pointer = sum_pointer + *(values + i);
    }
    cout << sum_pointer << endl;

    //배열의 초기화 방법
    int intArray[3] = {10, 20, 30}; // size 지정 후, 초기화
    int intArray_brace[3]{10,20,30}; // size 지정 후, brace를 이용해 초기화
    int intArray_nosize[]= {10,20,30}; // size를 지정하지 않고, 초기화
    int intArray_5[5] = {10,20,30}; // 지정한 size보다 작은 배열로 초기화 했을경우, 나머지는 모두 0으로 채워진다.
    int intArray_10[10] = {0}; //모든 값이 0으로 채워진 size가 5인 정수형 배열

    int i = 0;
    while(i<sizeof(intArray_5)/sizeof(int)){
        cout << intArray_5[i] << " ";
        i = i + 1;
    }
    cout << endl;

    i = 0;
    while(i != sizeof(intArray_10)/sizeof(int)){
        cout << *(intArray_10 + i) << " ";
        i = i + 1;
    }
    cout << endl;

    //direct initialization & brace initialization
    string str ("Hong");
    int num(51);
    cout << str << '\t' << num << '\n';

    string str_br = ("Park");
    int num_br(17);
    cout << str_br << '\t' << num_br << '\n';

};

int array2(){

    //Array with pointer
    int size;
    cout << "Enter the size of Array : ";
    cin >> size;

    int * array = new int[size];
    //int array [size];

    // dereference( * )연산자를 이용해 배열에 값을 대입
    for (int i = 0; i != size; ++i){
        *(array + i) = 10 + i;
    }
    //array = { 10, 11, 12, 13, 14 ... }

    //포인터를 이용해 배열을 정의해도, index로 접근 가능
    int j = 0;
    int sum = 0;

    while (j < size){
        cout << array[j] << " ";
        sum = sum + array[j];
        j = j + 1;
    }
    cout << '\n' << "Sum of array : " << sum << endl;

}

int char_array(){
    //char 배열
    char char_string[] = "Twins";
    cout << char_string << endl;

    //index로 접근
    for (int i = 0 ; i < sizeof(char_string) ; ++i){
        cout << char_string[i] << " ";
    }
    cout << endl;

    //포인터로 접근
    int j = 0;
    while(j != sizeof(char_string)){
        cout << *(char_string + j) << " ";
        j = j + 1;
    }
    cout << endl;
}

// 2차원 배열
// row  column ;
const int ROW_SIZE = 3;
const int COLUMN_SIZE = 5;

int two_dimensional_array(){

    //2차원 배열 생성
    int ArrayA[ROW_SIZE][COLUMN_SIZE];

    //index를 통해 값을 대입
    for (int i = 0 ; i < ROW_SIZE ; i ++ ){
        for (int j = 0 ; j != COLUMN_SIZE ; ++j){
            ArrayA[i][j] = i + j;
        }
    }


    for (int i = 0 ; i < ROW_SIZE ; i ++ ){
        for (int j = 0 ; j < COLUMN_SIZE ; j ++){
            cout << ArrayA[i][j] << '\t';
        }
        cout << endl;
    }


    int ArrayB[ROW_SIZE][COLUMN_SIZE];

    // 2차원 배열 - > 실제 메모리에서는 1차원으로 쭉 길게 이어진 형태
    // 포인터를 이용해 값 대입


    for (int i = 0 ; i < ROW_SIZE ; i ++ ){
        for (int j = 0 ; j < COLUMN_SIZE ; j ++ ){
            *(*(ArrayB + (i * ROW_SIZE))+j) = i * j;
        }
    }
}

