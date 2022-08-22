#include <iostream>

constexpr int get_value(){
    return 3;
}

int addnumbers(int a, int b) {
    return a + b ;
}

int mulnumbers(int a, int b){
    return a * b;
}

int main() {
//    constexpr
    int x = 5 ;
    int y = 10 ;
    int sum = addnumbers(x, y);
    int mul = mulnumbers(x, y);
    // Another way of declaring variables
    int p {12};
    int q {14};
    int sum2 = addnumbers(p, q);
    int mul2 = mulnumbers(p, q);
    std::cout << "Sum: " << sum << "  mul: " << mul << std::endl;
    std::cout << "Sum2: " << sum2 << "  mul2: " << mul2 << std::endl;
    return 0;
}
