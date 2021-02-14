#include <iostream>
#include <algorithm>
using namespace std;
int length;
char list[80];
void p(int a)
{
    if(a==length)
    {
        for (int j = 0;j<length;j++)
        {
            cout << list[j];
        }
        cout << endl;
    }
    else 
    {
        for (int i = a;i<length;i++)
        { 
            swap(list[i], list[a]);//abc,bac,cba,第一項與其他項做交換
            sort(list + i + 1,list + length);//排除第一項後做排序:cbad
            p(a + 1);
            sort(list+a, list+length);//排回ABC形式
        }
    }
}
void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    string input;
    cin >> input;
    length = input.length();
    for (int i = 0;i<length;i++)
    {
        list[i]=input[i];
    }
    sort(list, list + length);
    p(0);
}