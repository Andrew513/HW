#include <iostream>
#include <cmath>
using namespace std;
class quadratic
{
    public:
        int c1, c2, c3; 
        quadratic()
        {
            c1 = 0, c2 = 0, c3 = 0;
        }
        quadratic operator +(quadratic A)
        {
            quadratic temp;
            temp.c1 = c1 + A.c1;
            temp.c2 = c2 + A.c2;
            temp.c3 = c3 + A.c3;
            return temp;
        }
        friend ostream &operator<<(ostream &output,quadratic &op)
        {
            output << op.c1 << "x^2+" << op.c2 << "x+" << op.c3 << endl;
            return output;
        }
        friend istream &operator>>(istream &input,quadratic &ip)
        {
            input >> ip.c1 >> ip.c2 >> ip.c3;
            return input;
        }
        int eval(quadratic Q,int x)
        {
            int sum = Q.c1 * x * x + Q.c2 * x + Q.c3;
            return sum;
        }
            
};
int main()
{
    int x;
    quadratic p1,p2,p3;
    cout << "Input the first equation's coef:" ;
    cin >> p1;
    //cout << p1.c1 << " " << p1.c2 << " " << p1.c3 << endl;
    cout << "Input the second equation's coef:" ;
    cin >> p2;
    p3 = p1 + p2;
    cout << "This is p1's equation :" << p1 ;
    cout << "This is p2's equation :" << p2 ;
    cout << "This is p3's equation :" << p3 ;
    cout << "Please input x :";
    cin >> x;
    cout << "p1's answer :" << p1.eval(p1, x) << endl;
    cout << "p2's answer :" << p2.eval(p2, x) << endl;
    cout << "p3's answer :" << p3.eval(p3, x) << endl;
}