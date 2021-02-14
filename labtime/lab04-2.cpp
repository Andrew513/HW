#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    int s;
    cin >> s ;
    srand(s);
    int *ptr[1024];
    int a;
    double sum = 0;
    cin >> a;
    for (int i = 1;i<=a;i++)
    {
        ptr[i] = new int;
        *ptr[i] = rand() % 201 + (-100);
        sum = sum + *ptr[i];
    }
    double avg = sum / a;
    double std;
    double sum2 = 0;
    for (int i = 1;i<=a;i++)
    {
        sum2 = sum2 + (*ptr[i] - avg)*(*ptr[i] - avg);
    }
    std = sqrt(sum2 / a);
    cout << avg << "\n"
         << std << endl;
    delete ptr[1024];
}