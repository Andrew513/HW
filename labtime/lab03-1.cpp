#include <fstream>
#include <cmath>
using namespace std;
int findPrime(int a)
{
    if(a==1||a==2||a==3)
    {
        return 2;
    }
    if(a==4||a==5)
    {
        return 3;
    }
    for (int j = a-1;j>0;j--)
    {
        for (int i = 2; i <= sqrt(j) + 1; i++)
        {
            if (j % i == 0)
            {
                break;
            }
            if (j % i != 0 && i == (int)sqrt(j))
            {
                return j;
            }
        }
    }   
}
int main()
{
    ifstream read;
    ofstream write;
    read.open("1.in");
    write.open("1.out");
    int number,ans;
    while(read>>number)
    {
        ans = findPrime(number);
        write << ans << endl;
    }
    read.close();
    write.close();
}