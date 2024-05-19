#include "Admin.h"

string split(string& inp){
    string splited;
    for(char c: inp){
        if(c==' '){
            continue;
        }
        else{
            splited+=c;
        }
    }
    return splited;
}

int main(){
    //admin default
    Admin admin1;
    while (true){
        cout<<"Please enter your username and password"<<endl;
        cout<<"username: ";
        string user;
        string pass;
        cin>>user;
        cout<<endl;
        cout<<"password: ";
        cin>>pass;
        cout<<endl;
        if(user=="Admin"){
            if(!admin1.exist(pass)) {
                string admin_id;
                cout << "Enter your admin id : " << endl;
                cin >> admin_id;
                Admin new_admin(admin_id, user, pass);
                cout<<"log for this role ->"<<endl;
//                cout<<"create_professor\n";
//                cout<<"create_student\n";
                cout<<"read\n";
                cout<<"update_professor_number\n";
                cout<<"update_student_number\n";
                cout<<"delete_member_professor\n";
                cout<<"delete_member_student\n";
                cout<<"restore_user_professor\n";
                cout<<"restore_user_student\n";
                cout<<"exist\n";
                string input;
                cin>>input;
                if(input=="update_professor_number"){
                    new_admin.read();



                }

            }
            else{
                cout<<"log for this role ->"<<endl;
                cout<<"create_professor\n";
                cout<<"create_student\n";
                cout<<"read\n";
                cout<<"update_professor_number\n";
                cout<<"update_student_number\n";
                cout<<"delete_member_professor\n";
                cout<<"delete_member_student\n";
                cout<<"restore_user_professor\n";
                cout<<"restore_user_student\n";
                cout<<"exist\n";

            }
        }
        else if(user=="Professor"){
            string professor_name;
            cout << "Enter your professor_name" << endl;
            cin >> professor_name;
            string professor_number;
            cout << "Enter your professor_number" << endl;
            cin >> professor_number;
            cout<<"log for this role ->"<<endl;
            cout<<"create_course\n";
            cout<<"add_students_to_course\n";
            cout<<"remove_students_from_course\n";
            cout<<"set_grades\n";
            cout<<"create_Homework\n";
            cout<<"set_homework_grades\n";
            if(!admin1.exist(pass)) {
                Professor professor1 = admin1.create_professor(professor_name, professor_number, user, pass);
                string course_3="Riazi";
                string course_2="Fizik";
                string course_1="AP";
                Course course1(course_1);
                Course course2(course_2);
                Course course3(course_3);
                professor1.create_course(course1);
                professor1.create_course(course2);
                professor1.create_course(course3);
                string student_number="40229043";
                professor1.add_students_to_course(student_number,course1);
                professor1.add_students_to_course(student_number,course2);
            }
            else{
                Professor professor1(professor_name, professor_number, user, pass);
            }
        }
        else if(user=="Student"){
            string student_number;
            cout<<"Enter your student_number"<<endl;
            cin>>student_number;
            cout<<"log for this role ->"<<endl;
            cout<<"set_homework_ans\n";
            cout<<"get_student_number\n";
            cout<<"view_courses_and_grades\n";
            if(!admin1.exist(pass)) {
                Student student1 = admin1.create_student(student_number, user, pass);
            }
            else{
                Student student1(student_number, user, pass);
            }
        }
        else{
            cout<<"Wrong username!\n";
            continue;
        }
        string ending;
        cout<<"Do you wanna end the program? yes/no"<<endl;
        cin>>ending;
        if(ending=="yes" || ending=="Yes"){
            break;
        }
    }
}