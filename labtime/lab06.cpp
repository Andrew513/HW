#include <iostream>
#include <iomanip>
using namespace std;
class change
{
private:
    int year,month,day,hour,min,sec;
public:
    void settime(const int newhour, const int newmin, const int newsec);
    void setdate(const int newyear, const int newmonth, const int newday);
    int whatdate();
    void output();
    void outputroc();
    int seconds();
    bool isleap();
};
void change::settime(const int newhour, const int newmin, const int newsec)
{
    if(newhour>=0&&newhour<24)
    {
        hour = newhour;
    }
    if(newmin>=0&&newmin<=60)
    {
        min = newmin;
    }
    if(newsec>=0&&newsec<=60)
    {
        sec = newsec;
    }
}
void change::setdate(const int newyear,const int newmonth,const int newday)
{
    
    year = newyear;
    if(newmonth>=1&&newmonth<=12)
    {
        month = newmonth;
    }
    if(newday>=1&&newday<=31)
    {
        day = newday;
    }

}
int change::whatdate()
{
    int c, y, m, d;
    if ( month==1 || month == 2 )
	{
		c = ( year - 1 ) / 100;
		y = ( year - 1 ) % 100;
		m = month + 12;
		d = day;
	}
	else
	{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}
    int w = (y + (y / 4) + (c / 4) - (2 * c) + (26 * (m + 1) / 10) + d - 1)%7;
    return w;
}
void change::output()
{
    if(hour>12)
    {
        cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day 
             << " " << setw(2) << setfill('0') << hour - 12 << ":" << setw(2) << setfill('0') << min 
             << ":" << setw(2) << setfill('0') << sec << " "
             << "pm" << endl;
    }
    else if(hour == 12)
    {
        cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day 
             << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min 
             << ":" << setw(2) << setfill('0') << sec << " "
             << "pm" << endl;
    }
    else if(hour <12)
    {
        cout << year << "-" <<setw(2)<<setfill('0')<< month << "-" <<setw(2)<<setfill('0')<< day 
             << " " <<setw(2)<<setfill('0')<< hour << ":" <<setw(2)<<setfill('0')<< min 
             << ":" <<setw(2)<<setfill('0')<< sec << " "
             << "am" << endl;
    }
}
void change::outputroc()
{
    if(hour>12)
    {
        cout <<"中華民國"<<setw(3)<<setfill('0')<< year-1911 << "年" <<setw(2)<<setfill('0')<< month 
             << "月" <<setw(2)<<setfill('0')<< day << "日" << "下午" <<setw(2)<<setfill('0')
             << hour - 12 << "點" <<setw(2)<<setfill('0')<< min << "分" <<setw(2)<<setfill('0')
             << sec << "秒" << endl;
    }
    else if(hour == 12)
    {
        cout <<"中華民國"<<setw(3)<<setfill('0')<< year-1911 << "年" <<setw(2)<<setfill('0')<< month 
             << "月" <<setw(2)<<setfill('0')<< day << "日" << "下午" <<setw(2)<<setfill('0')
             << hour << "點" <<setw(2)<<setfill('0')<< min << "分" <<setw(2)<<setfill('0')
             << sec << "秒" << endl;
    }
    else if(hour<12)
    {
        cout <<"中華民國"<<setw(3)<<setfill('0')<< year-1911 << "年" <<setw(2)<<setfill('0')<< month 
             << "月" <<setw(2)<<setfill('0')<< day << "日" << "上午" <<setw(2)<<setfill('0')
             << hour << "點" <<setw(2)<<setfill('0')<< min << "分" <<setw(2)<<setfill('0')
             << sec << "秒" << endl;
    }
}
int change::seconds()
{
    int secs;
    secs = hour * 3600 + min * 60 + sec;
    return secs;
}
bool change::isleap()
{
    if( year%400==0 or ( year%4==0 and year%100!=0 ) )
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    change labtime;
    int y, m, d, h, min, s;
    for (int i = 0;;i++)
    {
        cin >> y >> m >> d >> h >> min >> s;
        if(y==0&&m==0&&d==0&&h==0&&min==0&&s==0)
        {
            break;
        }
        else 
        {
            labtime.settime(h, min, s);
            labtime.setdate(y, m, d);
            labtime.output();
            labtime.outputroc();
            cout<<labtime.isleap();
            switch(labtime.whatdate())
            {
                case 0:
                    cout << "Sunday" << endl;
                    break;
                case 1:
                    cout << "Monday" << endl;
                    break;
                case 2:
                    cout << "Tuesday" << endl;
                    break;
                case 3:
                    cout << "Wednesday" << endl;
                    break;
                case 4:
                    cout << "Thursday" << endl;
                    break;
                case 5:
                    cout << "Friday" << endl;
                    break;
                case 6:
                    cout << "Saturday" << endl;
                    break;
            }
            cout << labtime.seconds() << endl;
        }
    }
}