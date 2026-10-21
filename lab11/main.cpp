// LIST ADT: Linked-List Implementation
//
// ============================================================================
// Part 1: What is a linked list?
// ============================================================================
//   Q1. What is a linked list? What are the two parts of a node?
//   Q2. What does the head pointer hold when the list is empty?
//   Q3. Why can't we access the i-th element in O(1) like A[i]?
//   Q4. What is the difference between ptr, *ptr and ptr->next?
//
//     head
//     +---+    +-------+---+    +-------+---+    +-------+---+
//     | --+--->| 8,ant | --+--->| 3,bee | --+--->| 7,cat | / |
//     +---+    +-------+---+    +-------+---+    +-------+---+
//
// ============================================================================
// Part 2: LIST ADT
// ============================================================================
// A window w is a pointer to a node.
//
//     [ A ] ---> [ B ] ---> [ C ] ---> nullptr
//       ^                     ^           ^
//     First                 Last         End
//
// Operations
//   1. Declare   2. IsEmpty   3. First    4. Last     5. End
//   6. Next      7. Previous  8. Examine  9. Display  10. Insert
//   11. Delete   12. Empty    13. Reverse
//
//   Q5. Why does every function take NodePtr *list instead of NodePtr head?
//
// ============================================================================
// Part 3: Implementation
// ============================================================================
// For EACH operation: write your approach, list the edge cases, state the
// time complexity, then implement and test it in main().

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct ElementType
{
  int number;
  string str;
};

struct Node
{
  ElementType element;
  Node *next;
};

using NodePtr = Node *;

// 1. Declare(list): make list an empty list.
//    Approach: set the caller's head pointer to nullptr (no nodes yet).
//    Time complexity: O(1)
void Declare(NodePtr *list)
{
  *list = nullptr;
}

// 2. IsEmpty(list): return true if the list has no elements.
//    Approach: the list is empty when the head pointer is nullptr.
//    Time complexity: O(1)
bool IsEmpty(NodePtr *list)
{
  return *list == nullptr;
}

// 3. First(list): return the window of the first element.
//    Approach:
//    Time complexity:
NodePtr First(NodePtr *list)
{
  // TODO
  return nullptr;
}

// 4. Last(list): return the window of the last element.
//    Approach:
//    Time complexity:
NodePtr Last(NodePtr *list)
{
  // TODO
  return nullptr;
}

// 5. End(list): return the window after the last element.
//    Approach:
//    Time complexity:
NodePtr End(NodePtr *list)
{
  // TODO
  return nullptr;
}

// 6. Next(w, list): return the window after w.
//    Approach:
//    Time complexity:
NodePtr Next(NodePtr w, NodePtr *list)
{
  // TODO
  return nullptr;
}

// 7. Previous(w, list): return the window before w.
//    Approach:
//    Time complexity:
NodePtr Previous(NodePtr w, NodePtr *list)
{
  // TODO
  return nullptr;
}

// 8. Examine(w, list): return the element at w.
//    Approach:
//    Time complexity:
ElementType Examine(NodePtr w, NodePtr *list)
{
  // TODO
  return ElementType{};
}

// 9. Display(list): print (8, ant) -> (3, bee) -> NULL
//    Approach:
//    Time complexity:
void Display(NodePtr *list)
{
  // TODO
}

// 10. Insert(x, w, list): insert x before w.
//     Insert at End(list) appends to the tail.
//     Approach:
//     Time complexity:
void Insert(ElementType x, NodePtr w, NodePtr *list)
{
  // TODO
}

// 11. Delete(w, list): remove the node at w and free it.
//     Approach:
//     Time complexity:
void Delete(NodePtr w, NodePtr *list)
{
  // TODO
}

// 12. Empty(list): free every node and set the head to nullptr.
//     Approach:
//     Time complexity:
void Empty(NodePtr *list)
{
  // TODO
}

// 13. Reverse(list): reverse the list in place by re-linking the nodes.
//     Do not create new nodes or copy elements.
//     e.g. 8 -> 3 -> 7 -> NULL  becomes  7 -> 3 -> 8 -> NULL
//     Approach:
//     Time complexity:
void Reverse(NodePtr *list)
{
  // TODO
}

int main()
{
  NodePtr head;
  Declare(&head);
  cout << "IsEmpty: " << IsEmpty(&head) << endl;   // 1

  // Insert({8, "ant"}, End(&head), &head);
  // Insert({3, "bee"}, End(&head), &head);
  // Insert({7, "cat"}, End(&head), &head);
  // Display(&head);   // (8, ant) -> (3, bee) -> (7, cat) -> NULL

  // Insert({1, "ape"}, First(&head), &head);
  // Display(&head);   // (1, ape) -> (8, ant) -> (3, bee) -> (7, cat) -> NULL

  // cout << Examine(Last(&head), &head).number << endl;                    // 7
  // cout << Examine(Previous(Last(&head), &head), &head).number << endl;   // 3

  // Delete(First(&head), &head);
  // Display(&head);   // (8, ant) -> (3, bee) -> (7, cat) -> NULL

  // Reverse(&head);
  // Display(&head);   // (7, cat) -> (3, bee) -> (8, ant) -> NULL

  // Empty(&head);
  // cout << IsEmpty(&head) << endl;   // 1

  return 0;
}
