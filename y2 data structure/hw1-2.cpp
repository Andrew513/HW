#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int x;
    int y;
    cin >> x >> y;
    //--------------------------
    //declare a 2d dynamic array
    char **name = new char*[x];
    for (int i = 0;i<x;i++)
    {
        name[i] = new char[y];
    }
    //-----------------
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
    //check where the max space location is
    int max_space=0;
    int space_count = 0;
    for (int i = 0;i<x;i++)
    {
        space_count = 0;
        for (int j = 0;j<y;j++)
        {
            if(name[i][j]==' ')
            {
                space_count++;
                if(j>max_space&&space_count==1)
                {
                    max_space = j;
                    //cout << max_space << endl;
                }
            }
        }
    }

    int first_name = 0;
    for (int i = 0; i< x; i++)
    {
        first_name = 0;
        for (int j = 0; j < y; j++)
        {
            if(name[i][j]==' ')
            {
                break;
            }
            else
            {
                first_name++;
            }
        }
        //cout << "first name: " << first_name << endl;
        for (int k = 0;k<(max_space-first_name);k++)
        {
            cout << " "; 
        }
        for (int a = 0; a < y; a++)
        {
            cout << name[i][a];
        }
        cout << endl;
    }
    delete[] name;
    //-----------------
    //output the name
    /*for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << name[i][j];
        }
        cout << endl;
    }*/
}