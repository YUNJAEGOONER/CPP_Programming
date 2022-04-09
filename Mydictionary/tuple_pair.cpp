#include <iostream>
#include <tuple>
using namespace std;

pair<string, int>make_pair(){
    string name;
    int num;
    cin >> name >> num;
    pair<string, int> result = {name,num};
    return result;
}

tuple<string, int, int>make_tuple(){
    string name;
    int num;
    int age;
    cin >> name >> num >> age;
    tuple<string, int, int> result = {name, num, age};
    return result;
}

int tuple_pair(){
    //두 개의 값을 묶을 때는 pair, 3개 이상의 값을 묶을 때는 tuple 사용
    //map.insert(pair)가 가능
    auto pair = make_pair();

    auto tuple = make_tuple();

    cout << pair.first << " " << pair.second << endl;

    //c++ 17 부터 지원
    auto [name, number, age] = tuple;
    cout << name <<" "<<  number <<" "<< age << endl;
    cout << get<0>(tuple) << " " << get<1>(tuple) << " " <<get<2>(tuple)<< endl;

}


