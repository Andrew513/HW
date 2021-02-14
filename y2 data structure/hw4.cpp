#include <iostream>
#include <algorithm>
using namespace std;
class pol;
class node
{
    friend class pol;
    friend pol operator*(pol &p1, pol &p2);
    private:
        int coef;
        int exp;
        node *next;
};
class pol
{
    public:
        int term = 0;
        pol();
        int addpol(int c, int e);
        void showpol();
        //void operator*();
        friend pol operator*(pol &p1, pol &p2);
        void removedup(pol &a);
        void sortpol(pol &a);

    private:
        node *head;
        node *tail;
};
void pol::sortpol(pol &a)
{
    int term = 0;
    node *node1 = a.head, *node2 = a.head->next, *temp = a.head;
    while(temp!=NULL)
    {
        term++;
        temp = temp->next;
    }
    for (int i = 1;i<term;i++)
    {
        while (node1->next->next != NULL && node2->next != NULL)
        {
            if (node1->exp < node2->exp)
            {
                swap(node1->exp, node2->exp);
                swap(node1->coef, node2->coef);
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        node1 = a.head;
        node2 = a.head->next;
    }
        
    cout << "the term is:" << term << endl;
}
void pol::removedup(pol &a)
{
    node *node1=a.head, *node2, *node3=NULL;
    while(node1!=NULL&&node1->next!=NULL)
    {
        node2 = node1;
        while (node2->next!=NULL)
        {
            if(node1->exp==node2->next->exp)
            {
                node1->coef = node1->coef + node2->next->coef;
                node3 = node2->next;
                node2->next = node2->next->next;
                delete (node3);
            }
            else
            {
                node2 = node2->next;
            }
        }
        node1 = node1->next;
    }
}
pol operator*(pol &p1,pol &p2)
{
    pol temp;
    node *npol1 = p1.head;
    node *npol2 = p2.head;


    while(npol1!=NULL)
    {
        while(npol2!=NULL)
        {
            int coef, exp;
            coef = npol1->coef * npol2->coef;
            exp = npol1->exp + npol2->exp;
            temp.addpol(coef, exp);
            npol2 = npol2->next;
        }
        npol2 = p2.head;
        npol1 = npol1->next;
    }
    return temp;
}
pol::pol()
{
    head = NULL;
    tail = NULL;
}
int pol::addpol(int c,int e)
{
    node *add = new node;
    add->coef = c;
    if(c==0)//coef is 0 then skip
    {
        delete add;
        return 0;
    }
    add->exp = e;
    if(term==0)//at first term head&tail = add
    {
        head = add;
        tail = add;
    }
    else 
    {
        tail->next = add;
        tail = add;
        tail->next = NULL;
    }
    term++;
    return 0;
}
void pol::showpol()
{
    node *show = head;
    if(show->exp==0)
    {
        cout << show->coef << " ";
    }else 
    {
        cout << show->coef << "x^" << show->exp << " ";
    }
    show = show->next;
    while(show!=NULL)
    {
        if(show -> coef>=0)
        cout << "+ " ;
        if (show -> exp == 0)
        {
            cout << show -> coef << " ";
        }
        else
        {
            cout << show -> coef << "x^"<< show -> exp << " " ;
        }
        show = show->next;
    }
    cout << endl;
}
int main()
{
    pol p1, p2,p3;
    int p1time,p1coef, p1exp;
    cout << "Please enter the first poly's term:";
    cin >> p1time;
    for (int i = 1;i<=p1time;i++)
    {
        cin >> p1coef >> p1exp;
        p1.addpol(p1coef, p1exp);
    }
    int p2time, p2coef, p2exp;
    cout << "Please enter the second poly's term:";
    cin >> p2time;
    for (int i = 1;i<=p2time;i++)
    {
        cin >> p2coef >> p2exp;
        p2.addpol(p2coef, p2exp);
    }
    cout << "The first polynomial is:" << endl;
    p1.showpol();
    cout << "The second polynomial is:" << endl;
    p2.showpol();
    p3 = operator*(p1, p2);
    cout << "The multiplication of these two polynomial is:" << endl;
    p3.showpol();
    p3.removedup(p3);
    cout << "Remove the duplicated terms." << endl;
    p3.showpol();
    p3.sortpol(p3);
    cout << "Sort the terms" << endl;
    p3.showpol();
}