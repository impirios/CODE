#include<iostream>
using namespace std;
int main()
{
  int i=0 , j=0,a,b;
  for(int x=0;x<10;x++)
  {
    a = i++;
    cout<<a<<endl;
  }
  cout<<"BOOP"<<endl;
  for(int x=0;x<10;x++)
  {
    b = ++j;
    cout<<b<<endl;
  }
}
