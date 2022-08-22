### Strings

ASCII - A=65 Z=90, a=97 z=122, 0=48 9=57

#### Character type
```c++
char temp = 'A'; // single character saved as ASCII
```

#### Character array
```c++
char X[5] = {'A','B','C''D','E'};
```

#### Strings
- Strings are character arrays that are terminated by the string termination character `'\0'` 
```c++
char name[] = "john"; // declared as type string only
char same_name[] = {'j','o','h','n','\0'}; // including the string termination character to tell compiler its string
cout << name << endl;
cout << same_name << endl;

```