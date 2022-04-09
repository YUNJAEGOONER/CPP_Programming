#include <iostream>
#include <algorithm>
using namespace std;

int UppperLower(){
    string str = "HelLO C++ ProGRAMming";

    //algorithm에 있는 transform 이용 -> include<algorithm>
    //to Uppers
    transform(str.begin(), str.end(), str.begin(),::toupper);
    cout << "UPPER : "<< str << '\n';

    //to Lower
    transform(str.begin(), str.end(), str.begin(),::tolower);
    cout << "lower : " << str << '\n';
}