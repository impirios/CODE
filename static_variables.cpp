#include<iostream>
using namespace std;

class abc
{
  static int a,b;
public:
  abc()
  {
    a=10;
    b=15;
  }
  abc(abc &o2)
  {
    a = o2.a;
    b = o2.b;
  }
  abc(int x1 ,int x2 )
  {
    a = x1;
    b = x2;
  }

int getA(){return a;}
int getB(){return b;}
};

int main()
{
abc obj1;
abc obj2(89,23);
abc obj3 = obj2;
cout<<"object 1\n";
cout<<"a:"<<obj1.getA()<<endl;
cout<<"b:"<<obj1.getB()<<endl;
cout<<"object 2\n";
cout<<"a:"<<obj2.getA()<<endl;
cout<<"b:"<<obj2.getB()<<endl;
cout<<"object 3\n";
cout<<"a:"<<obj3.getA()<<endl;
cout<<"b:"<<obj3.getB()<<endl;
}
