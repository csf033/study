#include <iostream>
#include <typeinfo>

using namespace std;

class Base{};

struct STU{};

int main(){
  int n = 100;
  const type_info &ninfo = typeid(n);
  cout<<ninfo.name()<<endl;
  return 0;
}