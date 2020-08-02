#include "Teacher.h"

Teacher::Teacher()
{
    quit = 0;
    teacherID = "";
    teacherData = "";
}

Teacher::~Teacher()
{
}
void Teacher::Menu()
{
    cout<<endl;
    Login();
    cout<<endl;
    int teacherChoice;
    while(!quit)
    {
        cout<<"\t\t\t1.See Average of Class/Semester"<<endl;
        cout<<"\t\t\t2.See Ranks of Students Overall/Semester wise"<<endl;
        cout<<"\t\t\t3.LOG OUT"<<endl;
        cout<<"\t\t\tChoose: ";
        cin>>teacherChoice;
        switch(teacherChoice)
        {
        case 1:
            Average();
            break;
        case 2:
            Ranks();
            break;
        case 3:
            quit = 1;
            system("cls");
            break;
        default:
            cout<<"\t\t\t===>PLEASE ENTER A VALID CHOICE<==="<<endl;
        }
        cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    }
}
void Teacher::Login()
{
    string id;
    cout<<"Enter your ID: ";
    cin>>id;
    if(SearchID(id))
    {
        system("cls");
        quit = 0;
        teacherID = id;
        cout<<"-------------------------------- Access Granted --------------------------------"<<endl;
        for(unsigned int i = 5; i<teacherData.length(); i++)
        {
            if(teacherData[i] == '.')cout<<"\t";
            else if(teacherData[i] == ',')cout<<"\n";
            else cout<<teacherData[i];
        }
    }
    else
    {
        cout<<"\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxx Access Denied xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        quit = 1;
    }

}
void Teacher::Average()
{
    cout<<"\t\t------------------------------ Average ------------------------------"<<endl;
    float semAverage[NumberOfSemester];
    float avg=0;
    gf.getSemAverage(semAverage,NumberOfSemester);//sets the array with sem1,sem2,sem3 average
    for(unsigned int i = 0;i<NumberOfSemester;i++)
    {
        cout<<"\t\t\t\t==>Average of Semester "<<i+1<<": "<<semAverage[i]<<endl;
        avg+=semAverage[i];//For Total Class Average
    }
    avg/=NumberOfSemester;
    cout<<"\t\t\t\t==>Average of class\t: "<<avg<<endl;
}
void Teacher::Ranks()
{
    cout<<"\t\t---------------------- Rank/Topper ---------------------------"<<endl;
    string toppers[NumberOfSemester];//contains roll numbers
    gf.getSemRank(toppers,NumberOfSemester);
    for(unsigned int i = 0;i<NumberOfSemester;i++)
    {
        string s = fo.Search("StudentData.txt",toppers[i]);//searching for the roll number's data
        stringstream line(s.substr(4,s.length()-1));
        vector<string> row;
        string word;
        while(getline(line, word, ','))
        {
            row.push_back(word);
        }
        cout<<endl;
        cout<<"==>Topper of Semester "<<i+1<<": "<<row[1]<<endl;//row of 1 denotes data
    }
}
bool Teacher::SearchID(string id)
{
    fstream f;
    string line;
    f.open("TeacherID.txt");
    if(f.is_open())
    {
        while(getline(f,line))
        {
            if(fo.dataBTcomma(line,0) == id)
            {
                f.close();
                teacherData = line;
                return true;
            }
        }
    }
    f.close();
    return false;
}
