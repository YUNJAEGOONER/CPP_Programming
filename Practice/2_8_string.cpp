#include <iostream>
#include <string>
using namespace std;

int practice2_8(){

    //문자를 정수형으로 표현하게 되면 그 문자의 아스키 코드값이 나오게 된다.
    //대문자 A는 65 - 소문자 a 는 97

    int array[26] = {0};

    string str;
    cin >> str;

    for (int i = 0 ; i < str.size(); i++){
        int index = str[i] - 97;
        if (array[index] == 0){
            array[index] = i + 1;
        }
    }

    for (int i = 0 ; i < size(array) ; i ++ ){
        cout << array[i] << " ";
    }

}