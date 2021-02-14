#include<iostream>
#include"time.h"
using namespace std;
void Add(int **a,int **b,int **c,int m,int n,int p){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
int main(){
    clock_t start,end;
    float total;
    int m,n,p;
    m=200;
    p=200;
    n=100;
    int **a=new int *[m];
    int **b=new int *[n];
    int **c=new int *[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        b[i]=new int[p];
    }
    for(int i=0;i<m;i++){
        c[i]=new int[p];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            b[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            c[i][j]=0;
        }
    }
    //for (int j = 1;j<=30;j++)
    //{
        for (int i = 1; i <= 5; i++)
        {
            start = clock();
            Add(a, b, c, m, n, p);
            end = clock();
            total = (float)(end - start) / CLOCKS_PER_SEC;
            cout << total << " ";
        }
        //cout << endl;
        //n += 100;
    //}
}