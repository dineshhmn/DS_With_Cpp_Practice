//
// Created by Dinesh Hemnani on 8/8/22.
//

#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

//int test1(){
//    int A[5];
//    int B[5] = {2,4,5,6,7};
//    for (int i=0;i<5;i++) {
//        std::cout << B[i] << std::endl;
//    }
//    printf("%d\n",A[0]);
//}
//
//struct Rectangle {
//    int length;
//    int width;
//};

//struct Rectangle r2; // Global variable

//// Use Struct
//int struct_func(){
//    struct Rectangle r1={10,5};
//    printf("%d\n",r1.length * r1.width);
//}
//
//int ref() {
//    int a = 10;
//    int &r = a; // Define r as a reference type variable and initialized to a
//    r++;
//    cout << a << endl; // expect 11
//}

//struct Rectange {
//    int length;
//    int width;
//};

//int test_rect() {
//    struct Rectangle r = {10, 5};
//    struct Rectangle *p = &r;
//
//    // Change length using pointers 2 methods
//    (*p).length = 20;
//    p->length=20;
//    cout << r.length << r.width << endl;
//}

//int * func2(int n) {
//    return (int *)malloc(n*sizeof(int));
//}
//
//int pointer_func() {
//    int A[5] = {1,2,3,4,5};
//    //func(A, 5);
//    int *a = func2(5);
//}

//struct Rectangle{
//    int length;
//    int width;
//};
//
//// Call by address
//void init(struct Rectangle *r, int a, int b){
//    r->length = a;
//    r->width = b;
//}
//
//// Call by value
//void area(struct Rectangle r){
//    cout << (r.length * r.width) << endl;
//}
//
//int mai1n(){
//    struct Rectangle r;
//    init(&r, 1, 1);
//    area(r);
//}

class Rectangle{
    private:
        int length;
        int width;

    public:
        // Call by address
        void init(int a, int b){
            length = a;
            width = b;
        };
        // Call by value
        void area(){
            cout << length * width << endl;
        };
        // call by address again
        void change_len_ref(){
            length=10;
        };

        ~Rectangle(){ // destructor
            cout << "Bye" <<endl;
        };
};

int main(){
    Rectangle r;
    r.init(1,1);
    r.area();
    r.change_len_ref();
    r.area();
}