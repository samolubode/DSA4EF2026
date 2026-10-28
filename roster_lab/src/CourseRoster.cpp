#include "CourseRoster.h"

RosterEntry *last(EntryPtr *list)
{
  (void)list;
  // TODO: Return the tail node, or nullptr if empty.
  return nullptr;
}

RosterEntry *end(EntryPtr *list)
{
  (void)list;
  // TODO: Return the past-the-end marker.
  return nullptr;
}

bool isEmpty(EntryPtr *list)
{
  (void)list;
  // TODO: Check whether the roster is empty.
  return true;
}

RosterEntry *next(EntryPtr w, EntryPtr *list)
{
  (void)w;
  (void)list;
  // TODO: Return the entry after w.
  return nullptr;
}

RosterEntry *previous(EntryPtr w, EntryPtr *list)
{
  (void)w;
  (void)list;
  // TODO: Return the entry before w.
  return nullptr;
}

void insert_student(const Student &student, EntryPtr *list)
{
  EntryPtr newRoster = new RosterEntry{student, nullptr}; // for Keza
  // is the list empty
  if(list == nullptr || *list == nullptr){
    *list = newRoster;
    return;
  }

  // if there are already student roster entry
  // trace variable to keep track of current element (Node)
  EntryPtr trace = *list;

  // 
  while(trace->next != nullptr){
    trace = trace->next;
  }

  trace->next = newRoster;
}

void delete_student(EntryPtr w, EntryPtr *list)
{
  (void)w;
  (void)list;
  // TODO: Unlink and delete w.
}

bool update_student_dob(const std::string &andrewID, Date newBirthdate, EntryPtr *list)
{
  (void)andrewID;
  (void)newBirthdate;
  (void)list;
  // TODO: Update the matching student's birthdate.
  return false;
}

RosterEntry *empty(EntryPtr *list)
{
  (void)list;
  // TODO: Delete all nodes and reset the head pointer.
  return nullptr;
}

void printList(EntryPtr *list)
{
  EntryPtr trace = *list;

  //
  while (trace->next != nullptr)
  {
    std::cout << trace->record.name << std::endl;
    trace = trace->next;
  }

  std::cout << trace->record.name << std::endl;
}
