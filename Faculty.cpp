#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
  id = 0;
  name = "N/A";
  level = "N/A";
  department = "N/A";
}

Faculty::Faculty(int facultyID)
{
  id = facultyID;
}

Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment, GenDoublyLinkedList<int>* facultyAdvisees)
{
  id = facultyID;
	name = facultyName;
	level = facultyLevel;
	department = facultyDepartment;
  advisees = facultyAdvisees;
}
Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment)
{
  id = facultyID;
  name = facultyName;
  level = facultyLevel;
  department = facultyDepartment;
}

Faculty::~Faculty(){}

void Faculty::addAdvisee(int adviseeID)
{
  if(advisees->find(adviseeID) == -1)
  {
    advisees->insertFront(adviseeID);
  }
  else
  {
    cout << "The Advisee is already being advised by this faculty member." << endl;
  }
}


ostream& operator<<(ostream& os, const Faculty &f)
{
  os << f.name << '|' << f.level << '|' << f.department << '|' << f.id << '|';
  for(int i = 0; i < f.advisees->size; i++)
  {
    int x = f.advisees->removeBack();
    os << x << '|';
    f.advisees->insertFront(x);
  }
  return os;
}

bool operator> (const Faculty &s1, const Faculty &s2)
{
  return s1.id > s2.id;
}
bool operator< (const Faculty &s1, const Faculty &s2)
{
  return s1.id < s2.id;
}
bool operator== (const Faculty &s1, const Faculty &s2)
{
  return s1.id == s2.id;
}
bool operator!= (const Faculty &s1, const Faculty &s2)
{
  return s1.id != s2.id;
}
