#include <iostream>
using namespace std;
int main()
{
    int i1, i2;
    int gcd = 1, lcm = 0;
    cin >> i1 >> i2;
    if(i1<=0||i2<=0)
    {
        cout << "0 0" << endl;
    }
    else
    {
        for (int i = 2;i<=i1;i++)
        {
            if(i1%i==0&&i2%i==0)
            {
                gcd = gcd * i;
                i1 = i1 / i;
                i2 = i2 / i;
                i = i - 1;
            }
            lcm=i2*i1*gcd;
        }
        cout << gcd << " ";
        cout << lcm << endl;
    }
    
}