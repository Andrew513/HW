#include <iostream>
using namespace std;
class matrixTerm
{
    friend class sparseMatrix;
    public:
        int row, col, value;
};
class sparseMatrix
{
    public:
        int row, cols, terms, capacity,smcount;
        matrixTerm *smArray;
        sparseMatrix(int r, int c) //row column 
        {
            row = r;
            cols = c;
            terms = 0;
        }
        void input_triple();
        void output();
        void output_triple();
        void output_transpose();
        void output_triple_transpose();
        
};
void sparseMatrix::input_triple()
{
    int val, count = 0;
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<cols;j++)
        {
            cin >> val;
            terms++;
            if(val!=0)
            {
                smArray[count].row = i;
                smArray[count].col = j;
                smArray[count].value = val;
                count++;
            }
        }
    }
    smcount = count;
}
void sparseMatrix::output_transpose()
{

}
void sparseMatrix::output_triple()
{
    int count = 0;
    for (int i = 0;i<smcount;i++)
    {
        cout << smArray[count].row << "   "
                << smArray[count].col << "   "
                << smArray[count].value << "   ";
        count++;
    }
}
int main()
{
    int row, column,terms;
    cin >> row >> column;
    sparseMatrix m1(row, column);
    m1.input_triple();
    m1.output_triple();
}