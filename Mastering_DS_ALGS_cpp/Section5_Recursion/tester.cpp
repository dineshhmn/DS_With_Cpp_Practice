//
// Created by Dinesh Hemnani on 8/9/22.
//


#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//void fun1(int n);
//void fun2(int n);
//
//
//void fun1(int n){
//    if (n>0){
//        fun2(n-1);
//        cout << n << endl;
//    }
//}
//
//void fun2(int n){
//    if (n>0){
//        fun1(n-1);
//        cout << n << endl;
//    }
//}
//
//int fun3(int n){
//    if (n>0){
//        cout << n << endl;
//        return fun3(fun3(n-1));
//    }
//    else{return 0;};
//}
//
//int sum_n(int n){
//    if (n==0){
//        return 0;
//    }
//    return sum_n(n-1) + n;
//}
//
//int fact_n(int n){
//    if (n==0 or n==1){
//        return 1;
//    }
//    return fact_n(n-1) * n;
//}
//
//int pow_n(int a, int b){
//    if (b == 1){
//        return a;
//    }
//    return pow_n(a, b-1) * a;
//}
//
//int pow_n_faster(int a, int b){
//    if (b==1){
//        return a;
//    }
//    else if (b % 2 == 0){
//        return pow_n_faster(a*a, b/2);
//    }
//    else{
//        return pow_n_faster(a*a, (b-1)/2) * a;
//    }
//}
//
//double taylor_series(int x, int n){
//    static double p=1,f=1;
//    double r;
//    if (n == 0){
//        return 1;
//    }
//    else {
//        r = taylor_series(x, n-1);
//        p = p * x;
//        f = f * n;
//        return  r + (p/f);
//    }
//}
//
//double ts_homer_rule(int x, int n){
//    static double r=1;
//    if (n == 0){
//        return r;
//    }
//    r = 1 + x*r/n;
//    return ts_homer_rule(x, n-1);
//}
//
//int fib(int n){
//    if (n<=1){
//        return n;
//    }
//    return fib(n-2) + fib(n-1);
//}
//
//
//
//
//int F[10];
//
//int fib_memo(int n){
//    //cout << n << endl;
//    if (n <= 1){
//        F[n] = n;
//        return n;
//    }
//    else{
//        if (F[n-2] == -1){
//            F[n-2] = fib_memo(n-2);
//        }
//        if (F[n-1] == -1){
//            F[n-1] = fib_memo(n-1);
//        }
//        F[n] = F[n-2] + F[n-1];
//        return F[n];
//    }
//}
//
//int pasc(int n, int r){
//    if (r == 0 || n == r){
//        return 1;
//    }
//    return pasc(n-1, r-1) + pasc(n-1,r);
//}
////
//int tow_hanoi(int n, int a, int b, int c){
//    if (n > 0){
//        tow_hanoi(n-1, a, c, b);
//        cout << a << c << endl;
//        tow_hanoi(n-1, b,a,c);
//    }
//}

int f (int &x, int c)
{
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    cout << x << c << endl;
    return f(x,c) * x;

}

int fun (int n)

{

    int x=1, k;

    if (n==1) return x;

    for (k=1; k<n; ++k) {

        x=x + fun (k) * fun (n -k);
    }
    return x;
}

int main(){
    int i = 5;
    int b = 5;
//    cout << pow_n_faster(b, a) << endl;
//    cout << pow_n(b, a) << endl;
//    cout << taylor_series(b,a) << endl;
//    cout << ts_homer_rule(b,a) << endl;
//    cout << fib(7) << endl;
//    for (i=0;i<10;i++){
//        cout << F[i] << endl;
//        F[i] = -1;
//    }
//    cout << fib_memo(7) << endl;
//    cout << pasc(5,3) << endl;
    cout << fun(2) << endl;
}

