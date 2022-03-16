#include <iostream>
#include <memory>
#include <string>
#include <cstring>
using namespace std;

int pointer_1(){

    int integer = 10;

    // &interger : int형 변수 integer의 주소 가져오기
    // pointer_integer : 인트형 포인터 변수 -> int형 변수를 가르킬수 있다.
    int * pointer_interger = &integer;

    //*pointer_integer : 포인터 변수 pointer_integer가 가르키는 integer의'값' 가져오기
    //* : dereference
    cout << "address : " << &pointer_interger << " Value : " << *pointer_interger << '\n';


    //interger의 값 1증가 ( integer = 11 )
    //intger = integer + 1 과 같은 의미
    integer ++ ;
    //pointer_integer는 integer를 가르키고있으므로 기존의 값에서 1이 증가된 11을 가르키고 있다.
    cout << "address : " << &pointer_interger << " Value : " << *pointer_interger << '\n';

    //pointer_interger가 가르키는 '값'을 가져와 1증가 :pointer_integer가 가르키는 값이 interger는 1이 증가된 12가 된다.
    (*pointer_interger) ++;
    cout << integer << endl;

    int *pointer1 = &integer;
    int *pointer2 = pointer1; //pointer2에게 pointer1이 가르키는 주소를 전달

    //pointer1, pointer2 모두 intege를 가르키고 있다.
    cout << "address : " << &pointer1 <<'\t'<< "point to : " << pointer1 <<'\t'<< "Value : " << *pointer1 << '\n';
    cout << "address : " << &pointer2 <<'\t'<< "point to : " << pointer2 <<'\t'<< "Value : " << *pointer2 << endl;


}

//memeory allocation in C
int malloc_c(){

    int length;
    printf("Length of string :");
    scanf("%d",&length); //C++ : cin

    char * name = (char *)malloc(length + 1); // malloc()을 이용한 동적 메모리 할당 (C++ : new)
    //char의 크기가 1이기 때문에 sizeof(char) 생략가능

    scanf("%s",name);
    printf("%s\n",name); //C++ : cout

    //index를 활용하여 문자 하나 하나에 접근이 가능
    printf("%c\n",name[0]);
    printf("%c\n",*(name+1));

    free(name); //메모리 할당 해제 (C++ : delete)

}

int new_cpp(){
    //C++에서는 new/delete로 메모리 할당/해제를 한다.

    //3을 가르키는 int형 포인터 i
    int * i = new int(3);
    cout << i << '\t' << *i << endl;
    free(i);

    cout << "Length of string: " ;

    int length;
    cin >> length;
    char * string_array = new char[length+1]; //new type[length = 개수] -> 동적 메모리 할당
    //length + 1 이유 : 맨 마지막에 문자열이 끝났음을 표시해주는 '\0' (NULL)이 온다.
    cin >> string_array;
    cout << string_array <<endl;

    delete []string_array; //delete [] 배열이름 -> 동적 메모리 할당 해제
}

//smart pointer : 메모리를 자동으로 해제 ( delete를 자동으로 수행 ) <memory>
//3가지의 종류가 존재 ( unique_ptr /  shared_ptr / weak_ptr )

int unique_pointer(){

    //unique 포인터 : 포인터를 단독으로 소유 (대입 불가)
    //블럭안에서 생성시, 블럭안의 코드가 모두 수행되고 블럭을 나가게 되면 자동 소멸 (delete)
    //포인터가 해당 데이터 (객체)에 대한 소유권을 갖고 있다.

    unique_ptr<int> uniq_pointer (new int(3));
    //unique_ptr <type> variable_name ( new 가르키려는것 )
    //정수 3을 가르키고 있는 정수형 유니크 포인터 ( 정수 3을 가르키는 유일한 포인터 )
    cout << "address : " << &uniq_pointer << '\t' << " point : " << *uniq_pointer <<'\n';

    auto uniq_pointer2 = make_unique<int>(3);
    //make_unique<type>() 을 통해서도 유니크 포인터를 만들 수 있다.
    //uniq_pointer와 마찬가지로 정수 3을 가르키고 있는 정수형 유니크 포인터
    cout << "address : " << &uniq_pointer2 << '\t' << " point : " << *uniq_pointer2 <<'\n';

    //uniq_pointer.get()을 통해 유니크 포인터가 가르키고 있는 주소를 가져올 수 있음
    auto normal_pointer = uniq_pointer.get(); //-> normal_pointer가 uniq_pointer가 가르키는 3을 가르키게함
    cout << *normal_pointer <<'\n';

    unique_ptr<string> unique_str {new string };
    //string type을 가르킬수 있는 유니크 포인터 unique_str 선언
    unique_str->assign("Hello World");
    //unique_Str이 가르키고 있는 string에 "Hello World"를 할당
    cout << *unique_str <<'\n';

    //유니크 포인터를 활용한 배열
    unique_ptr<int[]>unique_arr{new int[3]};
    //유니크 포인터 unique_ptr은 크기가 3인 정수형 배열을 가르키고 있다.

    for (int i = 0; i < 3; i ++){
        unique_arr[i] = 100 + i;
    }

    for (int j  = 0; j < 3; ++j){
        cout << unique_arr[j] << '\t';
    }
    cout << endl;
}

int shared_pointer(){
    //하나의 데이터에 대해 여러 포인터가 존재
    //하나의 데이터에 대한 포인터의 개수를 count해, cout가 0이 되면 delete
    //여러 곳에서 공통으로 사용하는 메모리를 관리

    shared_ptr<int>sha_ptr{new int(3)}; //정수 3을 가르키는 sharedpointer sha_ptr
    auto sha_ptr2 = sha_ptr;

    cout << "address : " << sha_ptr << '\t' << "point :"<< sha_ptr << '\t' << "value : " <<*sha_ptr<< endl;
    cout << "address : " << sha_ptr2 << '\t' << "point :"<< sha_ptr2 << '\t' << "value : " <<*sha_ptr2<< endl;
    //2개의 포인터가 같은것(정수 3)을 가르키고 있음
    cout << sha_ptr.use_count() << endl;

    auto sha_ptr3 = make_shared<int>(4); //정수 3을 가르키는 sharedpointer sha_ptr3
    shared_ptr<int>sha_ptr4{sha_ptr3};
    cout << sha_ptr.use_count() << endl;

}


int const_pointer(){

    int integer_1 = 10;
    int integer_2 = 100;

    cout << "----- int * pointer -----" << endl;
    //일반 포인터 : 포인터가 가르키는 값을 변경 가능, 포인터가 다른 변수를 가르킬 수 있음
    int * normal_pointer; // int형 자료를 가르킬수 있는 포인터 : 포인터 변수 이므로 주소를 할당 받아야한다.
    normal_pointer = &integer_1; // &연산자를 이용해 integer_1의 주소를 가져옴

    cout << &normal_pointer << endl; //pointer의 주소가 나온다.
    cout << normal_pointer << endl; //pointer의 값 (현재 포인터가 가르키고 있는 변수의 주소 값)
    cout << &integer_1 << endl; //int형 변수 integer_1의 주소 값
    cout << *(normal_pointer) << endl; //pointer가 가르키고 있는 값 ( 포인터가 가르키고 있는 변수의 값 )
    cout << integer_1 << endl; //integer_1의 값

    cout << "address : " << &normal_pointer << "\t" << "value : " << *normal_pointer << endl; //*연산자를 이용해 포인터가 가르키고 있는 값을 가져옴
    (*normal_pointer) = (*normal_pointer) + 1; //normal_pointer가 가르키는 integer의 값이 증가  (원 변수 값 변경 가능)
    cout << "address : " << &normal_pointer << "\t" << "value : " << *normal_pointer << endl;
    cout << integer_1 << endl;
    normal_pointer = &integer_2; //normal_pointer가 다른 변수를 가르키게 함 : interger_2를 가르킨다,
    cout << "address : " << &normal_pointer << "\t" << "value : " << *normal_pointer << endl;

    cout << "----- const int * pointer -----" << endl;

    //상수에 대한 포인터 : 포인터가 가르키는 값을 변경 못함 , 포인터가 다른 변수를 가르킬 수 는 있음
    //-> 원 변수 값 변경 불가

    const int *const_pointer;
    const_pointer = &integer_1;
    cout << "address : " << &const_pointer << "\t" << "value : " << *const_pointer << endl;
    //(*const_pointer) = (*const_pointer) + 1; //read-only varialble : pointer가 가르키는 값 변경 불가
    const_pointer = &integer_2;
    //포인터가 다른 값을 가르키게 할 수 있다.
    cout << "address : " << &const_pointer << "\t" << "value : " << *const_pointer << endl;

    cout << "----- int * const pointer -----" << endl;
    //상수 포인터 : 포인터가 다른 변수를 가르키지 못함 , 가르키는 값을 변경 할 수는 있음
    //다른 주소의 대입 불가

    int * const pointer_const = &integer_1; //선언과 동시에 초기화가 ㅑ함
    cout << "address : " << &pointer_const << "\t"  << "value : " << *pointer_const << endl;
    (*pointer_const) = (*pointer_const) + 1; // 포인터가 가르키는 값 변경 가능
    cout << "address : " << &pointer_const << "\t"  << "value : " << *pointer_const << endl;
    cout<<integer_1<<endl;
    //pointer_const = &integer_2; -> 포인터가 다른 변수를 가르키지 못함

    cout << "----- const int * const pointer -----" << endl;
    //상수에 대한 상수 포인터 ( 상수에 대한 포인터 + 상수 포인터 )
    //가르키는 값 변경 불가 + 다른 변수를 가르키게 하지도 못함

    const int * const const_pointer_const = &integer_1;
    cout << "address : " << &const_pointer_const << "\t" << "value : " << *const_pointer_const << endl;
    //(*const_pointer_const) = (*const_pointer_const) + 1; => 포인터가 가르키는 값 변경 불가
    //const_pointer_const = &integer_2;  => 포인터가 다른 변수를 가르키는 것도 불가
}

//상수 포인터 예시
//int countUppercase(char * str , int length) -> 이렇게 해도 되지만, parmeter로 받는 값들은 변경되는 값이 아니므로 앞에 const를 붙여준다.

int countUppercase(const char * str , const int length){
    int count = 0;
    for (int i = 0 ; i < length ; ++i){
        if (str[i] >= 'A' && str[i]<'Z'){
            // 대문자 A 에서 Z 까지 사이의 값 찾기 => 대문자 찾기
            count = count + 1;
        }
    }
    return count;
}

int const_pointer_example(){

    char * msg = "Hello World";

    //strlen <cstring> : str의 길이를 알아내는 함수
    cout << strlen(msg) << endl;

    //함수 countUppercase의 parameter로 msg(char 포인터)와, string의 길이 (int)를 넘겨줌
    cout << countUppercase(msg, strlen(msg)) << endl;
}


//참조 변수
//-> 선언과 동시에 초기화가 이루어져야 하며, 초기화 후에는 다른 변수 참조 불가
//-> 초기화는 리터럴이 아닌 일반 변수로 초기화가 이루어져야 하며, 상수 변수는 가르 킬 수 없다.
int reference(){

    int num1 = 10;
    int num2 = 100;

    //pointer
    cout << "----- pointer ------" <<endl;
    int * ptr;
    ptr = &num1;
    //pointer를 위한 메모리가 할당됨
    cout << "pointer's address : " << &ptr << "\t" << "variable's address : " << ptr << endl;
    //pointer 변수가 가르키는 값 변경 가능
    (*ptr) = (*ptr) + 1;
    cout << "address : " << &ptr << "\t" << "value : " << *ptr << endl;
    //pointer는 다른 변수를 가르키게 할 수 있음
    ptr = &num2;
    cout << "address : " << &ptr << "\t" << "value : " << *ptr << endl;

    cout << "------ reference ------ " << endl;
    //reference
    // 선언과 동시에 초기화가 이루어져야하며, 일반 변수로 초기화 가능

    int & refer = num1;
    //참조변수를 위한 메모리가 할당 되지 않음 ( 동일한 메모리 공간 참조 ) : 변수에 별칭을 붙여줌
    cout <<"reference variable's address : "<< &refer << "\t" << "variable's address : " << &num1 << endl;
    refer = 999; //참조 변수가 가르키는 값 변경 가능
    cout << "reference variable : " <<  refer << "\t" <<  "Variable : " << num1 << endl ;

    //&refer = num2; //재참조 불가

    refer  = num2; //재참조가 아닌 값 변경 ( refer와 num2의 주소가 상이하다)
    cout << "reference variable : " <<  &refer << "\t" <<  "Variable : " << &num2 << endl ;
}

int null_ptr(){

    //Null pointer : 포인터가 아무것도 가르키고 있지 않음
    char * memory;

    if(memory == nullptr){
        cout << "Null pointer" <<endl;
    }

    cout << "Enter the length : ";

    int length;
    cin >> length;

    char * name  = new char [length + 1];

    //name은 nullptr가 아님 -> char 배열을 가르키고 있음
    if (name != nullptr){
        cin >> name;
        cout << name << endl;
        delete [] name;
    }

}

//Type inference (타입 추론)

int type_inference() {
    //auto : 초기화 된 값을 보고 자료형을 추론 하기 때문에 초기화가 필수적
    //함수 parameter로 사용 불가
    // &type을 지원 안해줌

    double a = 3.5;
    int b = 5;

    auto pointer = &b;

    auto sum = a + *(pointer);
    cout << a << " + " << b << " = " << sum << endl;

    //typeid().name을 통해 type을 알아낼 수 있다.
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(pointer).name() << endl;
    cout << typeid(sum).name() << endl;

    //string class
    string str = "Hello";
    //iterator : 반복문 (begin : 시작 주소 반환 / end : 끝 주소 반환)
    //auto it = str.begin();

    string::iterator it;

    for (it = str.begin(); it < str.end(); it++) {
        cout << *it;
        //begin과 end는 시작 주소와 끝 주소를 반환 함으로 그 주소에 저장되어 있는 값을 알기 위해서는 * 연산자가 필요하다.
    }
    cout << endl;

    for (auto itr = str.begin(); itr != str.end(); ++itr) {
        cout << *itr;
    }
    cout << endl;

    //decltype : auto보다 조금 더 정교한 type 추론

    int num = 3;
    const int const_num = 10;

    auto auto_1 = const_num; // auto_1의 type : int -> const 없이 그냥 int로 추론
    decltype(const_num)decl_1 = const_num; // decl_1의 type : const int

    decltype(num) decl_2 = num;
    decltype((num)) decl_3 = num; // ((int))하게 되면 int & 로 타입을 추론하게됨

    decl_2 = decl_2 + 1; // decl_2는 int 이므로 decl_2 + 1은 num에 영향을 안줌
    cout << num << '\t' << decl_2 << "\n";

    decl_3 = decl_3 + 1; // decl_3는 & int이므오 decl_3 + 1을 하게 되면 num도 영향을 받음
    cout << num << '\t' << decl_3 << '\n';

}

int for_while(){
    // ++i 와 i ++ : 1씩 증가라는 의미는 같음,  i++를 하게 되면 임시 변수를 생성 하게됨 =>++ i가 속도 측면에서 빠름
    cout << "----- for -----" << endl;

    for (int i = 0 ; i < 10 ; i ++ ){
        cout << i ;
    }
    cout << endl;

    for (int j = 0 ; j != 10; ++j){
        cout << j;
    }
    cout << endl;

    cout << "----- while -----" << endl;

    int i = 0;
    while(i < 10){
        cout << i ;
        i = i + 1;
    }
    cout << endl;

    int j = 0;
    while(j != 10){
        cout << j;
        ++ j;
    }
    cout << endl;

}

