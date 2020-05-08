#include <iostream>

class Test{
  public:
    Test(char *name);
  public:
    void show();
  private:
    char *m_name;
};
Test::Test(char *name): m_name(name){}
void Test::show(){
  std::cout<<"my name is "<<m_name<<std::endl;
}

int main(){
  using namespace std;
  int a=99;
  int &r = a;
  r = 100;
  cout<<a<<","<<r<<endl;
  cout<<&a<<","<<&r<<endl;

  Test test("jack");
  Test test1("lucy");
  Test *ptest;
  cout<<"pointer="<<ptest<<endl;
  ptest = new Test("smith");
  Test &rtest = test;
  rtest = test1;
  rtest.show();
  ptest -> show();
  cout<<&test<<"--"<<&test1<<endl;
  test.show();
  test1.show();
  cout<<"reference="<<&rtest<<endl;
  delete ptest;

  return 0;
}