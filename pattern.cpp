#include<iostream>
using namespace std;

int main()
{
  char pa[11][6];
  int ar[6];

  for(int i=0;i<6;i++)
  cin>>ar[i];

  for(int i=0;i<11;i++)
  {
    for(int j=0;j<6;j++)
    pa[i][j] = ' ';
  }

/*  for(int j=0;j<6;j++)
  pa[5][j]='-';*/

  for (int j = 0; j < 6; j++)
  {
    if(ar[j]>0)
    {
      for(int i=5-ar[j] ; i<5 ; i++)
      pa[i][j] = '*';
    }
    else
    {
      for(int i=5-ar[j] ; i>5 ; i--)
      {
        pa[i][j] = '*';
      }
    }
  }

system("clear");
  for(int i=0;i<11;i++)
  {
    for(int j=0;j<6;j++)
    cout<<"\t"/*pa["<<i<<"]["<<j<<"]"*/<<pa[i][j];
    cout<<"\n";
  }

/*  char pa[11];
  int n = 2;

    for(int i=0;i<10;i++)
      pa[j][i] = ' ';
    if(n>0)
    {
      for(int i=5-n;i<5;i++)
      pa[j][i]='*';
    }
    else
    {
      for(int i=5-n;i>=5;i--)
      pa[j][i]='*';
    }


    for(int i=0;i<10;i++)
    cout<<pa[j][i]<<"\t";
    cout<<endl;
  */
}
