#include <iostream>
using namespace std;

template <typename T> void swap(T *a, T *b){
  T temp = *a;
  *a = *b;
  *b = temp;
}

template<typename T1, typename T2>
class Point{
  public:
    Point(T1 x, T2 y);
  public:
    T1 getX() const;
    void setX(T1 x);
    T2 getY() const;
    void setY(T2 y);
  private:
    T1 m_x;
    T2 m_y;
};
template<typename T1, typename T2>
Point<T1, T2>::Point(T1 x, T2 y): m_x(x), m_y(y){}

template<typename T1, typename T2>
T1 Point<T1, T2>::getX() const{
    return this->m_x;
}

template<typename T1, typename T2>
void Point<T1, T2>::setX(T1 x){
    this->m_x = x;
}

template<typename T1, typename T2>
T2 Point<T1, T2>::getY() const{
    return this->m_y;
}

template<typename T1, typename T2>
void Point<T1, T2>::setY(T2 y){
    this->m_y = y;
}

Point<float, float> foo(){
    Point<float, float> p(22.556487, 120.54848);
    p.setX(55.22);
    p.setY(115.254);
    cout<<&p<<endl;
    return p;
}

Point<float, float> & foo1(){
    Point<float, float> p(22.556487, 120.54848);
    Point<float, float> &rp = p;
    cout<<&rp<<endl;
    return rp;
}

Point<float, float> * foo2(){
    Point<float, float> *pp = new Point<float, float>(22.556487, 120.54848);
    cout<<&(*pp)<<endl;
    return pp;
}

int main(){
  int n1=100, n2=200;
  swap(&n1, &n2);
  cout<<n1<<"--"<<n2<<endl;

  Point<float, float> p1(22.3434, 120.0988);
  Point<float, float> &rp1 = p1;
  cout<<rp1.getX()<<"::"<<rp1.getY()<<endl;
  cout<<"方法中返回对象"<<endl;
  Point<float, float> p2 = foo();
  cout<<p2.getX()<<"::"<<p2.getY()<<endl;
  cout<<&p2<<endl;
  cout<<"方法中返回引用"<<endl;
  Point<float, float> &rp = foo1();
  cout<<rp.getX()<<"::"<<rp.getY()<<endl;
  cout<<&rp<<endl;
  cout<<"方法中返回指针"<<endl;
  Point<float, float> *pp = foo2();
  cout<<pp->getX()<<"::"<<pp->getY()<<endl;
  cout<<&(*pp)<<endl;
  return 0;
}

