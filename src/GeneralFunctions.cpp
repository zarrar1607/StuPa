#include "GeneralFunctions.h"

GeneralFunctions::GeneralFunctions()
{
}

GeneralFunctions::~GeneralFunctions()
{
}
string GeneralFunctions::getSemSubjects(int sem)
{
    stringstream ss;
    ss << sem;
    string s = "se"+ ss.str();
    ss.clear();
    return fo.Search("Subjects.txt",s);
}
void GeneralFunctions::setSemAverage(const char* sourceFile,const char * destinationFile)
{
    fstream f;
    string line;
    unsigned int n = fo.totalStudent();
    string data[n][6],rn[n];
    unsigned int i=0,j=0;
    f.open(sourceFile);
    if(f.is_open())
    {
        while(getline(f,line))
        {
            rn[i]=line.substr(0,3);
            stringstream s(line.substr(4,line.length()-2));
            vector<string> row;
            string word;
            while(getline(s, word, ','))
            {
                row.push_back(word);
            }
            for(unsigned int j = 0; j<6; j++)
            {
                data[i][j]=row[j];
            }
            row.clear();
            i++;
        }
    }
    f.close();
    int sum = 0;
    int subavg[6];
    for(i=0; i<6; i++)
    {
        for(j=0; j<n; j++)
        {
            stringstream ss(data[j][i]),sst;
            int temp;
            ss>>temp;
            sum += temp;
            ss.clear();
        }
        subavg[i]=sum/6;
        sum = 0;
    }
    cout<<endl;
    f.open(destinationFile,ios::out|ios::trunc);
    for(i=0; i<n; i++)
    {
        f<<rn[i];
        f<<",";
        for(j=0; j<6; j++)
        {
            f<<compare(data[i][j],subavg[i]);
            f<<",";
        }
        f<<"\n";
    }
    f.close();
}
int GeneralFunctions::compare(int a,int average)
{
    if(a>average)return 1;
    else if(a==average) return 0;
    else return -1;
}
string GeneralFunctions::compare(string a,int average)
{
    stringstream ss(a);
    int b;
    ss>>b;
    if(b>average)return "1";
    else if(b==average) return "0";
    else return "-1";
}
void GeneralFunctions::getSemAverage(float a[],int NumberOfSemester)
{
    fstream f;
    string filename,data;
    float sum = 0,t;
    for(unsigned int i = 0; i<NumberOfSemester; i++)//in a semester (gpa of student1,2,3..)/no.of students
    {
        stringstream ss;
        ss << i+1;
        filename = "SemGPA" + ss.str() + ".txt";
        f.open(filename.c_str());
        if(f.is_open())
        {
            while(getline(f,data))
            {
                stringstream convert(data.substr(4,data.length()-1));//only the gpa
                convert>>t;
                convert.clear();
                sum+=t;
            }
        }
        a[i] = sum/fo.totalStudent();
        ss.clear();
        sum = 0;
        f.close();
    }
}
void GeneralFunctions::getSemRank(string a[], int NumberOfSemester)
{
    fstream f;
    string filename,data;
    unsigned int  n = fo.totalStudent();
    string rn[n];//Roll number
    int r[n];//Each Student gpa
    int tr[n];//Ranks of each student
    float t;//temporary variable for conversion
    for(unsigned int i = 0; i<NumberOfSemester; i++)
    {
        stringstream ss;
        unsigned int j = 0;
        ss << i+1;
        filename = "SemGPA" + ss.str() + ".txt";
        f.open(filename.c_str());
        if(f.is_open())
        {
            while(getline(f,data))
            {
                rn[j] = data.substr(0,3);//roll number
                stringstream convert(data.substr(4,data.length()-1));
                convert>>t;
                r[j]=t;//Each Student gpa
                convert.clear();
                j++;
            }
        }
        j=0;//reseting j value
        rank(r,n,tr);//storing ranks in tr
        a[i]=rn[getTopper(tr,n)];//returns 1st rank ==>Storing  the roll numbers of 1st rankers  in  the array
        ss.clear();
        f.close();
    }
}
int GeneralFunctions::getTopper(int r[],unsigned int n)
{

    for(unsigned int i = 0; i<n ; i++)
    {
        if(r[i] == 1)return i;
    }
    return -1;
}
void GeneralFunctions::rank(int a[], int n, int r[])
{
    int i,j;
    for(i=0; i<n; i++)r[i]=1;
    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
        {
            if(a[i]<a[j])r[i]++;
            else if(a[i]==a[j])continue;
            else r[j]++;
        }
}
void GeneralFunctions::display(int a[],int n)
{
    for(int i=0; i<n; i++)cout<<a[i]<<",";
    cout<<endl;
}
void GeneralFunctions::setRanks(const char* sourceFile,const char* destinationFile)
{
    fstream f;
    string line;
    unsigned int n = fo.totalStudent();
    string data[n][6],rn[n];
    unsigned int i=0,j=0;
    f.open(sourceFile);
    if(f.is_open())
    {
        while(getline(f,line))
        {
            rn[i]=line.substr(0,3);
            stringstream s(line.substr(4,line.length()-2));
            vector<string> row;
            string word;
            while(getline(s, word, ','))
            {
                row.push_back(word);
            }
            for(unsigned int j = 0; j<6; j++)
            {
                data[i][j]=row[j];
            }
            row.clear();
            i++;
        }
    }
    f.close();
    int dr[n][6];//data rank
    int tempGetSubjectData[n];
    int tempGetSujectRank[n];
    for(i=0; i<6; i++)
    {
        for(j=0; j<n; j++)
        {
            stringstream ss(data[j][i]);
            int temp;
            ss>>temp;
            tempGetSubjectData[j] = temp;
            ss.clear();
        }
        rank(tempGetSubjectData,n,tempGetSujectRank);
        for(j=0;j<n;j++)
        {
            dr[j][i] = tempGetSujectRank[j];
        }
    }
    f.open(destinationFile,ios::out|ios::trunc);
    for(i=0; i<n; i++)
    {
        f<<rn[i];
        f<<",";
        for(j=0; j<6; j++)
        {
            f<<dr[i][j];
            f<<",";
        }
        f<<"\n";
    }
    f.close();
}
