#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<FileOperations.h>
#include<GeneralFunctions.h>

using namespace std;

class Student
{
private:
    string rollno,subjects[6],marks[6];
    FileOperations fo;
    GeneralFunctions gf;
public:
    bool quit;
    Student();
    virtual ~Student();
    void Menu();
    void Login();
    void getSemesterMarks();
    void getSubjects(string s);
    void getMarks(string s);
    void Average();
    string compare(string avg);
    string compareRank(string r);
    void Rank();
    void Performance();
};

#endif // STUDENT_H
