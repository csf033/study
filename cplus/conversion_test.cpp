#include <iostream>
using namespace std;

class Complex{
  public:
    Complex(): m_real(0.0), m_imag(0.0){}
    Complex(double real, double imag): m_real(real), m_imag(imag){}
    Complex(double real): m_real(real), m_imag(0.0){}
  public:
    friend ostream & operator<<(ostream &out, Complex &c);
  private:
    double m_real;
    double m_imag;
};

ostream & operator<<(ostream &out, Complex &c){
  out<<c.m_real<<"+"<<c.m_imag<<"i";
  return out;
}

int main(){
  Complex a(10.0,20.0);
  Complex b(22.6, 11.2);
  a = 25.5;
  cout<<a<<endl;
  cout<<&a<<endl;
  a = Complex(44.0,22.5);
  cout<<&a<<endl;
  Complex &rc = a;
  Complex *pc = &a;
  cout<<&rc<<endl;
  rc = b;
  pc = &b;
  cout<<&rc<<endl;
  cout<<rc<<endl;
  cout<<a<<endl;
  cout<<&b<<endl;
  return 0;
}