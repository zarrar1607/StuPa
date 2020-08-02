#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<graphics.h>
#include<string>
using namespace std;

class FileOperations
{
private:
    fstream f;
public:
    FileOperations();
    virtual ~FileOperations();
    void write(const char* filename,string s);
    void read(const char* filename);
    void edit(const char* filename,string rollNumber, string newData, int commaCounter);
    void add(const char* filename, string data);
    int totalStudent();
    string Search(const char* filename,string s);
    string dataBTcomma(string line,int comma);
    void makeGraph(string rollno);
    void makeAxsis();
    int Map(float x, int in_min, int in_max, int out_min, int out_max);
};

#endif // FILEOPERATIONS_H
