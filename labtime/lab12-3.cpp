#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class intlist
{
    public:
        int *data;
        intlist()
        {
            totalsize = 100;
            data = new int[totalsize];
        }
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
        int totalsize;
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
        int sizeused=0;
        bool swapvalue(int pos1, int pos2)
        {
            int temp;
            temp = pos1;
            pos1 = pos2;
            pos2 = temp;
            return 0;
        }
        
        
};
void intlist::insert(int value)
{
    if(totalsize==sizeused)
    {
        expandsize();
    }
    data[sizeused] = value;
    sizeused = sizeused + 1;
}
class sortlist:public intlist 
{
    public:
        void sortnum(int input)
        {
            insert(input);
            sort(data, data + sizeused);
        } 
};
int main()
{   
    int input;
    intlist mylist;
    sortlist mylist2;
    for (int i = 0;;i++)
    {
        cin >> input;
        if(input==0)
        {
            break;
        }else 
        {
            mylist2.sortnum(input);
        }
    }
    for (int i = 0;i<mylist2.getsize();i++)
    {
        cout << mylist2.data[i] << endl;
    }
}