#include<iostream>
using namespace std;

int main()
{
  char pa[10][10];
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    pa[i][j]=' ';
  }

  for(int i=0,j=9;i<10,j>=0;i++,j--)
  {
    pa[i][j]='*';
  }

  for(int i=0;i<5;i++)
  pa[i][i]='*';

  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    cout<<pa[i][j];
    cout<<endl;
  }
}
