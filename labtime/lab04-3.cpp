#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ifstream read;
    ofstream write;
    read.open("1.in.txt");
    write.open("1.out.txt");
    char a,x;
    read.get(a);
    write << a;
    char kappa;
    while(read.get(x))
    {
        kappa = a ^ x;
        write << kappa;
    }
}