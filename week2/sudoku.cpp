#include<iostream>
using namespace std;
bool Valid(int row,int colm,int gamegrid[9][9],int val)
{
 
    for(int i=0;i<9;i++)
    {
        if(gamegrid[row][i]==val)
            return false;
        if(gamegrid[i][colm]==val)
            return false;
    }
    
    int a=row-row%3;
    int b=a+3;
    int x=colm-colm%3;
    int y=x+3;
    for(int i=a;i<b;i++)
    {
        for(int j=x;j<y;j++)
        {
            if(gamegrid[i][j]==val)
                return false;
        }
    }
    return true;
}
void displaygrid(int gamegrid[9][9])
{
    cout<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<gamegrid[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool sudokuplay(int row,int colm,int gamegrid[9][9])
{
    if(row==9)
    {
        return true;
    }
    if(colm==9)
    {
        return sudokuplay(row+1,0,gamegrid);
    }
    if(gamegrid[row][colm]!=0)
    {
        return sudokuplay(row,colm+1,gamegrid);
    }
    for(int val=1;val<=9;val++)
    {
        if(Valid(row,colm,gamegrid,val))
        {
            gamegrid[row][colm]=val;
            if(sudokuplay(row,colm+1,gamegrid)==true)
                return true;
        }
        gamegrid[row][colm]=0;
    }
    return false;
}
int main()
{
    int gamegrid[9][9];
    cout<<"Enter the grid values";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>gamegrid[i][j];
        }
    }
    if(sudokuplay(0,0,gamegrid)==true)
        displaygrid(gamegrid);
    else
        cout<<"Sudoku cannot ne solved";

}
