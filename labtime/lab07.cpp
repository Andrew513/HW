#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class student
{
    public:
        student(const char *stname);
        student(const char *stname, const int cal, const int phy, const int ics);
        bool setname(const char *stname);
        bool setcal(const int score);
        bool setphy(const int score);
        bool setics(const int score);
        const char *getname();
        int getcal();
        int getphy();
        int getics();
        double getaverage();
    private:
        char *studentname;
        int calscore=0;
        int physcore=0;
        int icsscore=0;
        
};
student::student(const char *stname)
{
    studentname = new char[strlen(stname)];
    strcpy(studentname,stname);
    calscore = rand() % 101 + 0;
    physcore = rand() % 101 + 0;
    icsscore = rand() % 101 + 0;
}
student::student(const char*stname,const int cal,const int phy,const int ics)
{
    studentname = new char[strlen(stname)];
    strcpy(studentname,stname);
    calscore = cal;
    physcore = phy;
    icsscore = ics;
}
bool student::setname(const char *setname)
{
    if(studentname!=NULL)
    {
        delete[]studentname;
    }
    return 0;
}
bool student::setcal(const int score)
{
    calscore = score;
    return 0;
}
bool student::setphy(const int score)
{
    physcore = score;
    return 0;
}
bool student::setics(const int score)
{
    icsscore = score;
    return 0;
}
const char* student::getname()
{
    cout << studentname << endl;
    return studentname;
}
int student::getcal()
{
    cout << calscore << endl;
    return calscore;
}
int student::getphy()
{
    cout << physcore << endl;
    return physcore;
}
int student::getics()
{
    cout << icsscore << endl;
    return icsscore;
}
double student::getaverage()
{
    double sum = calscore + physcore + icsscore;
    double avg = sum / 3;
    cout << avg << endl;
    return avg;
}
int main()
{
    for (int i = 0;;i++)
    {
        int n;
        cin >> n;
        if(n==0)
        {
            break;
        }else if(n==1)
        {
            int s;
            char iname[30];
            cin >> s >> iname;
            srand(s);
            student s1(iname);
            s1.getname();
            s1.getcal();
            s1.getphy();
            s1.getics();
            s1.getaverage();
            s1.setname(iname);
        }else if(n==2)
        {
            int iics, iphy, ical;
            char iname[30];
            cin >> iname >> ical >> iphy >> iics;
            student s2(iname,ical,iphy,iics);
            s2.getname();
            s2.getcal();
            s2.getphy();
            s2.getics();
            s2.getaverage();
            s2.setname(iname);//delete[] studentname
        }

    }
}