#include<iostream>
#include<vector>
#include<string>
#include "gradebook.h"
using namespace std;

GradeBook::GradeBook(string name,string iname){
  setCourseName(name);
  setInstructorName(iname);
}
void GradeBook::setCourseName(string name){courseName=name;}
string GradeBook::getCourseName(){return courseName;}
void GradeBook::displayMessage(){
  cout << "Welcome to the grade book for \n" <<getCourseName() << "!" << endl;
}
void GradeBook::setInstructorName(string name){instructorName=name;}
string GradeBook::getInstructorName(){return instructorName;}

