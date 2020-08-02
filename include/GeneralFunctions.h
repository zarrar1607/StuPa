#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H
#include<iostream>
#include<fstream>
#include<FileOperations.h>
#include<sstream>
using namespace std;

class GeneralFunctions
{
private:
    fstream f;
    FileOperations fo;
public:
    GeneralFunctions();
    virtual ~GeneralFunctions();
    string getSemSubjects(int sem);
    void setSemMarks(string rno,string m[], int sem);
    void getGPA(string rollno);
    void setSemAverage(const char* sourceFile,const char * destinationFile);
    void getSemAverage(float a[],int NumberOfSemester);
    int compare(int a,int average);
    string compare(string a,int average);
    void rank(int a[], int n, int r[]);
    void display(int a[],int n);
    void setRanks(const char* sourceFile,const char* destinationFile);
    void getSemRank(string a[],int NumberOfSemester);
    int getTopper(int r[],unsigned int n);
};

#endif // GENERALFUNCTIONS_H
