#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int container_vector(){

    //벡터 선언
    vector<int> vec1;

    //push_back(i) : i가 vector의 맨 끝에 삽입
    for (int i = 0 ; i < 5 ; i ++){
        vec1.push_back(i);  //push_back(i) : i가 vector의 끝에 추가된다.
    }

    //empty() : vector의 empty 여부를 알려준다. empty인 경우 True(1), 아닌경우 False(0)
    //size() : vector에 저장되어 있는 원소의 개수를 알려준다
    //capacity() : vector는 추가적인 원소들을 저장하기 위한 여유 공간을 갖는다.
    cout << "empty :"<< vec1.empty() << " size :"<< vec1.size() << " capacity :"<< vec1.capacity() << endl;  // 0 10 16

    //front() : vector의 가장 첫 번째 원소를 알려준다.
    //back() : vector의 마지막 원소를 알려준다.
    cout << "first element : " << vec1.front() << '\t' << "last element : " << vec1.back() << '\n';

    //data() : 벡터 내부 배열의 포인터, vector의 첫 번쨰 요소에 대한 주소를 return 해준다.
    for(int i = 0 ; i < vec1.size(); ++i){
        cout << "address : " << (vec1.data() + i) << '\t' << "value : " << *(vec1.data() + i) << endl;
    }

    // [i] 또는 .at(i)을 통해 vector에 접근 할 수 있다.
    for (int i = 0; i < vec1.size(); ++i){
        if (i % 2 == 0){
            cout << vec1[i] << ' ';
        }
        else{
            cout << vec1.at(i) << ' ';
        }
    }
    cout << endl;

    //resize() : vector의 크기를 줄이기
    vec1.resize(3);
    for (int i = 0 ; i < vec1.size() ; i ++ ){
        cout << vec1[i] << '\t';
    }

    cout << '\n' << "size : " << vec1.size() << " capacity : "<< vec1.capacity() << '\n';
    //shrink_to_fit() : size와 capacity가 같게 조정해줌
    vec1.shrink_to_fit();
    cout  << "size : " << vec1.size() << " capacity : "<< vec1.capacity() << endl;

    // clear() : 벡터 안의 모든 원소를 삭제
    vec1.clear();
    cout << vec1.empty(); // True(1) : clear()로 벡터의 모든 원소가 삭제 => empty

    return 0;
}

int cotainer_vector_2() {

    //벡터 선언 방식

    //size를 이용한 vector 선언 - > vector <type> vector's name ( size )
    cout << "Enter the size of the vector :";
    int size;
    cin >> size;
    vector <int> size_vector (size);
    //모든 원소가 int의 기본 값인 0으로 초기화 된다.
    for (int i = 0; i < size_vector.size() ; i ++ ){
        cout << size_vector.at(i) << '\t';
    }
    cout << endl;

    //brace initialization 을 통한 vector 초기화
    vector<int> brace_vector {1,2,3,4,5};
    cout << "Empty : " << brace_vector.empty() << " size :" <<  brace_vector.size() << " Capacity : " << brace_vector.capacity() << '\n';

    //배열을 이용한 vector 초기화
    // vector <type> vector's 이름 ( 시작 : 배열 + index , 끝 : 배열 + index + 1)

    int IntArray [10] = {10,9,8,7,6,5,4,3,2,1};
    vector<int> array_vector(IntArray + 1 ,IntArray+6); // array vector = {9,8,7,6,5}

    for (int i = 0; i < array_vector.size() ; i ++ ){
        cout << array_vector.at(i) << '\t';
    }
    cout << endl;

    return 0;
}

int comparison_vector_3(){

    //비교 ' == ' 와 ' != ' 을 이용해 vector들 간의 비교연산이 가능

    vector<int> vector1 {1,2,3,4,5};
    vector<int> vector2 = vector1;

    if (vector1 == vector2){
        cout << "Same Vector" << endl;
    }
    else{
        cout << "diffrent vector" << endl;
    }

    vector1.push_back(6);

    if (vector1 != vector2){
        cout << "diffrent vector" << endl;
    }
    else{
        cout << "Same Vector" << endl;
    }

}

int vector_itr(){
    vector<int> vector_itr {300,400,500,600,700};

    //vector의 iterator -> vector<type>::iterator variable_name;
    vector<int>::iterator it;
    for (it = vector_itr.begin(); it != vector_itr.end(); ++it){
        cout << *it << '\t';
    }
    cout << endl;

    //iterator를 이용하여 대입이 가능
    vector<int> vector_itr_2(5);

    vector<int>::iterator itr;
    int integer = 0;
    for (itr = vector_itr_2.begin(); itr != vector_itr_2.end(); ++itr){
        *itr = 100 * integer;
        integer = integer + 1;
    }

    //insert(위치, 원소) : 원하는 위치에 해당원소를 삽입
    vector_itr_2.insert(vector_itr_2.begin()+1,900); //begin() + 1 즉, 첫 번쨰 원소뒤에 900을 삽입
    //erase( 위치 ) : 해당 위치에 있는 원소를 삭제
    vector_itr_2.erase(vector_itr_2.end()-1); //마지막 요소가 삭제됨

    //const iterator : 읽기 전용
    vector<int>::const_iterator const_itr;
    //cbegin()과 cend()사용
    for (const_itr = vector_itr_2.cbegin(); const_itr != vector_itr_2.cend(); ++const_itr){
        cout << *const_itr << '\t';
    }
    cout << endl;

    vector<int> vector_function {0,1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it2;
    it2 = vector_function.begin();

    it2 = it2 + 2; // it2는 vector_function[2]를 가르키고 있다.
    cout << *it2 << endl;
    //next() : 다음 요소의 주소를 가져옴
    cout << "next() : " << *(next(it2)) << endl;
    //prev() : 이전 요소의 주소를 가져옴
    cout << "prev() : " << *(prev(it2)) << '\n';
    //advance(iterator,n) : + n 번째 요소를 가져옴
    advance(it2,3); //it2는 [2] - > [ 2 + 3 ]
    cout << "advance() : " << *it2 <<'\n';

    //begin(container) : 컨테이너의 시작점의 주소를 가져옴
    it2 = begin(vector_itr_2);
    cout << "begin(container) : " << *it2 << endl;
    //end(container) : 컨테이너의 끝의 주소를 가져옴
    it2 = end(vector_itr_2);
    cout << "end(container) : " << *it2 << endl;
    //cbegin(container), cend(container) : 읽기 전용

    //rbegin을 이용해 vector를 거꾸로 출력하기 -> reverse_iterator 사용
    vector<int> ::reverse_iterator reverseitr;
    for (reverseitr = vector_itr_2.rbegin(); reverseitr != vector_itr_2.rend(); ++reverseitr){
        cout << *reverseitr <<'\t';
    }
    cout << endl;

    return 0;
}

int stl_algorithm(){
    vector<int> vec {17,51,22,35,26,51,19};
    vector<int>::iterator itr;


    //find(시작, 끝, 찾으려는 값) : 범위 내에서 값을 찾는다.
    itr = find(vec.begin(), vec.end(), 17);
    cout << *itr << endl;
    //count(시작, 끝, count하려는 값) : 범위 내에서 해당 값의 개수를 센다.
    cout << count(vec.begin(),vec.end(),51) << endl;

    //replace(시작, 끝, 찾는 값, 수정값) : 범위 내에서 값을 찾고, 수정 값으로 해당 요소를 변경
    //{17,51,22,35,26,51,19} -> {17,51,22,35,26,51,21}
    replace(vec.begin(),vec.end(),19,21);

    //remove(시작, 끝, 값) : 범위 내에서 해당 값을 삭제
    //remove를 하게 되면 26이 빠지고 51, 21의 index가 하나씩 앞으로 가게되고, 21의 자리에는 21여전히 남아있게 된다.
    // {17,51,22,35,26,51,21} -> {17,51,22,35,51,21,21}
    remove(vec.begin(),vec.end(),26);
    //vecotor에 해당 요소를 완전히 지우기 위해서는 erase와 같이 써준다.
    // {17,51,22,35,51,21,21} -- > {17,51,22,35,51}
    vec.erase(remove(vec.begin(),vec.end(),21),vec.end());


    //fill(시작, 끝, 값) : 범위 내에있는 요소들을 모두 해당 값으로 채운다.
    // {17,51,22,35,51,21,21} -> {8,8,22,35,51}
    fill(vec.begin(),vec.begin()+2,8);

    //random_shuffle(시작, 끝) : 범위 내의 요소들을 임의순서로 섞는다.
    random_shuffle(vec.begin(),vec.end());

    for(itr = vec.begin(); itr != vec.end(); ++itr){
        cout << *itr << '\t';
    }
    cout << '\n';

    //sort(시작, 끝) : 범위 내의 요소들을 정렬
    sort(vec.begin(),vec.end());

    //unique(시작, 끝) : 범위 내의 요소들중 중복된 요소들 가져옴 ->중복되는 값들을 vector의 제일 뒷부분으로 보낸다.
    //중복된 요소들을 삭제하기 위해서는 remove와 마찬가지로 erase와 같이 써준다.
    vec.erase(unique(vec.begin(), vec.end()),vec.end());

    for(itr = vec.begin(); itr != vec.end(); ++itr){
        cout << *itr << '\t';
    }
    cout << '\n';

    //reverse(시작, 끝) : 범위 내의 요소들의 순서를 뒤집는다.
    reverse(vec.begin(),vec.end());

    //auto를 이용한 const_iterator 사용
    for(auto cit = vec.cbegin(); cit != vec.cend(); ++cit){
        cout << *cit << '\t';
    }
    cout << '\n';

    //max_element(시작, 끝), min_element(시작, 끝) : 범위 내의 최대/최소가 저장되어 있는 주소 리턴
    //auto를 이용한 type 추론
    auto a = min_element(vec.begin(),vec.end());
    cout << "index : " << a - vec.begin() << " Value : " << *a;

    return 0;
}

int stl_string(){

    string str = "Hello World";
    cout << str << '\n';

    //data() c.str() : 문자열 포인터 리턴
    for(int i = 0; i < str.size(); i ++){
        if (i % 2 == 0){
            cout << i << " : " << *(str.data()+i) << " ";
        }
        else{
            cout << i << " : "<< *(str.c_str()+i) << " ";
        }
    }
    cout << endl;

    //stoi() : string을 int형으로 바꾸어줌
    //stod() : string을 double형으로 바꾸어줌
    string string_int1 = "123";
    string string_int2 = "456";

    cout << "String : " << string_int1 + string_int2 << endl; // 123456
    cout << "Integer : " << stoi(string_int1) + stoi(string_int2)<< endl; //579

    string str2;
    //empty() : 빈 문자열인지 아닌지를 확인해 준다. 비어있다면 True(1) , 아니라면 False(0)
    cout << "Empty : "<< str2.empty() << endl;

    //"s--t--r--i--n--g"뒤에 s를 붙여 문자열임을 명시
    //str2 = "Come On You Gunners"; -> s없어도 무관
    str2 = "Come On You Gunners"s;
    //size() / length() : string의 길이를 알려줌
    //capacity() : string도 vector와 마찬가지로 여유공간을 갖고 있다.
    cout << "Empty : " <<str2.empty() << " length : "<< str2.length() << " capacity : " << str2.capacity() << endl;

    // vector와 마찬가지로 비교연산자 사용가능
    string str3(str2); //str2의 값을 복사해 str3 생성 및 초기화
    if(str2 == str3){
        cout << "Same String" << endl;
    }
    else{
        cout << "diffrent String" << endl;
    }

    //find('char' or "string") : 처음 'char' 나타난 위치(index)를 return "string"의 경우 string의 첫 문자의 index를 return
    cout <<"C : " <<str2.find('C')<< " On : " << str2.find("On") << endl;
    //rfind('char' or "string") : 맨 마지막에 'char' 나타난 위치(index)를 return "string"의 경우 string의 첫 문자의 index를 return
    cout <<"G : " <<str2.rfind('G')<< " You : " << str2.rfind("You") << endl;

    //push_back('char') : 문자열의 맨 뒤에 'char'를 삽입
    str2.push_back('A');
    cout << str2 << endl;
    //pop_back() : string의 맨 마지막 문자 삭제
    str2.pop_back();
    //문자열 병합
    str2 = str2 + " ARSENAL";
    cout << str2 << endl;

}

int int_to_string(){

    //int를 string으로 변환하는 방법
    int integer1 = 123;
    int integer2 = 321;

    // 1 . stringstream 사용 include <sstream>
    stringstream intstringstream;
    intstringstream << integer1; //정수 integer1을 intstringstream에 집어 넣는다
    string str1;
    intstringstream >> str1; //정수 integer1이 string으로 변환되어 str1에 저장된다.
    //str1 = intstringstream.str();
    //intstringstream.str()

    // 2. stoi() 사용
    string str2 = to_string(integer2);
    cout << str1 + str2 << endl;

    vector<string> str_vec1(5); // string 5개를 담을 수 있는 vector
    vector<string> str_vec2(5);

    for (int i = 0; i < str_vec1.size(); i++){
        //to_string() 을 이용해 int를 string으로 바꾼후,벡터에 저장
        str_vec1[i] = to_string(i*100);
    }

    for (int i = 0; i < str_vec2.size(); i++){

        //stringstream을 이용해 int를 string으로 바꾼후
        stringstream inttostring;
        inttostring << i * 100;
        string str_value;
        inttostring >> str_value;

        //string을 벡터에 저장
        str_vec2[i] = str_value;
    }

    if(str_vec1 == str_vec2){
        cout << "Same Vector" << endl;
    }
    else{
        cout << "Different Vector" << endl;
    }

    return 0;

}