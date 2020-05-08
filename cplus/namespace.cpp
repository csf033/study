#include <stdio.h>

namespace Diy{
  class Student{
    public:
      char *name;
      int age;
  public:
    void say(){
      printf("name=%s,age=%d\n",name,age);
    }
  };

}

int main(){
  Diy::Student stu;
  stu.name="小明";
  stu.age=22;
  stu.say();
  return 0;
}