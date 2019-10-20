#include<iostream>
using namespace std;

class complex
{
  float real;
  float imaginary;
public:
  complex()
  {
    real = 0;
    imaginary = 0;
  }
  complex(float x,float y)
  {
    real = x;
    imaginary = y;
  }

  complex operator + (complex test_obj)
  {
    complex temp;
    temp.real = real + test_obj.real;
    temp.imaginary = imaginary + test_obj.imaginary;
    return temp;
  }


  void show_number()
  {
    cout<<real<<"+("<<imaginary<<")i"<<endl;
  }
  friend istream & operator >> (istream &in,  complex &c);
};


istream & operator >> (istream &in,complex &test_obj)
{
  cout<<"Enter real part\n";
  in >> test_obj.real;
  cout<<"Enter imaginary part\n";
  in >> test_obj.imaginary;
  return in;
}

int main()
{
  complex obj1;
  complex obj2;
  cin >> obj1;
  obj1.show_number();
  cin >> obj2;
  obj2.show_number();
  complex obj3;
  obj3 = obj1+obj2;

  obj1.show_number();
  obj2.show_number();
  obj3.show_number();
}
