#include <iomanip>
#include <iostream>
using namespace std;

int fixed_precision(){

    double num = 52345.98765;

    //precision ->앞 자리 수부터 몇 번째 까지 (1.xx 형태) 표현
    cout << setprecision(2) << num << endl;   // '5.2'e+04 = 5.2 * 10^4
    cout << setprecision(3) << num << endl;   // '5.23'e+04 = 5.23 * 10^4

    //fixed + precision -> 소수 몇 번째 자리까지 나타내기
    cout << fixed << setprecision(3) << num << endl;


}