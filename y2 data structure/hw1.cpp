#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int x;
    int y;
    cin >> x >> y;
    //declare 2d dynamic array using malloc
    char **name1;
    name1 = (char **)malloc(x * y * sizeof(int));

    //declare a 2d dynamic array
    char **name = new char*[x];
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
    //-------------------------
    //output name
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