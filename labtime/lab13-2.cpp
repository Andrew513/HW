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
class mydatetime:public mydate
{
	public:
		mydatetime(const int y, const int m, const int d, const int h, const int min, const int s);
		int gethour();
		int getminute();
		int getsecond();
		bool setdatetime(const int y, const int m, const int d, const int h,const int min, const int s );
		void output(); //輸出 year-month-day (week) hour:minute:second

    private:
		int hour; 
		int minute;
		int second;
};
void mydatetime::output()
{
    cout << getyear() << "-" << getmonth() << "-" << getday() << " (" 
        << getweek() << ") " << gethour() << ":" << getminute() << ":" << getsecond() << endl;
}
mydatetime::mydatetime(const int y,const int m,const int d,const int h,const int min,const int s):mydate(y,m,d)
{
    mydate::setdate(y, m, d);
    hour = h;
    minute = min;
    second = s;
    //cout << hour << " " << minute << " " << second << endl;
}
bool mydatetime::setdatetime(const int y, const int m, const int d, const int h, const int min, const int s)
{
    setdate(y, m, d);
    hour = h;
    minute = min;
    second = s;
    
    return 0;
}
const mydatetime operator+( mydatetime &dt, int s)
{
    int sec = dt.getsecond();
    int min=dt.getminute(), hr=dt.gethour(),addday=0;
    sec = sec + s;
    if(sec>=60)
    {
        min = sec / 60 + min;
        sec = sec % 60; 
    }
    if(min>=60)
    {
        hr = min / 60 + hr;
        min = min % 60;
    }
    if(hr>=24)
    {
        addday = hr / 24;
        hr = hr % 24;
    }
    dt.operator+(addday);
    //cout << hr << " " << min << " " << sec << endl;
    return mydatetime(dt.getyear(), dt.getmonth(), dt.getday(), hr, min, sec);
}
const mydatetime operator-( mydatetime &dt, int s)
{
    int minusday = 0;
    int sec = dt.getsecond();
    int min=dt.getminute(), hr=dt.gethour();
    sec = sec - s;
    while(sec<0)
    {
        sec = sec + 60;
        min = min - 1;
    }
    while(min<0)
    {
        min = min + 60;
        hr = hr - 1;
    }
    while(hr<0)
    {
        hr = hr + 24;
        minusday = minusday - 1;
    }
    dt.operator+(minusday);
    return mydatetime(dt.getyear(), dt.getmonth(), dt.getday(), hr, min, sec);
}

int mydatetime::gethour()
{
    return hour;
}
int mydatetime::getminute()
{
    return minute;
}
int mydatetime::getsecond()
{
    return second;
}
int main()
{
    int y, m, d, h, min, s,x;
    cin >> y >> m >> d >> h >> min >> s;
    mydatetime mdt(y, m, d, h, min, s),a(y,m,d,h,min,s);
    for (int i = 0;;i++)
    {
        cin >> x;
        if(x==0)
        {
            break;
        }if(x<0)
        {
            a=mdt - (-x);
        }else if(x>0)
        {
            a=mdt + x;
        }
        a.output();
        mdt = a;
    }
}