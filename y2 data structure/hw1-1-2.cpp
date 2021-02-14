#include <iostream>
#include <cstring>
using namespace std;
//swap name 
void swap(char &arr1 , char &arr2)
{
    char temp;
    temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}
int main()
{
    int x;
    int y;
    cin >> x >> y;
    //declare 2d dynamic array using malloc
    char *name1;
    name1 = (char *)malloc(x * y * sizeof(int)); 

    //declare a 2d dynamic array using new
    char **name = new char *[x];
    for (int i = 0;i<x;i++)
    {
        name[i] = new char[y];
    }

    //clear the array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            name[i][j]=' ';
        }

    }

    //------------------------
    //enter the name
    cin.ignore();
    for (int i = 0; i < x; i++)
    {
        cin.getline(name[i], 100);
        if(strlen(name[i])>y)
        {
            cout << "Please re-enter the name"<<endl;
            i--;
        }
    }
    //----------------------
    //bbs the first alphabet
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - 1 - i; j++)
        {
            if (name[j][0] < name[j + 1][0])
            {
                swap(name[j], name[j + 1]);
            }
        }
    }
    //---------------
    //output the name

    cout << "The name in order is: " << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << name[i][j];
        }
        cout << endl;
    }
    free(name1);
    delete[] name;
}
