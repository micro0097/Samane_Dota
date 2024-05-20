#ifndef SAMANEDOTA_ADMIN_H
#define SAMANEDOTA_ADMIN_H

#include "Student.h"
#include "Professor.h"
class Admin:person{
    const string Admin_ID;
    string password;
public:
    explicit Admin(string admin_id="12345678",string _username="Admin", string _password="alireza");
    void save_admin(Admin &admin);
    Professor create_professor(string &name,string &_professor_number, string &_username, string &_password);
    Student create_student(string& _student_number,string& _username,string& _password);
    void read(); //All of users information
    void update_professor_number(Professor& professor,string &new_professor_number);
    void update_student_number(Student& student,string& new_student_number);
    void delete_member_professor(Professor& professor);
    void delete_member_student(Student& student);
    void restore_user_professor(Professor& professor);
    void restore_user_student(Student& student);
    bool exist(string& info);
    //soft delete
};

#endif //SAMANEDOTA_ADMIN_H