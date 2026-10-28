#include "CourseRoster.h"

int main()
{
  EntryPtr courseRoster = nullptr;

  const Student kwame{"kwame_a", "Kwame Mensah", {14, 3, 2002}};
  const Student devika{"dev_b", "Nafula Kakai", {22, 7, 2001}};
  const Student grace{"grace_c", "Grace Oswaldo", {5, 11, 2003}};

  insert_student(kwame, &courseRoster);
  insert_student(devika, &courseRoster);
  insert_student(grace, &courseRoster);

  std::cout << "Roster after insertion:\n";
  printList(&courseRoster);

  // const Date revisedBirthdate{23, 7, 2001};
  // const bool updated = update_student_dob("dev_b", revisedBirthdate, &courseRoster);
  // std::cout << "\nDOB update for dev_b: " << (updated ? "success" : "not found") << '\n';
  // printList(&courseRoster);

  // if (courseRoster != nullptr && courseRoster->next != nullptr)
  // {
  //   RosterEntry *target = courseRoster->next;
  //   delete_student(target, &courseRoster);
  // }
  // else
  // {
  //   std::cout << "\nDeletion demonstration skipped: implement insertion first.\n";
  // }
  // printList(&courseRoster);

  // empty(&courseRoster);
  // std::cout << "\nRoster empty: " << (isEmpty(&courseRoster) ? "yes" : "no") << '\n';
  // printList(&courseRoster);

  return 0;
}
