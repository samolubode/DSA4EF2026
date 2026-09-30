// Solution 1 : Base Address + Index Offset
//                                 This approach keeps the original base pointers stationary and calculates element
//                                     addresses on each iteration using an offset integer i.
// • Step 1 : Validate input(src != nullptr and size > 0)
//                 .
// • Step 2 : Allocate memory on the heap : float *dest = new float[size];.
// • Step 3: Set up a for loop running from index i = 0 to size - 1.
// • Step 4: Calculate source address (src + i) and destination address (dest + i).
// • Step 5: Copy element value using dereferencing: *(dest + i) = *(src + i);
// .
// • Step 6 : Return base pointer dest.

#include <iostream>

using namespace std;

float *deepCopy(float *src, int size)
{
  if (src != nullptr && size > 0)
  {
    // impletation
    float *dest = new float[size];
    for (int i = 0; i < size; i++)
    {
      *(dest + i) = *(src + i);
    }
    return dest;
  }
  return nullptr;
}

// Solution 2 : Moving Worker Pointers
//                  This approach creates temporary "worker" pointers that step through memory
//                      addresses increment -
//              by - increment(ptr++).
// • Step 1 : Validate input(src != nullptr and size > 0).
// • Step 2 : Allocate memory on the heap : float *dest = new float[size];
// .
// • Step 3 : Initialize worker pointers pointing to the start of each block :
// • const float *srcPtr = src;
// • float *destPtr = dest;
// • Step 4 : Loop size times :
// • Copy current element : *destPtr = *srcPtr;
// • Advance both worker pointers to the next element : srcPtr++;
// destPtr++;
// • Step 5 : Return the original base pointer dest(Warning : returning destPtr would return a
//                                                      pointer to the end of the array,
//                                                  causing memory corruption when freed)
//                .
float *deepCopyVector(float *src, int size)
{
  if (src != nullptr && size > 0)
  {
    // impletation
    float *dest = new float[size];
    float *srcPtr = src;
    float *destPtr = dest;
    for (int i = 0; i < size; i++)
    {
      *destPtr = *srcPtr;
      destPtr++;
      srcPtr++;
    }
    return dest;
  }
  return nullptr;
}

int main()
{
  float *arr = new float[4]{0.4, 0.6, 0.56, 0.51};

  float *copy = deepCopyVector(arr, 4);
  if (copy == nullptr)
  {
    cerr << "Couldn't copy the array" << endl;
  }

  arr[2] = 14.6;

  for (int i = 0; i < 4; i++)
  {
    cout << "Original array values: " << " at index " << i << " " << *(arr + i) << endl;
    cout << "Copy of array values: " << " at index " << i << " " << *(copy + i) << endl;
  }
  delete[] arr;
  delete[] copy;
  arr = copy = nullptr;
  return 0;
}
