### Array ADT
- We know C and Cpp are bare-bones programming languages with minimum DS available
- However, we can extend the bare-bones with our own operations
- *Array ADT* is one such extension that allows us to create Array DS and define operations on them

### Data
- Array space
- size
- length (number of elements)

### Operations
- Display()
- Add(x)/Append(x)
- Insert(index, x)
- Delete(index)
- Search(x)
- Get(index)
- Set(index,x)
- Max()/Min()
- Reverse()
- Shift()/Rotate()

Example

```c++
#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

int lin_search( struct Array arr, int val){
    for (int i = 0; i <= arr.length; i++){
        if (val == arr.A[i]){
            return i;
        }
    }
}

int main() {
    struct Array arr;
    cout << "Enter size of array" << endl;
    cin >> arr.size;
    arr.length = 0;
    arr.A = (int *)malloc(arr.size*sizeof(int));
    for (int x=0; x < arr.size; x++){
        cout << arr.A[x] << endl;
    }
}
```

**Binary search**
- Required: Array has to be sorted

```c++
int main(){
    
}
```