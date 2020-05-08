#include <stdio.h>
#include <stdlib.h>

#define N 2

void test1();

void test2();

void test3();

void test4();

void test5();

void test6();

int main(){
  // test1();
  // printf("\n==========================test1()调用结束=============================\n\n\n");
  // test2();
  // test3();
  // test4();
  test5();
//   test6();
  return 0;
}

void test1(){
  FILE *fp = fopen("test1.txt","rt");
  char str[N+1];
  if(fp == NULL){
    puts("fail to open file");
    exit(0);
  }

  while(fgets(str, N, fp) != NULL){
    printf("%s", str);
  }

  fclose(fp);
}

void test2(){
  FILE *fp = fopen("test1.txt","rt");
  char ch;

  if(fp == NULL){
    printf("fail to open file\n");
    exit(0);
  }

  while((ch=fgetc(fp)) != EOF){
    putchar(ch);
  }
  putchar('\n');

  if(ferror(fp)){
    puts("读取文件出错");
  }else{
    puts("读取文件成功");
  }
  fclose(fp);
}

void test3(){
  FILE *fp = fopen("test1.txt","wt+");
  char ch;
  if(fp == NULL){
    printf("fail to open file\n");
    exit(0);
  }

  while((ch=getchar()) != '\n'){
    fputc(ch,fp);
  }
  fclose(fp);
}

/*
  数据块二进制形式读取文件
*/
#define M 5
void test4(){
  int a[M],b[M];
  int i,size = sizeof(int);
  FILE *fp;
  
  if((fp = fopen("test1.txt","rb+")) == NULL){
    printf("Fail to open file!");
    exit(0);
  }

  for(i=0;i<M;i++){
    scanf("%d",&a[i]);
  }

  fwrite(a,size,M,fp);

  rewind(fp);

  fread(b,size,M,fp);

  for(i=0;i<M;i++){
    printf("%d",b[i]);
  }
  printf("\n");

  fclose(fp);

}

#define H 2
void test5(){
  struct stu{
    char name[10]; //姓名
    int num;  //学号
    int age;  //年龄
    float score;  //成绩
  }boya[N], boyb[N], *pa, *pb;

  FILE *fp;
  int i;
  pa = boya;
  pb = boyb;
  if( (fp=fopen("test6.txt", "wb+")) == NULL ){
    puts("Fail to open file!");
    exit(0);
  }
  //从键盘输入数据
  printf("Input data:\n");
  for(i=0; i<N; i++,pa++){
    scanf("%s %d %d %f",pa->name, &pa->num,&pa->age, &pa->score);
  }

  fwrite(boya,sizeof(struct stu),N,fp);

  rewind(fp);

  fread(boyb,sizeof(struct stu),N,fp);

  for(i=0;i<N;i++,pb++){
    printf("%s %d %d %f\n",pb->name,pb->num,pb->age,pb->score);
  }
  fclose(fp);
}

void test6(){
    struct stu{
        char name[10]; //姓名
        int num;  //学号
        int age;  //年龄
        float score;  //成绩
    }boya[N], boyb[N], *pa, *pb;

    FILE *fp;
    int i;
    pa = boya;
    pb = boyb;
    if( (fp=fopen("test6.txt", "wb+")) == NULL ){
        puts("Fail to open file!");
        exit(0);
    }
    //从键盘输入数据
    printf("Input data:\n");
    for(i=0; i<N; i++,pa++){
        scanf("%s %d %d %f",pa->name, &pa->num,&pa->age, &pa->score);
    }
    //将数组 boya 的数据写入文件
    fwrite(boya, sizeof(struct stu), N, fp);
    //将文件指针重置到文件开头
    rewind(fp);
    //从文件读取数据并保存到数据 boyb
    fread(boyb, sizeof(struct stu), N, fp);
    //输出数组 boyb 中的数据
    for(i=0; i<N; i++,pb++){
        printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
    }
    fclose(fp);
}