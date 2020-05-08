#include <stdio.h>

class Student{
  public:
    char *name;
    int age;

    void say(){
      printf("name:%s,age:%d\n",name,age);
    }
};

int main(){
  class Student stu;
  stu.name="小明";
  stu.age=21;
  stu.say();
  return 0;
}