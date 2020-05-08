#include <stdio.h>

void callPrintText(void (*callback)()){
  callback();
}

void printText(){
  printf("this is a callback function\n");
}

void callHandleData(int (*callback)(int)){
  int data = 10;
  printf("after handle the data=%d\n",callback(data));
}

void callHandleData2(void (*callback)(int *)){
  int a=100;
  callback(&a);
  printf("after handle2 the data=%d\n",a);
}

int increase(int data){
  return ++data;
}

void reduce(int *pData){
  *pData = --(*pData);
}

int main(){
  callPrintText(printText);
  callHandleData(increase);
  callHandleData2(reduce);
  printf("回调函数示例\n");
  return 0;
}