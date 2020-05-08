#include <stdio.h>

void test1();

void test2();

void test3();

int main(){
  test1();
  test2();
  test3();
  return 0;
}

void test1(){
  struct stu{
    char *name;
    int age;
    int num;
    char group;
    float score;
  };
  struct stu stu1;
  stu1.name="李斯";
  stu1.age=100;
  stu1.num=2212;
  stu1.group='A';
  stu1.score=97.5;

  char *str = "test";

  struct stu stu2={"嬴政",90,34,'B',98};

  struct stu *pstu2 = &stu2;
  
  printf("stu2 name=%s\n",stu2.name);
  printf("stu2 group=%c\n",pstu2->group);

  printf("%x\n",*str);
}

void test2(){
  union data{
    int n;
    char ch;
    short m;
  };
  union data a,b,c;
  printf("%ld, %ld\n",sizeof(a),sizeof(union data));
  a.n=0x40;
  printf("%X, %c, %hX\n",a.n,a.ch,a.m);
}

void test3(){
    typedef struct{
        char *name;
        int age;
    } STU;
    STU stu1 = {"张三",21};
    printf("name=%s,age=%d\n",stu1.name,stu1.age);
}

