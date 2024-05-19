#ifndef SAMANEDOTA_COURSE_H
#define SAMANEDOTA_COURSE_H
#include <iostream>
using namespace std;

class Course{
    string course;
    string course_grade;
public:
    explicit Course(string& _course);
    void set_course_grade(string& _grade);
    string get_course_name() const;
};

#endif //SAMANEDOTA_COURSE_H
