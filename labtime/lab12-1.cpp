#include <iostream>
#include <cmath>
using namespace std;
class intlist
{
    public:
        int *data;
        intlist();
        void insert(int value);
        bool remove(int pos)
        {
            if(pos>sizeused)
            {
                return false;
            }
            else 
            {
                data[pos - 1] = data[sizeused-1];
                sizeused = sizeused - 1;
                return true;
            }
            
        }
        int getvalue(int pos)
        {
            return data[pos - 1];
        }
        bool setvalue(int pos, int value)
        {
            data[pos - 1] = value;
            return 0;
        }
        int getsize()
        {
            return sizeused;
        }
    protected:
        bool swapvalue(int pos1, int pos2)
        {
            int temp;
            temp = pos1;
            pos1 = pos2;
            pos2 = temp;
            return 0;
        }
    private:
        
        int totalsize;
        int sizeused=0;
        void expandsize()
        {
            int *temp;
            temp = new int[totalsize];
            temp = data;
            delete[] data;
            data = new int[2 * totalsize];
            data = temp;
            delete[] temp;
        }
};
intlist::intlist()
{
    totalsize = 10;
    data = new int[totalsize];
}
void intlist::insert(int value)
{
    data[sizeused] = value;
    sizeused = sizeused + 1;
}
int main()
{   int input;
    intlist mylist;
    for (int i = 0;;i++)
    {
        cin >> input;
        if(input==0)
        {
            break;
        }else if(input>0)
        {
            mylist.insert(input);
        }else if(input<0)
        {
            input = abs(input);
            int removed;
            removed = mylist.data[input - 1];
            if(mylist.remove(input)==true)
            {
                cout << removed << endl;
            }else 
            {
                cout << "no" << endl;
            }
        }
    }
}