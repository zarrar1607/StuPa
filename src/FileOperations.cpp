#include "FileOperations.h"

FileOperations::FileOperations()
{
}

FileOperations::~FileOperations()
{
}
int FileOperations::totalStudent()
{
    fstream f;
    string line;
    int c = 1;
    f.open("Semester1.txt");
    if(f.is_open())
    {
        while(getline(f,line))
        {
            c++;
        }
    }
    f.close();
    return c-1;
}
string FileOperations::Search(const char* filename,string s)
{
    ifstream fin;
    fin.open(filename);
    string line;
    if (fin.is_open())
    {
        unsigned int i =0;
        try
        {
            bool condition = line[i]==s[i] && line[i+1]==s[i+1] && line[i+2]==s[i+2] && line.at(line.length()-4)!= 'N';
            while ( getline (fin,line) )
            {
                for(i = 0; i!=line.length()-4; i++)
                {
                    condition = line[i]==s[i] && line[i+1]==s[i+1] && line[i+2]==s[i+2] && line.at(line.length()-4)!= 'N';
                    if(condition)break;
                }
                if(condition)
                    break;
            }
            if(condition)
            {
                return line;
            }
            fin.close();
        }
        catch(exception e)
        {
            cout<<"Some Exception Caught"<<endl;
            fin.close();
            return "NULL";
        }
    }
    return "NULL";
}
string FileOperations::dataBTcomma(string line,int comma)
{
    vector<int> vect;
    stringstream ss(line);
    stringstream ss1;
    string temp;
    int i;

    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }
    ss1<<vect.at(comma);
    ss1>>temp;
    ss.clear();
    ss1.clear();
    return temp;
}
void FileOperations::makeGraph(string rollno)
{
    fstream f;
    string fnsg,s;
    int gd = DETECT, gm;
    int Yin_min = 0,Xin_min = 0;
    int Yin_max = 10,Xin_max = 10;
    int Yout_min = 400,Xout_min = 10;
    int Yout_max = 10,Xout_max = 400;
    int x1=0,y1=0,x2=0,y2=0;
    int tx1=0,tx2=0;
    float ty1=0,ty2=0;
    initgraph(&gd, &gm, "");
    makeAxsis();
    for(unsigned int i = 0; i<3 ; i++)
    {
        stringstream sem;
        sem<<i+1;
        fnsg = "SemGPA"+sem.str()+".txt";
        s = Search(fnsg.c_str(),rollno);
        s = s.substr(4,s.length()-1);
        stringstream gpa(s);
        tx2 = 4*(i+1);
        gpa>>ty2;
        x1 = Map(tx1,Xin_min,Xin_max,Xout_min,Xout_max);
        y1 = Map(ty1,Yin_min,Yin_max,Yout_min,Yout_max);
        x2 = Map(tx2,Xin_min,Xin_max,Xout_min,Xout_max);
        y2 = Map(ty2,Yin_min,Yin_max,Yout_min,Yout_max);
        char *c=const_cast<char*>(s.c_str());
        outtextxy(x2-20,y2-20,c);
        line(x1,y1,x2,y2);
        string xl="Semester "+sem.str();
        char *xLabel=const_cast<char*>(xl.c_str());
        outtextxy(x1+125, Yout_min+10, xLabel);
        tx1=tx2;
        ty1=ty2;
        x1=x2;
        y1=y2;
    }
    outtextxy(200,450,"Press 1 and Enter Key to Exit Graph");
    bool q;
    cout<<"Press 1 to close graph:";
    cin>>q;
    while(!q);
    closegraph(CURRENT_WINDOW);
}
void FileOperations::makeAxsis()
{
    line(10, 10, 10, 410);
    line(0, 400, 600, 400);
}
int FileOperations::Map(float x, int in_min, int in_max, int out_min, int out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
