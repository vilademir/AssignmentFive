#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;

class Faculty
{
public:
  Faculty();
  Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDept, GenDoublyLinkedList<int>* facultyAdvisees);
  Faculty(int facultyID);
  Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment);
  ~Faculty();

  void addAdvisee(int adviseeID);

  int id;
	string name;
	string level;
	string department;
	GenDoublyLinkedList<int>* advisees;

  friend ostream& operator<<(ostream& os, const Faculty &f1);
  friend bool operator> (const Faculty &s1, const Faculty &s2);
  friend bool operator< (const Faculty &s1, const Faculty &s2);
  friend bool operator== (const Faculty &s1, const Faculty &s2);
  friend bool operator!= (const Faculty &s1, const Faculty &s2);
};
