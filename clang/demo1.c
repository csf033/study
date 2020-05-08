#include <stdio.h>
#include <limits.h>
const int WIDTH=10;
const int HEIGHT=20;
#define RADIUS 5;
#define SQURE 100;
enum DAY{
  MON=1,TUE,WED,THU,FRI,SAT,SUN
};
void test1();
void test2();
__attribute__((constructor)) void test3(void);
int main()
{
    int arr[10];
    int i,j;
    for(i=0;i<10;i++){
      arr[i] = i+100;
    }

    for(j=0;j<10;j++){
      printf("Element[%d] = %d\n",j,arr[j]);
    }

    enum DAY day;
    day = WED;
    printf("%d\n",day);

    int a=15;
    int *p=&a;
    printf("%d,%d\n",a,*p);

    test2(1);

    return 0;
}

void test1(){
  printf("this is test1\n");
}

void test2(void){
  printf("this is test2");
}

__attribute__((constructor)) void test3(void){
  printf("__attribute__((constructor)) void test3()\n");
}