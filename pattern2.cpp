#include<iostream>
using namespace std;

int main()
{
  char pa[]="1234";
  for(int i=3;i>=0;i--)
  {
    for(int j=0;j<4;j++)
    cout<<pa[j];
    for(int j=3;j>=0;j--)
    cout<<pa[j];
    cout<<endl;
    pa[i] = '*';
  }

}
