#ifndef SAMANEDOTA_PERSON_H
#define SAMANEDOTA_PERSON_H

#include <iostream>
using namespace std;

class person{
    int age;
    string username;
    string password;
    string name;
public:
    person(string& _username,string& _password);
};

#endif //SAMANEDOTA_PERSON_H