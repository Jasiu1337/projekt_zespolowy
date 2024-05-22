//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Teacher.h
//  @ Date : 16.05.2024
//  @ Author : 
//
//


#if !defined(_TEACHER_H)
#define _TEACHER_H
#include "Student.h"

using namespace std;
class Teacher {
private:
	string login;
	string password;
	string name;
	string surname;
	vector<class Course*> courses;
    class Department* department;
public:
	Teacher(string login, string password, string name, string surname, Department* department);
	bool addCourse(string name, int capacity);
	bool addGrade(Course* course, class Student* student, float grade);
	vector<Course*> getCourses();
	string getLogin();
	string getPassword();
	string getName();
	string getSurname();
    Department* getDepartment();
};

#endif  //_TEACHER_H
