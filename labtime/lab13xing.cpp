#include <iostream>
#include<iomanip>
using namespace std;

class mydate
{
public:
    mydate(const int y, const int m, const int d);
    int getyear()const;
    int getmonth()const;
    int getday()const;
    int getweek()const;
    bool isleap();
    bool setdate(const int y, const int m, const int d);
    void output();
private:
    int year;
    int month;
    int day;
    int week;
};

const mydate operator+(const mydate & d, const int day);
const mydate operator-(const mydate & d, const int day);

int main()
{
    int Y, M, D, x;
    cin >> Y >> M >> D;
    mydate d(Y, M, D);

    if(d.setdate(Y, M, D)==true)
    {
        while(cin>>x)
        {
            if(x==0)
            {
                break;
            }
            else if(x>0)
            {
                mydate d1(Y, M, D);
                d1 = d + x;
                d1.output();
            }
            else if(x<0)
            {
                mydate d2(Y, M, D);
                d2 = d - x;
                d2.output();
            }
        }
    }
    return 0;
}

mydate::mydate(const int y, const int m, const int d)
{
    year = y;
    month = m;
    day = d;
}

int mydate::getyear()const
{
    return year;
}

int mydate::getmonth()const
{
    return month;
}

int mydate::getday()const
{
    return day;
}

int mydate::getweek()const
{
    int c, y,Y, M;
    M = month;
    Y = year;

    if ( (M == 1) || (M == 2))
    {
        M = month + 12;
        Y = year - 1;
    }

    c = Y / 100;
    y = Y % 100;
    week = (y + (y / 4) + (c / 4) - (2 * c) + ((26 * (M + 1)) / 10) + day - 1) % 7;

    if (week < 0)
    {
        week = (week % 7 + 7) % 7;
    }
    return week;
}

bool mydate::isleap()
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool setdate(const int y, const int m, const int d)
{ 
    if(y<0)
    {
        return false;
    }
    
    if(m == 1 || m == 3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if(d>31||d<1)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    else if(m == 4 || m == 6 || m==9 || m==11)
    {
        if(d>30||d<1)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    else if(m==2)
    {
        if (isleap()==true)
        {
           if(d>30||d<1)
            {
                return false;
            }
            else 
            {
                return true;
            }
        }
        else 
        {
            if(d>29||d<1)
            {
                return false;
            }
            else 
            {
                return true;
            }
        }
    }
    else if(m>12||m<1)
    {
        return false;
    }
}

void mydate::output()
{
    cout << getyear() << "-" << getmonth() << "-" << getday() << " (" << getweek() << ")" << endl;
}

const mydate operator+(const mydate & d, const int day)
{
    int _y = d.getyear();
    int _m = d.getmonth();
    int _d = d.getday();

    int newd = _d + day;
    if(_m == 1 || _m == 3 || _m==5 || _m==7 || _m==8 || _m==10 || _m==12)
    {
        if(newd>31)
        {
            newd = newd - 31;
            _m = _m + 1;
        }
    }
    else if(_m == 4 || _m == 6 || _m==9 || _m==11)
    {
        if(newd>30)
        {
            newd = newd - 30;
            _m = _m + 1;
        }
    }
    else if(_m==2)
    {
        if(d.isleap()==true)
        {
            if(newd>29)
            {
                newd = newd - 29;
                _m = _m + 1;
            }
        }
        else 
        {
            if(newd>28)
            {
                newd = newd - 28;
                _m = _m + 1;
            }
        }
    }

    if(_m>12)
    {
        _m = _m - 12;
        _y = _y + 1;
    }

    return mydate(_y, _m, newd);

}

const mydate operator-(const mydate & d, const int day)
{
    int Day = abs(day);
    int _y = d.getyear();
    int _m = d.getmonth();
    int _d = d.getday();

    if(Day<_d)
    {
        _d = _d - Day;
    }
    else if(Day>=_d)
    {
        for (int i = 1; i > 0;i++)
        {
            if(_m==1)
            {
                _y = _y - 1;
                _m = _m + 11;
            }
            else 
            {
                _m = _m - 1;
            }

            if(_m == 1 || _m == 3 || _m==5 || _m==7 || _m==8 || _m==10 || _m==12)
            {
                if( (_d + 31 - Day)>=1)
                {
                    _d = _d + 31 - Day;
                    break;
                } 
                else
                {
                    _d = _d + 31;
                }
                
            }
            else if(_m == 4 || _m == 6 || _m==9 || _m==11)
            {
                if((_d+30-Day)>=1)
                {
                    _d = _d + 30 - Day;
                    break;
                }
                else 
                {
                    _d = _d + 30;
                }
            }
            else if(_m==2)
            {
                if(d.isleap(_y)==true)
                {
                    if((_d + 29 - Day)>=1)
                    {
                        _d = _d + 29 - Day;
                        break;
                    }
                    else 
                    {
                        _d = _d + 29;
                    }
                }
                else if(d.isleap(_y)==false)
                {
                    if((_d + 28 - Day)>=1)
                    {
                        _d = _d + 28 - Day;
                        break;
                    }
                    else
                    {
                        _d = _d + 28;
                    }
                }
            }
        }

    }
    return mydate(_y, _m, _d);
}