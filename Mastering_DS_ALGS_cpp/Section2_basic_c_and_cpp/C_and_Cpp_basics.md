# Basics
Topics Covered
- Arrays
- structures
- pointers
- reference
- Parameter Passing
- Classes
- Constructor
- Templates

### Arrays
- Collection of similar objects
```c++
#include <iostream>

int main(){
int A[5];
int B[5] = {2,4,5,6,7};
for (int i=0;i<5;i++) {
std::cout << B[i] << std::endl;
}
}
```

**NEW NEW NEW**
**FOREACH LOOP CPP**
 ```c++
int main() {
    int A[5] = {2,3,4,5,6};
    for (int x:A){
        cout << x << endl;
    }
}
```

### Structures
- Complex DS in C, based on primitive types in C
  - Example: Rectangle=> composed of 2 values len, width
```c++
struct Rectangle {
    int len;
    int width;
};

int main() {
    struct Rectangle r;
    struct Rectangle s = {10,5};
    cout << "area" << s.len * s.width << endl; // should print 50
}
```
Examples of usage:
- Complex numbers: `a+ib` with `a` and `b` being floats
- Real World Objects: students, employees, books, cards

### Pointers
- Pointers are address variables that store the address of another variable
- Although all pointers occupy same amount of memory, they have types representing the object being pointed
- the major reasons to use
  - **access heap memory (done using malloc)**
  - resources outside program like keyboard, network, etc
  - passing variables by reference

```c++
int pointer_func(){
    int a = 10;
    int *p = &a; // declare and initialize
    printf('%d',*p); // usage or deference
}

#include <stdlib.h>

int main() {
    int *p;
    p = (int *) malloc(10) // malloc returns void type pointer, cast to int remember to delete in large code base
}
```

### Reference
- Similar to shallow copy in Python
- Only available in Cpp and not in C
- Used to pass values to functions for modification
example
```c++
int main() {
    int a = 10;
    int &r = a; // Define r as a reference of a
    r++;
    cout << a << endl; // expect 11
}
```

**POINTERS TO STRUCTS**
- pointers to structs are used in a manner that is slightly different to other variables
```c++
struct Rectange {
    int length;
    int width;
};

int main() {
    struct Rectangle r = {10, 5};
    struct Rectangle *p = &r;
    
    struct Rectangle *q;
    q=new Rectangle;
    
    
    // Change length using pointers 2 methods, `p.length` will not work 
    (*p).length = 20;
    p->length=20; 
}
```
To create an object of type rectangle in Heap, you can use malloc (C Style) or `new` keyword (Cpp style)

### Functions
- Structures are a group of data, functions are a group of instructions
- Functions are instructions broken into smaller simpler task, that can be used inside the main function
- C follows modular programming, and Cpp follows object-oriented programming 
- When a function is called, the parameters passed are called `actual parameters`
- when the control is inside the called function, the arguments are called `formal parameters`
Example:
```c++
#include <iostream>

using namespace std;

int add (int a, int b){ // formal parameters
    return a + b;
}

int main(){
    int num1=10, num2=20, sum;
    sum = add(num1, num2); // actual parameters
    cout << sum << endl;
}
```

**Passing parameters to functions**
- Three methods
  - Call by value: creates copies of actual values and any changes in formal parameters dont result in changes
  - Call by address: actual parameters are pointers, and you operate on pointer objects
  - Call by reference: Only in Cpp, you pass references to functions instead of pointers

- If you do not want to modify the passed values, the arguments must be passed as call by value

Example
```c++
void swap_value (int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_address (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_reference(int &x, int &y) { // Only passing a reference to original function
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a =5, b = 10;
    swap_value(a,b); 
    swap_address(&a, &b);
    swap_reference(a,b);
}
```

**Passing DS as arguments and returning arrays**
- **Arrays cannot be passed or returned as call by value function arguments in C and Cpp**
- DSes are also returned as pointers

```c++
void func(int A[], int n) { // A is pointer to array and n is length of array
// void func(int *A, int n) { Generic pointer A, can be of any int type, not necessarily array
    int i;
    for (i=0; i<n; i++){
        cout << A[i] << endl;
    }
}

int * func2(int n) {
    return (int *).malloc(n*sizeof(int))
}

int main() {
    int A[5] = {1,2,3,4,5};
    func(A, 5);
    int *a = func2(5);
}
```
NOTE: you cannot pass arrays by call by value, but you can pass structs as call by value. arrays inside structs will also work

Example

```c++
struct Rectangle{
    int length;
    int width;
};

// Call by address
void init(struct Rectangle *r, int a, int b){
    r->length = a;
    r->width = b;
}

// Call by value
void area(struct Rectange r){
    cout << r.length * r.width << endl;
}

// call by address again
void change_len_ref(struct Rectangle *r){
    r->length=10;
}

int main(){
    struct Rectangle r;
    init(&r, 1, 1);
    area(r);
    change_len_ref(&r)
}
```

### Classes and Constructors
Converting the above code to a class

Three steps:
- Change `struct to class` and extend the parend to whole code
- remove all references to self object
- add public and private values of class

```c++
class Rectangle{
private:
    int length;
    int width;
      
public:  
    // Call by address
    void init(struct Rectangle *r, int a, int b){
    length = a;
    width = b;
    };

// Call by value
    void area(struct Rectange r){
        cout << r.length * r.width << endl;
    };

    //    all by address again
    void change_len_ref(struct Rectangle *r){
        r->length=10;
    };
    
    ~Rectangle(){cout<<"Bye"; // remove dynamically allocated memory
    }
};        
        
int main(){
    Rectangle r;
    r.init(1, 1);
    r.area();
    r.change_len_ref();
    r.area();
}
```

**Types of constructors**
- Initializers
- facilitators
- accessors or getters
- setters
- destructors

**NOTE: Remember Scope resolution operator in Cpp and the `this` object (similar to self in python)**

```c++
Rectangle::Rectangle(int l, int b){
    length = l;
    width = b;
}

int Rectangle::area(){ // area is defined as a contructor in scope of Rectangle
    return length*width;
}
```

### Template Functions and Classes
- As Cpp is object-oriented in its nature, you can create your own classes as templates for inheritance and use them
Example
```c++
template <class T>
class Arithmatic{
        private:
            T a;
            T b;
        public:
            Arithmatic (T a, T b);
            T add();
            T sub();
            };
```

