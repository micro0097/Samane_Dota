#include "Course.h"

Course::Course(string &_course){
    this->course=_course;
}

void Course::set_course_grade(string& _grade) {
    this->course_grade=_grade;
}

string Course::get_course_name() const {
    return course;
}





