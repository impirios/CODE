#include<iostream>
#include"linked_list.cpp"
using namespace std;
int main()
{
  node start;
  int n,ch;
  cout<<"Enter how many nodes\n";
  cin>>n;
  cout<<"Enter Value for head node - ";
  cin>>ch;
  start = CreateNode(ch);
  for(int i=0;i<n-1;i++)
  {
    cout<<"Enter value for node "<<i+1<<" -> ";
    int value;
    cin>>value;
    AddNode(start,value);
  }

  start = SortList(start,1);
  cout<<"Length of list is "<<SizeOfList(start)<<endl;
  AddCustomNode(start,12,3);
  PrintList(start);

  //for(int i = 0;i<n ; i++)
  //cout<<BringPointer(start,i+1)<<endl;
  cout<<"Length of list is "<<SizeOfList(start)<<endl;
}
