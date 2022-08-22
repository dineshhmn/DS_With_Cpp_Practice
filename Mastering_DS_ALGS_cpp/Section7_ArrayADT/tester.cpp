//
// Created by Dinesh Hemnani on 8/17/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int bin_search(int *arr, int val){
    int l, h, mid;
    l = 0;
    h = sizeof(arr) -1;
    while (l <= h) {
        mid = floor((l+h)/2);
        if (val == arr[mid]){
            return mid;
        }
        else if (val < arr[mid]){
            h = mid -1;
        }
        else if (val > arr[mid]){
            l = mid + 1;
        }
    }
    return -1;
}

struct Array {
    int *A;
    int length;
};

void inplace_swap(struct Array *arr){
    int t;
    int l = 0;
    int r = sizeof(*arr)-1;
    //cout << r << endl;
    while (l <= r){
        t = (*arr).A[l];
        (*arr).A[l] = (*arr).A[r];
        arr->A[r] = t;
        l+=1;
        r-=1;
    }
}

void insert(struct Array *arr){
    for (int i=2;i==(*arr).length+2;i++){
        (*arr).A[i] = i+2;
    }
}

int main() {
    struct Array arst;
    arst.A = new int[5];
    arst.length = 5;
    insert(&arst);
    for (int i = 0; i < arst.length; i++){
        cout << arst.A[i] << endl;
    }
    inplace_swap(&arst);
    for (int i = 0; i < arst.length; i++){
        cout << arst.A[i] << endl;
    }
}