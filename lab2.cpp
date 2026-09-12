/*
================================================================================
CMU GRADUATE ENGINEERING: DATA STRUCTURES & ALGORITHMS
LAB 2: MEMORY MANAGEMENT, POINTERS, AND FUNCTIONS
================================================================================
*/

#include <iostream>

using namespace std;

// Custom Struct for our Drone examples and the final(small) project
struct Drone
{
  int id;
  const char *model; // C-style string pointer instead of string library
  double batteryLife;
};

// REFERENCES & POINTERS
void demonstrateReferencesAndPointers()
{
  cout << "\n--- 1. REFERENCES & POINTERS ---\n";

  int ammo = 50;

  // REFERENCE (&)
  // A reference is an ALIAS. A nickname. It IS the original variable.
  // It must be assigned immediately and cannot be re-assigned.
  int &ammoRef = ammo;
  ammoRef -= 10;                                          // Firing a weapon via the reference
  cout << "Ammo after using reference: " << ammo << "\n"; // Prints 40

  // POINTER (*)
  // Analogy: A Treasure Map.
  // A pointer does NOT hold data. It holds the HEXADECIMAL MEMORY ADDRESS (coordinates) of data.
  int *ammoPointer = &ammo; // The '&' here means "Address Of"

  cout << "The actual pointer (Memory Address): " << ammoPointer << "\n";

  // DEREFERENCING (*)
  // Using the '*' on a pointer means "Go to the coordinates on the map, open the box, and get the data."
  cout << "The data AT the pointer (Dereferenced): " << *ammoPointer << "\n";

  *ammoPointer = 100; // Reloading via the pointer
  cout << "Ammo after reloading via pointer: " << ammo << "\n";

  // NULL POINTER
  // Always initialize empty pointers to nullptr. A pointer with random garbage data
  // will cause a Segmentation Fault (crash) if you try to dereference it.
  int *safePointer = nullptr;

  int original = 42;
  int &ref = original;
  int *ptr = &original;

  // This will print the EXACT same memory address twice
  std::cout << "Original var mem addr: " << &original << std::endl;
  std::cout << "Reference's mem addr: " << &ref << std::endl;
  std::cout << "Pointer's mem addr: " << &ptr << std::endl;
}

// POINTER ARITHMETIC & MEMORY MANAGEMENT
void demonstrateMemoryManagement()
{
  cout << "\n--- 2. POINTER MATH & HEAP MEMORY ---\n";

  // STACK MEMORY: Fast, automatic, small (few MBs). Variables die when scope {} ends.
  // HEAP MEMORY: Massive, manual (GBs). You must request it and clean it up.

  // STATIC ALLOCATION (Stack)
  int val = 10;

  int n = 5; // Size of the dynamic array

  // DEFINE STATIC ARRAY (Stack)
  int stackArray[5]; // Fixed size, cannot be resized at runtime

  // DYNAMIC ALLOCATION ('new')
  // We are requesting a massive array of 5 integers on the HEAP.
  // The OS finds space in the warehouse and gives us the map (pointer) to the first box.
  int *heapArray = new int[n]; // malloc

  // Fill the array
  for (int i = 0; i < 5; i++)
  {
    heapArray[i] = (i + 1) * 10; // [10, 20, 30, 40, 50]
  }

  // POINTER ARITHMETIC
  // Because arrays are contiguous in memory, adding 1 to a pointer physically shifts
  // the address forward by the exact byte-size of the data type (e.g., +4 bytes for an int).
  int *traversalPtr = heapArray; // Points to index 0

  cout << "Index 0: " << *traversalPtr << "\n";
  // Print pointer address and value at index 0
  cout << "Pointer address b4 ptr++: " << traversalPtr << "\n";
  traversalPtr++; // Move the pointer forward by 1 integer block (4 bytes)
  // Print pointer address and value at index 1
  cout << "Pointer address after ptr++: " << traversalPtr << "\n";
  cout << "Index 1 (after ptr++): " << *traversalPtr << "\n";

  // Add int 1 to the pointer and print the address and value;
  traversalPtr += 1;
  cout << "Pointer address after ptr += 1: " << traversalPtr << "\n";
  cout << "Index 2 (after ptr += 1): " << *traversalPtr << "\n";

  // MEMORY CLEANUP ('delete')
  // CRITICAL: If you use 'new', you MUST use 'delete'.
  // If you don't, the memory is locked forever (Memory Leak) until the program closes.
  // In long-running servers, leaks crash the entire system over time.
  delete[] heapArray;  // The [] tells the OS to delete the whole array block, not just the first element.
  heapArray = nullptr; // Prevent a "Dangling Pointer" (pointing to deleted memory).
  cout << "Heap memory safely returned to the OS.\n";
}

// FUNCTIONS & PARAMETER PASSING
// Analogy: Functions are factory machines. You pass inputs, they do work, and return outputs.

// PASS BY VALUE (Default)
// Creates a heavy PHOTOCOPY of the data. The original is safe. Slow for massive structs.
void repairDroneValue(Drone d)
{
  d.batteryLife = 100.0; // Modifies the COPY.
}

// PASS BY REFERENCE (&)
// Sends the ORIGINAL. Fast, no copying. Function can modify the original data.
void repairDroneReference(Drone &d)
{
  d.batteryLife = 100.0; // Modifies the ORIGINAL.
}

// PASS BY CONST REFERENCE (const &)
// The Holy Grail. Fast (no copying), but SAFE (const prevents modification).
// Used extensively in professional C++ code.
void displayDrone(const Drone &d)
{
  // d.batteryLife = 0; // ERROR! Compiler stops this because of 'const'.
  cout << "Drone ID " << d.id << " (" << d.model << "): " << d.batteryLife << "% Battery\n";
}

void demonstrateFunctions()
{
  cout << "\n--- 3. FUNCTIONS & PARAMETER PASSING ---\n";

  Drone scout = {1, "Scout-X", 15.5};

  cout << "Initial battery: " << scout.batteryLife << "%\n";

  repairDroneValue(scout);
  cout << "Battery after Pass by Value: " << scout.batteryLife << "% (No change!)\n";

  repairDroneReference(scout);
  cout << "Battery after Pass by Reference: " << scout.batteryLife << "% (Repaired!)\n";

  displayDrone(scout);
}

// FUNCTION OVERLOADING & SCOPE
// Overloading: Multiple functions sharing the SAME NAME, but different parameter signatures.
void logMessage(const char *msg)
{ // Uses const char* instead of string
  cout << "TEXT LOG: " << msg << "\n";
}

void logMessage(int errorCode)
{
  cout << "ERROR LOG: Code " << errorCode << "\n";
}

// SCOPE: Variables only live inside their containing curly braces {}.
int globalVar = 99; // Exists everywhere. Avoid using these in professional code!

void demonstrateScopeAndOverload()
{
  cout << "\n--- 4. OVERLOADING & SCOPE ---\n";

  logMessage("System initialized."); // Calls the string version
  logMessage(404);                   // Calls the int version

  int localVar = 5;
  if (true)
  {
    int blockVar = 10;
    cout << "I can see localVar (" << localVar << ") and blockVar (" << blockVar << ")\n";
  }
  // blockVar is DEAD here. Its Stack memory was destroyed at the closing brace above.
}

// RECURSION & LAMBDAS
// Recursion: A function that calls itself.
// Analogy: Russian Nesting Dolls.
// CRITICAL RULE: You must define the BASE CASE (exit condition) first, or it loops forever (Stack Overflow).
int factorial(int n)
{
  if (n <= 1)
    return 1;                  // BASE CASE: Stops the recursion
  return n * factorial(n - 1); // RECURSIVE STEP
}

void demonstrateRecursionAndLambdas()
{
  cout << "\n--- 5. RECURSION & LAMBDAS ---\n";

  cout << "Factorial of 5 (5*4*3*2*1) = " << factorial(5) << "\n";

  // LAMBDAS: Anonymous, throwaway functions defined inline.
  // Syntax: [captures](parameters) { body }
  // Highly useful for defining custom rules on the fly, like sorting comparators.
  int numbers[] = {50, 20, 90, 10};
  int size = 4;

  cout << "Sorting array descending using a Lambda and Bubble Sort...\n";

  // The lambda provides the rule: "Return true if 'a' should go before 'b'"
  auto compareDescending = [](int a, int b)
  {
    return a > b;
  };

  // Manual bubble sort using our lambda rule (since we can't use <algorithm>)
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      // If they are in the wrong order according to our lambda, swap them
      if (!compareDescending(numbers[j], numbers[j + 1]))
      {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }

  // Print sorted array
  for (int i = 0; i < size; i++)
  {
    cout << numbers[i] << " ";
  }
  cout << "\n";
}

/*
=============================================================================
MINI PROJECT: DYNAMIC DRONE FLEET MANAGER
=============================================================================

PROJECT PROMPT FOR STUDENTS:
Synthesize pointers, heap memory, and pass-by-reference.
1. Use 'new' to allocate an array of 3 'Drone' structs on the Heap.
2. Manually initialize their data (ID, Model, Battery).
3. Write a function 'simulateFlight' that takes a pointer to the drone array and the array size.
   Inside, loop through the drones using POINTER ARITHMETIC (ptr++).
   Reduce each drone's battery by 20.0.
4. Write a Lambda function to find and print the drone with the lowest battery.
5. In main, call simulateFlight, execute the lambda, and CRITICALLY, use 'delete[]'
   to free the heap memory, setting the pointer to nullptr.
*/

int main()
{
  // Un-comment these one by one to run each function demo.

  // demonstrateReferencesAndPointers();
  demonstrateMemoryManagement();
  // demonstrateFunctions();
  // demonstrateScopeAndOverload();
  // demonstrateRecursionAndLambdas();

  return 0; // Success
}