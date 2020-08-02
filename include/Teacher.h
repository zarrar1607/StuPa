#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<GeneralFunctions.h>
#include<FileOperations.h>
using namespace std;

#define NumberOfSemester 3

class Teacher
{
private:
    FileOperations fo;
    GeneralFunctions gf;
    string teacherID;
    string teacherData;
    string subjects[6];
    string marks[6];
public:
    bool quit;
    Teacher();
    virtual ~Teacher();
    void Menu();
    void Login();
    void Average();
    void Ranks();
    bool SearchID(string id);
};

#endif // TEACHER_H
