/*
================================================================================
CMU GRADUATE ENGINEERING: DATA STRUCTURES & ALGORITHMS
LAB 3: LINEAR SEARCH, BINARY SEARCH, AND RECURSION
================================================================================
 */

#include <iostream>

using namespace std;

/*
LINEAR SEARCH
*/

// int linear_search(int s[], int key, int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//     if (s[i] == key)
//       return i; // returns the index of the key
//   }
//   return -1; // returns a sentinel value
// }

// // int indofKey = linear_search(s, key, n);

// int main()
// {
//   int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int key = 5;
//   int n = sizeof(s) / sizeof(s[0]); // sizeof of the arr 
//   int result = linear_search(s, key, n);
//   if (result == -1)
//     cout << "Element not found in the array\n";
//   else
//     cout << "Element found at index: " << result << "\n";
// }

/*
BINARY SEARCH
*/

// int binary_search(int s[], int key, int low, int high)
// {
//   int first, last, mid;
//   first = low;
//   last = high;

//   do
//   {
//     mid = (first + last) / 2;

//     if (s[mid] < key)
//     { // search top half
//       first = mid + 1; // 
//     }
//     else
//     { // search bottom half
//       last = mid - 1; // 
//     }
//   } while ((first <= last) && (s[mid] != key));

//   if (s[mid] == key)
//     return (mid);
//   else
//     return (-1); // returns a negative index in this case.
// }

// int main()
// {
//   int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int key = 5;
//   int n = sizeof(s) / sizeof(s[0]);
//   int result = binary_search(s, key, 0, n - 1);
//   if (result == -1)
//     cout << "Element not found in the array\n";
//   else
//     cout << "Element found at index: " << result << "\n";
// }

/*
RECURSION
*/
/* How programs run*/
// int fun(int n){
//   // 1. perform operation 1
//   // 2. perform operation 2
//   return n;
// }

// int main (){
//   printf("Hello World\n");
//   int var = fun(7) + 2; // control comes back to this line after the function call is complete
//   printf("Hello Globe\n");
// }

/* Recursive functions - a function calling itself*/
/* Base Condition to terminate recursion*/
// type recursive_func(parameters){
//   // 1. perform operation 1
//   // 2. perform operation 2
//   if (base condition is met){ // there must be a base condition that terminates the recursion
//     return something;
//   }
//   else{
//     return recursive_func(modified parameters);
//   }
// }

// Concerete Recursive Function Example
// EXAMPLE 1
void func1(int n)
{
  if (n > 0) // in some cases, you can simply use `return` to terminate the function
  {
    cout << n << " ";
    func1(n - 1);
  }
}

// // EXAMPLE 2
// void func2(int n)
// {
//   if (n > 0)
//   {
//     func2(n - 1);
//     cout << n << " ";
//   }
// }

int main()
{
  int n = 5;
  func1(n);
  // func2(n);

  // RECURSION IS ESSENTIALLY A TWO-PHASE PROCESS OF CALLING AND RETURNING A FUNCTION OF ITSELF.
  // THE CALLING PHASE IS WHEN THE FUNCTION KEEPS CALLING ITSELF UNTIL IT REACHES THE BASE CONDITION.
  // THE RETURNING PHASE IS WHEN THE FUNCTION STARTS RETURNING BACK TO THE PREVIOUS CALLS, EXECUTING ANY CODE THAT COMES AFTER THE RECURSIVE CALL.
}

// Recursive binary search

int binary_search_recv(int s[], int key, int low, int high)
{
  int mid;

  if (low > high)
    return (-1); // key not found
  mid = (low + high) / 2;

  if (s[mid] == key) // base condition: key found
    return (mid);

  if (s[mid] > key)
  {
    return (binary_search_recv(s, key, low, mid - 1)); // search bottom half
  }
  else
  {
    return (binary_search_recv(s, key, mid + 1, high)); // search top half
  }
}

int main()
{
  int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key = 5;
  int n = sizeof(s) / sizeof(s[0]);
  int result = binary_search_recv(s, key, 0, n - 1);
  if (result == -1)
    cout << "Element not found in the array\n";
  else
    cout << "Element found at index: " << result << "\n";
}