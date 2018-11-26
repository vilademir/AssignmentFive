#include <iostream>
#include "Simulation.h"
#include <fstream>
#include <string>
#include <locale>

using namespace std;

Simulation::Simulation(){}

Simulation::~Simulation(){}

//Number 1
void Simulation::printStudent()
{
  masterStudent->printTree();
}

//Number 2
void Simulation::printFaculty()
{
  masterFaculty->printTree();
}

// Number 3
void Simulation::findStudent(int studentID)
{
  Student tempStudent(studentID);

  if(masterStudent->contains(tempStudent))
  {
    Student foundStudent = masterStudent->find(tempStudent);

    cout << foundStudent << endl;
  }
  else
  {
    cout << "The student is not in the database." << endl;
  }
}

Student Simulation::getStudent(int studentID)
{
  Student tempStudent(studentID);

  if(masterStudent->contains(tempStudent))
  {
    Student foundStudent = masterStudent->find(tempStudent);

    return foundStudent;
  }
  else
  {
    cout << "The student is not in the database." << endl;
  }
}


Faculty Simulation::getAdvisor(int facultyID)
{
  Faculty tempFaculty(facultyID);
  if(masterFaculty->contains(tempFaculty))
  {
    Faculty foundFaculty = masterFaculty->find(tempFaculty);

    string newName = foundFaculty.name;
    return foundFaculty;
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

// Nubmer 4
void Simulation::findFaculty(int facultyID)
{
  Faculty tempFaculty(facultyID);
  if(masterFaculty->contains(tempFaculty))
  {
    Faculty foundFaculty = masterFaculty->find(tempFaculty);

    cout << foundFaculty << endl;
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

// Number 5
void Simulation::printStudentAdvisor(int studentID)
{
  Student tempStudent(studentID);
  if(masterStudent->contains(tempStudent))
  {
    Student foundStudent = masterStudent->find(tempStudent);

    int newID = foundStudent.id;

    getAdvisor(newID);
  }
  else
  {
    cout << "The student is not in the database." << endl;
  }
}

// Number 6
void Simulation::printAdvisees(int facultyID)
{
  Faculty tempFaculty(facultyID);

  if(masterFaculty->contains(tempFaculty))
  {
    Faculty foundFaculty = masterFaculty->find(tempFaculty);

    for(int i = 0; i < foundFaculty.advisees->size; i++)
    {
      int tempID = foundFaculty.advisees->removeBack();
      findStudent(tempID);
      foundFaculty.advisees->insertFront(tempID);
    }
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

//Number 7
void Simulation::addStudent(Student student)
{
  if(!masterStudent->contains(student))
  {
    masterStudent->insert(student);
  }
  else
  {
    cout << student.name << " is already in the database." << endl;
  }
}

//Number 8
void Simulation::deleteStudent(Student student)
{
  if(masterStudent->contains(student))
  {
    string answer;

    cout << "Are you sure you wish to delete: " << student.name << '|' << student.id << endl;
    cin >> answer;

    string lowerAnswer;
    for(int i = 0; i < answer.length(); i++)
    {
      lowerAnswer += tolower(answer[i]);
    }

    if(lowerAnswer == "yes" || lowerAnswer == "y")
    {
      masterStudent->deleteRec(student);

      cout << student.name << " was successfully removed from the database" << endl;
    }
    else
    {
      cout << student.name << " was not removed from the database" << endl;
    }
  }
}


// Number 9
void Simulation::addFaculty(Faculty faculty)
{
  if(!masterFaculty->contains(faculty))
  {
    masterFaculty->insert(faculty);
  }
  else
  {
    cout << faculty.name << " is already in the database." << endl;
  }
}

//Number 10
void Simulation::deleteFaculty(Faculty faculty)
{
  if(masterFaculty->contains(faculty))
  {
    string answer;
    GenDoublyLinkedList<int>* tempAdvisees = faculty.advisees;

    cout << "Are you sure you wish to delete: " << faculty.name << '|' << faculty.id << endl;
    cin >> answer;

    string lowerAnswer;
    for(int i = 0; i < answer.length(); i++)
    {
      lowerAnswer += tolower(answer[i]);
    }

    if(lowerAnswer == "yes" || lowerAnswer == "y")
    {
      string newAdvisorString;

      cout << "Please enter a new advisor ID for all of the advisees of this advisor: " << endl;
      cin >> newAdvisorString;
      int newAdvisorID = stoi(newAdvisorString);

      for(int i = 0; i < tempAdvisees->size; i++)
      {
        int tempID = tempAdvisees->removeBack();
        Student tempStudent(tempID);

        Student newTemp = masterStudent->find(tempStudent);
        newTemp.advisorID = newAdvisorID;
      }

      masterFaculty->deleteRec(faculty);
    }
  }
}

//Nubmer 11
void Simulation::changeAdvisor(int studentID, int newFacultyID)
{
  Student tempStudent(studentID);

  if(masterStudent->contains(tempStudent))
  {
    Student foundStudent = masterStudent->find(tempStudent);
    Faculty tempFaculty(newFacultyID);

    if(masterFaculty->contains(tempFaculty))
    {
      foundStudent.advisorID = newFacultyID;

      cout << "Advisor successfully changed" << endl;
    }
    else
    {
      cout << "The new faculty member is not in the database" << endl;
    }
  }
  else
  {
    cout << "The student is not in the database" << endl;
  }
}

// Number 12
void Simulation::removeAdvisee(int facultyID, int studentID)
{
  Faculty tempFaculty(facultyID);
  if(masterFaculty->contains(tempFaculty))
  {
    Faculty foundFaculty = masterFaculty->find(tempFaculty);

    GenDoublyLinkedList<int>* tempAdvisees = foundFaculty.advisees;
    int index = tempAdvisees->find(studentID);
    string tempIDString;

    cout << "Please enter new advisor ID for the student: " << endl;
    cin >> tempIDString;
    int tempID = stoi(tempIDString);

    Faculty testAdvisor(tempID);
    if(masterFaculty->contains(testAdvisor))
    {
      if(index != -1)
      {
          tempAdvisees->deletePos(index);

          cout << "Advisee sucessfully removed" << endl;
      }

      testAdvisor.addAdvisee(tempID);
      cout << "Advisee sucessfully added to new advisor" << endl;
    }
    else
    {
      cout << "New Advisor ID cannot be found" << endl;
    }

  }
}

// Number 13
void Simulation::rollback()
{

}

// Number 14
void Simulation::Exit()
{
  string studentText = "studentTable.txt";
  string facultyText = "facultyTable.txt";

  masterStudent->filePrint(studentText);
  masterFaculty->filePrint(facultyText);

  cout << "Thank you." << endl;

  // Print out all of masterFaculty and masterStudent to corresponding txt files
  // with all of their information contained maybe with pipe delimited format
  // and then exit the program
}

void Simulation::printOptions()
{
  cout << "Please Enter the Number of the Option!" << endl;
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id" << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}

//Run Simulation
void Simulation::runSimulation()
{
  //Reading from files
  ifstream studentFile;
  ifstream facultyFile;

  studentFile.open("studentTable.txt");
  facultyFile.open("facultyTable.txt");
  string studentLine;
  string facultyLine;

  if(studentFile.good())
  {
    string delimiter = "|";

    while(getline(studentFile, studentLine))
    {
      string studentArr[10];
      // Parsing through each line
      int i = 0;
      int pos = 0;
      while((pos = studentLine.find(delimiter)) != std::string::npos)
      {
        studentArr[i] = studentLine.substr(0, pos);
        studentLine.erase(0, pos + delimiter.length());
      }
      studentArr[i] = studentLine;

      // Reassigning variables from text document
      string tempName = studentArr[0];
      string tempLevel = studentArr[1];
      string tempMajor = studentArr[2];
      string tempAdvisorString = studentArr[3];
      int tempAdvisorID = stoi(tempAdvisorString);
      string tempGPAString = studentArr[4];
      double tempGPA = stod(tempGPAString);
      string tempIDStirng = studentArr[5];
      int tempID = stoi(tempIDStirng);
      // Creating student out of values
      Student tempStudent(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorID);
      // Adding student to tree
      masterStudent->insert(tempStudent);
    }
  }
  if(facultyFile.good())
  {
    string delimter = "|";

    while(getline(facultyFile, facultyLine))
    {
      string facultyArr[1000];
      // Parsing through each line
      int i = 0;
      int pos = 0;
      while((pos = facultyLine.find(delimter)) != std::string::npos)
      {
        facultyArr[i] = facultyLine.substr(0, pos);
        facultyLine.erase(0, pos + delimter.length());
      }
      facultyArr[i] = facultyLine;

      //Reassigning variables
      string tempName = facultyArr[0];
      string tempLevel = facultyArr[1];
      string tempDepart = facultyArr[2];
      string tempIDString = facultyArr[3];
      int tempID = stoi(tempIDString);
      GenDoublyLinkedList<int>* tempAdvisees;
      for(int i = 4; i < (sizeof(facultyArr)/sizeof(*facultyArr)); i++)
      {
        int tempAdvisee = stoi(facultyArr[i]);
        tempAdvisees->insertFront(tempAdvisee);
      }

      //Creating Faculty
      Faculty tempFaculty(tempID, tempName, tempLevel, tempDepart, tempAdvisees);
      //Adding to tree
      masterFaculty->insert(tempFaculty);
    }
  }

  string answer;
  // Running the Simulation
  printOptions();
  cin >> answer;

  while(answer != "14")
  {
    if(answer == "1")
    {
      printStudent();
    }
    else if(answer == "2")
    {
      printFaculty();
    }
    else if(answer == "3")
    {
      string tempAnswer;
      cout << "Please enter the student's id number: " << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      findStudent(tempID);
    }
    else if(answer == "4")
    {
      string tempAnswer;
      cout << "Please enter the advisor's id number: " << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      findFaculty(tempID);
    }
    else if(answer == "5")
    {
      string tempAnswer;
      cout << "Please enter the student's id number: " << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      printStudentAdvisor(tempID);
    }
    else if(answer ==  "6")
    {
      string tempAnswer;
      cout << "Please enter the advisor's id number: " << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      printAdvisees(tempID);
    }
    else if(answer == "7")
    {
      string tempAnswer;
      string tempName;
      string tempMajor;
      string tempLevel;
      cout << "Enter the Student's ID:" << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);
      cout << "Enter the Student's Name: " << endl;
      cin >> tempName;
      cout << "Enter the Student's Major: " << endl;
      cin >> tempMajor;
      cout << "Enter the Student's Level: " << endl;
      cin >> tempLevel;
      cout << "Enter the Student's GPA: " << endl;
      cin >> tempAnswer;
      double tempGPA = stod(tempAnswer);
      cout << "Enter the Student's Advisor's ID: " << endl;
      cin >> tempAnswer;
      int tempAdvisorID = stoi(tempAnswer);

      Student tempStudent(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorID);
      addStudent(tempStudent);
    }
    else if(answer == "8")
    {
      string tempAnswer;
      cout << "Enter the Student's ID:" << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      Student tempStudent = getStudent(tempID);
      deleteStudent(tempStudent);
    }
    else if(answer == "9")
    {
      string tempAnswer;
      string tempName;
      string tempDepart;
      string tempLevel;
      cout << "Enter the Advisor's ID:" << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);
      cout << "Enter the Advisor's Name: " << endl;
      cin >> tempName;
      cout << "Enter the Advisor's Department: " << endl;
      cin >> tempDepart;
      cout << "Enter the Advisor's Level: " << endl;
      cin >> tempLevel;

      Faculty tempFaculty(tempID, tempName, tempLevel, tempDepart);

      string tempAdviseeIDString;
      cout << "Enter one of the Advisor's Advisees' ID numbers (Enter (0) once you're done): " << endl;
      cin >> tempAdviseeIDString;
      while(tempAdviseeIDString != "0")
      {
        int tempAdviseeID = stoi(tempAdviseeIDString);
        tempFaculty.addAdvisee(tempAdviseeID);

        cout << "Enter one of the Advisor's Advisees' ID numbers (Enter (0) once you're done): " << endl;
        cin >> tempAdviseeIDString;
      }

      addFaculty(tempFaculty);
    }
    else if(answer == "10")
    {
      string tempAnswer;
      cout << "Enter the Advisor's ID:" << endl;
      cin >> tempAnswer;
      int tempID = stoi(tempAnswer);

      Faculty tempAdvisor = getAdvisor(tempID);
      deleteFaculty(tempAdvisor);
    }
    else if(answer == "11")
    {
      string studAnswer;
      string facAnswer;
      cout << "Enter the student's id: " << endl;
      cin >> studAnswer;
      int studID = stoi(studAnswer);
      cout << "Enter the new advisor's id: " << endl;
      cin >> facAnswer;
      int facID = stoi(facAnswer);

      changeAdvisor(studID, facID);
    }
    else if(answer == "12")
    {
      string studAnswer;
      string facAnswer;
      cout << "Enter the advisor's id: " << endl;
      cin >> facAnswer;
      int facID = stoi(facAnswer);
      cout << "Enter the student's id: " << endl;
      cin >> studAnswer;
      int studID = stoi(studAnswer);

      removeAdvisee(facID, studID);
    }
    else if(answer == "13")
    {
      cout << "Don't Please" << endl;
    }
    else if(answer == "14")
    {
      Exit();
    }
    else
    {
      cout << "No Valid Answer Given -- Please Enter the Number of the Option" << endl;
    }

    printOptions();
  }

}
