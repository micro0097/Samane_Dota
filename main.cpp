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
            cout<<"log for this role ->"<<endl;
            cout<<"read\n";
            cout<<"update_professor_number\n";
            cout<<"update_student_number\n";
            cout<<"delete_member_professor\n";
            cout<<"delete_member_student\n";
            cout<<"restore_user_professor\n";
            cout<<"restore_user_student\n";
            cout<<"exist\n";
            if(!admin1.exist(pass)) {
                string admin_id;
                cout << "Enter your admin id : " << endl;
                cin >> admin_id;
                Admin new_admin(admin_id, user, pass);
                admin1.save_admin(new_admin);
                string input;
                cin>>input;
                if(input=="read"){
                    new_admin.read();
                }
                else if(input=="update_professor_number"){
                    new_admin.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    string new_professor_number;
                    cout<<"enter new number: "<<endl;
                    cin>>new_professor_number;
                    Professor professor2(professor_name1,professor_name1,username,password);
                    new_admin.update_professor_number(professor2,new_professor_number);
                }
                else if(input=="update_student_number"){
                    new_admin.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    string new_student_number;
                    cout<<"enter new number: "<<endl;
                    cin>>new_student_number;
                    Student student2(student_number1,username,password);
                    new_admin.update_student_number(student2,new_student_number);
                }
                else if(input=="delete_member_professor"){
                    new_admin.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Professor professor2(professor_name1,professor_name1,username,password);
                    new_admin.delete_member_professor(professor2);
                }
                else if(input=="delete_member_student"){
                    new_admin.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Student student2(student_number1,username,password);
                    new_admin.delete_member_student(student2);
                }
                else if(input=="restore_user_professor"){
                    new_admin.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Professor professor2(professor_name1,professor_name1,username,password);
                    new_admin.restore_user_professor(professor2);
                }
                else if(input=="restore_user_student"){
                    new_admin.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Student student2(student_number1,username,password);
                    new_admin.restore_user_student(student2);
                }
            }
            else{
                string input;
                cin>>input;
                if(input=="read"){
                    admin1.read();
                }
                else if(input=="update_professor_number") {
                    admin1.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout << "username: " << endl;
                    string username;
                    string password;
                    cin >> username;
                    cout << endl;
                    cout << "password: " << endl;
                    cin >> password;
                    string new_professor_number;
                    cout << "enter new number: " << endl;
                    cin >> new_professor_number;
                    Professor professor2(professor_name1, professor_number1, username, password);
                    admin1.update_professor_number(professor2, new_professor_number);
                }
                else if(input=="update_student_number") {
                    admin1.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout << "username: " << endl;
                    string username;
                    string password;
                    cin >> username;
                    cout << endl;
                    cout << "password: " << endl;
                    cin >> password;
                    string new_student_number;
                    cout << "enter new number: " << endl;
                    cin >> new_student_number;
                    Student student2(student_number1, username, password);
                    admin1.update_student_number(student2, new_student_number);
                }
                else if(input=="delete_member_professor"){
                    admin1.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Professor professor2(professor_name1,professor_number1,username,password);
                    admin1.delete_member_professor(professor2);
                }
                else if(input=="delete_member_student"){
                    admin1.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Student student2(student_number1,username,password);
                    admin1.delete_member_student(student2);
                }
                else if(input=="restore_user_professor"){
                    admin1.read();
                    string professor_name1;
                    cout << "Enter your professor_name" << endl;
                    cin >> professor_name1;
                    string professor_number1;
                    cout << "Enter your professor_number" << endl;
                    cin >> professor_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Professor professor2(professor_name1,professor_number1,username,password);
                    admin1.restore_user_professor(professor2);
                }
                else if(input=="restore_user_student"){
                    admin1.read();
                    string student_number1;
                    cout << "Enter your student_number" << endl;
                    cin >> student_number1;
                    cout<<"username: "<<endl;
                    string username;
                    string password;
                    cin>>username;
                    cout<<endl;
                    cout<<"password: "<<endl;
                    cin>>password;
                    Student student2(student_number1,username,password);
                    admin1.restore_user_student(student2);
                }
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
            string input_professor;
            cin>>input_professor;
            if(!admin1.exist(pass)) {
                Professor professor1 = admin1.create_professor(professor_name, professor_number, user, pass);
                if(input_professor=="create_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    professor1.create_course(course1);
                }
                else if(input_professor=="add_students_to_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    professor1.add_students_to_course(student_number,course1);
                }
                else if(input_professor=="remove_students_from_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    professor1.remove_students_from_course(student_number,course1);
                }
                else if(input_professor=="set_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    cout<<"Enter the grade : ";
                    string grade;
                    cin>>grade;
                    professor1.set_grades(course1,student_number,grade);
                }
                else if(input_professor=="create_Homework"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the homework : ";
                    string homework;
                    cin>>homework;
                    professor1.create_Homework(course1,homework);
                }
                else if(input_professor=="set_homework_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    cout<<"Enter the homework grade : ";
                    string homework_grade;
                    cin>>homework_grade;
                    professor1.set_homework_grades(student_number,course1,homework_grade);
                }
            }
            else{
                Professor professor1(professor_name, professor_number, user, pass);
                if(input_professor=="create_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    professor1.create_course(course1);
                }
                else if(input_professor=="add_students_to_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    professor1.add_students_to_course(student_number,course1);
                }
                else if(input_professor=="remove_students_from_course"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    professor1.remove_students_from_course(student_number,course1);
                }
                else if(input_professor=="set_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    cout<<"Enter the grade : ";
                    string grade;
                    cin>>grade;
                    professor1.set_grades(course1,student_number,grade);
                }
                else if(input_professor=="create_Homework"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the homework : ";
                    string homework;
                    cin>>homework;
                    professor1.create_Homework(course1,homework);
                }
                else if(input_professor=="set_homework_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    Course course1(course_name);
                    cout<<"Enter the number of student : ";
                    string student_number;
                    cin>>student_number;
                    cout<<"Enter the homework grade : ";
                    string homework_grade;
                    cin>>homework_grade;
                    professor1.set_homework_grades(student_number,course1,homework_grade);
                }
            }
        }
        else if(user=="Student"){
            string student_number;
            cout<<"Enter your student_number"<<endl;
            cin>>student_number;
            cout<<"log for this role ->"<<endl;
            cout<<"set_homework_ans\n";
            cout<<"view_courses_and_grades\n";
            string input_student;
            cin>>input_student;
            if(!admin1.exist(pass)) {
                Student student1 = admin1.create_student(student_number, user, pass);
                if(input_student=="set_homework_ans"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    cout<<"Enter the homework answer : "<<endl;
                    string homework_ans;
                    student1.set_homework_ans(course_name,homework_ans);
                }
                else if(input_student=="view_courses_and_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    student1.view_courses_and_grades(course_name);
                }
            }
            else{
                Student student1(student_number, user, pass);
                if(input_student=="set_homework_ans"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    cout<<"Enter the homework answer : "<<endl;
                    string homework_ans;
                    student1.set_homework_ans(course_name,homework_ans);
                }
                else if(input_student=="view_courses_and_grades"){
                    cout<<"Enter the course: ";
                    string course_name;
                    cin>>course_name;
                    student1.view_courses_and_grades(course_name);
                }
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