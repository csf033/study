#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  cout<<hex<<12<<","<<24<<endl;
  cout<<setiosflags(ios::scientific|ios::showpos)<<12.34<<endl;
  return 0;
}