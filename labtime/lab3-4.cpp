#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream read;
    ofstream write;
    read.open("1.in");
    write.open("1.out");
    char kappa;
    while(read>>kappa)
    {
        if(kappa=='\n')
        {
            break;
        }
        kappa = kappa ^ 'a';
        write << kappa ;
    }
}