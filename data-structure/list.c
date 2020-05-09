#include <stdio.h>

#define MAXSIZE 20
typedef int ElemType;
typedef struct{
  ElemType data[MAXSIZE];
  int length;
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

/*
    获取元素
*/
Status getElem(SqList list, int i, ElemType *e);

Status ListInsert(SqList *list, int index, ElemType e);

int main(){
  SqList list = {{9,20,1,3,5,6,78,9,92,31,23,42,12,21,41,65,46,64,23,53},20};
  ElemType e;
  getElem(list, 20, &e);
  int len = sizeof(list.data)/sizeof(int);
  printf("the array length is %d\n", len);
  printf("the 7th element is %d\n",e);
}

Status getElem(SqList list, int i, ElemType *e){
  if(list.length==0 || i<1 || i>list.length){
    return ERROR;
  }
  *e = list.data[i-1];
  return OK;
}