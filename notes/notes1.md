# Modern C++

Instructor using windows and VSCode
I am using Mac and CLion

C++ beginner - intermediate concepts
- Ranges
- Modules
- Concepts
- CoRoutines
- Lambdas
- semantics
- ....

- The course also goes through cppreference.com <- default reference for C++

## Chapter 3 Basic Structure of a CPP program (Skip Chapter 2 for install)

```c++
// Imports
#include <iostream>

// global variables
using namespace std;


// main function
int main(){
    std::cout <<"Hello from CLion" << std::endl ;
    std::cout <<"Bye";
    return 0;
}
```

Note:
- Imports
- Namespace
- Comments
- main is returning 0

#### Errors and Warnings
- Ultimate goal of a dev is to generate code that executes without trouble
- 3 types of errors
  - Runtime Error -> Mostly logical error
  - Compile time Error -> Mostly syntax or variable error 
  - Warnings

#### Statements and functions
- Statement is an independent piece of C++ that makes sense independently
  - All statements end with a semicolon
  - All statements are executed from top to bottom
- A function is like a math function that takes inputs **BUT gives only one object as output**
  - Each function is defined with its return type
  - It can accept many inputs as args

#### Core Features, Standard Library, STL

Compared to python below
- Core features are features that come with the base C++ system -> minimal python
- standard library-> all packages like json, os, collections, etc that come with base python
- STL - Collection of container types
  - Containers of algos, iterators, etc
  - Will cover more in future

## Chapter 4 Variables
- Multiple types, variables have to be declared with type, `auto` keyword if you want compiler to auto deduce type
- Number systems: OCTAL, Hexadecimal, binary and decimal

## Chapter 5 operations on data
- **NOTE** some operators in C++ have left to right and right to left movement
- Follow operator precedence table
- libraries `#include <iostream>`, `<ios>`, `<iomanip>`
- Mathematical operators `+`, `-`, `*`, `/`, `%`
- Prefix and postfix operator `--a`, `a--`, `++b`, `b++`
- Compound assignment operators `+=`, `-=`, `*=`, `/=`, `%=`
- Comparison operators `<`, `>`, `<=`, `>=`, `==`, `!=`
- Logical operators `&&`, `||`, `!`
- output formatting `std::cout`, `std::setw` set width, `std::flush` flush output buffer, `std::dec`, `std::hex`,
`std::oct`, `std::uppercase`, `std:scientific`, `std::setprecision` etc
- library `#include <cmath>`

## Chapter 6 literals, constants and constexprs
- literals are variables that you save in memory but do not initialize
  - Example `std::cout << "size = " << size/1000 << std::endl;`
- Constants are special subset of variables that cannot be modified after initialization
  - have to be initialized at declaration
  - 2 ways to define
    - `#define double pi 3.14` <- global constant
    - `const double pi = 3.14`
- `constexpr` is a compile time computation keyword where the result of the expression is saved in the binary and not 
computed during execution
  - Compile time computation also has something called `static_insert(bool_exp)` which check compile time conditions
and returns a boolean
  - You cannot use run time variables with `static_assert`
  - Example `constexpr double pi=22/7;`
- `constinit` is also a compile time keyword that initializes values but this is a **variable not a constant**
  - Introduced in C++20
  - you can combine `const` and `constinit`
  - you cannot combine `constexpr` and `constinit`

## Chapter 7 Implicit and Explicit data conversions
- In everyday programming, the compiler converts variables into same types before performing its operations
  - Example when we multiply a float and an int, the int is automatically converted to float and evaluated
  - All conversions happen to upgrade the lower variable to the upper variable
- Explicit data conversions (avoid using mostly if possible)
  - Example `sum = static_cast<int>(x) + static_cast<int>(y)`
  - NOTE: There is a possibility of changes in expected value by casting, example sum 3 floats => 12.4 + 12.4 + 12.4
    - casting before summation, => int(12.4) + int(12.4) + int(12.4) = 36
    - casting after summation => 12.4 + 12.4 + 12.4 => int(37.2) > 37
**Overflow and underflow**
    - Happens when we try to put more data than what that type of variable can save
      - Example save 261 in a char value (overflow)
      - Example save -1 in unsigned int

## Chapter 8 bitwise operators
- Highly useful in low level hardware operations   
- Operators: `<<`, `>>`, `>>=`, `<<=`, `!=`, `&=`, `^=`
- Using masks on binary data

### printing integers in binary
- use standard library `#include <bitset>`
  - You can now use `std::bitset` as you use `std:dec`
    - Example `std::cout << "data in octal: " << std::showbase << std:: std::oct << data << std::endl;` for octal, 
`std::cout << "data in octal: " << std::bitset<16>(data) << std::endl;` for binary

### Bit Shift operators
- Let us look at a binary data object
  - Example `1011 0100`
- Applying a left shift `0110 1000` is the output of `<< 1011 0100`
- The preceding one is lost and a right shift by `>> 1` will not recover your data
- **NOTE: C++ requires static type casting to perform bitwise operations as it auto converts the type to be int not bit**
  - Example: `value = static_cast<unsigned short int>(value << 1);`

### Logical bitwise operators
- bitwise or, and, not, nand, nor, xor
- **Note: Make sure you use the right values for saving and printing to see the right operations on bits**

### Masking
- you can also use masks to modify bits in a byte of data
- a byte needs a byte sized mask
- specific results require specific operations to be done on a char
  - Example: Convert required bit in byte to be 1, all others to remain unchanged
    - `1011 0100` to become `1011 0101` mask is `0000 0001` and performing an _OR_ operation
    - Or with LHS || 0 always gives LHS
    - Or with LHS || 1 will always give 1
    - AND with LHS || 0 will always give 0
    - AND with LHS || 1 will always give LHS
    - Toggling a bit will always give its opposite
  - You can do this to multiple bits at the same time
  - You can also perform operations in sequence to get the output as needed
- Usage examples
  - A lot of boolean arguments and manipulation libraries use masking
  - You also use bytes to store color information
    - Example RGBA Red, green, blue, and Alpha(transparency)

## Chapter 9 Variable lifetime and memory and scope
- Variable Lifetime: Defined as period of time it stays alive in memory
- 3 types:
  - static: Dies when program dies
  - dynamic: Dies at point of choosing
  - local: Dies when block ends
- Variable Scope: A local subspace where variables can be stored and used
  - Variables will not be usable outside scope
  - All variables declared in outer scope will be usable in the inner scope

## Chapter 10 Control Flow
- IF/ELSE IF/ELSE statements
- SWITCH Statements
  - `break` necessary
  - `default` also necessary 
  - curly braces for `case` is not necessary
  - Entire switch statement block is one scope 
  - Be careful not to add variable initialization inside case statements
example for reference
```c++
const int Pen {30};
const int Marker {40};

int tool {Pen};
switch (tool) {
    case Pen: {
        std::cout << "Active tool is pen" << std::endl;
    }
    break;
    case Marker: {
    std::cout << "Active tool is marker" << std::endl;
    }
    break;
    default: {
        std:cout << "Nothing Selected" << std::endl; 
    }
    break;
}
```
- TERNARY EXPRESSION: `result = (condition) ? option1 : option2 ;`
  - Types of option1 or option2 have to be the same
- IF CONSTEXPR: A compile time if condition that can be hard coded
  - is a feature of c++ 17
example:
```c++
constexpr bool condition{false};

if constexpr(condition) {
    std::cout << "Condition is True" << std::endl;
} else {
    std::cout << "Condition is not true" << std::endl;
}
```
- IF INITIALIZERS: You can declare variables inside the if condition before your expression returns the boolean
  - The variable is active in the if else block and dies when scope goes outside
example:
```c++
int main() {
    bool go {true};
    
    if (int speed {30}; go){
        if (speed > 20) {
            std::cout << "speed is too fast" << std::endl;
        } else {
        std::cout << "speed is okay at "<< speed << std::endl;
        }
    }
}
```
- SWITCH INITIALIZERS: you can also apply the same logic to switch statements
  - Example: `switch (double strength {3.56}; tool) { ... }`

## Chapter 11 Loops
- FOR loops: Most commonly used loops in CS
  - NOTE: UNLIKE PYTHON, You need to initialize the variable inside the loop to print
  - You can create multiple variables in the loop
  - You can also add multiple expressions in the execution of iterator action
  - NOTE: COMMA OPERATOR: PERFORMS MULTIPLE OPERATIONS 
example: `for (int i {0}, int j {1}; i < 10; i++, j*=j;) { ... }`
