#include "Admin.h"

Admin::Admin(string admin_id,string _username, string _password):Admin_ID(admin_id), person(_username,_password){
    ofstream user("user_information.txt",ios::app);
    if(user.is_open()) {
        user << Admin_ID + "-" + _username + "-" + _password << endl;
    }
    user.close();
}

Professor Admin::create_professor(string &name, string &_professor_number, string &_username, string &_password) {
    Professor professor(name,_professor_number,_username,_password);
    ofstream user("user_information.txt",ios::app);
    if(user.is_open()) {
        user << professor.professor_number + "-" +professor.professor_name+"-"+ _username + "-" + _password << endl;
    }
    user.close();
    ofstream courses_file;
    courses_file.open("course_file.txt",ios::app);
    if(courses_file.is_open()){
        courses_file<<"Professor: "+professor.professor_number<<endl;
    }
    courses_file.close();
    return professor;
}

Student Admin::create_student(string &_student_number, string &_username, string &_password) {
    Student student(_student_number,_username,_password);
    ofstream user("user_information.txt",ios::app);
    if(user.is_open()) {
        user << student.student_number + "-" + _username + "-" + _password << endl;
    }
    user.close();
    return student;
}

void Admin::read() {
    ifstream user("user_information.txt");
    if(user.is_open()){
        string l;
        while (getline(user,l)){
            cout<<l<<endl;
        }
    }
    user.close();
}

void Admin::update_professor_number(Professor &professor, string &new_professor_number) {
    ifstream user("user_information.txt");
    if(user.is_open()){
        string l;
        vector<string> users;
        while (getline(user,l)){
            if(l.find(professor.professor_number)!=string::npos){
                int len=professor.professor_number.length();
                int len_l=l.length();
                l=new_professor_number+l.substr(len,len_l-len);
            }
            users.push_back(l);
        }
        user.close();
        ofstream user_edit("user_information.txt");
        if(user.is_open()) {
            for (string &i: users) {
                user_edit<<i<<endl;
            }
        }
        user_edit.close();
    }
    else{
        user.close();
    }
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line=="Professor: "+professor.professor_number){
                line="Professor: "+new_professor_number;
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
    professor.professor_number=new_professor_number;
}

void Admin::update_student_number(Student &student, string &new_student_number) {
    ifstream user("user_information.txt");
    if(user.is_open()){
        string l;
        vector<string> users;
        while (getline(user,l)){
            if(l.find(student.student_number)!=string::npos){
                int len=student.student_number.length();
                int len_l=l.length();
                l=new_student_number+l.substr(len,len_l-len);
            }
            users.push_back(l);
        }
        user.close();
        ofstream user_edit("user_information.txt");
        if(user.is_open()) {
            for (string &i: users) {
                user_edit<<i<<endl;
            }
        }
        user_edit.close();
    }
    else{
        user.close();
    }
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line.find(student.student_number)!=string::npos){
                int len=student.student_number.length();
                int len_l=line.length();
                line=new_student_number+line.substr(len,len_l-len);
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
    student.student_number=new_student_number;
}

void Admin::delete_member_professor(Professor &professor) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        int find_professor=0;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line=="Professor: "+professor.professor_number){
                find_professor+=1;
            }
            else if(find_professor==1){
                find_professor=2;
                line="del-"+line;
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
}

void Admin::delete_member_student(Student &student) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        int find_student=0;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line.find(student.student_number)!=string::npos){
                find_student+=1;
            }
            else if(find_student==1){
                find_student=2;
                line="del-"+line;
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
}

void Admin::restore_user_professor(Professor &professor) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        int find_professor=0;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line=="del-Professor: "+professor.professor_number){
                find_professor+=1;
            }
            else if(find_professor==1){
                find_professor=2;
                line=line.substr(4,line.length()-4);
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
}

void Admin::restore_user_student(Student &student) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        int find_student=0;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line.find(student.student_number)!=string::npos){
                find_student+=1;
            }
            else if(find_student==1){
                find_student=2;
                line=line.substr(4,line.length()-4);
            }
            information.push_back(line);
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string & i : information){
                courses_file<<i<<endl;
            }
        }
        courses_file.close();
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
}

bool Admin::exist(string &info) {
    ifstream read_user("user_information.txt");
    bool f= false;
    if(read_user.is_open()){
        string l;
        while (getline(read_user,l)){
            if(l.find(info)!=string::npos){
                f= true;
                break;
            }
        }
    }
    read_user.close();
    return f;
}




