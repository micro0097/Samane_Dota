#include "Student.h"

Student::Student(string &_student_number, string &_username, string &_password): person(_username,_password){
    this->student_number=_student_number;
}

void Student::set_homework_ans(string &course,string &_homework) {
    this->homework_answer=_homework;
    ofstream homework_ans("homework_answer.txt",ios::app);
    if(homework_ans.is_open()){
        homework_ans<<student_number+"-"+course+"-"+homework_answer<<endl;
    }
    homework_ans.close();
}

string Student::get_student_number() const {
    return student_number;
}

void Student::view_courses_and_grades(string& course) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        string line;
        bool find_course= false;
        int find_student= 0;
        bool find_del= false;
        while(getline(read_courses,line)){
            if(line.find(course)!=string::npos){
                find_course= true;
            }
            else if(find_course && line.find(student_number)!=string::npos){
                if(line.find("del")!=string::npos){
                    find_del= true;
                }
                find_student+=1;
            }
            if(find_student==1 && !find_del){
                find_student=2;
                cout<<line<<endl;
                return;
            }
        }
        read_courses.close();
        if(!find_course){
            cout<<"Didn't find the course"<<endl;
        }
        else if(find_student==0){
            cout<<"Didn't find the student"<<endl;
        }
    }
    else {
        read_courses.close();
        cout << "An error happened while opening file" << endl;
        return;
    }
}
