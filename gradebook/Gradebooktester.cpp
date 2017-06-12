#include<iostream>
#include<string>
#include"gradebook.cpp"
using namespace std;
int main(){

  GradeBook gradebook1("cs101 introductino to c++ programming","susan");
  GradeBook gradebook2("cs102 data structures in c++","john");

  cout << "gradebook1 created for course: "<< gradebook1.getCourseName()<<" this course is presented by "<<gradebook1.getInstructorName()<<endl;

  cout << "gradebook2 created for course: "<< gradebook2.getCourseName()<<" this course is presented by "<<gradebook2.getInstructorName()<<endl;

  return 0;
}

