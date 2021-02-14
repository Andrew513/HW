#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int input;
    cin >> input;
    int prime[5];
    int k = 0;
    if(input==2)
    {
        cout << "3 5 7 11 13" << endl;
    }
    else
    {
        for (int i = input+1;i>input;i++)
            {
            if(k==5)
            {
                break;
            }
            for (int j = 2;j<=(int)(sqrt(i));j++)
            {
                if(i%j==0)
                {
                    break;
                }
                if(i%j!=0&&j==(int)(sqrt)(i))
                {
                    prime[k] = i;
                    k = k + 1;
                }
                
            }
        }
        for (int i = 0;i<5;i++)
        {
            cout << prime[i] << " ";
        }
    }
    
}