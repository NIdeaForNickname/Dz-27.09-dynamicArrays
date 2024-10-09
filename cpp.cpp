#include "myDynam.h"
#include <iostream>

using namespace std;
int main(){
    int aSize = 7;
    int* a = new int[aSize];
    for(int i = 0; i < aSize; i++){
        a[i] = i;
        cout << a[i] << ", ";
    }
    cout << "\n";
    myPop(a, aSize, 3);
    for(int i = 0; i < aSize; i++){
        cout << a[i] << ", ";
    }
    cout << "\n";

    myInsert(a, aSize, 10, 3);
    for(int i = 0; i < aSize; i++){
        cout << a[i] << ", ";
    }
    cout << "\n";

    delete[] a;

    // пример создания и удаления 2д массива
    int** tdDynamicArray = new int*[5];
    for(int i = 0; i < 5; i++){
        tdDynamicArray[i] = new int[i]; 
    }
    // no sense to fill it
    // Удаление сперва подмасивов
    for(int i = 0; i < 5; i++){
        delete[] tdDynamicArray[i];
    }
    // удаление основного массива
    delete[] tdDynamicArray;

}