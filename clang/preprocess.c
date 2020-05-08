#include <stdio.h>
#include <stdlib.h>

#define _DUBUG

void test1(void){
   #if _WIN32
    printf("windows\n");
  #elif __linux__
    printf("linux\n");
  #endif
}

void test2(void){
  #ifdef _DUBUG
    printf("debug mode\n");
  #else
    printf("release mode\n");
  #endif
}

int main(){
  test1();
  test2();
  return 0;
}