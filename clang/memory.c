#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char b[] = "data area";
int main(){
  char a[] = "stack area";

  char *c = (char *)malloc(10);
  if(c == NULL){
    printf("malloc error\n");
    return -1;
  }

  memset(c,0,10);
  strcpy(c,"heap area");

  printf("%s\n",a);
  printf("%s\n",b);
  printf("%s\n",c);

  printf("%p\n",a);
  printf("%p\n",b);
  printf("%p\n",c);

  free(c);
  c = NULL;

  char *p = "linux";
  p = "windows";
  *(p+0)='f';
  printf("%s\n",p);

  return 0;
}