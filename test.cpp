#include "test.h"
#include "Department.h"
#include "Course.h"
#include "University.h"
#include <iostream>
using namespace std;
//
// Created by jantr on 22.05.2024.
//
void addCourseTest()
{
    Department* department=new Department("department");
    Course* course1=new Course("course",10);
    Course* course2=new Course("course",10);
    Course* course3=new Course("other course",10);
    assert(department->addCourse(course1)==true);//dodanie pierwszego kursu
    assert(department->getCourses().size()==1);//sprawdzenie ilosci kursow
    assert(department->addCourse(course2)==false);//dodanie kursu o takiej samej nazwie jak pierwszy kurs
    assert(department->getCourses().size()==1);//sprawdzenie ilosci kursow
    assert(department->addCourse(course3)==true);//dodanie kursu o innej nazwie
    assert(department->getCourses().size()==2);//sprawdzenie ilosci kursow
}
void teacherTest()
{
    string login="login";
    string password="password";
    string name="name";
    string surname="surname";
    Department* department=new Department("department");
    Teacher* teacher=new Teacher(login,password,name,surname,department);
    assert(teacher->getLogin()==login);//sprawdzenie, czy parametry podawane w konstruktorze sa poprawnie zwracane przez akcesory
    assert(teacher->getPassword()==password);
    assert(teacher->getName()==name);
    assert(teacher->getSurname()==surname);
    assert(teacher->getDepartment()==department);
}
void addTeacherTest()
{
    Department* department=new Department("department");
    Teacher* teacher=new Teacher("login","password","name","surname",department);
    assert(department->addTeacher(teacher));//dodanie nauczyciela
    assert(department->getTeachers().size()==1);//sprawdzienie ilosci nauczycieli
    assert(department->getTeachers()[0]==teacher);//sprawdzenie, czy dodany nauczyciel odpowiada nauczucielowi na wydziale
}
void registerTeacherTest(){
    University* university=new University("university");
    university->addDepartment("department");
    assert(university->RegisterTeacher("login","password","name1","surname1",university->getDepartments()[0])==true);
    //dodanie nauczyciela
    assert(university->getTeachers().size()==1);//sprawdzienie ilosci nauczycieli
    assert(university->RegisterTeacher("login","password","name","surname",university->getDepartments()[0])==false);
    //dodanie nauczyciela o tych samych danych logowania
    assert(university->getTeachers().size()==1);//sprawdzienie ilosci nauczycieli
    assert(university->RegisterTeacher("LOGIN","PASSWORD","name","surname",university->getDepartments()[0])==true);
    //dodanie nauczyciela o innych danych logowania
    assert(university->getTeachers().size()==2);//sprawdzienie ilosci nauczycieli
}
void runAllTests()
{
    addCourseTest();
    teacherTest();
    addTeacherTest();
    registerTeacherTest();
}