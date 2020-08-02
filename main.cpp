#include <iostream>
#include<cstdlib>
#include<Teacher.h>
#include<Student.h>
#include<graphics.h>

using namespace std;
void heading();
int main()
{
    //Local Declarations:
    int profChoice;
    bool exit=0;
    char exitConfirmation;
    Teacher t;
    Student s;
    //Login / Front-(Front-End) Design
    heading();
    cout<<endl<<endl;
    do
    {
        t.quit=0;
        s.quit=0;
        cout<<"\t\t\t\t\t\t1.Teacher"<<endl;
        cout<<"\t\t\t\t\t\t2.Student"<<endl;
        cout<<"\t\t\t\t\t\t3.Exit"<<endl;
        cout<<"\t\t\t\t\tChoose your Profession:";
        cin>>profChoice;
        switch(profChoice)
        {
        case 1:
            t.Menu();
            break;
        case 2:
            s.Menu();
            break;
        case 3:
            cout<<"Are you Sure(y or n): ";
            cin>>exitConfirmation;
            exit = (exitConfirmation == 'y')?1:0;
            break;
        default:
            cout<<"\t\t\t\t----------------------------------------------"<<endl;
            cout<<"\t\t\t\t\t==>PLEASE ENTER A VALID CHOICE<=="<<endl;
            cout<<"\t\t\t\t----------------------------------------------"<<endl;
            break;
        }
    }while(!exit);
}
void heading()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm;
    // initgraph initializes the
    // graphics system by loading
    // a graphics driver from disk
    initgraph(&gd, &gm, "");
    // location of text
    int x = 140;
    int y = 200;
    // font style
    int font = 10;
    // font direction
    int direction = 0;
    // font size
    int font_size = 7;
    // for setting text style
    settextstyle(font, direction, font_size);
    // for printing text in grahics window
    outtextxy(x, y, "StuPa v3.0");
    settextstyle(font, direction, font_size-1);
    outtextxy(x+20, y-100, "Welcome To");
    delay(1500);
    closegraph(CURRENT_WINDOW);
}
