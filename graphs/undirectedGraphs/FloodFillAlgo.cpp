#include<iostream>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int R,C;

void printMat(char input[][30])
{
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;j++)
        {
            cout<<input[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void floodFill(char mat[][30],int i,int j,char ch,char color)
{
    if(i<0 || j<0 || i>=R || j>=C)
    return;

    if(mat[i][j]!=ch)
    {
        return;
    }

    mat[i][j]=color;

    for(int k=0;k<4;k++)
    {
        floodFill(mat,i+dx[k],j+dy[k],ch,color);
    }

}

int main()
{
    cin>>R>>C;
    char input[15][30];
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;j++)
        {
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodFill(input,8,15,'.','r');
    printMat(input);
}