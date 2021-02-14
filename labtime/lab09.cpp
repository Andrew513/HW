#include <iostream>
#include <iomanip>
using namespace std;
class powerDate
{
private:
    int year;
    int month;
    int day;
    int date;
    bool leap;
public:
    powerDate(int y, int m, int d);
    bool isleap();
    int getweek();
    bool set(int y,int m,int d);
    int getyear();
    int getmonth();
    int getday();
    friend ostream &operator>>(ostream &outputstream, powerDate &mydate);
    friend istream &operator<<(istream &inputstream, powerDate &mydate);
    int operator[](int);
};
int powerDate::operator[](int index)
{
    int sum = index + day;
    //cout <<"the sum is " <<sum << endl;
    int m = month;
    //cout << "the m is " << m << endl;
    int y = year;
    //cout << "the y is " << y << endl;
    while(sum>28)
    {
        if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&sum>31)
        {
            m = m + 1;
            sum = sum - 31;
        }else if((m==4||m==6||m==9||m==11)&&sum>30)
        {
            m = m + 1;
            sum = sum - 30;
        }else if(m==2&&isleap())
        {
            m = m + 1;
            sum = sum - 29;
        }else if(m==2&&isleap())
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
        }else if(m==2&&leap==true)
        {
            sum = sum + 29;
        }else if(m==2&&leap==false)
        {
            sum = sum + 28;
        }
    }
    year = y;
    month = m;
    day = sum;
    return 0;
}
powerDate::powerDate(int y,int m,int d)
{
    if(y<1||m<1||m>12||d<1||d>31)
    {
        year = 1900;
        month = 1;
        day = 1;
    }else
    {
        year = y;
        month = m;
        day = d;
    }
}
bool powerDate::isleap()
{
    if (year % 400 == 0||(year%4==0&&year%100!=0))
    {
        leap = true;
        return true;
    }else 
    {
        leap = false;
        return false;
    }
}
int powerDate::getweek()
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
bool powerDate::set(int y,int m,int d)
{
    if(y<1||m<1||m>12||d<1||d>31||(leap==true&&d>29&&m==2)||(leap==false&&day>28&&m==2))
    {
        year = 1900;
        month = 1;
        day = 1;
    }else
    {
        year = y;
        month = m;
        day = d;
    }
    return 0;
}
int powerDate::getyear()
{
    return year;
}
int powerDate::getmonth()
{
    return month;
}
int powerDate::getday()
{
    return day;
}
ostream& operator <<(ostream& outputstream,powerDate& mydate)
{
    int y = mydate.getyear();
    int m = mydate.getmonth();
    int d = mydate.getday();
    char leap;
    if(mydate.isleap())
    {
        leap = 'L';
    }
    else
    {
        leap = 'l';
    }
    outputstream <</*"現在日期: "<<*/ y << '-' << setw(2) << setfill('0') << m << '-' << setw(2) << setfill('0') << d << leap << " ";
    switch(mydate.getweek())
    {
        case 0:
            outputstream << "Sunday" << endl;
            break;
        case 1:
            outputstream << "Monday" << endl;
            break;
        case 2:
            outputstream << "Tuesday" << endl;
            break;
        case 3:
            outputstream << "Wednesday" << endl;
            break;
        case 4:
            outputstream << "Thursday" << endl;
            break;
        case 5:
            outputstream << "Friday" << endl;
            break;
        case 6:
            outputstream << "Saturday" << endl;
            break;
    }
    return outputstream;
}
istream &operator >>(istream& inputstream,powerDate &mydate)
{
    int y, m, d;
    inputstream >> y >> m >> d;
    mydate.set(y, m, d);
    return inputstream;
}
int main()
{
    powerDate d1(1900, 1, 1);
    for (int i = 0;;i++)
    {
        int a;
        cin >> a;
        if(a==0)
        {
            break;
        }else if(a==1)
        {
            cin >> d1;
            cout << d1 ;
        }else if(a==2)
        {
            int n;
            cin >> d1;
            cin >> n;
            d1[n];
            cout << d1 ;
        }

    }
}