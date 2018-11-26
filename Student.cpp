#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
  id = 0;
  name = "N/A";
  level = "N/A";
  major = "N/A";
  gpa = 0.0;
  advisorID = 0;
}

Student::Student(int studentID)
{
  id = studentID;
}

Student::Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID)
{
  id = studentID;
  name = studentName;
  level = studentLevel;
  major = studentMajor;
  gpa = studentGPA;
  advisorID = studentAdvisorID;
}

Student::~Student()
{

}

ostream& operator<<(ostream& os, const Student &s)
{
  os << s.name << '|' << s.level << '|' << s.major << '|' << s.advisorID << '|' << s.gpa << '|' << s.id;
  return os;
}

bool operator> (const Student &s1, const Student &s2)
{
  return s1.id > s2.id;
}

bool operator< (const Student &s1, const Student &s2)
{
  return s1.id < s2.id;
}
bool operator== (const Student &s1, const Student &s2)
{
  return s1.id == s2.id;
}
bool operator!= (const Student &s1, const Student &s2)
{
  return s1.id != s2.id;
}
