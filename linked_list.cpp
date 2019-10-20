#include<iostream>
using namespace std;


struct list
{
  int data;
  struct list *next;
};

typedef struct list *node;

/*
Function Declarations of all the functions in the library
*/
node CreateNode(int);
void AddNode(node,int);
int BringPointer(node,int);
void PrintList(node);
int AddAllNodes(node);
int SizeOfList(node);
node SortList(node,int);

/*
Defination of all the functions are below
in the proper order as they are declared
*/

/*
CreateNode function creates an empty node known as the head
*/
node CreateNode(int x)
{
  node temp;
  //temp = (node)malloc(sizeof(struct list));
  temp = new list;
  temp->next = NULL;
  temp->data = x;
  return temp;
}

/*
AddNode function adds nodes to the head node
*/
void AddNode(node head,int value)
{
  node temp,p;
  temp = CreateNode(value);

  if(head == NULL)
  {
    head = temp;
  }
  else
  {
    p = head;
    while(p->next != NULL)            //traversing the list to the last node
    {
      p = p->next;
    }
    p->next = temp;                   //Assigning the new node at the end of the list
  }
}


/*
BringPointer function returns the data present at a given node
*/
int BringPointer(node head,int position)
{
  node p;
  p = head;
  for(int i=0;i<position;i++)
  p = p->next;
  return p->data;
}

/*
PrintList function prints the whole list
*/
void PrintList(node head)
{
  node p,size;
  p = head;
  size = head;
  int len = SizeOfList(size);
  for(int i=0;i<len;i++)
  {
    cout<<p->data<<endl;
    p = p->next;
  }

}

int AddAllNodes(node head)
{
  node p;
  p=head;
  int sum;
  while(p->next != NULL)
  {
    sum = sum + p->data;
    p = p->next;
  }
  return sum;
}


int SizeOfList(node head)                 //returns the size of the list
{
  node p;
  int count = 0;
  p = head;
  while(p->next != NULL)
  {
    count++;
    p = p->next;
  }
  return (count+1);
}


// this function sorts the list according to the user choice
node SortList(node head,int ch=0)
{
  //cout<<"Inside SortList function\n";
  node p,size,q;
  p=head;
  size=head;
  int len = SizeOfList(size);
  //cout<<"End of step 1"<<endl;
  if(ch == 1)
  {
    for(int i=0;i<len;i++)
    {
      //cout<<"Start of loop 1"<<endl;
      for(int j=i+1;j<len;j++)
      {
        //cout<<"Start of loop 2"<<endl;
        q=head;
        for(int h=0;h<j;h++)
        {
          q = q->next;
          //cout<<"Start of loop 3"<<endl;
        }

        int data1 = p->data;
        int data2 = q->data;
        //cout<<data1<<" - "<<data2<<endl;
        if(data1<data2)
        {
          p->data = data2;
          q->data = data1;
        }

      }
      p = p->next;
    }
  }
  else
  {
    for(int i=0;i<len;i++)
    {
      //cout<<"Start of loop 1"<<endl;

      for(int j=i+1;j<len;j++)
      {
        //cout<<"Start of loop 2"<<endl;
        q=head;
        for(int h=0 ; h<j ; h++)
        {
          q = q->next;
          //cout<<"Start of loop 3"<<endl;
        }

        int data1 = p->data;
        int data2 = q->data;
        //cout<<data1<<" - "<<data2<<endl;
        if(data1>data2)
        {
          p->data = data2;
          q->data = data1;
        }

      }
      p = p->next;
    }
  }

  //cout<<"Leaving SortList function\n";

  return head;
}


node AddCustomNode(node head,int value,int position)
{
  node p,q;
  node custom;
  p = head;
  q = head;
  custom = CreateNode(value);
  for(int i=0;i<position;i++)
  {
    p = p->next;
  }

  custom->next = p;
  for(int i=0;i<position-1;i++)
  {
    q = q->next;
  }
  q->next = custom;
  cout<<"Leaving f(x)"<<endl;
  return head;
}
