#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA,int studentAdvisorID);
  Student(int studentID);
  ~Student();

  int id;
	string name;
	string level;
	string major;
	double gpa;
	int advisorID;

  //TreeNode<Student>* foundStudent;
  //TreeNode<Faculty>* foundFaculty;

  friend ostream& operator<<(ostream& os, const Student &f1);
  friend bool operator> (const Student &s1, const Student &s2);
  friend bool operator< (const Student &s1, const Student &s2);
  friend bool operator== (const Student &s1, const Student &s2);
  friend bool operator!= (const Student &s1, const Student &s2);
};
