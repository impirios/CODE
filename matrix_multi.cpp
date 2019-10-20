#include<iostream>
using namespace std;

int main()
{
  int matA[3][3],matB[3][3];
  int prod[3][3],p;

  cout<<"Enter Matrix A(3x3)\n";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    cin>>matA[i][j];
  }
  cout<<"Enter Matrix B(3x3)\n";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    cin>>matB[i][j];
  }


  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    prod[i][j] = 0;
  }

  for(int i=0;i<3;i++)
  {

    for(int j = 0;j<3;j++)
    {
      for(int k=0 ;k<3;k++)
      {
        prod[i][j] = prod[i][j] + (matA[i][k]*matB[k][j]);
      }
    }
  }

  cout<<"MATRIX A\n";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<matA[i][j]<<"\t";
    }
    cout<<endl;
  }

  cout<<"MATRIX B\n";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<matB[i][j]<<"\t";
    }
    cout<<endl;
  }

  cout<<"Product of Matrix A and B\n";
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<prod[i][j]<<"\t";
    }
    cout<<endl;
  }
}
