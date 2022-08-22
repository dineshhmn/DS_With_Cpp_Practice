### Arrays
- Continuous set of values stored in memory with one variable
- Each element in array is accessed by its index

```c++
int A[5]; // declare an array of 5 elements

int B[5] = {2,3,4}; //declare and initialize first 3 elements
cout << B[2] << endl; // access 3rd element of B

cout << *(B+2) << endl; // access 3rd element by pointer

int C[5] = {0}; //all elements are of value 0
```

**Static vs Dynamic arrays**
- In C language, you can only create arrays of fixed size as size has to be given during compile
- In Cpp, an array's size can be given at run time
- Both of them are created inside **stack**
- You can create new arrays inside **heap** by giving `new` keyword in Cpp or `malloc` keyword in C
```c++
inr *p, *q;
p = new int[5]; //returns pointer to memory in Cpp
q = (int *)malloc(5*sizeof(int)); // pointer to memory in C
```
- **IN C or CPP, arrays are immutable objects**
- All arrays inside stack cannot be mutated
- You can increase the size of a heap array by 
- If you want to increase the size of the array then create a larger array and change the pointer to new array finally delete old array 
- To copy elements you can use `memcpy(&q, &p, 5*sizeof(int))` or use a loop

**2D or 3D arrays**
- In C or Cpp, you can use 3 ways of creating an n-D array
- While we see that elements are stored in 2D for representation, these elements are saved in a single contiguous memory location
- During compile time, we do not get the initial address location of the array. The compiler creates a formula and references elements using that formula
- The formula is called **Row Major Mapping** or **Column Major mapping**

```c++
// method 1
int A[3][4]; // 2d array in stack

// method 2 Array pointer that points to 2nd dim arrays in heap
int *B[3];
B[0] = new int[4];
B[1] = (int *) malloc(4*sizeof(int));
B[2] = (int *) malloc(4*sizeof(int));

// method 3 double pointer method (has address of column arrays and row arrays
int **C;
C = (int *)new int[4]; // create 4 columns in one array to create columns 
C[0] = (int *) malloc(4*sizeof(int));
C[1] = (int *) malloc(4*sizeof(int));
C[2] = (int *) malloc(4*sizeof(int));
C[3] = (int *) malloc(4*sizeof(int));
```

**Accessing elements of 2D array**
```c++
int main( )

{
    unsigned int x[4] [3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    printf("%u,%u, %u, %u", x+3, *(x+3),*(*(x+2)+3));
}
// assume address of x is 2000
```

Looking at the above code
- `x + 3` means location of 3rd element in x -> 3rd row or 3rd row 1st col
- `*(x+3)` means address of -> 3rd row or 3rd row 1st col
- `*(x+2)+3` means address of -> (2nd row or 2nd row 1st column) + 3 locations or 3,1 location 
- **`*(*(x+2)+3)` means value at location 3,1**

**NOTE** every time you use 2 pointer `*` operator for a 2d array, you are accessing elements