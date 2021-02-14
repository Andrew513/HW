#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ifstream read;
    ofstream write;
    read.open("1.in");
    write.open("1.out");
    string word;
    int lgth;
    while (read >> word)
    {
        lgth = word.length();
        write << lgth << word << endl;
    }
}