#include <iostream>
#include <cmath>
using namespace std;
class intlist
{
    public:
        int *data;
        intlist()
        {
                totalsize = 10;
                data = new int[totalsize];
        }
        void insert(int value);
        bool remove(int pos)//REMOVING POSITION IN ARRAY NOTTTT DATA'S POSITION
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
class searchlist:public intlist
{
    public:
        int searchnum(int a)
        {
            for (int i = 0;i<intlist::getsize();i++)
            {
                if(data[i]==a)
                {
                    return i+1;
                }
            }
            return -1;
        }

};
void intlist::insert(int value)
{
    data[sizeused] = value;
    sizeused = sizeused + 1;
}
int main()
{      
    int input;
    intlist mylist;
    searchlist mylist2;
    for (int i = 0;;i++)
    {
        cin >> input;
        if(input==0)
        {
            break;
        }else if(input>0)
        {
            mylist2.insert(input);
        }else if(input<0)
        {
            int datapos = mylist2.searchnum(abs(input));
            if(datapos==-1)
            {
                    cout << "no" << endl;
            }else
            {
                mylist2.remove(datapos);
                cout << "ok" << endl;
            }
        }
    }
}