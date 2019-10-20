#include<iostream>
using namespace std;

int main()
{
  char pa[6][100];

  for(int i=0;i<6;i++)
  {
    for(int j=0;j<100;j++)
    pa[i][j] = ':';
  }

  for(int i=0;(4*i*i)<=100;i++)
  {
    int j = 4*i*i;
    if(i!=0){j--;}
    pa[i][j] = '*';
  }

  for(int i=0;i<6;i++)
  {
    for(int j=0;j<100;j++)
    cout<</*"["<<i<<"]["<<j<<"]"<<"="<<*/pa[i][j];

    cout<<endl;
  }
}
