#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int s, a;
    cin >> s >> a;
    srand(s);
    int *x;
    for (int i = 1;i<=a;i++)
    {
        x = new int;
        *x = rand() % 100 + 1;
        if(*x%2==0)
        {
            cout << *x << endl;
        }
        else 
        {
            delete x;
        }
    }
}