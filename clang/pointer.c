#include <stdio.h>
#include <string.h>

void test1();

void test2();

void test3();

void test4();

void test5();

void test6();

void test7(void);


int main(){
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  printf("program running end");
  return 0;
}

void test1(){
  int a=10, *pa=&a, *paa=&a;
  double b=99.9, *pb=&b;
  char c='@', *pc=&c;
  printf("&a=%p, &b=%p, &c=%p\n",&a,&b,&c);
  printf("pa=%p, pb=%p, pc=%p\n",pa,pb,pc);

  //加法运算
  pa++;
  pb++;
  pc++;
  printf("pa=%p, pb=%p, pc=%p\n",pa,pb,pc);

  //减法运算
  pa-=2;
  pb-=2;
  pc-=2;
  printf("pa=%p, pb=%p, pc=%p\n",pa,pb,pc);

}

/*
  数组也是指针
*/
void test2(){
  int arr[] = {99,15,20,33,9};
  int len = sizeof(arr)/sizeof(int);
  printf("array length is %d \n",len);
  int i;
  

  int *p = arr;
  printf("%d, %d\n",p[2],*(p+2));
  printf("%d\n",*p++);

  for(i=0;i<len;i++){
    printf("%d ,",*(arr+i));
  }
  printf("\n");
}

/*
  字符串指针
*/
void test3(){
  char str[]="this is a string";
  int len = strlen(str);
  int i = 0;
  printf("%s\n",str);
  char *p = "this is a pointer string";
  printf("%s\n",p);
  //数组字符串和指针字符串的区别，就是数组可以改变字符串的值，而指针是只读的
}

void test4(){
  int a=10;
  int b=20;
  void swap(int *x,int *y);
  swap(&a,&b);
  printf("a=%d, b=%d\n",a,b);
  int max(int *arr,int len);
  int arr[] = {100,2,90,818,99};
  int len = sizeof(arr)/sizeof(int);
  printf("maxValue=%d\n",max(arr,len));
}

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int max(int *arr,int len){
  int maxValue;
  int i;
  for(i=0;i<len;i++){
    int value = *(arr+i);
    if(maxValue < value){
      maxValue = value;
    }
  }
  return maxValue;
}

void test5(){
  int a=1;
  int b=82;
  int c=99;
  int *arr[] = {&a,&b,&c};
  int **parr = arr;
  printf("%d, %d, %d\n",**arr,**(arr+1),**(arr+2));

  char *str[] = {"string1","string2","string3"};
  printf("%s\n%s\n%s\n",*str,*(str+1),*(str+2));
}

void test6(){
  int a[3][4]={{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
  printf("%ld\n",sizeof(a));
  int (*p)[4] = a;
  
}

void test7(void){
  int a=1;
  int* p=&a;
  printf("指针=%p\n",p);
}