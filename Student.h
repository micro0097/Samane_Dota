#ifndef SAMANEDOTA_STUDENT_H
#define SAMANEDOTA_STUDENT_H
#include "Person.h"
#include <fstream>
class Student:person{
    string student_number;
    string homework_answer="None";
    friend class Admin;
public:
    Student(string& _student_number,string& _username,string& _password);
    void set_homework_ans(string &course,string &_homework);
    string get_student_number() const;
//    string get_homework_ans() const;
    void view_courses_and_grades(string& course);
};

#endif //SAMANEDOTA_STUDENT_H