#ifndef SAMANEDOTA_PROFESSOR_H
#define SAMANEDOTA_PROFESSOR_H
#include "Person.h"
#include "Course.h"
#include <fstream>
#include <vector>
class Professor:person{
    string professor_name;
    string professor_number;
    int course_number=1;
    friend class Admin;
public:
    Professor(string &name,string &_professor_number, string &_username, string &_password);
    //    void change_professor_number(string& new_professor_number);
    void create_course(Course &course);
    void add_students_to_course(string &student,Course &course);
    void remove_students_from_course(string &student, Course &course);
    void set_grades(Course &course,string &student,string &grade);
    void create_Homework(Course &course, string &homework);
    void set_homework_grades(string &student, Course &course, string &homework_grades);
};
// student number is always 8 digit

#endif //SAMANEDOTA_PROFESSOR_H
