#include <iostream>
using namespace std;
void cbfsort(int &v1,int &v2,int &v3)
{
    int temp;
    if(v1<v2)
    {
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
    if(v2<v3)
    {
        temp = v2;
        v2 = v3;
        v3 = temp;
    }
    if(v1<v2)
    {
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cbfsort(a, b, c);
    cout << a << " " << b << " " << c << endl;
}