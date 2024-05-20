#include "Professor.h"

Professor::Professor(string &name,string &_professor_number, string &_username, string &_password): person(_username,_password){
    this->professor_number=_professor_number;
    this->professor_name=name;
}

void Professor::create_course(Course &course) {
    ifstream read_courses("course_file.txt");
    if(read_courses.is_open()){
        int find_professor=0;
        string line;
        vector<string> information;
        while(getline(read_courses,line)){
            if(line=="Professor: "+professor_number && find_professor==0){
                information.push_back(line);
                information.push_back(to_string(course_number)+"_ "+course.get_course_name());
                find_professor+=1;
            }
            else {
                information.push_back(line);
            }
        }
        read_courses.close();
        ofstream courses_file;
        courses_file.open("course_file.txt");
        if(courses_file.is_open()){
            for(string &i:information)
                courses_file<<i<<endl;
            course_number++;
        }
        courses_file.close();
    }
}

void Professor::add_students_to_course(string &student,Course &course) {
    ifstream read_user("user_information.txt");
    bool f= false;
    if(read_user.is_open()){
        string l;
        while (getline(read_user,l)){
            if(l.find(student)!=string::npos){
                f= true;
                break;
            }
        }
    }
    read_user.close();
    if(f) {
        ifstream read_courses("course_file.txt");
        if (read_courses.is_open()) {
            string line;
            bool find_course = false;
            int find_professor = 0;
            vector<string> information;
            while (getline(read_courses, line)) {
                if (line == "Professor: " + professor_number) {
                    find_professor += 1;
                } else if (find_professor == 1 && line.find("Professor") != string::npos) {
                    find_professor = 2;
                } else if (find_professor == 1 && line.find(course.get_course_name()) != string::npos) {
                    find_course = true;
                    information.push_back(student + "-");
                }
                information.push_back(line);
            }
            read_courses.close();
            if (!find_course) {
                cout << "Didn't find the course" << endl;
            } else {
                ofstream courses_file;
                courses_file.open("course_file.txt");
                if (courses_file.is_open()) {
                    for (string &i: information) {
                        courses_file << i << endl;
                    }
                }
                courses_file.close();
            }
        } else {
            read_courses.close();
            cout << "An error happened while opening file or didn't create any courses\n";
            return;
        }
    }
}

void Professor::remove_students_from_course(string &student, Course &course) {
    ifstream read_user("user_information.txt");
    bool f= false;
    if(read_user.is_open()){
        string l;
        while (getline(read_user,l)){
            if(l.find(student)!=string::npos){
                f= true;
                break;
            }
        }
    }
    read_user.close();
    if(f) {
        ifstream read_courses("course_file.txt");
        if (read_courses.is_open()) {
            string line;
            bool find_course = false;
            int find_student = 0;
            int find_professor = 0;
            vector<string> information;
            while (getline(read_courses, line)) {
                if (line == "Professor: " + professor_number) {
                    find_professor += 1;
                } else if (find_professor == 1 && line.find("Professor") != string::npos) {
                    find_professor = 2;
                } else if (find_professor == 1 && line.find(course.get_course_name()) != string::npos) {
                    find_course = true;
                } else if (find_professor == 1 && find_course && line.find(student) != string::npos) {
                    find_student += 1;
                }
                if (find_student == 1) {
                    find_student = 2;
                } else {
                    information.push_back(line);
                }
            }
            read_courses.close();
            if (!find_course) {
                cout << "Didn't find the course" << endl;
            } else if (find_student == 0) {
                cout << "Didn't find the student" << endl;
            } else {
                ofstream courses_file;
                courses_file.open("course_file.txt");
                if (courses_file.is_open()) {
                    for (string &i: information) {
                        courses_file << i << endl;
                    }
                }
                courses_file.close();
            }
        } else {
            read_courses.close();
            cout << "An error happened while opening file or didn't create any courses\n";
            return;
        }
    }
}

void Professor::set_grades(Course &course, string &student,string &grade) {
    ifstream read_user("user_information.txt");
    bool f= false;
    if(read_user.is_open()){
        string l;
        while (getline(read_user,l)){
            if(l.find(student)!=string::npos){
                f= true;
                break;
            }
        }
    }
    read_user.close();
    if(f) {
        ifstream read_courses("course_file.txt");
        if (read_courses.is_open()) {
            string line;
            bool find_course = false;
            int find_student = 0;
            int find_professor = 0;
            bool find_del = false;
            vector<string> information;
            while (getline(read_courses, line)) {
                if (line == "Professor: " + professor_number) {
                    find_professor += 1;
                } else if (find_professor == 1 && line.find("Professor") != string::npos) {
                    find_professor = 2;
                } else if (find_professor == 1 && line.find(course.get_course_name()) != string::npos) {
                    find_course = true;
                } else if (find_professor == 1 && find_course && line.find(student) != string::npos) {
                    if (line.find("del") == string::npos) {
                        find_del = true;
                    }
                    find_student += 1;
                }
                if (find_student == 1 && !find_del) {
                    find_student = 2;
                    line += "Course grade: " + grade + "-";
                }
                information.push_back(line);
            }
            read_courses.close();
            if (!find_course) {
                cout << "Didn't find the course" << endl;
            } else if (find_student == 0) {
                cout << "Didn't find the student" << endl;
            } else {
                ofstream courses_file;
                courses_file.open("course_file.txt");
                if (courses_file.is_open()) {
                    for (string &i: information) {
                        courses_file << i << endl;
                    }
                }
                courses_file.close();
            }
        } else {
            read_courses.close();
            cout << "An error happened while opening file" << endl;
            return;
        }
    }
}

void Professor::create_Homework(Course &course, string &homework) {
    ofstream homework_file;
    homework_file.open("homework_file.txt", ios::app);
    if (homework_file.is_open()) {
        homework_file << professor_name+"-"+course.get_course_name() + "-" + homework << endl;
    }
    homework_file.close();
}

void Professor::set_homework_grades(string &student, Course &course, string &homework_grades) {
    ifstream read_user("user_information.txt");
    bool f= false;
    if(read_user.is_open()){
        string l;
        while (getline(read_user,l)){
            if(l.find(student)!=string::npos){
                f= true;
                break;
            }
        }
    }
    read_user.close();
    if(f) {
        ifstream homework_ans("homework_answer.txt");
        if (homework_ans.is_open()) {
            string l;
            while (getline(homework_ans, l)) {
                cout << l << endl;
            }
        }
        homework_ans.close();
        ifstream read_courses("course_file.txt");
        if (read_courses.is_open()) {
            string line;
            bool find_course = false;
            int find_student = 0;
            int find_professor = 0;
            bool find_del = false;
            vector<string> information;
            while (getline(read_courses, line)) {
                if (line == "Professor: " + professor_number) {
                    find_professor += 1;
                } else if (find_professor == 1 && line.find("Professor") != string::npos) {
                    find_professor = 2;
                } else if (find_professor == 1 && line.find(course.get_course_name()) != string::npos) {
                    find_course = true;
                } else if (find_professor == 1 && find_course && line.find(student) != string::npos) {
                    if (line.find("del") == string::npos) {
                        find_del = true;
                    }
                    find_student += 1;
                }
                if (find_student == 1 && !find_del) {
                    find_student = 2;
                    line += "Homework grade for course " + course.get_course_name() + ": " + homework_grades;
                }
                information.push_back(line);
            }
            read_courses.close();
            if (!find_course) {
                cout << "Didn't find the course" << endl;
            } else if (find_student == 0) {
                cout << "Didn't find the student" << endl;
            } else {
                ofstream courses_file;
                courses_file.open("course_file.txt");
                if (courses_file.is_open()) {
                    for (string &i: information) {
                        courses_file << i << endl;
                    }
                }
                courses_file.close();
            }
        } else {
            read_courses.close();
            cout << "An error happened while opening file" << endl;
            return;
        }
    }
}