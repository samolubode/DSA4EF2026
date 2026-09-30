// Exercise: Deep Copying a Dynamic Array
//
// Shallow copy (p2 = p1): both pointers hold the same address.
// Deep copy: allocate a new block with new, then copy each element over.
//
// Constraint: no bracket notation inside the function bodies, except for
// the heap allocation (new float[size]). We use pointer arithmetic instead:
//   arr[i]  <=>  *(arr + i)

#include <iostream>

using namespace std;

// Solution 1: Base Address + Index Offset
// The base pointers never move; each element address is computed as base + i.
//
// Time:  O(n) - the loop runs n times, each iteration does O(1) work
//               (one address calculation, one read, one write).
// Space: O(1) auxiliary - only the loop counter i. The new n-element block is
//               the output itself, not auxiliary space (O(n) if you count it).
float *deepCopyVector1(const float *src, int size)
{
    if (src == nullptr || size <= 0)
        return nullptr;

    float *dest = new float[size];

    for (int i = 0; i < size; i++)
        *(dest + i) = *(src + i);

    return dest;
}

// Solution 2: Moving Worker Pointers
// Two worker pointers step through memory one element at a time (ptr++).
//
// Time:  O(n) - the loop runs n times, each iteration does O(1) work
//               (one read, one write, two pointer increments).
// Space: O(1) auxiliary - only the two worker pointers and a counter. As above,
//               the n-element output block is O(n) if counted.
float *deepCopyVector2(const float *src, int size)
{
    if (src == nullptr || size <= 0)
        return nullptr;

    float *dest = new float[size];

    const float *srcPtr = src;
    float *destPtr = dest;

    for (int i = 0; i < size; i++)
    {
        *destPtr = *srcPtr;
        srcPtr++;
        destPtr++;
    }

    // Return the base address, not destPtr (which now points one past the end)
    return dest;
}

// Comparison:
//   Both are O(n) time and O(1) auxiliary space - asymptotically identical.
//   Solution 1 recomputes base + i each iteration; Solution 2 just increments
//   the pointers. In practice the compiler generates essentially the same code
//   for both, so the difference is stylistic.

void printArray(const float *arr, int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << (i < size - 1 ? " | " : " ");
    cout << "]" << endl;
}

int main()
{
    const int size = 3;
    float *src = new float[size];
    *(src + 0) = 10.5f;
    *(src + 1) = 20.2f;
    *(src + 2) = 30.8f;

    float *copy1 = deepCopyVector1(src, size);
    float *copy2 = deepCopyVector2(src, size);

    cout << "src:   ";
    printArray(src, size);
    cout << "copy1: ";
    printArray(copy1, size);
    cout << "copy2: ";
    printArray(copy2, size);

    // Prove the copies are independent: modify src, copies stay unchanged
    *src = 99.9f;
    cout << "\nAfter setting src[0] = 99.9:" << endl;
    cout << "src:   ";
    printArray(src, size);
    cout << "copy1: ";
    printArray(copy1, size);
    cout << "copy2: ";
    printArray(copy2, size);

    cout << "\nAddresses: src=" << src << " copy1=" << copy1 << " copy2=" << copy2 << endl;

    // Null pointer safety
    cout << "\nnullptr src -> " << (deepCopyVector1(nullptr, 3) == nullptr ? "nullptr" : "not null") << endl;
    cout << "size 0      -> " << (deepCopyVector2(src, 0) == nullptr ? "nullptr" : "not null") << endl;

    delete[] src;
    delete[] copy1;
    delete[] copy2;
    src = copy1 = copy2 = nullptr;

    return 0;
}
