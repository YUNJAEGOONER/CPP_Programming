#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int practice2_7(){

    //vector의 erase와 remove 활용하기
    //remove의 경우에는 원소가 지워지는게 아니라 그 원소자리를 비우고 뒤에 있는 원소들로 채워짐으로 erase를 함께 사용해야한다.

    //remove만 사용할 경우
    // ex){17,18,19,20} - > {17,19,20,20}
    // 18을 remove하게되면 18 뒤에 있는 19,20 이 한칸씩 땡겨지면서 18의 빈자리를 채우고 맨 끝자리에는 20이 그대로 남아있다.

    int size;
    cin >> size;

    vector<int> vec(size);

    for (int i = 0; i < vec.size(); i ++){
        cin >> vec[i];
    }


    int del;
    cin >> del;

    vec.erase(vec.begin()+del);

    int del2;
    cin >> del2;

    auto itr =remove(vec.begin(),vec.end(),del2);
    vec.erase(itr,vec.end());

    cout << vec.size() << endl;

    for (int i = 0; i < vec.size(); i ++){
        cout << vec[i] << " ";
    }

}
