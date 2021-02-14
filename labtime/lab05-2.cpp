#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int spent = 50 * n;
    int **lottery;
    lottery = new int *[n];//create dynamic array
    for (int i = 0;i<n;i++)
    {
        lottery[i] = new int[5];
    }
    for (int i = 0; i < n;i++)//input lottery
    {
        for (int j = 0;j<5;j++)
        {
            cin >> lottery[i][j];
        }
    }
    int pool[5];
    for (int i = 0;i<5;i++)//input prizepool
    {
        cin >> pool[i];
    }
    long long int sum = 0;
    for (int i = 0;i<n;i++)
    {
        int duplicate = 0;
        for (int j = 0;j<5;j++)
        {
            for (int k = 0;k<5;k++)
            {
                if(lottery[i][j]==pool[k])
                {
                    duplicate = duplicate + 1;
                }
            }
        }
        if(duplicate==0||duplicate==1)//judge prize
        {
        }else if(duplicate==2)
        {
            for (int a = 4;a>0;a--)
            {
                for (int b = 0;b<a;b++)
                {
                    if(lottery[i][b]>lottery[i][b+1])
                    {
                        swap(lottery[i][b], lottery[i][b + 1]);
                    }
                }
            }
            cout << 50 ;
            for (int a = 0;a<5;a++)
            {
                cout <<" "<<lottery[i][a] ;
            }
            cout << endl;
            sum = sum + 50;
        }else if(duplicate==3)
        {
            for (int a = 4;a>0;a--)
            {
                for (int b = 0;b<a;b++)
                {
                    if(lottery[i][b]>lottery[i][b+1])
                    {
                        swap(lottery[i][b], lottery[i][b + 1]);
                    }
                }
            }
            cout << 300 ;
            for (int a = 0;a<5;a++)
            {
                cout <<" "<<lottery[i][a];
            }
            cout << endl;
            sum = sum + 300;
        }else if(duplicate ==4)
        {
            for (int a = 4;a>0;a--)
            {
                for (int b = 0;b<a;b++)
                {
                    if(lottery[i][b]>lottery[i][b+1])
                    {
                        swap(lottery[i][b], lottery[i][b + 1]);
                    }
                }
            }
            cout << 20000;
            for (int a = 0;a<5;a++)
            {
                cout <<" "<< lottery[i][a];
            }
            cout << endl;
            sum = sum + 20000;
        }else if(duplicate==5)
        {
            for (int a = 4;a>0;a--)
            {
                for (int b = 0;b<a;b++)
                {
                    if(lottery[i][b]>lottery[i][b+1])
                    {
                        swap(lottery[i][b], lottery[i][b + 1]);
                    }
                }
            }
            cout << 8000000;
            for (int a = 0;a<5;a++)
            {
                cout <<" "<< lottery[i][a];
            }
            cout << endl;
            sum = sum + 8000000;
        }
    }
    long long int get = sum - spent;
    cout << get << endl;
}