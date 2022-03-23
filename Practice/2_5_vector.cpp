#include <iostream>
#include <vector>

using namespace std;

int practice2_5(){

    //2차원 벡터를 만들고 index를 활용하여 원소 출력하기

    vector<vector<int>> vector_2d;

    int row;
    int question;

    cin >> row >> question;

    for (int i = 0; i < row; ++i){
        int size;
        cin >> size;
        vector<int> vec(size);
        for (int j = 0; j < size; ++j){
            cin >> vec[j];
        }
        vector_2d.push_back(vec);
    }

    for(int i = 0; i < question ; i++){
        int indexi, indexj;
        cin >> indexi >> indexj;
        cout << vector_2d[indexi][indexj] << endl;
    }

    return 0;
}