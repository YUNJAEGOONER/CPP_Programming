#include <iostream>
#include <string>
#include <cstdint>
#include <climits>
#include <limits>

using namespace std;

//const(상수) : 선언과 동시에 초기화가 이루어져야하며, 그 값은 변경 불가능
const int BASE_SCORE = 50;
const int GOOD_SCORE = 80;
const string GOOD_MSG = "Good";
const string BAD_MSG = " Not Good";

int type1(){
    //cout은 출력함수 (C언어에서의 Printf)
    cout << "Enter your Score: ";
    //cin은 입력함수 (C언어에서의 scanf)
    int score;
    cin >> score; //변수 score의 type이 int이므로 사용자로 부터 int를 입력받는다.

    int result = BASE_SCORE + score; //BASE_SCORE는 상수이므로 프로그램 동작 내내 초기설정값인 50이 유지된다.
    string msg; //include <string>

    if(result >= GOOD_SCORE){
        msg = GOOD_MSG;
    }
    else{
        msg = BAD_MSG;
    }

    //endl은 개행문자인 "\n"와 마찬가지로 줄바꾸기를 위해 사용된다. endl을 사용하게 되면 버퍼가 비워지게 된다.
    cout << "The result: " << result << " is " << msg << endl;

}

int type2(){
    int integerNumber, positiveNumber;
    cin >> integerNumber >> positiveNumber;
    //공백(spcaebar)을 기준으로 두 개의 입력을 받을 수 있음 (공백으로 입력값을 구분)
    //ex) 50 30이런식으로 입력하게 되면 integer의 값고 positiveNumber의 값이 각각 50과 30으로 초기화 된다.

    //boolean 2가지의 상태 True(1), False(0)가 있다.
    //boolean을 따로 초기화 하지 않을경우, 초기값으로 false(0)를 갖는다.

    bool zeroOrMore = integerNumber >=0;

    float product;
    char signChar;

    if (zeroOrMore){
        product = integerNumber * positiveNumber;
        signChar = '+';
    }
    else{
        product = -integerNumber * positiveNumber;
        signChar = '-';
    }
    cout << signChar << product << endl;

}

int type3(){
    //byte수를 명시하여 정수 사용 <cstdint>
    int8_t signed_int8; //signed 8비트 정수
    uint8_t usigned_int8; //unsigned 8비트 정수

    //sizeof 함수를 이용해 변수의 size 알아내기
    cout << sizeof(signed_int8) <<"byte = " << 8 * sizeof (signed_int8) << "bit" << endl;

    //is_same을 이용해 타입을 비교하기 is_same<type, type>::value

    cout << is_same<int,signed int>::value<< "\n"; //true이므로 1이 출력
    cout << is_same<int8_t,int>::value << endl; //false이므로 0이 출력


    //INT_MAX & MIN 를 통해 최대/최소 알아보기 <climits>
    cout << "signed 8bit integer: " << INT8_MIN << " ~ " << INT8_MAX << endl;
    cout << "unsigned 8bit interger: " << '0' << " ~ " << UINT8_MAX << endl; //usigned의 경우는 최소값이 항상 0

    //numeric_limits<type>을 통해 type의 최대/최소 알아보기  <limits>
    //흔히 쓰는 int는 앞에 signed가 생략된 형태
    cout << "integer : " << numeric_limits<int>::min() << " ~ " << numeric_limits<int>::max() << endl;

    //int의 리터럴로 10진수, 8진수, 16진수가 올 수 있다.
    int decimal = 256; //10진수
    int octal = 0400; //8진수 (앞에 0)
    int hexa = 0x100; //16진수 (앞에 0x) , 주소를 핸들링해야하는 경우에 종종 사용

    cout << "decimal : " << decimal << " octal : " << octal << " hexa : " << hexa << endl;

    float real_number = 1.23f; // 실수 뒤에 f/F 붙여 float type임을 명시

    //special character
    cout << "Backslash : " << " \\ " << "\n" ; //두 개의 Backslash(\\) 한개의 Backslash (\)출력 가능 , "\n"을 이용해 줄 바꾸기
    cout << "Tab" << "\t" << "Tab" << endl;
    cout << "double quotes : " << " \" " << "\n" ; // Backslash + 큰 따옴표 (\")로 큰 따옴표 출력
    cout << "single quote : " << " \' " << "\n"; // Backslash + 작은 따옴표 (\')로 작은 따옴표 출력
}

//상수는 선언과 동시에 초기화가 이루어져야하며, 그 값은 변경 불가능하다.(새로운 값 대입 허용되지 않음)

int circle(){
    const float PI = 3.14;

    float radius;
    cin >> radius;

    float area = radius * radius * PI;
    cout << "radius : " << radius << " area : " << area << endl;
}

int type_cast() {
    //형 변환 : 크기가 큰 type을 작은 type으로 변경시 자료 손실의 가능성이 발생
    //implicit -> 자료 손실 가능성이 있는 경우 컴파일러가 경고

    //explicit : static_cast<type>을 이용하여 명시적으로 형 변환
}

int brace(){

    // 초기값으로 0이 할당된다. {}안에 숫자를 넣어 초기화 가능
    int brace_integer {};
    int brace_initialized_integer {5};
    cout << "default : " << brace_integer <<" initialized :" << brace_initialized_integer << endl;


    //brace를 이용해 배열을 초기화 할 수 있다. index를 활용해 접근 가능
    int intArray[] = {1,2,3,4,5,};

    for (int i = 0; i < sizeof(intArray)/sizeof(int); i ++){
        cout << intArray[i];
    }

}

int globalvariable;
//전역변수 -> 선언된 지점부터 프로그램의 끝까지 접근 가능

void print(int v){
    //parameter : int
    //local_1은 함수 global_local 내의 지역변수이므로 parameter를 통해 가져옴
    //globalvariable은 전역변수이므로 바로 접근 가능
    cout << "\n" << v << " " << globalvariable << endl;
}

int global_local(){
    //함수 global_local의 지역변수 local_1 : 함수 global_local 밖에서는 접근 불가능
    int local_1;

    for (int i = 0; i < 10 ; i ++){
        int local_2 = i + 1;
        //local_2는 for 블럭내의 지역변수 : 해당 for문 밖에서는 접근 불가능
        local_1 = local_2;
        globalvariable= globalvariable + local_1;
    }
    //for문 종료시 local_1에는 10(i = 9)이, globalvariable은 1부터 10까지의 합인 55가 할당되어있다.
    print(local_1);
    //local_1인 10이 parameter로 넘겨짐
}


int default_integer;
bool default_boolean;
float default_float;

int not_initialized_gloabal_variable(){
    //int,bool,float 변수를 초기화 하지 않으면 초기값으로 0 (0, false, 0.0f) 을 가진다
    cout << "not_initialized_gloabal_variable" << "\n";
    cout << default_integer << " " << default_boolean << " " << default_float << endl;
}

int print_static(int v){

    int sum = 0;
    //함수 실행 시 0으로 초기화
    sum = sum + v;

    static int static_sum = 0;
    //함수 종료후에도 그 값이 유지됨
    static_sum = static_sum + v;

    cout << sum << " " << static_sum << endl;
}

int static_variable(){
    print_static(1); //sum = 1 static_sum = 1
    print_static(2); //sum = 2 static_sum = 3 (v = 1 실행된 후, static_sum = 1로 유지)
    print_static(3); //sum = 3 static_sum = 6
}

int hiding_variable = -100;

int hiding(){

    //전역변수와 지역변수의 변수명이 같은 경우 -> 전역변수를 가림
    int hiding_variable = 100;
    cout << hiding_variable << "\n"; //지역변수가 출력됨

    //영역 연산자 ::을 이용해 전역변수 지칭
    cout << ::hiding_variable << "\n"; //전역변수가 출력됨

}