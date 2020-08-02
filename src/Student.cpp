#include "Student.h"

Student::Student()
{
    rollno = "";
    quit = 0;
}

Student::~Student()
{
    remove("SemAvg1.txt");remove("SemAvg2.txt");remove("SemAvg3.txt");
    remove("SemRank1.txt");remove("SemRank2.txt");remove("SemRank3.txt");
}
void Student::Menu()
{
    cout<<endl;
    Login();
    int choice;
    while(!quit)
    {
        cout<<"1.Semester Marks"<<endl;
        cout<<"2.Average"<<endl;
        cout<<"3.Rank"<<endl;
        cout<<"4.Performance"<<endl;
        cout<<"5.LOG OUT"<<endl;
        cout<<"Choose: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            getSemesterMarks();
            break;
        case 2:
            Average();
            break;
        case 3:
            Rank();
            break;
        case 4:
            Performance();
            break;
        case 5:
            quit = 1;
            system("cls");
            break;
        default:
            cout<<"Please Enter A Valid Choice"<<endl;
        }
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }

}
void Student::Login()
{
    string rno;
    try
    {
        cout<<"Enter your Roll Number 1604-17-733-";
        cin>>rno;
        if(rno.length()!=3 || fo.Search("Semester1.txt",rno)=="NULL")throw "Enter A Valid Roll Number";
        system("cls");
        cout<<"----------------------------------------Access Granted------------------------------------------------"<<endl<<endl;
        rollno = rno;
        string s = fo.Search("StudentData.txt",rollno);
        stringstream line(s.substr(4,s.length()-1));
        vector<string> row;
        string word;
        while(getline(line, word, ','))
        {
            row.push_back(word);
            cout<<"\t\t"<<word<<endl<<endl;
        }
        cout<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }
    catch(char const* s)
    {
        cout<<"\t\t\t\t    ===>"<<s<<"<==="<<endl;
        cout<<"\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxx Access Denied xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        quit = 1;
    }
}
void Student::getSemesterMarks()
{
    string semfname,fg, m,g;
    cout<<"\t-------------------------- MARKS ---------------------------"<<endl;
    for(unsigned int i = 0; i<3 ; i++)
    {
        stringstream sem,semgpa;
        sem<<i+1;
        cout<<"\t\t\t\t Semester "+sem.str()<<endl;
        cout<<"\t\t\t\t------------"<<endl;
        semfname = "Semester"+sem.str()+".txt";
        getSubjects(gf.getSemSubjects(i+1));
        m = fo.Search(semfname.c_str(),rollno);
        getMarks(m);
        for(unsigned int j =0; j<6; j++)
            cout<<"\t\t\t"<<subjects[j]<<":"<<marks[j]<<endl;
        semgpa<<i+1;
        fg =  "semGPA"+semgpa.str()+".txt";
        g = fo.Search(fg.c_str(),rollno);
        cout<<endl<<"\t\t\t\t GPA\t:"<<g.substr(4,4)<<endl<<endl;
        sem.clear();
    }
}
void Student::getSubjects(string s)
{
    stringstream line(s.substr(4,s.length()-1));
    vector<string> row;
    string word;
    while(getline(line, word, ','))
    {
        row.push_back(word);
    }
    for(unsigned int i = 0; i<6; i++)
    {
        subjects[i]=row[i];
    }
    row.clear();
}
void Student::getMarks(string s)
{
    stringstream line(s.substr(4,s.length()-1));
    vector<string> row;
    string word;
    while(getline(line, word, ','))
    {
        row.push_back(word);
    }
    for(unsigned int i = 0; i<6; i++)
    {
        marks[i]=row[i];
    }
    row.clear();
}
void Student::Average()
{
    string fsn,fsa;
    string  avg;
    for(unsigned int i = 0; i<3 ; i++)
    {
        cout<<"\t-------------------------- AVERAGE ---------------------------"<<endl;
        stringstream sem;
        sem<<i+1;
        cout<<"\t\t\t\t Semester "+sem.str()<<endl;
        cout<<"\t\t\t\t------------"<<endl;
        fsn = "Semester"+sem.str()+".txt";
        fsa = "SemAvg"+sem.str()+".txt";
        gf.setSemAverage(fsn.c_str(),fsa.c_str());
        getSubjects(gf.getSemSubjects(i+1));

        avg = fo.Search(fsa.c_str(),rollno);
        stringstream line(avg.substr(4,avg.length()-1));
        vector<string> row;
        string word;
        while(getline(line, word, ','))
        {
            row.push_back(word);
        }
        for(unsigned int j =0; j<6; j++)
            cout<<"\t\t\t"<<subjects[j]<<":"<<compare(row[j])<<endl;
        sem.clear();
        row.clear();
    }
}
string Student::compare(string avg)
{
    if(avg == "1")return "Above Average";
    else if(avg == "0")return "Average";
    else return "Below Average";
}
void Student::Rank()
{
    string fsn,fsa, r;
    cout<<"\t----------------------------- RANKS ------------------------------"<<endl;
    for(unsigned int i = 0; i<3 ; i++)
    {
        stringstream sem;
        sem<<i+1;
        cout<<"\t\t\t\t Semester "+sem.str()<<endl;
        cout<<"\t\t\t\t------------"<<endl;
        fsn = "Semester"+sem.str()+".txt";
        fsa = "SemRank"+sem.str()+".txt";
        gf.setRanks(fsn.c_str(),fsa.c_str());
        getSubjects(gf.getSemSubjects(i+1));

        r = fo.Search(fsa.c_str(),rollno);
        stringstream line(r.substr(4,r.length()-1));
        vector<string> row;
        string word;
        while(getline(line, word, ','))
        {
            row.push_back(word);
        }
        for(unsigned int j =0; j<6; j++)
            cout<<"\t\t\t"<<subjects[j]<<":"<<compareRank(row[j])<<endl;
        sem.clear();
        row.clear();
    }
}
string Student::compareRank(string r)
{
    if(r == "1")return "1st";
    else if(r == "2")return "2nd";
    else if(r == "3")return "3rd";
    else return r+"th";
}
void Student::Performance()
{
    fo.makeGraph(rollno);
}
