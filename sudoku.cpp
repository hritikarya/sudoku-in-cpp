#include <iostream>
using namespace std;


bool emptySpaceFound(int a[][9], int &row, int &col)
{
    for (row=0; row<9; row++)
    {
        for (col=0; col<9; col++)
        {
            if (a[row][col]==0)
                return 1;
        }
    }
    return 0;
}
bool foundInColumn(int a[][9], int col, int num)
{
    for (int i=0; i<9; i++)
    {
        if (a[i][col]==num)
            return 1; 
    }
    return 0;
}

//returns true if the number 'num' is found in the row
bool foundInRow(int a[][9], int row, int num)
{
    for (int j=0; j<9; j++)
    {
        if (a[row][j]==num)
            return 1;
    }
    return 0;
}
//retuns true if the number 'num' is found in the box
bool foundInBox(int a[][9], int row, int col, int num)
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (a[row+i][col+j]==num)
                return 1;
        }
    }
    return 0;
}

bool canInsertNumHere (int a[][9], int row, int col, int num)
{
    return !foundInBox(a, row - row%3, col - col%3, num) && !foundInRow(a, row, num) &&
           !foundInColumn(a, col, num);
}

//returns true if the number 'num' is found in the column
bool solve(int a[][9])
{
    int row, col;
    if (!emptySpaceFound(a, row, col))
        return 1;
    for (int num=1; num<10; num++)
    {
        if (canInsertNumHere(a, row, col, num))
        {    
            a[row][col]=num;
            if (solve(a))
                return 1;
            a[row][col]=0;
        }
    }    
    return 0;
}

void printSudoku(int a[][9])
{
    //i is for row
    //j is for column
    for (int i=0; i<9; i++)
    { 
        if (i%3==0)
            cout<<" - - - - - - - - - - - - \n";
        for (int j=0; j<9; j++)
        {
            if(j%3==0)
                cout<<"| ";
            cout<<a[i][j]<<" ";
        }
        cout<<"| \n";
    }
    cout<<" - - - - - - - - - - - - \n";
}
int main()
{
    int a[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                   {6, 0, 0, 1, 9, 5, 0, 0, 0},
                   {0, 9, 8, 0, 0, 0, 0, 6, 0},
                   {8, 0, 0, 0, 6, 0, 0, 0, 3},
                   {4, 0, 0, 8, 0, 3, 0, 0, 1},
                   {7, 0, 0, 0, 2, 0, 0, 0, 6},
                   {0, 6, 0, 0, 0, 0, 2, 8, 0},
                   {0, 0, 0, 4, 1, 9, 0, 0, 5},
                   {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    
    /*int a[9][9] =  {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};*/
    if (solve(a))
        printSudoku(a);
    else
    {
        cout<<"No Solution Possible\n";
    }
    return 0;
}