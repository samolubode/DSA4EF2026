// Array ADT
//
// ============================================================================
// Part 1: What is an array?
// ============================================================================
//   Q1. What is an array?
//   Q2. Why must all the elements be of the same type?
//   Q3. What does "contiguous memory" mean? Why does it matter?
//   Q4. Given the address of A[0], how does the computer find A[i]?
//       Why is accessing A[i] O(1)?
//   Q5. What is the difference between an array on the stack (int A[5])
//       and an array on the heap (new int[5])?
//   Q6. Once an array is created, can its size change? What can we do if
//       we run out of space?
//
//   Definition: An array is a collection of elements of the same type,
//   stored in contiguous memory space.
//
// ============================================================================
// Part 2: Array ADT
// ============================================================================
// An ADT (Abstract Data Type) = the data + the operations on that data.
//
// Data
//   1. Array space   -> where the elements are stored (A)
//   2. Size          -> how many elements the array CAN hold (capacity)
//   3. Length        -> how many elements the array DOES hold right now
//
//   Q7. What is the difference between size and length?
//
//   Example: size = 10, length = 5
//
//     index:  0   1   2   3   4   5   6   7   8   9
//           +---+---+---+---+---+---+---+---+---+---+
//        A: | 8 | 3 | 7 |12 | 6 |   |   |   |   |   |
//           +---+---+---+---+---+---+---+---+---+---+
//                             ^ last element is at index length - 1
//
// Operations (L = the entire list)
//   1. Display(L)
//   2. Append(e, L)
//   3. Insert(e, index, L)
//   4. Delete(index, L)
//   5. Search(x, L)
//   6. Get(index, L)
//   7. Set(index, x, L)
//   8. Max(L) / Min(L)
//   9. Reverse(L)
//
// ============================================================================
// Part 3: Implementation
// ============================================================================
// For EACH operation:
//   1. Outline your approach in the "Approach" comment (in plain English,
//      step by step) BEFORE writing any code.
//   2. Think about the edge cases (empty array? full array? invalid index?)
//   3. State the time complexity.
//   4. Then implement it, and test it in main().

#include <iostream>

using namespace std;

struct Array
{
  int *A;     // array space (on the heap)
  int size;   // capacity
  int length; // number of elements
};

// Q8. Some functions below take `Array L` and others take `Array *L`. Why?
//     Which operations need a pointer, and which do not?

// ----------------------------------------------------------------------------
// 1. Display(L)
//    Print all the elements of L.
//    Approach:
//
//    Time complexity:
// ----------------------------------------------------------------------------
void Display(Array L)
{
  // TODO
  for (int i = 0; i < L.length; i++)
  {
    cout << "\nElement " << i << " " << L.A[i] << endl;
  }
}

// ----------------------------------------------------------------------------
// 2. Append(e, L)
//    Add element e to the end of L.
//    Approach:
//
//    Edge cases:
//    Time complexity:
// ----------------------------------------------------------------------------
void Append(int e, Array *L)
{
  // check if we still have space to append
  if (L->size > L->length)
  {
    L->A[L->length] = e;
    L->length = L->length + 1;
    cout << "Element appended, kudos.";
  }
  else
  {
    cout << "No space left for you" << endl;
  }
}

// ----------------------------------------------------------------------------
// 3. Insert(e, index, L)
//    Insert element e at the given index, keeping the order of the other
//    elements.  e.g. Insert(9, 2, [8 3 7 12 6]) -> [8 3 9 7 12 6]
//    Approach:
//
//    Edge cases:
//    Time complexity (best / worst):
// ----------------------------------------------------------------------------
void Insert(int e, int index, Array *L)
{
  // TODO
  cout << "Inserting...\n";
  if (L->length == L->size)
  {
    throw new std::runtime_error("Hey, the array is full!!");
  }
  for (int i = L->length; i >= index; i--)
  {
    L->A[i] = L->A[i - 1];
  }
  L->A[index] = e;
  L->length++;

  cout << "Insert successful!!\n";
}

// ----------------------------------------------------------------------------
// 4. Delete(index, L)
//    Remove the element at the given index and return it.
//    The remaining elements must stay in order with no gaps.
//    Return -1 if the index is invalid.
//    Approach:
//
//    Edge cases:
//    Time complexity (best / worst):
// ----------------------------------------------------------------------------
int Delete(int index, Array *L)
{
  // validate array
  if (L == nullptr)
  {
    cerr << "Invalid array\n";
    return -1;
  }

  // ensure index within valid range
  if (index < 0 || index > L->length - 1)
  {
    cerr << "Invalid index\n";
    return -1;
  }

  // store element to delete
  int element = L->A[index];

  // shift all elements backward by 1 position starting at index+1
  for (int i = index; i < L->length; i++)
  {
    L->A[i] = L->A[i + 1];
  }

  // update array length
  L->length = L->length - 1;

  return element;
}

// ----------------------------------------------------------------------------
// 5. Search(x, L)
//    Return the index of x in L, or -1 if x is not found. (Linear search)
//    Approach:
//
//    Time complexity (best / worst):
// ----------------------------------------------------------------------------
int Search(int x, Array L)
{
  for (int i = 0;i<L.length;i++)
  {
    if(L.A[i]==x){
      return i;
    }
  }

  return -1;
}

// ----------------------------------------------------------------------------
// 6. Get(index, L)
//    Return the element at the given index, or -1 if the index is invalid.
//    Approach:
//
//    Time complexity:
// ----------------------------------------------------------------------------
int Get(int index, Array L)
{
  if(index < 0 || index >=L.length)
    return -1;
  
  return L.A[index];
}

// ----------------------------------------------------------------------------
// 7. Set(index, x, L)
//    Replace the element at the given index with x.
//    Approach:
//
//    Time complexity:
// ----------------------------------------------------------------------------
void Set(int index, int x, Array *L)
{
  if (index < 0 || index >= L->length)
    return;

   L->A[index] = x;
}

// ----------------------------------------------------------------------------
// 8. Max(L) / Min(L)
//    Return the largest / smallest element in L.
//    Approach:
//
//    Time complexity:
// ----------------------------------------------------------------------------
int Max(Array L)
{
  // TODO
  return -1;
}

int Min(Array L)
{
  // TODO
  return -1;
}

// ----------------------------------------------------------------------------
// 9. Reverse(L)
//    Reverse the elements of L in place.
//    e.g. [8 3 7 12 6] -> [6 12 7 3 8]
//    Approach:
//
//    Time complexity:
// ----------------------------------------------------------------------------
void Reverse(Array *L)
{
  // TODO
}

int main()
{
  Array arr;
  arr.size = 10;
  arr.A = new int[arr.size];
  arr.length = 0;

  // --- Display / Append ---
  Append(8, &arr);
  Append(3, &arr);
  Append(7, &arr);
  Append(12, &arr);
  Append(6, &arr);
  // Display(arr); // 8 3 7 12 6

  // --- Insert ---
  Insert(9, 2, &arr);
  // Display(arr); // 8 3 9 7 12 6

  // --- Delete ---
  cout << "Deleted: " << Delete(2, &arr) << endl; // 9
  Display(arr);                                   // 8 3 7 12 6

  // --- Search ---
  cout << "Search 12: " << Search(12, arr) << endl; // 3
  cout << "Search 50: " << Search(50, arr) << endl; // -1

  // --- Get / Set ---
  cout << "Get(1): " << Get(1, arr) << endl;       // 3
  Set(1, 15, &arr);
  Display(arr);                                    // 8 15 7 12 6

  // --- Max / Min ---
  // cout << "Max: " << Max(arr) << endl;             // 15
  // cout << "Min: " << Min(arr) << endl;             // 6

  // --- Reverse ---
  // Reverse(&arr);
  // Display(arr);                                    // 6 12 7 15 8

  delete[] arr.A;
  arr.A = nullptr;

  return 0;
}
