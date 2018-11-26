#include <iostream>
#include "BST.h"
#include "Stack.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();

  // Read from corresponding txt files and parse the data into the corresponding
  // Binary Search Trees upon reading in at start of runSimulation function
  void runSimulation();
  void Exit();
  void rollback();
  void printOptions();

  void addStudent(Student student);
  void addFaculty(Faculty faculty);

  void deleteStudent(Student student);
  void deleteFaculty(Faculty faculty);

  void checkStudent(Student student);
  void checkFaculty(Faculty facultyID);

  void findStudent(int studentID);
  Student getStudent(int studentID);
  void findFaculty(int facultyID);
  Faculty getAdvisor(int facultyID);

  void printStudentAdvisor(int studentID);
  void printAdvisees(int facultyID);

  void removeAdvisee(int facultyID, int studentID);
  void changeAdvisor(int studentID, int newFacultyID);

// Change the print function in the BST class to print to a file
  void printStudent();
  void printFaculty();

  BST<Student>* masterStudent;
  BST<Faculty>* masterFaculty;
  // The stacks keep track of the previous actions done onto the types -- meant for the undo function
  Stack<Student>* studentRecord;
  Stack<Faculty>* facultyRecord;
};
