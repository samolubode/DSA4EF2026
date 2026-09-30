// Pointers
//   1. Why pointers
//   2. Declaration
//   3. Initialization
//   4. Dereferencing
//   5. Dynamic allocation
//
// Memory layout of a program:
//   +-------------------+
//   | Code (Text)       |  <- main() and other functions
//   | Static (Globals)  |
//   |                   |
//   | Heap              |  <- dynamic allocation (new / delete)
//   | Stack             |  <- local variables
//   +-------------------+
//
// A pointer is a variable that holds the address of another variable.
// We use it to access data indirectly.
//
// Why do we need pointers?
//   Your program can directly access the stack, but not the heap memory,
//   where dynamic allocation takes place.
//   1. To access a resource (external resources e.g. monitor, network, etc.)
//   2. To access the heap
//   3. Passing parameters

#include <cstdio>
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

// Accessing a (stack) variable with a pointer
void basicPointer()
{
    cout << "--- Basic pointer ---" << endl;

    int a = 10; // data variable
    int *p;     // pointer variable (declaration)
    p = &a;     // initialization

    printf("%d\n", a);
    printf("%d\n", *p); // dereferencing
    cout << "address of a: " << &a << ", value of p: " << p << endl;
}

// Pointer with an array
void pointerWithArray()
{
    cout << "--- Pointer with an array ---" << endl;

    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = A; // or if you want to use &:  p = &A[0]; A is already a pointer for the array

    // printing with A
    for (int i = 0; i < 5; i++)
        cout << A[i] << endl;

    // printing with p
    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;
}

// Accessing heap variable with pointer
void heapArray()
{
    cout << "--- Heap array ---" << endl;

    int *p;         // every variable declaration resides in the stack
    p = new int[5]; // the array itself lives in the heap

    for (int i = 0; i < 5; i++)
        p[i] = (i + 1) * 2;
    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;

    delete[] p; // release memory
    p = nullptr;
}

// Pointer size is independent of the data type
void pointerSizes()
{
    cout << "--- Pointer sizes ---" << endl;

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    Rectangle *p5;

    // Whatever the data type of the pointer, pointers take the same amount of memory
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;
}

// Pointer to a structure
void pointerToStruct()
{
    cout << "--- Pointer to a structure ---" << endl;

    Rectangle r = {10, 5};
    Rectangle *p = &r;

    int b = 5;
    int *p1 = &b;

    r.length = 15; // normal variable
    cout << r.length << endl;
    (*p).length = 20; // dereferencing (not *p.length)
    cout << (*p).length << endl;
    p->length = 25; // using pointer variable, C convention
    cout << r.length << endl;
}

// Creating Rectangle dynamically using pointer
void dynamicStruct()
{
    cout << "--- Dynamic Rectangle ---" << endl;

    Rectangle *p;

    p = new Rectangle(); // () for value init to prevent random values
                         //   int -> 0, double -> 0.0
    p->length = 5;
    p->breadth = 10;

    cout << "length: " << p->length << ", breadth: " << p->breadth << endl;

    delete p;    // free memory
    p = nullptr; // avoid dangling pointer
}

int main()
{
    // basicPointer();
    // pointerWithArray();
    // heapArray();
    // pointerSizes();
    pointerToStruct();
    // dynamicStruct();

    return 0;
}
