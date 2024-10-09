#include <iostream>

using namespace std;
void myPop(int* &arr, int &N, int elemToPop){ // 1
    if (elemToPop >= N || elemToPop < 0){
        return;
    }

    int* oldArr = arr;
    arr = new int[N-1];

    int temp = 0;
    for(int i = 0; i < N; i++){
        if(i != elemToPop){
            arr[temp] = oldArr[i];
            temp++;
        }
    }
    N--;
    delete[] oldArr;
    return;
}

void myInsert(int* &arr, int &N, int elemToInsert, int index){
    if (index >= N || index < 0){
        return;
    }

    int* oldArr = arr;
    arr = new int[N+1];

    N++;
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(i != index){
            arr[i] = oldArr[temp];
            temp++;
        } else {
            arr[i] = elemToInsert;
        }
    }

    delete[] oldArr;
    return;
}



void startInsert(int* &arr, int &N, int elemToInsert){ // 2
    myInsert(arr, N, elemToInsert, 0);
}

void deleteLast(int* &arr, int &N, int elemToInsert){ // 3
    myPop(arr, N, N-1);
}

void deleteMiddle(int* &arr, int &N, int elemToInsert){ // 4.1 удаление всего что после середины
    int times = N / 2;
    for(int i = 0; i < times; i++)
        myPop(arr, N, N-1);
    // .2 удаление центрального елемента
    // myPop(arr, N, (N/2)-1);
}

void deleteFirst(int* &arr, int &N, int elemToInsert){ // 5.1 удаление всего с начала массива
    int times = N;
    for(int i = 0; i < times; i++)
        myPop(arr, N, 0);
    // .1 удаление первого элемента
    // myPop(arr, N, 0);
}