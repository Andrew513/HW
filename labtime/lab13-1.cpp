#include <iostream>
#include <iomanip>
using namespace std;
class mydate
{
private:
    int year;
    int month;
    int day;
    //int date;
public:
    mydate(int y, int m, int d);
    bool isleap(int a);
    int getweek();
    bool setdate(int y,int m,int d);
    int getyear();
    int getmonth();
    int getday();
    int operator+(int);
    void output();
};
int mydate::operator+(int index)
{
    int sum = index + day;
    int m = month;
    int y = year;
    while(sum>28)
    {
        if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&sum<=31)
        {
            break;
        }else if((m==4||m==6||m==9||m==11)&&sum<=30)
        {
            break;
        }
        if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&sum>31)
        {
            m = m + 1;
            sum = sum - 31;
        }else if((m==4||m==6||m==9||m==11)&&sum>30)
        {
            m = m + 1;
            sum = sum - 30;
        }else if(m==2&&isleap(y)==true)
        {
            m = m + 1;
            sum = sum - 29;
        }else if(m==2&&isleap(y)==false)
        {
            m = m + 1;
            sum = sum - 28;
        }
        if(m>12)
        {
            y = y + 1;
            m = 1;
        }
    }
    while(sum<1)
    {
        m = m - 1;
        if(m<1)
        {
            y = y - 1;
            m = 12;
        }
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        {
            sum = sum + 31;
        }else if(m==4||m==6||m==9||m==11)
        {
            sum = sum + 30;
        }else if(m==2&&isleap(y)==true)
        {
            sum = sum + 29;
        }else if(m==2&&isleap(y)==false)
        {
            sum = sum + 28;
        }
    }
    year = y;
    month = m;
    day = sum;
    return 0;
}
mydate::mydate(int y,int m,int d)
{
        year = y;
        month = m;
        day = d;
}
bool mydate::isleap(int a)
{
    if (a % 400 == 0||(a%4==0&&a%100!=0))
    {
        return true;
    }else 
    {
        return false;
    }
}
int mydate::getweek()
{
    int c, y, m, d, date;
    if(month==1||month==2)
    {
        c = (year - 1) / 100;
        y = (year - 1) % 100;
        m = month + 12;
        d = day;
    }else
    {
        c = year / 100;
        y = year % 100;
        m = month;
        d = day;
    }
    int week = y + (y / 4) + (c / 4) - (2 * c) + (26 * (m + 1) / 10) + d - 1;
    if(week<1)
    {   
        date=( week % 7 + 7 ) % 7;
    }else 
    {
        date = week % 7;
    }
    return date;
}
bool mydate::setdate(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
    return 0;
}
int mydate::getyear()
{
    return year;
}
int mydate::getmonth()
{
    return month;
}
int mydate::getday()
{
    return day;
}
void mydate::output()
{
    cout << getyear() << "-" << getmonth() << "-" << getday() << " (" << getweek() << ")" << endl;
}

int main()
{
    int y, m, d, index;
    cin >> y >> m >> d;
    mydate d1(y, m, d);
    for (int i=0;;i++)
    {
        cin >> index;
        if(index==0)
        {
            break;
        }else 
        {
            d1 + (index);
            d1.output();
        }
    }
}