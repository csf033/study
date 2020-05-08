#include <stdio.h>

void test1();

int main(){
  test1();
  return 0;
}

void test1(){
  typedef int INTEGER;
  INTEGER a=1;
  printf("%d\n",a);

  typedef char ARRAY20[5];
  ARRAY20 a1={'a','b','c','d','e'};
  int len = sizeof(a1)/sizeof(char);
  printf("len=%d\n",len);
  int i;
  for(i=0;i<len;i++){
    printf("%c",*(a1+i));
    if(i < len-1){
      printf(",");
    }
  }
  printf("\n");

  struct stu{
    int age;
    char *name;
  };
  typedef struct stu STU;
  STU stu1={20,"李斯"};
  STU *pstu1 = &stu1;
  printf("name=%s, age=%d\n",pstu1->name,pstu1->age);

  //给二维数组指定别名
  typedef int(*PTR_TO_ARR)[4];

  //给函数指针指定别名
  typedef void (*PTR_TO_FUNC)(int,int);
}