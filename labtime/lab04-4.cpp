#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream read;
    ofstream write;
    read.open("1.in.txt");
    write.open("1.out.txt");
    int arr[123]={0};
    char a;
    int x;
    while(read.get(a))
    {
        x = a;
        for (int i = 48;i<=122;i++)
        {
            if(x==i)
            {
                arr[i] = arr[i] + 1;
            }
        }
    }
    int max = 0,bignum=0;
    for(int i = 48;i<=122;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            bignum = i;
        }
    }
    char k = bignum;
    cout << k << endl;
}