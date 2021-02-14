#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class findPrime
{
private:
    int primenum;
public:
    findPrime();
    findPrime(int input);
    int getPrime();
    bool setPrime(int input);
};
findPrime::findPrime()
{
    int randnum;
    randnum = rand() % 9001 + 1000;
    int squart = sqrt(randnum) + 1;
    for (int i = randnum;;i++)
    {
        for (int j = 2;j<=squart;j++)
        {
            if(i%j==0)
            {
                break;
                //not prime
            }else if(i%j!=0&&j==squart)
            {
                primenum = i;
                break;
            }
        }
        if(primenum==i)
        {
            break;
        }
    }
}
findPrime::findPrime(int input)
{
    int squart = sqrt(input) + 1;
    for (int i = input;;i++)
    {
        if(i==2)
        {
            primenum = 2;
            break;
        }
        for (int j = 2;j<=squart;j++)
        {
            if(i%j==0)
            {
                break;
                //not prime
            }else if(i%j!=0&&j==squart)
            {
                primenum = i;
                break;
            }
        }
        if(primenum==i)
        {
            break;
        }
    }
}
int findPrime::getPrime()
{
    return primenum;
}
bool findPrime::setPrime(int input)
{
    int squart = sqrt(input) + 1;
    for (int i = input;;i++)
    {
        for (int j = 2;j<=squart;j++)
        {
        if(i==2)
        {
            primenum = 2;
            break;
        }
            if(i%j==0)
            {
                break;
                //not prime
            }else if(i%j!=0&&j==squart)
            {
                primenum = i;
                break;
            }
        }
        if(primenum==i)
        {
            break;
        }
    }
    return 0;
}
const findPrime operator +( findPrime& a, findPrime& b)
{
    int newPrime=a.getPrime() + b.getPrime();
    findPrime data;
    data.setPrime(newPrime);
    return data;
}
const findPrime operator -(findPrime& a,findPrime& b)
{
    int newPrime = a.getPrime() - b.getPrime();
    if(newPrime<0)
    {
        newPrime = -newPrime;
    }
    findPrime data;
    data.setPrime(newPrime);
    return data;
}
const findPrime operator +(findPrime& a,int b)
{
    int newPrime = a.getPrime() + b;
    findPrime data;
    data.setPrime(newPrime);
    return data;
}
int main()
{
    int s,a, b, c;
    cin >> s;
    srand(s);
    cin >> a >> b >> c;
    if (a == 0)
    {
        findPrime data1, data2, data3;
        if(b!=0)
        {
            data1.setPrime(b);
        }
        if(c!=0)
        {
            data2.setPrime(c);
        }
        data3 = data1 + data2;
        cout << data3.getPrime() << endl;
    }
}