#include "header_for_1_4.h"

void update(int* a, int* b){
    int operand1 = *a;
    int operand2 = *b;

    *a = operand1 + operand2;
    *b = operand1 - operand2;
}

