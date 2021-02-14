#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //smcount for triple's count
    int row, column,terms,smcount=0;
    cin >> row >> column;
    terms = row * column;
    int triple[terms][3];
    //2d array for matrix-------------
    int** matrix = new int*[row];
    for(int i = 0; i < row; i++)
    {
        matrix[i] = new int[column];
    }
    //input matrix--------------------
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<column;j++)
        {
            cin >> matrix[i][j];
        }
    }
    //implement triple----------------
    for (int i = 0,count=0;i<row;i++)
    {
        for (int j = 0;j<column;j++)
        {
            if(matrix[i][j]!=0)
            {
                triple[count][0] = i;
                triple[count][1] = j;
                triple[count][2] = matrix[i][j];
                count++;  
            }
        }
        smcount = count;
    }
   
    //output triple-----------------------
    cout << "row   column  value " << endl;
    for (int i = 0;i<smcount;i++)
    {
        for (int j = 0;j<3;j++)
        {
            cout << " " << triple[i][j] << "      ";
        }
        cout << endl;
    }

    //row size + row start  &  initialize them---
    int rowszstrt[2][row];
    for (int i = 0;i<2;i++)
    {
        for (int j = 0;j<row;j++)
        {
            rowszstrt[i][j] = 0;
        }
    }
 
    //rowsize start assign---------------------
    for (int j = 0; j < row; j++)
    {
        for (int i = 0; i < smcount; i++)
        {   
            if (triple[i][0] == j)
            {
                rowszstrt[0][j]++;
            }
        }
    }
    for (int j = 0; j < row;j++)
    {
        rowszstrt[1][j + 1] = rowszstrt[0][j] + rowszstrt[1][j];
        //cout <<"triple:"<< triple[0][0] << endl;----->this shit will change triple for no fking reason
    }
    
    
    //output rowsize and rowstart---------------
    cout << "rowSize and rowStart are:" << endl;
    for (int i = 0;i<2;i++)
    {
        for (int j = 0;j<row;j++)
        {
            cout<<rowszstrt[i][j]<<" ";
        }
        cout << endl;
    }
    
    //triple transpose------------------------
    int transtrip[smcount][3];
    int transcount = 0;
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<smcount;j++)
        {
            if(triple[j][1]==i)
            {
                transtrip[transcount][0] = triple[j][1];
                transtrip[transcount][1] = triple[j][0];
                transtrip[transcount][2] = triple[j][2];
                transcount++;
            }
        }
    }
    //output transtriple-----------------------
    cout << "row   column  value " << endl;
    for (int i = 0;i<smcount;i++)
    {
        for (int j = 0;j<3;j++)
        {
            cout << " " << transtrip[i][j] << "      ";
        }
        cout << endl;
    }

    //trans matrix initialize + assign---------
    int transmatrix[row][column];
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<column;j++)
        {
            transmatrix[i][j] = 0;
        }
    }
    for (int i = 0;i<smcount;i++)
    {
        transmatrix[transtrip[i][0]][transtrip[i][1]] = transtrip[i][2];
    }

    //output the matrix-------------------
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<column;j++)
        {
            cout << transmatrix[i][j] << " ";
        }
        cout << endl;
    }
    delete[] matrix;
}