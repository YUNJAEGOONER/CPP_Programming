#include <iostream>
using namespace std;

int practice2_2(){
    //2차원 배열을 만든 후, 그 배열의 행과 열의 합을 구하기

    int row_size;
    int column_size;
    cin >> row_size >> column_size;

    int intArray[row_size][column_size];

    for (int i = 0 ; i < row_size ; i ++){
        for (int j = 0 ; j < column_size ; ++j){
            cin >> intArray[i][j];
        }
    }

    for (int i = 0 ; i != row_size ; i ++){
        int sum_column = 0;
        for (int j = 0 ; j != column_size; j ++){
            sum_column = sum_column + intArray[i][j];
        }
        cout << sum_column << " ";
    }
    cout << endl;

    for (int i = 0 ; i != column_size ; i ++){
        int sum_row = 0;
        for (int j = 0 ; j != row_size; j ++){
            sum_row = sum_row + intArray[j][i];
        }
        cout << sum_row << " ";
    }


}