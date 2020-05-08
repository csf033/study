#include <stdio.h>
#include <ctype.h>

int compare(const unsigned char *string1,const unsigned char *string2);

int main(){
  int result = compare("ads","ADS");
  printf("%d\n",result);
  printf("%ld\n",sizeof("aaa")-sizeof(""));
}

int compare(const unsigned char *string1,const unsigned char *string2){
  if(string1 == NULL || string2 == NULL){
    return 1;
  }
  if(string1 == string2){
    return 0;
  }

  for(;tolower(*string1) == tolower(*string2);(void)string1++,string2++){
    // printf("%c\n",*string1);
    if(*string1 == '\0'){
      return 0;
    }
  }

  return tolower(*string1) - tolower(*string2);
}
