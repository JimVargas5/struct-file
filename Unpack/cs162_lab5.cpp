//Put your header comments here with your name, class
//and purpose of the program

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <fstream>

using namespace std;
const int NAME = 20;
const char outy[] = "Schedule.txt";

//Place your structure definition here (globally):
struct student
{
    char firstName[NAME];
    char middleName[NAME];
    char lastName[NAME];
};
struct course
{
    int section;
    char crn[NAME];
    char designator[NAME];
};


//Place any prototypes that use the structure here:
student newStudent(void);
course newCourse(void);
void display(student&, course&);
void write_out(const char f[], student&, course&);

int main()
{
     //Create a variable of the struct here:
    student s = newStudent();
    course c = newCourse();

    display(s,c);

    write_out(outy, s, c);
    cout << "It is written...\n";

     return 0;
}

//Implement the body of the functions here:

student newStudent()
{
    student newStudent;

    cout << "Student first name:\n";
    cin.get(newStudent.firstName, NAME, '\n');
    cin.ignore(1000, '\n');
    cout << "Student middle name:\n";
    cin.get(newStudent.middleName, NAME, '\n');
    cin.ignore(1000, '\n');
    cout << "Student last name:\n";
    cin.get(newStudent.lastName, NAME, '\n');
    cin.ignore(1000, '\n');
    
    return newStudent;
}

course newCourse()
{
    course c;

    cout << "Course designator:\n";
    cin.get(c.designator, NAME, '\n');
    cin.ignore(1000, '\n');
    cout << "Course CRN:\n";
    cin.get(c.crn, NAME, '\n');
    cout << "Course section number:\n";
    cin >> c.section;
    c.section = abs(c.section);

    return c;
}

void display(student&s, course&c)
{
    cout << "Student: " << s.firstName << " " << s.middleName << " " << s.lastName << endl;
    cout << "Course: " << c.designator << " " << c.crn << "-" << c.section << endl;

    return;
}

void write_out (const char f[], student&s, course&c)
{
    ofstream out;
    out.open(f, ios::app);

    if (out)
    {
        out << s.firstName << ":" << s.middleName << ":" << s.lastName << endl;
        out << c.designator << ":" << c.crn << ":" << c.section << endl;

        out.close();
        out.clear();
    }
    return;
}




