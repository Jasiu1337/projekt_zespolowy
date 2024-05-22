//
// Created by jantr on 16.05.2024.

#include <thread>
#include "interface.h"

University* init()
{
    University* umcs=new University("Uniwersytet Marii Curie-Sklodowskiej w Lublinie");
    umcs->addDepartment("Wydzial Matematyki Fizyki i Informatyki");
    umcs->RegisterStudent("j","j","Jan","Trojnar",umcs->getDepartments()[0]);
    umcs->RegisterStudent("p","p","Piotr","Stec",umcs->getDepartments()[0]);
    umcs->RegisterStudent("a","a","Amelia","Kowalik",umcs->getDepartments()[0]);
    umcs->RegisterStudent("u","u","Urszula","Wrobel",umcs->getDepartments()[0]);
    umcs->RegisterTeacher("n","n","nauczyciel","",umcs->getDepartments()[0]);
    umcs->getDepartments()[0]->getTeachers()[0]->addCourse("Inzynieria Oprogramowania",10);
    umcs->getDepartments()[0]->getCourses()[0]->setMaterials("materialy.pdf");
    umcs->getDepartments()[0]->getTeachers()[0]->addCourse("ASyKo",10);
    for(Student* student:umcs->getStudents())
    {
        student->joinCourse(umcs->getDepartments()[0]->getCourses()[0]);
    }
    umcs->getDepartments()[0]->getCourses()[0]->addGrade(umcs->getStudents()[0],2);
    umcs->addDepartment("Wydzial Prawa i administracji");
    umcs->addDepartment("Wydzial Filologiczny");
    return umcs;
}
void start(University* university)
{
    cout<<"Witaj w systemie "+university->getName()<<endl;
    while(true)
    {
        cout<<"student (1) / nauczyciel (2) / wyjscie (3)"<<endl;
        int choice;
        validatedInput(choice);
        if(choice==1)
        {
            cout<<"logowanie studenta (1) / rejestracja studenta (2) / anuluj (3)"<<endl;
            validatedInput(choice);
            if(choice==1)
            {
                string login,password;
                cout<<"podaj login: "<<endl;
                cin.ignore();
                getline(cin,login);
                cout<<"podaj haslo: "<<endl;
                getline(cin,password);
                Student* student=university->LoginStudent(login,password);
                if(student)
                {
                    start(student);
                }
                else
                {
                    cout<<"niepoprawny login lub haslo!"<<endl;
                }
            }
            else if(choice==2)
            {
                vector<Department*> departments=university->getDepartments();
                cout<<"wybierz wydzial:"<<endl;
                for(int i=0;i<departments.size();++i)
                {
                    cout<<i+1<<": "<<departments[i]->getName()<<endl;
                }
                validatedInput(choice);
                if(choice>0&&choice<=departments.size()) {
                    Department *department = departments[choice - 1];
                    string login, password, name, surname;
                    cout << "podaj login: " << endl;
                    cin.ignore();
                    getline(cin,login);
                    cout << "podaj haslo: " << endl;
                    getline(cin,password);
                    cout << "podaj imie: " << endl;
                    getline(cin,name);
                    cout << "podaj nazwisko: " << endl;
                    getline(cin,surname);
                    if (university->RegisterStudent(login, password, name, surname, department)) {
                        cout << "zarejestrowano pomyslnie!" << endl;
                    } else {
                        cout << "rejestracja nie powiodla sie!" << endl;
                    }
                }
                else
                {
                    cout<<"niepoprawny wybor!"<<endl;
                }
            }
        }
        else if(choice==2)
        {
            cout<<"logowanie nauczyciela (1) / rejestracja nauczyciela (2) / anuluj (3)"<<endl;
            validatedInput(choice);
            if(choice==1)
            {
                string login,password;
                cout<<"podaj login: "<<endl;
                cin.ignore();
                getline(cin,login);
                cout<<"podaj haslo: "<<endl;
                getline(cin,password);
                Teacher* teacher=university->LoginTeacher(login,password);
                if(teacher)
                {
                    start(teacher);
                }
                else
                {
                    cout<<"niepoprawny login lub haslo!"<<endl;
                }
            }
            else if(choice==2)
            {
                vector<Department*> departments=university->getDepartments();
                cout<<"wybierz wydzial:"<<endl;
                for(int i=0;i<departments.size();++i)
                {
                    cout<<i+1<<": "<<departments[i]->getName()<<endl;
                }
                validatedInput(choice);
                if(choice>0&&choice<=departments.size()) {
                    Department *department = departments[choice - 1];
                    string login, password, name, surname;
                    cout << "podaj login: " << endl;
                    cin.ignore();
                    getline(cin,login);
                    cout << "podaj haslo: " << endl;
                    getline(cin,password);
                    cout << "podaj imie: " << endl;
                    getline(cin,name);
                    cout << "podaj nazwisko: " << endl;
                    getline(cin,surname);
                    if (university->RegisterTeacher(login, password, name, surname, department)) {
                        cout << "zarejestrowano pomyslnie!" << endl;
                    } else {
                        cout << "rejestracja nie powiodla sie!" << endl;
                    }
                }
                else
                {
                    cout<<"niepoprawny wybor!"<<endl;
                }
            }
        }
        else if(choice==3)
        {
            break;
        }
    }
}
void start(Student* student)
{
    cout<<"zalogowano jako "<<student->getName()+" "<<student->getSurname()<<endl;
    int choice;
    while(true)
    {
        cout<<"zapisy na kurs (1) / pobieranie materialow (2) / oceny (3) / wyloguj (4)"<<endl;
        validatedInput(choice);
        if(choice==1)
        {
            vector<Teacher*> teachers=student->getDepartment()->getTeachers();
            if(teachers.empty())
            {
                cout<<"brak prowadzacych na tym wydziale!"<<endl;
            }
            else
            {
                cout << "wybierz prowadzacego:" << endl;
                for (int i = 0; i < teachers.size(); ++i) {
                    cout << i + 1 << ": " << teachers[i]->getName() << " " << teachers[i]->getSurname() << endl;
                }
                validatedInput(choice);
                if (choice > 0 && choice <= teachers.size()) {
                    vector<Course *> courses = teachers[choice - 1]->getCourses();
                    if(courses.empty())
                    {
                        cout<<"brak kursow u tego prowadzacego!"<<endl;
                    }
                    else {
                        cout << "wybierz kurs, na ktory chcesz sie zapisac:" << endl;
                        for (int i = 0; i < courses.size(); ++i) {
                            cout << i + 1 << ": " << courses[i]->getName() << endl;
                        }
                        validatedInput(choice);
                        if (choice > 0 && choice <= courses.size()) {
                            if (student->joinCourse(courses[choice - 1])) {
                                cout << "pomyslnie zapisano na kurs " << courses[choice - 1]->getName() << endl;
                            } else {
                                cout << "nie udalo sie zapisac!" << endl;
                            }
                        } else {
                            cout << "niepoprawny wybor!" << endl;
                        }
                    }
                } else {
                    cout << "niepoprawny wybor!" << endl;
                }
            }
        }
        else if(choice==2)
        {
            vector<Course*> courses=student->getCourses();
            if(courses.empty())
            {
                cout<<"brak kursow!"<<endl;
            }
            else {
                cout << "wybierz kurs, z ktorego materialy chcesz pobrac:" << endl;
                for (int i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ": " << courses[i]->getName() << endl;
                }
                validatedInput(choice);
                if (choice > 0 && choice <= courses.size()) {
                    if (courses[choice - 1]->getMaterials() == "") {
                        cout << "brak materialow do pobrania!" << endl;
                    } else {
                        cout << "pobieranie pliku " << courses[choice - 1]->getMaterials() << ":" << endl;
                        downloadAnimation();
                        cout << "pomyslnie pobrano plik" << endl;
                    }
                } else {
                    cout << "niepoprawny wybor!" << endl;
                }
            }
        }
        else if(choice==3)
        {
            vector<Course*> courses=student->getCourses();
            if(courses.empty())
            {
                cout<<"brak kursow!"<<endl;
            }
            else {
                cout << "wybierz kurs, z ktorego oceny chcesz zobaczyc:" << endl;
                for (int i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ": " << courses[i]->getName() << endl;
                }
                validatedInput(choice);
                if (choice > 0 && choice <= courses.size()) {
                    vector<float> grades = courses[choice - 1]->getGrades()[student];
                    if (grades.empty()) {
                        cout << "brak ocen do wyswietlenia!" << endl;
                    } else {
                        cout << "oceny z kursu " << courses[choice - 1]->getName() << ": " << endl;
                        for (int i = 0; i < grades.size(); ++i) {
                            cout << grades[i] << endl;
                        }
                    }
                } else {
                    cout << "niepoprawny wybor!" << endl;
                }
            }
        }
        else if(choice==4)
        {
                cout<<"wylogowano!"<<endl;
                break;
        }
    }
}
void start(Teacher* teacher)
{
    cout<<"zalogowano jako "<<teacher->getName()+" "<<teacher->getSurname()<<endl;
    while(true)
    {
        cout<<"tworzenie kursu (1) / dodawanie materialow (2) / dodawanie ocen (3) / wyloguj (4)"<<endl;
        int choice;
        validatedInput(choice);
        if(choice==1)
        {
            cout<<"podaj nazwe nowego kursu: "<<endl;
            string name;
            cin.ignore();
            getline(cin,name);
            cout<<"podaj maksymalna liczbe miejsc: "<<endl;
            validatedInput(choice);
            if(teacher->addCourse(name,choice))
            {
                cout<<"pomyslnie utworzono kurs "<<name<<endl;
            }
            else
            {
                cout<<"nie udalo sie utworzyc kursu"<<endl;
            }
        }
        else if(choice==2)
        {
            vector<Course*> courses=teacher->getCourses();
            if(courses.empty())
            {
                cout<<"brak prowadzonych kursow!"<<endl;
            }
            else {
                cout << "wybierz kurs, do ktorego materialy chcesz dodac:" << endl;
                for(int i=0;i<courses.size();++i)
                {
                    cout<<i+1<<": "+courses[i]->getName()<<endl;
                }
                validatedInput(choice);
                if(choice > 0 && choice <= courses.size())
                {
                    cout<<"podaj nazwe pliku, ktory chcesz zalaczyc:"<<endl;
                    string filename;
                    cin.ignore();
                    getline(cin,filename);
                    cout<<"przesylanie pliku "<<filename<<endl;
                    downloadAnimation();
                    courses[choice-1]->setMaterials(filename);
                    cout<<"pomyslnie dodano materialy do kursu"<<endl;
                }
                else
                {
                    cout<<"niepoprawny wybor!"<<endl;
                }
            }
        }
        else if(choice==3)
        {
            vector<Course*> courses=teacher->getCourses();
            if(courses.empty())
            {
                cout<<"brak prowadzonych kursow!"<<endl;
            }
            else {
                cout << "wybierz kurs, z ktorego chcesz wystawic ocene:" << endl;
                for(int i=0;i<courses.size();++i)
                {
                    cout<<i+1<<": "+courses[i]->getName()<<endl;
                }
                validatedInput(choice);
                if(choice > 0 && choice <= courses.size())
                {
                   Course* course=courses[choice-1];
                   vector<Student*>students=course->getStudents();
                   if(students.empty())
                   {
                       cout<<"brak studentow zapisanych na kurs!"<<endl;
                   }
                   else
                   {
                       cout<<"Wybierz studenta, ktoremu chcesz wystawic ocene:"<<endl;
                       for(int i=0;i<students.size();++i)
                       {
                           cout<<i+1<<": "+students[i]->getName()<<" "<<students[i]->getSurname()<<endl;
                       }
                       validatedInput(choice);
                       if(choice > 0 && choice <= students.size())
                       {
                           cout<<"wpisz ocene:"<<endl;
                           float grade;
                           validatedInput(grade);
                           if(teacher->addGrade(course,students[choice-1],grade))
                           {
                               cout<<"pomyslnie wystwiono ocene ("<<grade<<") "<<"studentowi "<<students[choice-1]->getName()
                               <<" "<<students[choice-1]->getSurname()<<" w kursie "<<course->getName()<<endl;
                           }
                       }
                       else
                       {
                           cout<<"niepoprawny wybor!"<<endl;
                       }

                   }
                }
                else
                {
                    cout<<"niepoprawny wybor!"<<endl;
                }
            }
        }
        else if(choice==4)
        {
            cout<<"wylogowano!"<<endl;
            break;
        }
    }
}
void downloadAnimation()
{
    for(int i=0;i<20;++i)
    {
        cout<<"*";
        this_thread::sleep_for(300ms);
    }
    cout<<endl;
}
void validatedInput(int& value)
{
    for (;;) {
        if (cin >> value) {
            break;
        } else {
            cout <<"Wprowadz poprawna wartosc!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void validatedInput(float& value)
{
    for (;;) {
        if (cin >> value) {
            break;
        } else {
            cout <<"Wprowadz poprawna wartosc!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}