#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};

int main(){
    // struct = A structure that group related variables under one name
    //          structs can contain many different data types (string, int, double, bool, etc.)
    //          members can be access with . "Class Member Access Operator"

    student student1;
    student1.name = "Henrique";
    student1.gpa = 3.2;
    student1.enrolled = true;

    std::cout << student1.name << '\n';
    std::cout << student1.gpa << '\n';
    std::cout << student1.enrolled << '\n';

    return 0;
}