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
int main()
{
    int s;
    cin >> s;//seed
    srand(s);
    int input1;
    cin >> input1;
    if (input1 == 0)
    {
        findPrime data1;
        int prime = data1.getPrime();
        cout << prime << endl;
        int input2;
        for (int i = 0;;i++)
        {
            cin >> input2;
            if(input2<=1)
            {
                break;
            }else
            {
                data1.setPrime(input2);
                prime = data1.getPrime();
                cout << prime << endl;
            }
        }
    }else if(input1!=0)
    {
        findPrime data1(input1);
        int prime = data1.getPrime();
        cout << prime << endl;
        int input2;
        for (int i = 0;;i++)
        {
            cin >> input2;
            if(input2<=1)
            {
                break;
            }else
            {
                data1.setPrime(input2);
                prime = data1.getPrime();
                cout << prime << endl;
            }
        }
    }
    
}